// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1.h for the primary calling header

#include "verilated.h"

#include "Vf1___024root.h"

VL_ATTR_COLD void Vf1___024root___settle__TOP__0(Vf1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1___024root___settle__TOP__0\n"); );
    // Body
    if (((((((((0U == vlSelf->f1__DOT__current_state) 
               | (1U == vlSelf->f1__DOT__current_state)) 
              | (2U == vlSelf->f1__DOT__current_state)) 
             | (3U == vlSelf->f1__DOT__current_state)) 
            | (4U == vlSelf->f1__DOT__current_state)) 
           | (5U == vlSelf->f1__DOT__current_state)) 
          | (6U == vlSelf->f1__DOT__current_state)) 
         | (7U == vlSelf->f1__DOT__current_state))) {
        if ((0U == vlSelf->f1__DOT__current_state)) {
            vlSelf->f1__DOT__next_state = 1U;
            vlSelf->out = 0U;
        } else if ((1U == vlSelf->f1__DOT__current_state)) {
            vlSelf->f1__DOT__next_state = 2U;
            vlSelf->out = 1U;
        } else if ((2U == vlSelf->f1__DOT__current_state)) {
            vlSelf->f1__DOT__next_state = 3U;
            vlSelf->out = 3U;
        } else if ((3U == vlSelf->f1__DOT__current_state)) {
            vlSelf->f1__DOT__next_state = 4U;
            vlSelf->out = 7U;
        } else if ((4U == vlSelf->f1__DOT__current_state)) {
            vlSelf->f1__DOT__next_state = 5U;
            vlSelf->out = 0xfU;
        } else if ((5U == vlSelf->f1__DOT__current_state)) {
            vlSelf->f1__DOT__next_state = 6U;
            vlSelf->out = 0x1fU;
        } else if ((6U == vlSelf->f1__DOT__current_state)) {
            vlSelf->f1__DOT__next_state = 7U;
            vlSelf->out = 0x3fU;
        } else {
            vlSelf->f1__DOT__next_state = 8U;
            vlSelf->out = 0x7fU;
        }
    } else {
        vlSelf->f1__DOT__next_state = 0U;
        vlSelf->out = ((8U == vlSelf->f1__DOT__current_state)
                        ? 0xffU : 0U);
    }
}

VL_ATTR_COLD void Vf1___024root___eval_initial(Vf1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vf1___024root___eval_settle(Vf1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1___024root___eval_settle\n"); );
    // Body
    Vf1___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vf1___024root___final(Vf1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1___024root___final\n"); );
}

VL_ATTR_COLD void Vf1___024root___ctor_var_reset(Vf1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->out = VL_RAND_RESET_I(8);
    vlSelf->f1__DOT__current_state = 0;
    vlSelf->f1__DOT__next_state = 0;
}
