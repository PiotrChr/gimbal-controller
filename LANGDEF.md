# Movement language definition:

## Movement:
```yaml
{type: [A]} {mode: [A|R]} {x movement: X[number]} {y movement: Y[number]} {speed: S[number]}
```

For example: 

```gcode
A A X15 Y40 S50
```
Moves the gimbal to the absolute position of X=15 and Y=40 with a speed of 50

```gcode
A R X15 Y5 S50
```
Moves the gimbal by a ralative position of 15 in X and 5 in Y with a speed of 50

```gcode
A R X15 Y-5 S50
```
Moves the gimbal by a ralative position of 15 in X and -5 in Y with a speed of 50


## Other commands:
`START` - starts movement program

`DELAY [number]` - delay (in miliseconds)

`END` - stops movement program

`RESTART` - restarts the program


## Examples:

Example program could look like this:

```gcode
START
A A X15 Y40 S50
A R X0 Y-5 S50
A R X0 Y5 S50
A R X0 Y-5 S50
DELAY 500
A R X-5 Y0 S50
A R X5 Y0 S10
RESTART
```