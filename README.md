# MTOBridge

MTOBridge is a Qt 6 desktop application for configuring truck platoons and
bridge spans, then running MATLAB-backed solvers to compute force responses and
visualize results. The GUI guides the full workflow: input, validation,
calculation, visualization, and export.

## Highlights
- Configure truck platoons (axle loads, spacing, headway, truck count) with a live visual.
- Configure bridge geometry (1-3 spans, concerned section, discretization) with a live visual.
- Run force-response calculations and view charts plus a truck-on-bridge animation.
- Save/load configurations and reports (`.trk`, `.brg`, `.txt`) and export charts (`.png`).
- Automated tests via Qt Test and CTest, integrated with CMake.

## Requirements
Runtime:
- Windows 10/11
- Qt 6 runtime dependencies (staged via `windeployqt`)
- MATLAB runtime components and `mtobridge_matlab.ctf` next to the executable

Build:
- CMake 3.16+
- C++20 toolchain (MSVC 2019+ recommended for Qt 6)
- Qt 6.4+ (Core, Widgets, Charts, Test)
- MATLAB R2022b (or compatible) with MATLAB C++ Shared Library support

## Project Layout
- `docs/` - project documentation, guides, and references.
- `src/` - application source code and modules.
- `tests/` - automated tests and CTest integration.
- `tools/` - developer tooling and IDE settings.

## Build and Run
See `INSTALL.md` for full prerequisites and build steps. Typical configure/build:

```powershell
cmake -S . -B build -DQT_PATH="C:/Qt/6.4.2/msvc2019_64/" -DMatlab_ROOT_DIR="C:/Program Files/Matlab/R2022b"
cmake --build build --config Release
```

Run the generated `MTOBridge.exe` from the build output directory.

## Testing
Tests are enabled by default. Disable with `-DMTOBRIDGE_BUILD_TESTS=OFF`.

```powershell
cmake -S . -B build -DMTOBRIDGE_BUILD_TESTS=ON
cmake --build build --config Debug
ctest --test-dir build --output-on-failure
```

## File Formats
Configuration and report formats are plain text. See `docs/file-formats.md` for
schemas and examples.

## Documentation
- `docs/README.md` for the documentation index.
- `docs/usage.md` for the GUI workflow.
- `docs/architecture.md` for module and data-flow notes.
- `docs/troubleshooting.md` for common build and runtime issues.
- `docs/development.md` for build options and contributor notes.

## Contributing
See `CONTRIBUTING.md` for development and submission guidelines.

## License
Licensed under the terms in `LICENSE`.
