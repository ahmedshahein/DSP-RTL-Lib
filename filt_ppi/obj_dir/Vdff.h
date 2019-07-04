// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vdff_H_
#define _Vdff_H_

#include "verilated.h"

class Vdff__Syms;

//----------

VL_MODULE(Vdff) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(i_rst_an,0,0);
    VL_IN8(i_clk,0,0);
    VL_IN8(i_fclk,0,0);
    VL_IN8(i_ena,0,0);
    VL_IN8(i_data,7,0);
    VL_OUT8(o_sclk,0,0);
    VL_OUT(o_data,25,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
	// Begin mtask footprint  all: 
	VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT__r_idx,4,0);
	VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT__r_done,0,0);
	VL_SIGW(filt_ppi__DOT__ppi_mul_add__DOT__w_mul,1439,0,45);
	VL_SIGW(filt_ppi__DOT__ppi_mul_add__DOT__w_sum,1559,0,49);
	VL_SIGW(filt_ppi__DOT__ppi_mul_add__DOT__w_reg,779,0,25);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__30__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__35__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__40__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__45__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__46__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__51__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__56__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt,29,0);
	VL_SIGW(filt_ppi__DOT__ppi_commutator__DOT__w_data,779,0,25);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
    };
    struct {
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG(filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data,25,0);
	VL_SIG16(filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[27],15,0);
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__i_fclk,0,0);
    VL_SIG8(__Vclklast__TOP__i_rst_an,0,0);
    VL_SIG8(__Vclklast__TOP__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdff__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdff);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdff(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdff();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vdff__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdff__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdff__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__35(Vdff__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(Vdff__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vdff__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vdff__Syms* __restrict vlSymsp);
    static void _eval_settle(Vdff__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__36(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__10(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__13(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__14(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__15(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__16(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__17(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__18(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__19(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__20(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__21(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__22(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__23(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__24(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__25(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__26(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__27(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__28(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__29(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__30(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__31(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__32(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__33(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__34(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vdff__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vdff__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vdff__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
