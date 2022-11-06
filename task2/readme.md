# Task 2 Formula 1 Light Sequence
## Step 1 - create f1.sv
Pretty straight forward and intuitive sv code
```systemverilog
module f1(
    input logic         clk,
    input logic         rst,
    input logic         en,
    output logic [8:1]  out
);

    //Define the states
    typedef enum {IDLE, S1, S2, S3, S4, S5, S6, S7, S8} my_state;
    my_state current_state, next_state;

    //state registers 
    always_ff @(posedge clk)
        if (rst)        current_state <= IDLE;
        else if (en)         current_state <= next_state;

    //next state logic 
    always_comb 
        case(current_state)
            IDLE:   next_state = S1;
            S1:     next_state = S2;
            S2:     next_state = S3;
            S3:     next_state = S4;
            S4:     next_state = S5;
            S5:     next_state = S6;
            S6:     next_state = S7;
            S7:     next_state = S8;
            S8:     next_state = IDLE;
            default:next_state = IDLE;
        endcase

    always_comb
        case (current_state)
            IDLE:   out = 8'b0;
            S1:     out = 8'b1;
            S2:     out = 8'b11;
            S3:     out = 8'b111;
            S4:     out = 8'b1111;
            S5:     out = 8'b11111;
            S6:     out = 8'b111111;
            S7:     out = 8'b1111111;
            S8:     out = 8'b11111111;
            default: out = 8'b0;
        endcase
endmodule 

```
## Step 2 - Change testbench
Basically same as task1 challenge, the only changes are the module names.
```cpp
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vf1.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vf1* top = new Vf1;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("f1.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L2T1: LFSR");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 1;
  top->en = 1;

  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    top->rst = 0;
    top->en = vbdFlag();
   
    // plot ROM output and print cycle count
    vbdHex(2, (top->out >> 4) & 0xF);
    vbdHex(1, top->out & 0xF);
    vbdBar(top->out & 0xFF);

    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);                // ... exit if finish OR 'q' pressed
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
```