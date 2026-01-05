# Troubleshooting

## CMake cannot find Qt
- Verify `QT_PATH` points to the Qt install root (example:
  `C:/Qt/6.4.2/msvc2019_64/`).
- Ensure `CMAKE_PREFIX_PATH` includes `QT_PATH` and `QT_PATH/lib/cmake`.
- Confirm you are using a compatible compiler for the Qt build (MSVC vs MinGW).

## CMake cannot find MATLAB
- Set `Matlab_ROOT_DIR` to your MATLAB installation directory.
- Verify `Matlab_ROOT_DIR/extern/lib/win64/libMatlabCppSharedLib.lib` exists.
- Make sure MATLAB is installed with C++ Shared Library support.

## Application fails on startup
- Ensure `mtobridge_matlab.ctf` is next to `MTOBridge.exe`.
- Run the build again; the post-build step copies the CTF file.
- Confirm Qt runtime DLLs are staged via `windeployqt`.
- If you see a Qt platform plugin error, re-run the build to ensure the Qt
  plugins directory is deployed next to the executable.

## Calculations fail or return errors
- Check that inputs satisfy validation rules (see `docs/usage.md`).
- Negative moment calculations are not supported for single-span bridges.
- If loading a report, results are not imported; re-run the calculation.

## Exported chart is blank or cropped
- Make sure a calculation has completed and the chart is populated.
- Try re-saving after switching tabs to force a redraw.
