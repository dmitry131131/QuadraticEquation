# Квадратка






# QuadraticEquation
Console programm to solve quadratic equation

### Compile
`make rec`       -- compile realise version

`make rec_t`      -- compile test version 

## Usage: [flag]
### Realise Mode
`[]`               -- console input and console output
Enter a b c decimal coefficients separated by a space

`[-f] [filename]`  -- input first 3 numbers in row from and output solutions to console
programm works until End Of File

`[-h]`             -- output help information about programm


### Test Mode
`[-t] [filename]`  -- test mode:
programm read first 3 numbers, solve equation and compare roots with roots in file
a b c  real1 complex1 real2 complex2
a, b, c - decimal coefficient
real1, real2 - real parts of first and second answers
complex1, complex2 - complex parts of first and second answers
