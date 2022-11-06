# Task 3 - Exploring the clktick.sv and the delay.sv modules
When vbdValue() is 60 the period is 1 tick per second for my computer.

N determins period time, because `Top->N = vbdValue()`. In clktick.sv, we then see that the width of the clock is equal to N. Therefore the length of the signal and break is determined by vbdValue.

## Test yourself challenge
### Step 1 - Top level module
I needed a top-level module that would combine clktick with f1_fsm

### Step 2 - New testbench