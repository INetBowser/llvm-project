//===-- XtensaSubtarget.h - Define Subtarget for the Xtensa ----*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the Xtensa specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSASUBTARGET_H
#define LLVM_LIB_TARGET_XTENSA_XTENSASUBTARGET_H

#include "XtensaFrameLowering.h"
#include "XtensaISelLowering.h"
#include "XtensaInstrInfo.h"
#include "XtensaRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAGTargetInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"

#define GET_SUBTARGETINFO_HEADER
#include "XtensaGenSubtargetInfo.inc"

namespace llvm {
class StringRef;

class XtensaSubtarget : public XtensaGenSubtargetInfo {
private:
  Triple TargetTriple;
  XtensaInstrInfo InstrInfo;
  XtensaTargetLowering TLInfo;
  SelectionDAGTargetInfo TSInfo;
  XtensaFrameLowering FrameLowering;

  // Enabled Xtensa Density extension
  bool HasDensity;

  // Enabled Xtensa Single FP instructions
  bool HasSingleFloat;

  // Enabled Xtensa Windowed Register option
  bool HasWindowed;

  // Enabled Xtensa Boolean extension
  bool HasBoolean;

  // Enabled Xtensa Loop extension
  bool HasLoop;

  // Enable Xtensa Sign Extend option
  bool HasSEXT;

  // Enable Xtensa NSA option
  bool HasNSA;

  XtensaSubtarget &initializeSubtargetDependencies(StringRef CPU, StringRef FS);

public:
  XtensaSubtarget(const Triple &TT, const std::string &CPU,
                  const std::string &FS, const TargetMachine &TM);

  const TargetFrameLowering *getFrameLowering() const { return &FrameLowering; }
  const XtensaInstrInfo *getInstrInfo() const { return &InstrInfo; }
  const XtensaRegisterInfo *getRegisterInfo() const {
    return &InstrInfo.getRegisterInfo();
  }

  const XtensaTargetLowering *getTargetLowering() const { return &TLInfo; }
  const SelectionDAGTargetInfo *getSelectionDAGInfo() const { return &TSInfo; }

  bool isWinABI() const { return hasWindowed(); }

  bool hasDensity() const { return HasDensity; }

  bool hasSingleFloat() const { return HasSingleFloat; }

  bool hasWindowed() const { return HasWindowed; }

  bool hasBoolean() const { return HasBoolean; }

  bool hasLoop() const { return HasLoop; }

  bool hasSEXT() const { return HasSEXT; }

  bool hasNSA() const { return HasNSA; }

  // Automatically generated by tblgen.
  void ParseSubtargetFeatures(StringRef CPU, StringRef FS);
};
} // end namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_XTENSASUBTARGET_H */
