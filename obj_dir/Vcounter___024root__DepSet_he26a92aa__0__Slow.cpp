// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter.h for the primary calling header

#include "Vcounter__pch.h"
#include "Vcounter___024root.h"

VL_ATTR_COLD void Vcounter___024root___eval_static(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_static\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vcounter___024root___eval_initial(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_initial\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vcounter___024root___eval_final(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_final\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vcounter___024root___eval_settle(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_settle\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcounter___024root___dump_triggers__act(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___dump_triggers__act\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcounter___024root___dump_triggers__nba(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___dump_triggers__nba\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcounter___024root___ctor_var_reset(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___ctor_var_reset\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7710216835639188562ull);
    vlSelf->count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10730142128712957955ull);
    vlSelf->counter__DOT__count_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5031681349134613073ull);
    vlSelf->counter__DOT___Vpast_1_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5028774121756876537ull);
    vlSelf->counter__DOT___Vpast_3_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1002207995669072024ull);
    vlSelf->counter__DOT___Vpast_5_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17990235344780237838ull);
    vlSelf->__Vsampled_TOP__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9336069700868475665ull);
    vlSelf->__Vsampled_TOP__counter__DOT___Vpast_1_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7950301601252886370ull);
    vlSelf->__Vsampled_TOP__count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11052205530776015261ull);
    vlSelf->__Vsampled_TOP__counter__DOT__count_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10954969549248318080ull);
    vlSelf->__Vsampled_TOP__counter__DOT___Vpast_3_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3080027649066327215ull);
    vlSelf->__Vsampled_TOP__counter__DOT___Vpast_5_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3553377745532245492ull);
    vlSelf->__Vsampled_TOP__en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 267288428877444113ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
}
