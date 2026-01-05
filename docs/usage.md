# Usage Guide

## Typical Workflow
1. **Platoon tab**: Configure axle loads, axle spacing, number of trucks, and
   headway. Use Save/Load to persist `.trk` configurations.
2. **Bridge tab**: Configure number of spans, span lengths, concerned section,
   and discretization length. Use Save/Load to persist `.brg` configurations.
3. **Solver tab**: Select the force response and solver type, then run the
   calculation. Review the force response chart, force envelope (when
   applicable), and the truck/bridge animation.
4. **Export**: Save charts as `.png` and reports as `.txt`. Use "Load From
   Report" to restore a full analysis state.

## Input Details
### Platoon
- **Axle loads**: space-separated list of axle loads.
- **Axle spacing**: space-separated list of axle spacings.
- **Number of trucks**: positive integer.
- **Headway**: positive number.

### Bridge
- **Number of spans**: 1 to 3.
- **Span lengths**: space-separated list with one entry per span.
- **Concerned section**: position along the bridge.
- **Discretization length**: positive number that controls solver granularity.

### Solver
- **Force response**: Positive Moment, Negative Moment, or Shear.
- **Solver type**: Concerned Section or Critical Section.

## Validation Rules
Inputs are validated before a calculation:
- Axle loads must have one more entry than axle spacings.
- Headway and number of trucks must be greater than zero.
- Bridge span count must be 1 to 3, with matching span lengths.
- Concerned section must be between 0 and the total bridge length.
- Discretization length must be greater than zero.
- Negative moment is not supported for single-span bridges.

## Report Loading
Loading a report restores input settings. Results are not imported; re-run the
calculation to regenerate charts and animations.

## Chart Interaction and Animation
- Use the animation controls to step forward/backward or play the sequence.
- When the animation is paused (or at the beginning/end), click the force
  response chart to jump the truck position to that point.

## Output Files
- `*.trk` - truck/platoon configuration.
- `*.brg` - bridge configuration.
- `*.txt` - analysis report (inputs and results).
- `*.png` - exported chart image.
