// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdff.h for the primary calling header

#include "Vdff.h"
#include "Vdff__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vdff) {
    Vdff__Syms* __restrict vlSymsp = __VlSymsp = new Vdff__Syms(this, name());
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdff::__Vconfigure(Vdff__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vdff::~Vdff() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vdff::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdff::eval\n"); );
    Vdff__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vdff::_eval_initial_loop(Vdff__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vdff::_settle__TOP__1(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_settle__TOP__1\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
	= (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
	= (0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
	= (0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
	= (0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
	= (0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
	= (0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
	= (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
	= (0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
	= (0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
	= (0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
	= (0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU]);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0U] = 0xfffaU;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[1U] = 0xfff7U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[2U] = 0xfff5U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[3U] = 0xfff6U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[4U] = 0U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[5U] = 0x13U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[6U] = 0x30U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[7U] = 0x52U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[8U] = 0x6fU;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[9U] = 0x79U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0xaU] = 0x61U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0xbU] = 0x1cU;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0xcU] = 0xffa9U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0xdU] = 0xff10U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0xeU] = 0xfe6cU;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0xfU] = 0xfde6U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x10U] = 0xfdb1U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x11U] = 0xfe00U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x12U] = 0xfefdU;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x13U] = 0xb9U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x14U] = 0x32cU;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x15U] = 0x629U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x16U] = 0x964U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x17U] = 0xc7dU;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x18U] = 0xf11U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x19U] = 0x10c6U;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[0x1aU] = 0x115eU;
    vlTOPp->o_sclk = vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_done;
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U]) 
	   | vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__30__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			  >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		       >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__35__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			>> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__40__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU]) 
	   | (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			  >> 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU]) 
	   | (0xfffff000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU]) 
	   | (0xfffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			>> 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU]) 
	   | (0xffffffc0U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__45__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU]) 
	   | vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__46__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			  >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		       >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__51__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			>> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__56__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x18U] 
	= (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		       >> 0xeU));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 1U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 3U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 5U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 7U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 9U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xbU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xdU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xfU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x11U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x13U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x15U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x17U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x19U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1bU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1dU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U]) 
	   | vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data);
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			  >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		       >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			>> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU]) 
	   | (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			  >> 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU]) 
	   | (0xfffff000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU]) 
	   | (0xfffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			>> 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU]) 
	   | (0xffffffc0U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU]) 
	   | vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data);
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			  >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		       >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			>> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x18U] 
	= (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		       >> 0xeU));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [1U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[1U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [2U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [2U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [3U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [4U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [5U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[5U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [6U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [6U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [7U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [8U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [9U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[9U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xaU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xaU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xbU]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0xcU])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xdU]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0xdU]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xeU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xeU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xfU]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x10U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x11U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x11U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x12U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x12U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x13U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x14U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x15U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x15U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x16U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x16U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x17U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x18U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x19U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x19U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x1aU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x1aU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x19U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x18U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x17U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x17U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x16U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x16U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x15U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x14U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x13U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x13U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x12U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x12U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x11U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x10U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xfU]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0xfU]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xeU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xeU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xdU]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0xcU])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xbU]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0xbU]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xaU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xaU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [9U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [8U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [7U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[7U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [6U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [6U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [5U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [4U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [3U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[3U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [2U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [2U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [1U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0U])))));
    vlTOPp->o_data = (0x3ffffffU & ((0x30bU >= (0x3ffU 
						& ((((IData)(0x1aU) 
						     * 
						     ((IData)(1U) 
						      + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
						    - (IData)(1U)) 
						   - (IData)(0x19U))))
				     ? (((0U == (0x1fU 
						 & ((((IData)(0x1aU) 
						      * 
						      ((IData)(1U) 
						       + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
						     - (IData)(1U)) 
						    - (IData)(0x19U))))
					  ? 0U : (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[
						  ((IData)(1U) 
						   + 
						   (0x1fU 
						    & (((((IData)(0x1aU) 
							  * 
							  ((IData)(1U) 
							   + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
							 - (IData)(1U)) 
							- (IData)(0x19U)) 
						       >> 5U)))] 
						  << 
						  ((IData)(0x20U) 
						   - 
						   (0x1fU 
						    & ((((IData)(0x1aU) 
							 * 
							 ((IData)(1U) 
							  + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
							- (IData)(1U)) 
						       - (IData)(0x19U)))))) 
					| (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[
					   (0x1fU & 
					    (((((IData)(0x1aU) 
						* ((IData)(1U) 
						   + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
					       - (IData)(1U)) 
					      - (IData)(0x19U)) 
					     >> 5U))] 
					   >> (0x1fU 
					       & ((((IData)(0x1aU) 
						    * 
						    ((IData)(1U) 
						     + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
						   - (IData)(1U)) 
						  - (IData)(0x19U)))))
				     : 0U));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U]) 
	   | (0xfffff000U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
			      << 0x1cU) | (0xffff000U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U]) 
	   | (0xfffU & ((0x30U & (VL_NEGATE_I((IData)(
						      (1U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
							  >> 7U)))) 
				  << 4U)) | (0xfU & 
					     (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U]) 
	   | (0xffffffc0U & ((0xc0000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
								     >> 0x1fU)))) 
					     << 0x1eU)) 
			     | (0x3fffffc0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
						<< 0x1eU) 
					       | (0x3fffffc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
						     >> 2U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU]) 
	   | ((0x3000000U & (VL_NEGATE_I((IData)((1U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
						     >> 0x17U)))) 
			     << 0x18U)) | (0xffffffU 
					   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU]) 
	   | (0x3ffffffU & ((0xc0000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
								 >> 0xfU)))) 
					 << 0x12U)) 
			    | (0x3ffffU & ((0x3fffffcU 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
					       << 2U)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
					      >> 0x1eU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU]) 
	   | (0xfffffU & ((0x3000U & (VL_NEGATE_I((IData)(
							  (1U 
							   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
							      >> 7U)))) 
				      << 0xcU)) | (0xfffU 
						   & ((0xffff0U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
							  << 4U)) 
						      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
							 >> 0x1cU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU]) 
	   | (0x3fffU & ((0xc0U & (VL_NEGATE_I((IData)(
						       (1U 
							& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
							   >> 0x1fU)))) 
				   << 6U)) | (0x3fU 
					      & ((0x3fc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
						     << 6U)) 
						 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
						    >> 0x1aU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU]) 
	   | (3U & VL_NEGATE_I((IData)((1U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
					      >> 0x17U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU]) 
	   | (0xfffffffcU & ((0xc000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
								    >> 0xfU)))) 
					    << 0x1aU)) 
			     | (0x3fffffcU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
					       << 0xaU) 
					      | (0x3fcU 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
						    >> 0x16U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU]) 
	   | (0xfffffffU & ((0x300000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
								  >> 7U)))) 
					  << 0x14U)) 
			    | (0xfffffU & ((0xffff000U 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
					       << 0xcU)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
					      >> 0x14U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U]) 
	   | (0x3fffffU & ((0xc000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
							       >> 0x1fU)))) 
				       << 0xeU)) | 
			   (0x3fffU & ((0x3fc000U & 
					(vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
					 << 0xeU)) 
				       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
					  >> 0x12U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U]) 
	   | (0xffffU & ((0x300U & (VL_NEGATE_I((IData)(
							(1U 
							 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
							    >> 0x17U)))) 
				    << 8U)) | (0xffU 
					       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
						  >> 0x10U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U]) 
	   | (0xfffffc00U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
			      << 0x12U) | (0x3fc00U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
					      >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U]) 
	   | (0x3ffU & ((0xcU & (VL_NEGATE_I((IData)(
						     (1U 
						      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
							 >> 0xfU)))) 
				 << 2U)) | (3U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
						  >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U]) 
	   | (0xfffffff0U & ((0x30000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
								     >> 7U)))) 
					     << 0x1cU)) 
			     | (0xffffff0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
					       << 0x14U) 
					      | (0xffff0U 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
						    >> 0xcU)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U]) 
	   | (0x3fffffffU & ((0xc00000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
								   >> 0x1fU)))) 
					   << 0x16U)) 
			     | (0x3fffffU & ((0x3fc00000U 
					      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
						 << 0x16U)) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
						>> 0xaU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U]) 
	   | (0xffffffU & ((0x30000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
								>> 0x17U)))) 
					<< 0x10U)) 
			   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
					 >> 8U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U]) 
	   | (0xfffc0000U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
			      << 0x1aU) | (0x3fc0000U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
					      >> 6U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U]) 
	   | (0x3ffffU & ((0xc00U & (VL_NEGATE_I((IData)(
							 (1U 
							  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
							     >> 0xfU)))) 
				     << 0xaU)) | (0x3ffU 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
						     >> 6U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U]) 
	   | (0xfffff000U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
			      << 0x1cU) | (0xffff000U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U]) 
	   | (0xfffU & ((0x30U & (VL_NEGATE_I((IData)(
						      (1U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
							  >> 7U)))) 
				  << 4U)) | (0xfU & 
					     (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U]) 
	   | (0xffffffc0U & ((0xc0000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
								     >> 0x1fU)))) 
					     << 0x1eU)) 
			     | (0x3fffffc0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
						<< 0x1eU) 
					       | (0x3fffffc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
						     >> 2U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U]) 
	   | ((0x3000000U & (VL_NEGATE_I((IData)((1U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
						     >> 0x17U)))) 
			     << 0x18U)) | (0xffffffU 
					   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U]) 
	   | (0x3ffffffU & ((0xc0000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
								 >> 0xfU)))) 
					 << 0x12U)) 
			    | (0x3ffffU & ((0x3fffffcU 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
					       << 2U)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
					      >> 0x1eU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U]) 
	   | (0xfffffU & ((0x3000U & (VL_NEGATE_I((IData)(
							  (1U 
							   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
							      >> 7U)))) 
				      << 0xcU)) | (0xfffU 
						   & ((0xffff0U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
							  << 4U)) 
						      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
							 >> 0x1cU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU]) 
	   | (0x3fffU & ((0xc0U & (VL_NEGATE_I((IData)(
						       (1U 
							& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
							   >> 0x1fU)))) 
				   << 6U)) | (0x3fU 
					      & ((0x3fc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
						     << 6U)) 
						 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
						    >> 0x1aU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU]) 
	   | (3U & VL_NEGATE_I((IData)((1U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
					      >> 0x17U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU]) 
	   | (0xfffffffcU & ((0xc000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
								    >> 0xfU)))) 
					    << 0x1aU)) 
			     | (0x3fffffcU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
					       << 0xaU) 
					      | (0x3fcU 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
						    >> 0x16U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU]) 
	   | (0xfffffffU & ((0x300000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
								  >> 7U)))) 
					  << 0x14U)) 
			    | (0xfffffU & ((0xffff000U 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
					       << 0xcU)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
					      >> 0x14U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU]) 
	   | (0x3fffffU & ((0xc000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
							       >> 0x1fU)))) 
				       << 0xeU)) | 
			   (0x3fffU & ((0x3fc000U & 
					(vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
					 << 0xeU)) 
				       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
					  >> 0x12U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU]) 
	   | (0xffffU & ((0x300U & (VL_NEGATE_I((IData)(
							(1U 
							 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
							    >> 0x17U)))) 
				    << 8U)) | (0xffU 
					       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
						  >> 0x10U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU]) 
	   | (0xfffffc00U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
			      << 0x12U) | (0x3fc00U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
					      >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU]) 
	   | (0x3ffU & ((0xcU & (VL_NEGATE_I((IData)(
						     (1U 
						      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
							 >> 0xfU)))) 
				 << 2U)) | (3U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
						  >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU]) 
	   | (0xfffffff0U & ((0x30000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
								     >> 7U)))) 
					     << 0x1cU)) 
			     | (0xffffff0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
					       << 0x14U) 
					      | (0xffff0U 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
						    >> 0xcU)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x30U] 
	= (0x3fffffffU & ((0xc00000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
								>> 0x1fU)))) 
					<< 0x16U)) 
			  | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
					  >> 0xaU))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U]) 
	   | (0x3ffffffU & (((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
								    >> 0x17U)))) 
					    << 0x18U)) 
			     | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U])) 
			    + vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U]) 
	   | (0xfc000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
					    >> 0x1aU))) 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U]) 
	   | (0xfffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
								   >> 0xfU)))) 
					   << 0x18U)) 
			    | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
					     << 8U) 
					    | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
					       >> 0x18U)))) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
			       << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
					 >> 0x1aU))) 
			  >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U]) 
	   | (0xfff00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
					      >> 0x14U))) 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U]) 
	   | (0x3fffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								  >> 7U)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
					    << 0x10U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
					      >> 0x10U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
			      << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
					  >> 0x14U))) 
			 >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U]) 
	   | (0xffffc000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
					       >> 0xeU))) 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U]) 
	   | (0xffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								>> 0x1fU)))) 
					<< 0x18U)) 
			 | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
					  << 0x18U) 
					 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
					    >> 8U)))) 
			+ ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
			    << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
					 >> 0xeU))) 
		       >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U]) 
	   | (0xffffff00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
					       >> 8U))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U]) 
	   | (3U & ((((0x3000000U & (VL_NEGATE_I((IData)(
							 (1U 
							  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
							     >> 0x17U)))) 
				     << 0x18U)) | (0xffffffU 
						   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U])) 
		     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
			 << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
				      >> 8U))) >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U]) 
	   | (0xffffffcU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
								     >> 0xfU)))) 
					     << 0x18U)) 
			      | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
					       << 8U) 
					      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
						 >> 0x18U)))) 
			     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
				 << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
					      >> 2U))) 
			    << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U]) 
	   | (0xf0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
					    >> 0x1cU))) 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U]) 
	   | (0x3fffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								    >> 7U)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
					      << 0x10U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
						>> 0x10U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
				<< 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
					  >> 0x1cU))) 
			   >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U]) 
	   | (0xffc00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
					      >> 0x16U))) 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U]) 
	   | (0xffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								  >> 0x1fU)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
					    << 0x18U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
					      >> 8U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
			      << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
					  >> 0x16U))) 
			 >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U]) 
	   | (0xffff0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
					       >> 0x10U))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U]) 
	   | (0x3ffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
								 >> 0x17U)))) 
					 << 0x18U)) 
			  | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U])) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
			     << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
					  >> 0x10U))) 
			>> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U]) 
	   | (0xfffffc00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
					       >> 0xaU))) 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U]) 
	   | (0xfU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
							       >> 0xfU)))) 
				       << 0x18U)) | 
			(0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
				       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
						 >> 0x18U)))) 
		       + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
			   << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
					>> 0xaU))) 
		      >> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U]) 
	   | (0x3ffffff0U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
					       >> 4U))) 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U]) 
	   | (0xc0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
					    >> 0x1eU))) 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U]) 
	   | (0xffffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
								    >> 0x1fU)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
					      << 0x18U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
						>> 8U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
				<< 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
					  >> 0x1eU))) 
			   >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U]) 
	   | (0xff000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
				  << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
					    >> 0x18U))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU]) 
	   | (0x3ffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
								   >> 0x17U)))) 
					   << 0x18U)) 
			    | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U])) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
			       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
					 >> 0x18U))) 
			  >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU]) 
	   | (0xfffc0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
				  << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
					      >> 0x12U))) 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU]) 
	   | (0xfffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
								 >> 0xfU)))) 
					 << 0x18U)) 
			  | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
					   << 8U) | 
					  (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
					   >> 0x18U)))) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
			     << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
					 >> 0x12U))) 
			>> 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU]) 
	   | (0xfffff000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
				  << 0x14U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
					       >> 0xcU))) 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU]) 
	   | (0x3fU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
								>> 7U)))) 
					<< 0x18U)) 
			 | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
					  << 0x10U) 
					 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
					    >> 0x10U)))) 
			+ ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
			    << 0x14U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
					 >> 0xcU))) 
		       >> 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU]) 
	   | (0xffffffc0U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
				  << 0x1aU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
					       >> 6U))) 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU]) 
	   | (0x3ffffffU & (((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
								    >> 0x17U)))) 
					    << 0x18U)) 
			     | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU])) 
			    + vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU]) 
	   | (0xfc000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
					    >> 0x1aU))) 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU]) 
	   | (0xfffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
								   >> 0xfU)))) 
					   << 0x18U)) 
			    | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
					     << 8U) 
					    | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
					       >> 0x18U)))) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
			       << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
					 >> 0x1aU))) 
			  >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU]) 
	   | (0xfff00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
					      >> 0x14U))) 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU]) 
	   | (0x3fffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								  >> 7U)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
					    << 0x10U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
					      >> 0x10U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
			      << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
					  >> 0x14U))) 
			 >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU]) 
	   | (0xffffc000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
					       >> 0xeU))) 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U]) 
	   | (0xffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								>> 0x1fU)))) 
					<< 0x18U)) 
			 | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
					  << 0x18U) 
					 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
					    >> 8U)))) 
			+ ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
			    << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
					 >> 0xeU))) 
		       >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U]) 
	   | (0xffffff00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
					       >> 8U))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U]) 
	   | (3U & ((((0x3000000U & (VL_NEGATE_I((IData)(
							 (1U 
							  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
							     >> 0x17U)))) 
				     << 0x18U)) | (0xffffffU 
						   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU])) 
		     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
			 << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
				      >> 8U))) >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U]) 
	   | (0xffffffcU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
								     >> 0xfU)))) 
					     << 0x18U)) 
			      | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
					       << 8U) 
					      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
						 >> 0x18U)))) 
			     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
				 << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
					      >> 2U))) 
			    << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U]) 
	   | (0xf0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
					    >> 0x1cU))) 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U]) 
	   | (0x3fffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								    >> 7U)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
					      << 0x10U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
						>> 0x10U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
				<< 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
					  >> 0x1cU))) 
			   >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U]) 
	   | (0xffc00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
					      >> 0x16U))) 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U]) 
	   | (0xffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								  >> 0x1fU)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
					    << 0x18U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
					      >> 8U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
			      << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
					  >> 0x16U))) 
			 >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U]) 
	   | (0xffff0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
					       >> 0x10U))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U]) 
	   | (0x3ffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
								 >> 0x17U)))) 
					 << 0x18U)) 
			  | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U])) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
			     << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
					  >> 0x10U))) 
			>> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U]) 
	   | (0xfffffc00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
					       >> 0xaU))) 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U]) 
	   | (0xfU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
							       >> 0xfU)))) 
				       << 0x18U)) | 
			(0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
				       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
						 >> 0x18U)))) 
		       + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
			   << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
					>> 0xaU))) 
		      >> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U]) 
	   | (0x3ffffff0U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
					       >> 4U))) 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U]) 
	   | (0xc0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
					    >> 0x1eU))) 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U]) 
	   | (0xffffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
								    >> 0x1fU)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
					      << 0x18U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
						>> 8U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
				<< 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
					  >> 0x1eU))) 
			   >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U]) 
	   | (0xff000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
				  << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
					    >> 0x18U))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U]) 
	   | (0x3ffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
								   >> 0x17U)))) 
					   << 0x18U)) 
			    | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U])) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
			       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
					 >> 0x18U))) 
			  >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U]) 
	   | (0xfffc0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x18U] 
				  << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
					      >> 0x12U))) 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U]) 
	   | (0xfffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
								 >> 0xfU)))) 
					 << 0x18U)) 
			  | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
					   << 8U) | 
					  (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
					   >> 0x18U)))) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x18U] 
			     << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
					 >> 0x12U))) 
			>> 0xeU)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__2(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__2\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG(__Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt,29,0);
    // Body
    __Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt;
    // ALWAYS at rtl/commutator.v:116
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx 
		= (0x1fU & ((0x1dU > (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))
			     ? ((IData)(1U) + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))
			     : 0U));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx = 0x1fU;
    }
    // ALWAYS at rtl/commutator.v:116
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_done 
		= (1U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
			 >> 0x1dU));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_done = 0U;
    }
    // ALWAYS at rtl/commutator.v:116
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    if ((0U == vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt)) {
		__Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    = (1U | __Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt);
	    } else {
		__Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    = ((0x3ffffffeU & __Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt) 
		       | (1U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
				>> 0x1dU)));
		__Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    = ((1U & __Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt) 
		       | (0x3ffffffeU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
					 << 1U)));
	    }
	}
    } else {
	__Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
	= __Vdly__filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt;
    vlTOPp->o_sclk = vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_done;
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 1U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 3U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 5U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 7U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 9U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xbU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xdU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0xfU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x11U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x13U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x15U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x17U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x19U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1bU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= (1U & (~ (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt 
		    >> 0x1dU)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__3(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__3\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x30U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
					    >> 0x1eU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x30U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
					       >> 4U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU] 
					       >> 0xaU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__56__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU] 
					       >> 0x10U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__56__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU] 
					      >> 0x16U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
					    >> 0x1cU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU] 
				  << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
					       >> 2U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU] 
					       >> 8U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__51__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U] 
					       >> 0xeU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__51__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U] 
					      >> 0x14U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U] 
					    >> 0x1aU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U]);
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U] 
				  << 0x1aU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U] 
					       >> 6U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__46__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U] 
				  << 0x14U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U] 
					       >> 0xcU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__46__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__45__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U] 
				  << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U] 
					      >> 0x12U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__45__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U] 
				  << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U] 
					    >> 0x18U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
					    >> 0x1eU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
					       >> 4U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U] 
					       >> 0xaU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__40__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U] 
					       >> 0x10U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__40__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU] 
					      >> 0x16U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
					    >> 0x1cU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU] 
				  << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
					       >> 2U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU] 
					       >> 8U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__35__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU] 
					       >> 0xeU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__35__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU] 
					      >> 0x14U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU] 
					    >> 0x1aU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU]);
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU] 
				  << 0x1aU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U] 
					       >> 6U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__30__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U] 
				  << 0x14U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U] 
					       >> 0xcU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__30__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x18U] 
	= (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		       >> 0xeU));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__56__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			>> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__51__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		       >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			  >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU]) 
	   | vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__46__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data);
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU]) 
	   | (0xffffffc0U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__45__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU]) 
	   | (0xfffff000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU]) 
	   | (0xfffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			>> 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU]) 
	   | (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			  >> 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__40__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			>> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			   >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__35__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
		       >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			 >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			  >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data 
			    >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U]) 
	   | vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__30__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data);
}

VL_INLINE_OPT void Vdff::_combo__TOP__4(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_combo__TOP__4\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [1U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[1U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [2U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [2U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [3U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [4U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [5U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[5U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [6U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [6U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [7U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [8U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [9U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[9U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xaU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xaU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xbU]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0xcU])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xdU]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0xdU]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xeU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xeU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xfU]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x10U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x11U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x11U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x12U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x12U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x13U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x14U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x15U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x15U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x16U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x16U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x17U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x18U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x19U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x19U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x1aU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x1aU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x19U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x18U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x17U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x17U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x16U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x16U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x15U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x14U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x13U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0x13U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x12U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0x12U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0x11U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0x10U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xfU]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0xfU]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xeU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xeU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xdU]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0xcU])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xbU]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[0xbU]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [0xaU]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [0xaU]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [9U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [8U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [7U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[7U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [6U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [6U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [5U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [4U])))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U]) 
	   | (0xff000000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [3U]))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U]) 
	   | (0xffffU & (VL_MULS_III(24,24,24, (0xffffffU 
						& VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				     (0xffffffU & VL_EXTENDS_II(24,16, 
								vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
								[3U]))) 
			 >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U]) 
	   | (0xffff0000U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [2U]))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U]) 
	   | (0xffU & (VL_MULS_III(24,24,24, (0xffffffU 
					      & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				   (0xffffffU & VL_EXTENDS_II(24,16, 
							      vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							      [2U]))) 
		       >> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U]) 
	   | (0xffffff00U & (VL_MULS_III(24,24,24, 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
					 (0xffffffU 
					  & VL_EXTENDS_II(24,16, 
							  vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
							  [1U]))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U]) 
	   | (0xffffffU & VL_MULS_III(24,24,24, (0xffffffU 
						 & VL_EXTENDS_II(24,8, (IData)(vlTOPp->i_data))), 
				      (0xffffffU & 
				       VL_EXTENDS_II(24,16, 
						     vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__c_coeff
						     [0U])))));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__5(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__5\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U]);
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U]) 
	   | vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data);
}

VL_INLINE_OPT void Vdff::_sequent__TOP__6(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__6\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U] 
					    >> 0x1aU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0U]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 6U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__7(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__7\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U] 
					      >> 0x14U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[1U]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			  >> 0xcU)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__8(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__8\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U] 
					       >> 0xeU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[2U]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x12U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__9(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__9\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U] 
					       >> 8U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[3U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		       >> 0x18U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__10(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__10\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U] 
				  << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
					       >> 2U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 2U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__11(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__11\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
					    >> 0x1cU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[4U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 4U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__12(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__12\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U] 
					      >> 0x16U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[5U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 0xaU)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__13(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__13\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U] 
					       >> 0x10U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[6U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x10U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__14(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__14\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U] 
					       >> 0xaU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[7U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			>> 0x16U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__15(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__15\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
					       >> 4U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 4U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__16(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__16\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
					    >> 0x1eU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[8U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     >> 2U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__17(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__17\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU] 
				  << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U] 
					    >> 0x18U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[9U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 8U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__18(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__18\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU] 
				  << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU] 
					      >> 0x12U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xaU]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU]) 
	   | (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			  >> 0xeU)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__19(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__19\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU] 
				  << 0x14U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU] 
					       >> 0xcU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xbU]) 
	   | (0xfffff000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU]) 
	   | (0xfffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			>> 0x14U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__20(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__20\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU] 
				  << 0x1aU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU] 
					       >> 6U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xcU]) 
	   | (0xffffffc0U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 6U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__21(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__21\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU]);
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU]) 
	   | vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data);
}

VL_INLINE_OPT void Vdff::_sequent__TOP__22(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__22\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU] 
					    >> 0x1aU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xdU]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU]) 
	   | (0x3ffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 6U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__23(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__23\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU] 
					      >> 0x14U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xeU]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU]) 
	   | (0xfffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			  >> 0xcU)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__24(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__24\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU] 
					       >> 0xeU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0xfU]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U]) 
	   | (0x3fffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x12U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__25(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__25\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U] 
					       >> 8U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x10U]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U]) 
	   | (0xffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		       >> 0x18U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__26(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__26\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U] 
				  << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
					       >> 2U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U]) 
	   | (0xfffffffcU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 2U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__27(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__27\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
					    >> 0x1cU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x11U]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U]) 
	   | (0xfffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			    >> 4U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__28(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__28\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U] 
					      >> 0x16U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x12U]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U]) 
	   | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 0xaU)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__29(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__29\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U] 
					       >> 0x10U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x13U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U]) 
	   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			 >> 0x10U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__30(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__30\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U] 
					       >> 0xaU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x14U]) 
	   | (0xfffffc00U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U]) 
	   | (0x3ffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			>> 0x16U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__31(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__31\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
					       >> 4U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U]) 
	   | (0xfffffff0U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 4U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__32(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__32\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
					    >> 0x1eU)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x15U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U]) 
	   | (0x3fffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     >> 2U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__33(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__33\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U] 
				  << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U] 
					    >> 0x18U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x16U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U]) 
	   | (0xffffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			   >> 8U)));
}

VL_INLINE_OPT void Vdff::_sequent__TOP__34(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_sequent__TOP__34\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/dff.v:19
    if (vlTOPp->i_rst_an) {
	if (vlTOPp->i_ena) {
	    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		= (0x3ffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U] 
				  << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U] 
					      >> 0x12U)));
	}
    } else {
	vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = 0U;
    }
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x17U]) 
	   | (0xfffc0000U & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[0x18U] 
	= (0x3ffffU & (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data 
		       >> 0xeU));
}

VL_INLINE_OPT void Vdff::_combo__TOP__35(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_combo__TOP__35\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U]) 
	   | (0xfffff000U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
			      << 0x1cU) | (0xffff000U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U]) 
	   | (0xfffU & ((0x30U & (VL_NEGATE_I((IData)(
						      (1U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
							  >> 7U)))) 
				  << 4U)) | (0xfU & 
					     (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x19U]) 
	   | (0xffffffc0U & ((0xc0000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
								     >> 0x1fU)))) 
					     << 0x1eU)) 
			     | (0x3fffffc0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
						<< 0x1eU) 
					       | (0x3fffffc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x17U] 
						     >> 2U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU]) 
	   | ((0x3000000U & (VL_NEGATE_I((IData)((1U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
						     >> 0x17U)))) 
			     << 0x18U)) | (0xffffffU 
					   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1aU]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU]) 
	   | (0x3ffffffU & ((0xc0000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
								 >> 0xfU)))) 
					 << 0x12U)) 
			    | (0x3ffffU & ((0x3fffffcU 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
					       << 2U)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x18U] 
					      >> 0x1eU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1bU]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU]) 
	   | (0xfffffU & ((0x3000U & (VL_NEGATE_I((IData)(
							  (1U 
							   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
							      >> 7U)))) 
				      << 0xcU)) | (0xfffU 
						   & ((0xffff0U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
							  << 4U)) 
						      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x19U] 
							 >> 0x1cU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1cU]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU]) 
	   | (0x3fffU & ((0xc0U & (VL_NEGATE_I((IData)(
						       (1U 
							& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
							   >> 0x1fU)))) 
				   << 6U)) | (0x3fU 
					      & ((0x3fc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
						     << 6U)) 
						 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1aU] 
						    >> 0x1aU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1dU]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU]) 
	   | (3U & VL_NEGATE_I((IData)((1U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
					      >> 0x17U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU]) 
	   | (0xfffffffcU & ((0xc000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
								    >> 0xfU)))) 
					    << 0x1aU)) 
			     | (0x3fffffcU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
					       << 0xaU) 
					      | (0x3fcU 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1bU] 
						    >> 0x16U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1eU]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU]) 
	   | (0xfffffffU & ((0x300000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
								  >> 7U)))) 
					  << 0x14U)) 
			    | (0xfffffU & ((0xffff000U 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
					       << 0xcU)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1cU] 
					      >> 0x14U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x1fU]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U]) 
	   | (0x3fffffU & ((0xc000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
							       >> 0x1fU)))) 
				       << 0xeU)) | 
			   (0x3fffU & ((0x3fc000U & 
					(vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
					 << 0xeU)) 
				       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1dU] 
					  >> 0x12U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x20U]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U]) 
	   | (0xffffU & ((0x300U & (VL_NEGATE_I((IData)(
							(1U 
							 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
							    >> 0x17U)))) 
				    << 8U)) | (0xffU 
					       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
						  >> 0x10U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x21U]) 
	   | (0xfffffc00U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
			      << 0x12U) | (0x3fc00U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1eU] 
					      >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U]) 
	   | (0x3ffU & ((0xcU & (VL_NEGATE_I((IData)(
						     (1U 
						      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
							 >> 0xfU)))) 
				 << 2U)) | (3U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
						  >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U]) 
	   | (0xfffffff0U & ((0x30000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
								     >> 7U)))) 
					     << 0x1cU)) 
			     | (0xffffff0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
					       << 0x14U) 
					      | (0xffff0U 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x1fU] 
						    >> 0xcU)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x22U]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U]) 
	   | (0x3fffffffU & ((0xc00000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
								   >> 0x1fU)))) 
					   << 0x16U)) 
			     | (0x3fffffU & ((0x3fc00000U 
					      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
						 << 0x16U)) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x20U] 
						>> 0xaU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x23U]) 
	   | (0xff000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U]) 
	   | (0xffffffU & ((0x30000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
								>> 0x17U)))) 
					<< 0x10U)) 
			   | (0xffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
					 >> 8U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x24U]) 
	   | (0xfffc0000U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
			      << 0x1aU) | (0x3fc0000U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x21U] 
					      >> 6U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U]) 
	   | (0x3ffffU & ((0xc00U & (VL_NEGATE_I((IData)(
							 (1U 
							  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
							     >> 0xfU)))) 
				     << 0xaU)) | (0x3ffU 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
						     >> 6U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x25U]) 
	   | (0xfffff000U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
			      << 0x1cU) | (0xffff000U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x22U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U]) 
	   | (0xfffU & ((0x30U & (VL_NEGATE_I((IData)(
						      (1U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
							  >> 7U)))) 
				  << 4U)) | (0xfU & 
					     (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
					      >> 4U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x26U]) 
	   | (0xffffffc0U & ((0xc0000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
								     >> 0x1fU)))) 
					     << 0x1eU)) 
			     | (0x3fffffc0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
						<< 0x1eU) 
					       | (0x3fffffc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x23U] 
						     >> 2U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U]) 
	   | ((0x3000000U & (VL_NEGATE_I((IData)((1U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
						     >> 0x17U)))) 
			     << 0x18U)) | (0xffffffU 
					   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x27U]) 
	   | (0xfc000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
			     << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U]) 
	   | (0x3ffffffU & ((0xc0000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
								 >> 0xfU)))) 
					 << 0x12U)) 
			    | (0x3ffffU & ((0x3fffffcU 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
					       << 2U)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x24U] 
					      >> 0x1eU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x28U]) 
	   | (0xfff00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U]) 
	   | (0xfffffU & ((0x3000U & (VL_NEGATE_I((IData)(
							  (1U 
							   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
							      >> 7U)))) 
				      << 0xcU)) | (0xfffU 
						   & ((0xffff0U 
						       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
							  << 4U)) 
						      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x25U] 
							 >> 0x1cU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x29U]) 
	   | (0xffffc000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU]) 
	   | (0x3fffU & ((0xc0U & (VL_NEGATE_I((IData)(
						       (1U 
							& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
							   >> 0x1fU)))) 
				   << 6U)) | (0x3fU 
					      & ((0x3fc0U 
						  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
						     << 6U)) 
						 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x26U] 
						    >> 0x1aU))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2aU]) 
	   | (0xffffff00U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU]) 
	   | (3U & VL_NEGATE_I((IData)((1U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
					      >> 0x17U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU]) 
	   | (0xfffffffcU & ((0xc000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
								    >> 0xfU)))) 
					    << 0x1aU)) 
			     | (0x3fffffcU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
					       << 0xaU) 
					      | (0x3fcU 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x27U] 
						    >> 0x16U)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2bU]) 
	   | (0xf0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU]) 
	   | (0xfffffffU & ((0x300000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
								  >> 7U)))) 
					  << 0x14U)) 
			    | (0xfffffU & ((0xffff000U 
					    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
					       << 0xcU)) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x28U] 
					      >> 0x14U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2cU]) 
	   | (0xffc00000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU]) 
	   | (0x3fffffU & ((0xc000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
							       >> 0x1fU)))) 
				       << 0xeU)) | 
			   (0x3fffU & ((0x3fc000U & 
					(vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
					 << 0xeU)) 
				       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x29U] 
					  >> 0x12U))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2dU]) 
	   | (0xffff0000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU]) 
	   | (0xffffU & ((0x300U & (VL_NEGATE_I((IData)(
							(1U 
							 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
							    >> 0x17U)))) 
				    << 8U)) | (0xffU 
					       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
						  >> 0x10U)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2eU]) 
	   | (0xfffffc00U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
			      << 0x12U) | (0x3fc00U 
					   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2aU] 
					      >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU]) 
	   | (0x3ffU & ((0xcU & (VL_NEGATE_I((IData)(
						     (1U 
						      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
							 >> 0xfU)))) 
				 << 2U)) | (3U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
						  >> 0xeU)))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU]) 
	   | (0xfffffff0U & ((0x30000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
								     >> 7U)))) 
					     << 0x1cU)) 
			     | (0xffffff0U & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
					       << 0x14U) 
					      | (0xffff0U 
						 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2bU] 
						    >> 0xcU)))))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x2fU]) 
	   | (0xc0000000U & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x30U] 
	= (0x3fffffffU & ((0xc00000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
								>> 0x1fU)))) 
					<< 0x16U)) 
			  | (0x3fffffU & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x2cU] 
					  >> 0xaU))));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U]) 
	   | (0x3ffffffU & (((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
								    >> 0x17U)))) 
					    << 0x18U)) 
			     | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U])) 
			    + vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0U]) 
	   | (0xfc000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
					    >> 0x1aU))) 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U]) 
	   | (0xfffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
								   >> 0xfU)))) 
					   << 0x18U)) 
			    | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
					     << 8U) 
					    | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0U] 
					       >> 0x18U)))) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
			       << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0U] 
					 >> 0x1aU))) 
			  >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[1U]) 
	   | (0xfff00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
					      >> 0x14U))) 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U]) 
	   | (0x3fffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								  >> 7U)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
					    << 0x10U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[1U] 
					      >> 0x10U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
			      << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[1U] 
					  >> 0x14U))) 
			 >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[2U]) 
	   | (0xffffc000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
					       >> 0xeU))) 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U]) 
	   | (0xffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
								>> 0x1fU)))) 
					<< 0x18U)) 
			 | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
					  << 0x18U) 
					 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[2U] 
					    >> 8U)))) 
			+ ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
			    << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[2U] 
					 >> 0xeU))) 
		       >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[3U]) 
	   | (0xffffff00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
					       >> 8U))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U]) 
	   | (3U & ((((0x3000000U & (VL_NEGATE_I((IData)(
							 (1U 
							  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
							     >> 0x17U)))) 
				     << 0x18U)) | (0xffffffU 
						   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U])) 
		     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
			 << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[3U] 
				      >> 8U))) >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U]) 
	   | (0xffffffcU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
								     >> 0xfU)))) 
					     << 0x18U)) 
			      | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
					       << 8U) 
					      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[3U] 
						 >> 0x18U)))) 
			     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
				 << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
					      >> 2U))) 
			    << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[4U]) 
	   | (0xf0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
					    >> 0x1cU))) 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U]) 
	   | (0x3fffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								    >> 7U)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
					      << 0x10U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[4U] 
						>> 0x10U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
				<< 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[4U] 
					  >> 0x1cU))) 
			   >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[5U]) 
	   | (0xffc00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
					      >> 0x16U))) 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U]) 
	   | (0xffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
								  >> 0x1fU)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
					    << 0x18U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[5U] 
					      >> 8U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
			      << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[5U] 
					  >> 0x16U))) 
			 >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[6U]) 
	   | (0xffff0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
					       >> 0x10U))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U]) 
	   | (0x3ffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
								 >> 0x17U)))) 
					 << 0x18U)) 
			  | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U])) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
			     << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[6U] 
					  >> 0x10U))) 
			>> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[7U]) 
	   | (0xfffffc00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
					       >> 0xaU))) 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U]) 
	   | (0xfU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
							       >> 0xfU)))) 
				       << 0x18U)) | 
			(0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
				       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[6U] 
						 >> 0x18U)))) 
		       + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
			   << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[7U] 
					>> 0xaU))) 
		      >> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U]) 
	   | (0x3ffffff0U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[7U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
					       >> 4U))) 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[8U]) 
	   | (0xc0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
					    >> 0x1eU))) 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U]) 
	   | (0xffffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
								    >> 0x1fU)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
					      << 0x18U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[8U] 
						>> 8U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
				<< 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[8U] 
					  >> 0x1eU))) 
			   >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[9U]) 
	   | (0xff000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
				  << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
					    >> 0x18U))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU]) 
	   | (0x3ffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
								   >> 0x17U)))) 
					   << 0x18U)) 
			    | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U])) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
			       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[9U] 
					 >> 0x18U))) 
			  >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xaU]) 
	   | (0xfffc0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
				  << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
					      >> 0x12U))) 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU]) 
	   | (0xfffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
								 >> 0xfU)))) 
					 << 0x18U)) 
			  | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
					   << 8U) | 
					  (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[9U] 
					   >> 0x18U)))) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
			     << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xaU] 
					 >> 0x12U))) 
			>> 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU] 
	= ((0xfffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xbU]) 
	   | (0xfffff000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
				  << 0x14U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
					       >> 0xcU))) 
			     << 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU] 
	= ((0xffffffc0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU]) 
	   | (0x3fU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
								>> 7U)))) 
					<< 0x18U)) 
			 | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
					  << 0x10U) 
					 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xaU] 
					    >> 0x10U)))) 
			+ ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
			    << 0x14U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xbU] 
					 >> 0xcU))) 
		       >> 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU] 
	= ((0x3fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xcU]) 
	   | (0xffffffc0U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xbU] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
				  << 0x1aU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xcU] 
					       >> 6U))) 
			     << 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU] 
	= ((0xfc000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU]) 
	   | (0x3ffffffU & (((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
								    >> 0x17U)))) 
					    << 0x18U)) 
			     | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU])) 
			    + vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU])));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU] 
	= ((0x3ffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xdU]) 
	   | (0xfc000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
				  << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
					    >> 0x1aU))) 
			     << 0x1aU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU] 
	= ((0xfff00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU]) 
	   | (0xfffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
								   >> 0xfU)))) 
					   << 0x18U)) 
			    | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
					     << 8U) 
					    | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xcU] 
					       >> 0x18U)))) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
			       << 6U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xdU] 
					 >> 0x1aU))) 
			  >> 6U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU] 
	= ((0xfffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xeU]) 
	   | (0xfff00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
				  << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
					      >> 0x14U))) 
			     << 0x14U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU] 
	= ((0xffffc000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU]) 
	   | (0x3fffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								  >> 7U)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
					    << 0x10U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xdU] 
					      >> 0x10U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
			      << 0xcU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xeU] 
					  >> 0x14U))) 
			 >> 0xcU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU] 
	= ((0x3fffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0xfU]) 
	   | (0xffffc000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
				  << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
					       >> 0xeU))) 
			     << 0xeU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U] 
	= ((0xffffff00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U]) 
	   | (0xffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							    (1U 
							     & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
								>> 0x1fU)))) 
					<< 0x18U)) 
			 | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
					  << 0x18U) 
					 | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xeU] 
					    >> 8U)))) 
			+ ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
			    << 0x12U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0xfU] 
					 >> 0xeU))) 
		       >> 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U] 
	= ((0xffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x10U]) 
	   | (0xffffff00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
				  << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
					       >> 8U))) 
			     << 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
	= ((0xfffffffcU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U]) 
	   | (3U & ((((0x3000000U & (VL_NEGATE_I((IData)(
							 (1U 
							  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
							     >> 0x17U)))) 
				     << 0x18U)) | (0xffffffU 
						   & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU])) 
		     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
			 << 0x18U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x10U] 
				      >> 8U))) >> 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
	= ((0xf0000003U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U]) 
	   | (0xffffffcU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
								     >> 0xfU)))) 
					     << 0x18U)) 
			      | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
					       << 8U) 
					      | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0xfU] 
						 >> 0x18U)))) 
			     + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
				 << 0x1eU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
					      >> 2U))) 
			    << 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U] 
	= ((0xfffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x11U]) 
	   | (0xf0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
				  << 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
					    >> 0x1cU))) 
			     << 0x1cU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U] 
	= ((0xffc00000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U]) 
	   | (0x3fffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								    >> 7U)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
					      << 0x10U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x10U] 
						>> 0x10U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
				<< 4U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x11U] 
					  >> 0x1cU))) 
			   >> 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U] 
	= ((0x3fffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x12U]) 
	   | (0xffc00000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
				  << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
					      >> 0x16U))) 
			     << 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U] 
	= ((0xffff0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U]) 
	   | (0xffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							      (1U 
							       & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
								  >> 0x1fU)))) 
					  << 0x18U)) 
			   | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
					    << 0x18U) 
					   | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x11U] 
					      >> 8U)))) 
			  + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
			      << 0xaU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x12U] 
					  >> 0x16U))) 
			 >> 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U] 
	= ((0xffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x13U]) 
	   | (0xffff0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
				  << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
					       >> 0x10U))) 
			     << 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U] 
	= ((0xfffffc00U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U]) 
	   | (0x3ffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
								 >> 0x17U)))) 
					 << 0x18U)) 
			  | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U])) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
			     << 0x10U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x13U] 
					  >> 0x10U))) 
			>> 0x10U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U] 
	= ((0x3ffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x14U]) 
	   | (0xfffffc00U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
				  << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
					       >> 0xaU))) 
			     << 0xaU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
	= ((0xfffffff0U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U]) 
	   | (0xfU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
							       >> 0xfU)))) 
				       << 0x18U)) | 
			(0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
				       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x12U] 
						 >> 0x18U)))) 
		       + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
			   << 0x16U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x14U] 
					>> 0xaU))) 
		      >> 0x16U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
	= ((0xc000000fU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U]) 
	   | (0x3ffffff0U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
								      >> 7U)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
						<< 0x10U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x13U] 
						  >> 0x10U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
				  << 0x1cU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
					       >> 4U))) 
			     << 4U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U] 
	= ((0x3fffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x15U]) 
	   | (0xc0000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
								      >> 0x1fU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
						<< 0x18U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
						  >> 8U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
				  << 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
					    >> 0x1eU))) 
			     << 0x1eU)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U] 
	= ((0xff000000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U]) 
	   | (0xffffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
								(1U 
								 & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
								    >> 0x1fU)))) 
					    << 0x18U)) 
			     | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
					      << 0x18U) 
					     | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x14U] 
						>> 8U)))) 
			    + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
				<< 2U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x15U] 
					  >> 0x1eU))) 
			   >> 2U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U] 
	= ((0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x16U]) 
	   | (0xff000000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
								      >> 0x17U)))) 
					      << 0x18U)) 
			       | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U])) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
				  << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
					    >> 0x18U))) 
			     << 0x18U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U] 
	= ((0xfffc0000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U]) 
	   | (0x3ffffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
								   >> 0x17U)))) 
					   << 0x18U)) 
			    | (0xffffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U])) 
			   + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
			       << 8U) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x16U] 
					 >> 0x18U))) 
			  >> 8U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U] 
	= ((0x3ffffU & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x17U]) 
	   | (0xfffc0000U & ((((0x3000000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
								      >> 0xfU)))) 
					      << 0x18U)) 
			       | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
						<< 8U) 
					       | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
						  >> 0x18U)))) 
			      + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x18U] 
				  << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
					      >> 0x12U))) 
			     << 0x12U)));
    vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U] 
	= ((0xfffff000U & vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_sum[0x18U]) 
	   | (0xfffU & ((((0x3000000U & (VL_NEGATE_I((IData)(
							     (1U 
							      & (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
								 >> 0xfU)))) 
					 << 0x18U)) 
			  | (0xffffffU & ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x16U] 
					   << 8U) | 
					  (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_mul[0x15U] 
					   >> 0x18U)))) 
			 + ((vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x18U] 
			     << 0xeU) | (vlTOPp->filt_ppi__DOT__ppi_mul_add__DOT__w_reg[0x17U] 
					 >> 0x12U))) 
			>> 0xeU)));
}

VL_INLINE_OPT void Vdff::_multiclk__TOP__36(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_multiclk__TOP__36\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_data = (0x3ffffffU & ((0x30bU >= (0x3ffU 
						& ((((IData)(0x1aU) 
						     * 
						     ((IData)(1U) 
						      + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
						    - (IData)(1U)) 
						   - (IData)(0x19U))))
				     ? (((0U == (0x1fU 
						 & ((((IData)(0x1aU) 
						      * 
						      ((IData)(1U) 
						       + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
						     - (IData)(1U)) 
						    - (IData)(0x19U))))
					  ? 0U : (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[
						  ((IData)(1U) 
						   + 
						   (0x1fU 
						    & (((((IData)(0x1aU) 
							  * 
							  ((IData)(1U) 
							   + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
							 - (IData)(1U)) 
							- (IData)(0x19U)) 
						       >> 5U)))] 
						  << 
						  ((IData)(0x20U) 
						   - 
						   (0x1fU 
						    & ((((IData)(0x1aU) 
							 * 
							 ((IData)(1U) 
							  + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
							- (IData)(1U)) 
						       - (IData)(0x19U)))))) 
					| (vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__w_data[
					   (0x1fU & 
					    (((((IData)(0x1aU) 
						* ((IData)(1U) 
						   + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
					       - (IData)(1U)) 
					      - (IData)(0x19U)) 
					     >> 5U))] 
					   >> (0x1fU 
					       & ((((IData)(0x1aU) 
						    * 
						    ((IData)(1U) 
						     + (IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT__r_idx))) 
						   - (IData)(1U)) 
						  - (IData)(0x19U)))))
				     : 0U));
}

void Vdff::_eval(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_eval\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->i_fclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_fclk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__14(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__15(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__16(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__17(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__18(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__19(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__20(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__21(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__22(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__23(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__24(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__25(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__26(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__27(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__28(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__29(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__30(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__31(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__32(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__33(vlSymsp);
    }
    if ((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_sequent__TOP__34(vlSymsp);
    }
    vlTOPp->_combo__TOP__35(vlSymsp);
    if ((((((((((((((((((((((((((((((((((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
					& (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk))) 
				       | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
					  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
				      | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
					 & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
				     | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
					& (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
				    | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				       & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
				   | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				      & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
				  | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				     & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
				 | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				    & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
				| ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				   & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			       | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			      | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				 & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			     | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
				& (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			    | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			       & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			   | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			      & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			  | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			     & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			 | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			    & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
			| ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			   & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		       | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		      | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			 & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		     | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
			& (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		    | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		       & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		   | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		      & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		  | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		     & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		 | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		    & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
		| ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		   & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
	       | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		  & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
	      | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		 & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
	     | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
		& (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
	    | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	       & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
	   | ((IData)(vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk) 
	      & (~ (IData)(vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk)))) 
	  | ((IData)(vlTOPp->i_fclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_fclk)))) 
	 | ((~ (IData)(vlTOPp->i_rst_an)) & (IData)(vlTOPp->__Vclklast__TOP__i_rst_an)))) {
	vlTOPp->_multiclk__TOP__36(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_fclk = vlTOPp->i_fclk;
    vlTOPp->__Vclklast__TOP__i_rst_an = vlTOPp->i_rst_an;
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
}

void Vdff::_eval_initial(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_eval_initial\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_fclk = vlTOPp->i_fclk;
    vlTOPp->__Vclklast__TOP__i_rst_an = vlTOPp->i_rst_an;
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
    vlTOPp->__Vclklast__TOP__filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk 
	= vlTOPp->filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk;
}

void Vdff::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::final\n"); );
    // Variables
    Vdff__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdff::_eval_settle(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_eval_settle\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vdff::_change_request(Vdff__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_change_request\n"); );
    Vdff* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdff::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_rst_an & 0xfeU))) {
	Verilated::overWidthError("i_rst_an");}
    if (VL_UNLIKELY((i_ena & 0xfeU))) {
	Verilated::overWidthError("i_ena");}
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
	Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_fclk & 0xfeU))) {
	Verilated::overWidthError("i_fclk");}
}
#endif // VL_DEBUG

void Vdff::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff::_ctor_var_reset\n"); );
    // Body
    i_rst_an = VL_RAND_RESET_I(1);
    i_ena = VL_RAND_RESET_I(1);
    i_clk = VL_RAND_RESET_I(1);
    i_fclk = VL_RAND_RESET_I(1);
    i_data = VL_RAND_RESET_I(8);
    o_data = VL_RAND_RESET_I(26);
    o_sclk = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<27; ++__Vi0) {
	    filt_ppi__DOT__ppi_mul_add__DOT__c_coeff[__Vi0] = VL_RAND_RESET_I(16);
    }}
    VL_RAND_RESET_W(1440,filt_ppi__DOT__ppi_mul_add__DOT__w_mul);
    VL_RAND_RESET_W(1560,filt_ppi__DOT__ppi_mul_add__DOT__w_sum);
    VL_RAND_RESET_W(780,filt_ppi__DOT__ppi_mul_add__DOT__w_reg);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__30__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__31__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__32__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__33__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__34__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__35__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__36__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__37__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__38__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__39__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__40__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__41__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__42__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__43__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__44__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__45__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__46__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__47__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__48__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__49__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__50__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__51__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__52__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__53__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__54__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__55__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__56__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__57__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__58__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_mul_add__DOT__g_tf_ppi__DOT__g_tf_reg__BRA__59__KET____DOT__g_ccw__DOT__TF_DFF__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__r_ring_cnt = VL_RAND_RESET_I(30);
    filt_ppi__DOT__ppi_commutator__DOT__r_idx = VL_RAND_RESET_I(5);
    filt_ppi__DOT__ppi_commutator__DOT__r_done = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(780,filt_ppi__DOT__ppi_commutator__DOT__w_data);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT____Vcellinp__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__i_clk = VL_RAND_RESET_I(1);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__0__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__1__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__2__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__3__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__4__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__5__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__6__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__7__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__8__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__9__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__10__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__11__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__12__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__13__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__14__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__15__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__16__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__17__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__18__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__19__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__20__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__21__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__22__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__23__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__24__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__25__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__26__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__27__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__28__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
    filt_ppi__DOT__ppi_commutator__DOT__g_commutator_ccw__DOT__g_reg_comm_inp__BRA__29__KET____DOT__REG_COMMUTATOR_INP_DATA__DOT__r_data = VL_RAND_RESET_I(26);
}
