# File Formats

MTOBridge uses plain-text files for configuration and reporting. Files are
parsed with strict numeric checks, so keep values space-separated and avoid
extra labels unless shown below.

## Truck Configuration (`.trk`)
Purpose: save/load a truck platoon configuration.

Format (4 lines):
1) Axle loads (space-separated)
2) Axle spacings (space-separated)
3) Headway (single number)
4) Number of trucks (integer)

Example:
```text
120 130 130
4.0 4.0
2.5
3
```

Notes:
- The axle load list must contain exactly one more entry than the axle spacing list.
- All values must be numeric; the truck count must be an integer.
- Only the first four non-empty lines are read on load.

## Bridge Configuration (`.brg`)
Purpose: save/load a bridge configuration.

Format (4 lines):
1) Number of spans (integer)
2) Span lengths (space-separated)
3) Concerned section (single number)
4) Discretization length (single number)

Example:
```text
2
18.0 20.0
12.5
0.5
```

Notes:
- The number of spans must be 1 to 3.
- The span length list size must match the span count.
- The concerned section must be within the total bridge length.
- Only the first four non-empty lines are read on load.

## Report (`.txt`)
Purpose: save a full analysis report (inputs and results) and reload inputs.

Structure:
```text
Report
*******
*******
*******
[Platoon]
axleLoad = ...
axleSpacing = ...
headway = ...
numberofTrucks = ...
*******
[Bridge]
numberSpans = ...
spanLength = ...
concernedSection = ...
discretizationLength = ...
*******
[Solver]
forceType = Positive Moment | Negative Moment | Shear
solverType = Concerned | Critical
*******
[Results]
...
```

Notes:
- The loader parses `[Platoon]`, `[Bridge]`, and `[Solver]` sections only.
- The `[Results]` section is preserved for reporting but is not used when loading.
- Lines starting with `*` or empty lines are ignored by the loader.

## Solver Configuration (`.slv`)
Purpose: save/load solver settings at the module level.

Format (2 lines):
1) Force type: `Positive Moment`, `Negative Moment`, or `Shear`
2) Solver type: `Concerned` or `Critical`

Example:
```text
Shear
Concerned
```

Notes:
- The UI does not currently expose a direct save/load for `.slv`, but the
  module APIs support it.
