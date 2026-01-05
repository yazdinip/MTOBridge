# Architecture Overview

## System Flow
MTOBridge is a Qt 6 desktop application that gathers user inputs for truck
platoons and bridge geometry, runs MATLAB-based calculations, and visualizes the
results in charts and animations.

High-level flow:
1. The user configures a platoon and bridge in the GUI.
2. The solver collects inputs and dispatches a calculation request to the engine.
3. The engine invokes MATLAB compiled functions (`mtobridge_matlab.ctf`) on a
   background thread and returns results.
4. The solver visualizes force responses and enables report/chart export.

## Components and Responsibilities
- **GUI shell** (`src/gui/`): Creates the tabbed window and wires signals.
- **Platoon configuration** (`src/PlatoonConfiguration/`): Owns platoon inputs
  and the truck visualization.
- **Bridge configuration** (`src/bridge/`): Owns bridge inputs and the bridge
  visualization.
- **Solver** (`src/solver/`): Collects inputs, triggers calculations, renders
  charts, and drives the animation state machine.
- **Engine** (`src/engine/`): Runs MATLAB-backed calculations on a dedicated
  thread and reports results via Qt signals.
- **Persistence** (`src/saver/`): Serializes configs, reports, and chart images.
- **Shared types** (`src/util/`, `src/report/`): Data structures and validation.

## Threading Model
The engine runs in a separate `QThread` to keep the GUI responsive. The solver
emits a `runCommand` signal with inputs; the engine performs the calculation and
emits `finishedCommand` or `errorOccurred` back to the GUI thread.

## Data Model
Core structs are defined in `src/util/include/util/data_types.hpp`:
- `MockTruckT` for platoon data.
- `MockBridgeT` for bridge data.
- `MockSolverT` for solver choices.
- `MockCalculationInputT` and `MockCalculationOutputT` for computation IO.

`src/report/report.hpp` wraps inputs and outputs into a single `Report` type for
save/load workflows.

## MATLAB Integration
The engine initializes MATLAB in-process and loads the compiled library from
`mtobridge_matlab.ctf`. Calculation inputs are marshalled into MATLAB arrays
and converted back into `MockCalculationOutputT` for the GUI.

## Validation
Validation helpers in `src/util/data_types.cpp` enforce:
- Axle load/spacing consistency and positive headway/truck counts.
- Bridge span limits (1-3) and valid section ranges.
- Disallowed combinations (negative moment with single-span bridges).

## Persistence and IO
Configuration files are plain text with simple schemas. Reports include both
inputs and results, but only inputs are loaded when a report is imported. See
`docs/file-formats.md` for full schemas and examples.

## Key Modules
- `src/gui/` - application shell and tab wiring (`Window`).
- `src/PlatoonConfiguration/` - truck/platoon inputs and visualization.
- `src/bridge/` - bridge inputs and visualization.
- `src/solver/` - solver controls, charts, animation, and report handling.
- `src/engine/` - background thread and MATLAB invocation.
- `src/matlab/` - compiled MATLAB component (`mtobridge_matlab.ctf`) and headers.
- `src/saver/` - persistence for configs, reports, and chart export.
- `src/util/` - core data types and validation helpers.
- `src/report/` - report structure for input/result capture.
