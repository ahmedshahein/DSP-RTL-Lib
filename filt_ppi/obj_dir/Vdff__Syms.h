// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vdff__Syms_H_
#define _Vdff__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vdff.h"

// SYMS CLASS
class Vdff__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vdff*                          TOPp;
    
    // CREATORS
    Vdff__Syms(Vdff* topp, const char* namep);
    ~Vdff__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
