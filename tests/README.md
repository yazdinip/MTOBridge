# Automated Tests

Tests are organized by module and use Qt Test with CTest integration.

## Layout
- `tests/engine/` - engine and MATLAB wrapper tests.
- `tests/saverLoader/` - save/load tests for file IO.
- `tests/solver/` - solver logic tests.

## Running Tests
Build the project with tests enabled, then run CTest from the build directory:

```powershell
ctest --output-on-failure
```

## Notes
- Engine tests link against the MATLAB C++ Shared Library and require a valid
  MATLAB installation.
- GUI-related tests may require a desktop session to render widgets.
