#pragma once

#include <QtCharts>
#include <QtWidgets>

#include "../report/report.hpp"
#include "util/data_types.hpp"

#define ANIMATION_TIME 15000          //Total time the animation should take in miliseconds
#define PIXELS_PER_METER 5            //Pixels per meter in truck and bridge visualisations
#define TRUCK_POSITION_INCREMENT 0.1  //Amount the truck moves forward per data point (in meters)
#define BUTTON_HOLD_TIME 500          //Amount of time (in ms) the nextFrame or backFrame button needs to be held before manual animation is started

namespace mtobridge {
enum AnimationStatus { NotLoaded, AtBeginning, AtEnd, Paused, RunningForward, RunningBackward };
class ChartView : public QChartView {
  Q_OBJECT

 public:
  ChartView(QChart* chart, QWidget* parent = 0) {}

 protected:
  void mouseReleaseEvent(QMouseEvent* event) override;
};

class SolverVisual : public QWidget {
  Q_OBJECT

 public:
  SolverVisual(QWidget* parent) : QWidget(parent) { createPage(); };
  ~SolverVisual(){};

  void updateScene(std::string, QGraphicsScene*);
  //void setBridge(QGraphicsScene*);
  //void setPlatoon(QGraphicsScene*);
  void showEvent(QShowEvent* showEvent);

  friend class ChartView;

 signals:
  void runCommand(MockCalculationInputT);
  void loadReport();

 public slots:
  void errorOccurred(QString);
  void updateChart(MockCalculationInputT, MockCalculationOutputT);
  void loadedReport(Report);

 private:
   int animationMin;
   int animationMax;
   int animationInc;
   int animationSpeed;
   AnimationStatus animationStatus;

  QGroupBox* forceSettingGroup;
  QGroupBox* solverSettingGroup;
  // Force setting window
  // Solver setting window
  QPushButton* calculateButton;
  QTimer* animationTimer;
  QPushButton* firstFrameButton;
  QPushButton* backFrameButton;
  QPushButton* animationButton;
  QPushButton* nextFrameButton;
  QPushButton* lastFrameButton;
  QPushButton* saveButton;
  QGroupBox* saveLoadGroup;
  // QPushButton* saveButton;
  // QPushButton* loadButton;
  // Truck + bridge window

  QTabWidget* mChartTabWidget;
  QChart* mChart;
  ChartView* mChartView;

  // Force Envelope Chart
  QChart* mEnvelopeChart;
  QChartView* mEnvelopeChartView;

  QRadioButton* positiveMomentButton;
  QRadioButton* negativeMomentButton;
  QRadioButton* shearButton;
  QRadioButton* concernedButton;
  QRadioButton* criticalButton;

  QGraphicsView* truckBridgeVisual;

  QLabel* concernedSectionLabel;
  QLineEdit* concernedSectionReminder;
  QLabel* discretizationLengthLabel;
  QLineEdit* discretizationLengthReminder;

  Report mReport;

  QGraphicsItemGroup *truckGroup;
  QGraphicsItemGroup *bridgeGroup;
  QGraphicsLineItem *concernedSectionLine;
  QGraphicsLineItem *criticalSectionLine;
  QGraphicsTextItem *discretizationLengthText;

  void setTruckPosition(double);
  bool moveFrames(int);
  void animateForward();
  void animateBackward();
  void setUpAnimation();
  void createPage();
  void updatePage();

};
};  // namespace mtobridge
