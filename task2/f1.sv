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
