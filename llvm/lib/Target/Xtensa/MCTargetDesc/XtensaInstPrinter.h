//===- XtensaInstPrinter.h - Convert Xtensa MCInst to asm syntax -*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints an Xtensa MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_MCTARGETDESC_XTENSAINSTPRINTER_H
#define LLVM_LIB_TARGET_XTENSA_MCTARGETDESC_XTENSAINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include "llvm/Support/Compiler.h"

namespace llvm {
class MCOperand;

class XtensaInstPrinter : public MCInstPrinter {
public:
  XtensaInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                    const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  // Automatically generated by tblgen.
  void printInstruction(const MCInst *MI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  // Print the given operand.
  static void printOperand(const MCOperand &MO, raw_ostream &O);

  // Override MCInstPrinter.
  void printRegName(raw_ostream &O, unsigned RegNo) const override;
  void printInst(const MCInst *MI, raw_ostream &O, StringRef Annot,
                 const MCSubtargetInfo &STI) override;

private:
  // Print various types of operand.
  void printOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printMemOperand(const MCInst *MI, int OpNUm, raw_ostream &O);
  void printBranchTarget(const MCInst *MI, int OpNum, raw_ostream &O);
  void printJumpTarget(const MCInst *MI, int OpNum, raw_ostream &O);
  void printCallOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printL32RTarget(const MCInst *MI, int OpNum, raw_ostream &O);

  void printImm8_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm8_sh8_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm12_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm12m_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printUimm4_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printUimm5_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printShimm1_31_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm1_16_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm1n_15_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printImm32n_95_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset8m8_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset8m16_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset8m32_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printOffset4m32_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printEntry_Imm12_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printB4const_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printB4constu_AsmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
};
} // end namespace llvm

#endif /* LLVM_LIB_TARGET_XTENSA_MCTARGETDESC_XTENSAINSTPRINTER_H */
