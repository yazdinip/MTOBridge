# Development Guide

## Build Options
The top-level `CMakeLists.txt` exposes common cache variables:
- `QT_PATH`: Qt installation root (used to populate `CMAKE_PREFIX_PATH`).
- `Matlab_ROOT_DIR`: MATLAB installation root (used for headers and libraries).
- `MTOBRIDGE_BUILD_TESTS`: enable/disable tests (default: ON).

Example:
```powershell
cmake -S . -B build -DQT_PATH="C:/Qt/6.4.2/msvc2019_64/" -DMatlab_ROOT_DIR="C:/Program Files/Matlab/R2022b" -DMTOBRIDGE_BUILD_TESTS=ON
```

## Build Outputs
By default, binaries are written under the build directory:
- Libraries: `build/lib`
- Executables: `build/bin`

`windeployqt` runs after build to stage Qt dependencies next to the binary.

## Tests
Tests use Qt Test and CTest. The engine tests link against the MATLAB C++
Shared Library, so they require a valid MATLAB installation.

```powershell
ctest --test-dir build --output-on-failure
```

## Notes for Contributors
- Keep changes scoped and avoid refactoring unrelated files.
- Prefer updating documentation in `docs/` for user-facing changes.
- Use `clang-format` only on files you touch.

## IDE Notes
- `CMakeSettings.json` is provided for Visual Studio CMake workflows.
- Qt Creator users can reference `tools/qtcreator/CMakeLists.txt.user`.
