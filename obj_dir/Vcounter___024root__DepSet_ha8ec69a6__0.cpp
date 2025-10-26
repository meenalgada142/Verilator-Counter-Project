// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter.h for the primary calling header

#include "Vcounter__pch.h"
#include "Vcounter__Syms.h"
#include "Vcounter___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcounter___024root___dump_triggers__act(Vcounter___024root* vlSelf);
#endif  // VL_DEBUG

void Vcounter___024root___eval_triggers__act(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___eval_triggers__act\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcounter___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vcounter___024root___nba_sequent__TOP__0(Vcounter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter___024root___nba_sequent__TOP__0\n"); );
    Vcounter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vdly__count;
    __Vdly__count = 0;
    // Body
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((~ (IData)(vlSelfRef.__Vsampled_TOP__counter__DOT___Vpast_5_0)) 
                                   | (0U == (IData)(vlSelfRef.__Vsampled_TOP__count)))))))) {
            VL_WRITEF_NX("[%0t] %%Error: counter.sv:44: Assertion failed in %Ncounter.assert_reset_zero: [%0t] ASSERTION FAILED: reset=1 but count=%0#, expected=0\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name(),64,VL_TIME_UNITED_Q(1),
                         -12,4,(IData)(vlSelfRef.count));
            VL_STOP_MT("rtl\\counter.sv", 44, "");
        }
    }
    __Vdly__count = vlSelfRef.count;
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.__Vsampled_TOP__reset) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__counter__DOT___Vpast_1_0)) 
                                      | ((IData)(vlSelfRef.__Vsampled_TOP__count) 
                                         == (0xfU & 
                                             ((IData)(1U) 
                                              + (IData)(vlSelfRef.__Vsampled_TOP__counter__DOT__count_q))))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: counter.sv:32: Assertion failed in %Ncounter.assert_increment: [%0t] ASSERTION FAILED: en=1 but count=%0#, expected=%0#\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name(),64,VL_TIME_UNITED_Q(1),
                         -12,4,(IData)(vlSelfRef.count),
                         4,vlSelfRef.counter__DOT__count_q);
            VL_STOP_MT("rtl\\counter.sv", 32, "");
        }
    }
    if (vlSymsp->_vm_contextp__->assertOnGet(1, 1)) {
        if (VL_UNLIKELY(((1U & (~ ((IData)(vlSelfRef.__Vsampled_TOP__reset) 
                                   | ((~ (IData)(vlSelfRef.__Vsampled_TOP__counter__DOT___Vpast_3_0)) 
                                      | ((IData)(vlSelfRef.__Vsampled_TOP__count) 
                                         == (IData)(vlSelfRef.__Vsampled_TOP__counter__DOT__count_q))))))))) {
            VL_WRITEF_NX("[%0t] %%Error: counter.sv:38: Assertion failed in %Ncounter.assert_hold: [%0t] ASSERTION FAILED: en=0 but count=%0#, expected=%0#\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name(),64,VL_TIME_UNITED_Q(1),
                         -12,4,(IData)(vlSelfRef.count),
                         4,vlSelfRef.counter__DOT__count_q);
            VL_STOP_MT("rtl\\counter.sv", 38, "");
        }
    }
    if (vlSelfRef.reset) {
        __Vdly__count = 0U;
    } else if (vlSelfRef.en) {
        __Vdly__count = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.count)));
    }
    vlSelfRef.counter__DOT___Vpast_5_0 = vlSelfRef.__Vsampled_TOP__reset;
    vlSelfRef.counter__DOT___Vpast_1_0 = ((~ (IData)(vlSelfRef.__Vsampled_TOP__reset)) 
                                          & (IData)(vlSelfRef.__Vsampled_TOP__en));
    vlSelfRef.counter__DOT___Vpast_3_0 = (1U & ((~ (IData)(vlSelfRef.__Vsampled_TOP__reset)) 
                                                & (~ (IData)(vlSelfRef.__Vsampled_TOP__en))));
    vlSelfRef.counter__DOT__count_q = vlSelfRef.count;
    vlSelfRef.count = __Vdly__count;
}
