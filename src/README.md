# Source Code

This directory contains the core application and its modules.

## Entry Points
- `main.cpp` initializes Qt and launches the main window.
- `gui/window.*` wires the application tabs and routes signals between modules.

## Modules
- `bridge/` - bridge configuration data structures and visual widgets.
- `engine/` - background execution and MATLAB integration.
- `gui/` - main window and tab wiring.
- `matlab/` - compiled MATLAB artifacts and headers.
- `PlatoonConfiguration/` - truck/platoon configuration UI and data.
- `report/` - report data structure for results.
- `saver/` - save/load for configurations, reports, and charts.
- `solver/` - solver UI, charting, and animation.
- `util/` - shared data types and validation helpers.

## Build Structure
Each module has its own `CMakeLists.txt` and is linked into the `MTOBridge`
executable from `src/CMakeLists.txt`.

## Notes for Developers
- The engine runs in a dedicated thread; avoid blocking work on the GUI thread.
- MATLAB integration requires `mtobridge_matlab.ctf` at runtime.
- File IO is handled through `saver/loader.*` and `saver/saver.*`.
