# Contributing

Thanks for your interest in improving MTOBridge. This guide keeps changes
consistent and reviewable.

## Getting Started
1. Review `README.md` and `INSTALL.md`.
2. Create a branch for your change.
3. Keep changes focused and scoped to a single purpose.

## Development Standards
- Use C++20 and follow the existing Qt/QtCharts patterns in the codebase.
- Prefer small, readable functions over large refactors.
- Keep UI changes consistent with existing layouts and labels.
- Run `clang-format` only on files you touch.

## Tests
Run the test suite before opening a PR:

```powershell
ctest --test-dir build --output-on-failure
```

## Submitting Changes
Include a clear summary of what changed and why. If you add new behavior, add or
update tests where practical.

By participating, you agree to follow `CODE_OF_CONDUCT.md`.
