# Installation

## Requirements
- Windows 10/11
- CMake 3.16+
- C++20 toolchain (MSVC 2019+ recommended for Qt 6)
- Qt 6.4+ (Core, Widgets, Charts, Test)
- MATLAB R2022b (or compatible) with MATLAB C++ Shared Library support

## Configure and Build
MTOBridge uses CMake. The build expects a Qt install root and a MATLAB root.

```powershell
cmake -S . -B build -DQT_PATH="C:/Qt/6.4.2/msvc2019_64/" -DMatlab_ROOT_DIR="C:/Program Files/Matlab/R2022b"
cmake --build build --config Release
```

Notes:
- The build copies `src/matlab/mtobridge_matlab.ctf` to the output directory.
- `windeployqt` runs after build to stage Qt runtime dependencies.
- The build scripts are currently Windows-focused; other platforms will require
  path and deployment adjustments.

## Run
Launch the generated `MTOBridge.exe` from the build output directory. Ensure the
MATLAB runtime components and `mtobridge_matlab.ctf` are available next to the
executable.

## Clean Build
If you need a clean build, delete the build directory and reconfigure:

```powershell
Remove-Item -Recurse -Force build
cmake -S . -B build -DQT_PATH="C:/Qt/6.4.2/msvc2019_64/" -DMatlab_ROOT_DIR="C:/Program Files/Matlab/R2022b"
```

## Tests
Tests are enabled by default; you can disable them with `-DMTOBRIDGE_BUILD_TESTS=OFF`.

```powershell
cmake -S . -B build -DMTOBRIDGE_BUILD_TESTS=ON
cmake --build build --config Debug
ctest --test-dir build --output-on-failure
```

## Uninstall
There is no installer yet. To remove the application, delete the build output
directory and any exported files you created (reports, charts, configs).
