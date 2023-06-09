#include "window.hpp"

#include <chrono>
#include <sstream>
#include <thread>

#include "../PlatoonConfiguration/PlatoonVisual.hpp"
#include "../bridge/bridgevisual.hpp"
#include "../engine/engine.hpp"
#include "../saver/loader.hpp"
#include "util/data_types.hpp"

namespace mtobridge {
Window::Window(QWidget *parent) : QWidget(parent) {
  setWindowTitle("MTOBridge");
  resize(800, 600);
  createWindow();
}

/**
 * @brief creates the main gui window and connections between widgets
 */
void Window::createWindow() {
  mTabWidget = new QTabWidget(this);
  mTabWidget->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Expanding,
                                        QSizePolicy::Policy::Expanding));

  auto *mainLayout = new QStackedLayout(this);
  mainLayout->addWidget(mTabWidget);
  setLayout(mainLayout);

  mPlatoon = new PlatoonVisual(this);
  mBridge = new BridgeVisual(this);
  mSolver = new SolverVisual(this);

  mTabWidget->addTab(mPlatoon, "Platoon");
  mTabWidget->addTab(mBridge, "Bridge");
  mTabWidget->addTab(mSolver, "Solver");

  auto &engine = Engine::getInstance();

  QObject::connect(&engine, &Engine::errorOccurred, this,
                   &Window::errorOccurred);

  QObject::connect(mPlatoon->getScene(), &QGraphicsScene::changed, this, [&]() {
    mSolver->updateScene("Truck", mPlatoon->getScene());
  });

  QObject::connect(mBridge->getScene(), &QGraphicsScene::changed, this, [&]() {
    mSolver->updateScene("Bridge", mBridge->getScene());
  });

  QObject::connect(mSolver, &SolverVisual::loadReport, this,
                   &Window::loadReport);
}

/**
 * @brief loads the report and validates the values received
 */
void Window::loadReport() {
  Report report = loader::loadReportConfiguration();
  if (report == Report())
    return;

  auto inputs = report.input;


  if (!validateTruckConfig(inputs.truckConfig)) {
    QMessageBox::warning(this, QString("Invalid report"),
                         QString("The report you loaded contains an "
                                 "invalid truck configuration"));
    return;
  }
  if (!validateBridgeConfig(inputs.bridgeConfig))
  {
    QMessageBox::warning(this, QString("Invalid report"),
      QString("The report you loaded contains an "
        "invalid bridge configuration"));
    return;
  }
  if (!validateInput(inputs)) {
    QMessageBox::warning(this, QString("Invalid report"),
      QString("The report you loaded is invalid"));
    return;
  }
  mPlatoon->loadConfiguration(inputs.truckConfig);
  MockBridgeT bridge = inputs.bridgeConfig;
  BridgeT config = {.numberSpans = bridge.numberSpans,
                    .spanLength = bridge.spanLength,
                    .concernedSection = bridge.concernedSection,
                    .discretizationLength = bridge.discretizationLength};
  mBridge->loadConfiguration(config);
  mSolver->loadedReport(report);
}

/**
 * @brief opens a message box indicating an error has occured
 * @param error a string of the error message to be display
 */
void Window::errorOccurred(QString error) {
  QMessageBox::critical(this, QString("Unknown Error!"), error);
}
};  // namespace mtobridge