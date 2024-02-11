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
A R X15 Y40 S1000
DELAY 200
A R X0 Y-5 S100
DELAY 200
A R X0 Y5 S100
DELAY 200
A R X0 Y-5 S1000
DELAY 500
A R X-5 Y-35 S500
DELAY 200
A R X5 Y0 S500
DELAY 200
A R X-15 Y0 S1000
DELAY 1000
A R X-60 Y0 S1000
DELAY 1000
A R X60 Y0 S1000
DELAY 1000
A R X0 Y60 S1000
DELAY 1000
A R X0 Y-60 S1000
DELAY 1000
RESTART
```