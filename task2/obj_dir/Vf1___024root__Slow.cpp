// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1.h for the primary calling header

#include "verilated.h"

#include "Vf1__Syms.h"
#include "Vf1___024root.h"

void Vf1___024root___ctor_var_reset(Vf1___024root* vlSelf);

Vf1___024root::Vf1___024root(Vf1__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vf1___024root___ctor_var_reset(this);
}

void Vf1___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vf1___024root::~Vf1___024root() {
}
