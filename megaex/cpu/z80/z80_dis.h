/*
 *  z80_dis.h

Copyright (c) 2011 Lee Hammerton

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

 */

#include "mytypes.h"

extern char mnemonicData[256];

U16 Z80_DIS_UNKNOWN(U32 adr,U16* operands);

U16 Z80_DIS_CB_TABLE(U32 adr,U16* operands);
U16 Z80_DIS_DD_TABLE(U32 adr,U16* operands);
U16 Z80_DIS_ED_TABLE(U32 adr,U16* operands);
U16 Z80_DIS_FD_TABLE(U32 adr,U16* operands);

U16 Z80_DIS_CB_BITm(U32 adr,U16* operands);
U16 Z80_DIS_CB_SLA(U32 adr,U16* operands);
U16 Z80_DIS_CB_BIT(U32 adr,U16* operands);
U16 Z80_DIS_CB_SRL(U32 adr,U16* operands);
U16 Z80_DIS_CB_SETm(U32 adr,U16* operands);
U16 Z80_DIS_CB_RESm(U32 adr,U16* operands);
U16 Z80_DIS_CB_RLC(U32 adr,U16* operands);
U16 Z80_DIS_CB_RES(U32 adr,U16* operands);
U16 Z80_DIS_CB_SET(U32 adr,U16* operands);
U16 Z80_DIS_CB_RL(U32 adr,U16* operands);
U16 Z80_DIS_CB_RRC(U32 adr,U16* operands);
U16 Z80_DIS_CB_RR(U32 adr,U16* operands);
U16 Z80_DIS_CB_RLm(U32 adr,U16* operands);
U16 Z80_DIS_CB_SRA(U32 adr,U16* operands);
U16 Z80_DIS_CB_RLCm(U32 adr,U16* operands);
U16 Z80_DIS_CB_RRm(U32 adr,U16* operands);
U16 Z80_DIS_CB_SLAm(U32 adr,U16* operands);
U16 Z80_DIS_CB_RRCm(U32 adr,U16* operands);
U16 Z80_DIS_CB_SRLm(U32 adr,U16* operands);

U16 Z80_DIS_ED_IM(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDIR(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDI_A(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDR_A(U32 adr,U16* operands);
U16 Z80_DIS_ED_SBCHL(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDnn_dd(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDDR(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDdd_nn(U32 adr,U16* operands);
U16 Z80_DIS_ED_INr_C(U32 adr,U16* operands);
U16 Z80_DIS_ED_ADCHL(U32 adr,U16* operands);
U16 Z80_DIS_ED_NEG(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDI(U32 adr,U16* operands);
U16 Z80_DIS_ED_RLD(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDA_R(U32 adr,U16* operands);
U16 Z80_DIS_ED_CPIR(U32 adr,U16* operands);
U16 Z80_DIS_ED_OUTC_r(U32 adr,U16* operands);
U16 Z80_DIS_ED_RETI(U32 adr,U16* operands);
U16 Z80_DIS_ED_OUTD(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDA_I(U32 adr,U16* operands);
U16 Z80_DIS_ED_LDD(U32 adr,U16* operands);
U16 Z80_DIS_ED_OTDR(U32 adr,U16* operands);
U16 Z80_DIS_ED_INI(U32 adr,U16* operands);
U16 Z80_DIS_ED_RRD(U32 adr,U16* operands);
U16 Z80_DIS_ED_OUTI(U32 adr,U16* operands);
U16 Z80_DIS_ED_OTIR(U32 adr,U16* operands);
U16 Z80_DIS_ED_CPI(U32 adr,U16* operands);
U16 Z80_DIS_ED_RETN(U32 adr,U16* operands);

U16 Z80_DIS_DI(U32 adr,U16* operands);
U16 Z80_DIS_LDRP(U32 adr,U16* operands);
U16 Z80_DIS_JP(U32 adr,U16* operands);
U16 Z80_DIS_CALL(U32 adr,U16* operands);
U16 Z80_DIS_LDn(U32 adr,U16* operands);
U16 Z80_DIS_XOR(U32 adr,U16* operands);
U16 Z80_DIS_JPcc(U32 adr,U16* operands);
U16 Z80_DIS_LDm(U32 adr,U16* operands);
U16 Z80_DIS_LD_nn_A(U32 adr,U16* operands);
U16 Z80_DIS_RET(U32 adr,U16* operands);
U16 Z80_DIS_INC(U32 adr,U16* operands);
U16 Z80_DIS_LDA_nn(U32 adr,U16* operands);
U16 Z80_DIS_OR(U32 adr,U16* operands);
U16 Z80_DIS_LDrr(U32 adr,U16* operands);
U16 Z80_DIS_DEC(U32 adr,U16* operands);
U16 Z80_DIS_RLCA(U32 adr,U16* operands);
U16 Z80_DIS_RRCA(U32 adr,U16* operands);
U16 Z80_DIS_ORA_n(U32 adr,U16* operands);
U16 Z80_DIS_LD_HL(U32 adr,U16* operands);
U16 Z80_DIS_ADDA_n(U32 adr,U16* operands);
U16 Z80_DIS_ADCA_n(U32 adr,U16* operands);
U16 Z80_DIS_INCRP(U32 adr,U16* operands);
U16 Z80_DIS_DECRP(U32 adr,U16* operands);
U16 Z80_DIS_NOP(U32 adr,U16* operands);
U16 Z80_DIS_LDSP_HL(U32 adr,U16* operands);
U16 Z80_DIS_POPIX(U32 adr,U16* operands);
U16 Z80_DIS_POPIY(U32 adr,U16* operands);
U16 Z80_DIS_POPRP(U32 adr,U16* operands);
U16 Z80_DIS_EXAF(U32 adr,U16* operands);
U16 Z80_DIS_EXX(U32 adr,U16* operands);
U16 Z80_DIS_LDHL_n(U32 adr,U16* operands);
U16 Z80_DIS_JPHL(U32 adr,U16* operands);
U16 Z80_DIS_CP(U32 adr,U16* operands);
U16 Z80_DIS_RRA(U32 adr,U16* operands);
U16 Z80_DIS_RLA(U32 adr,U16* operands);
U16 Z80_DIS_ANDA_n(U32 adr,U16* operands);
U16 Z80_DIS_ADDHL(U32 adr,U16* operands);
U16 Z80_DIS_DJNZ(U32 adr,U16* operands);
U16 Z80_DIS_CPHL(U32 adr,U16* operands);
U16 Z80_DIS_INCHL(U32 adr,U16* operands);
U16 Z80_DIS_JR(U32 adr,U16* operands);
U16 Z80_DIS_SUBA_n(U32 adr,U16* operands);
U16 Z80_DIS_CP_n(U32 adr,U16* operands);
U16 Z80_DIS_JRcc(U32 adr,U16* operands);
U16 Z80_DIS_PUSHRP(U32 adr,U16* operands);
U16 Z80_DIS_LDA_DE(U32 adr,U16* operands);
U16 Z80_DIS_EI(U32 adr,U16* operands);
U16 Z80_DIS_LDIX_nn(U32 adr,U16* operands);
U16 Z80_DIS_LDIX_d_r(U32 adr,U16* operands);
U16 Z80_DIS_LDIY_nn(U32 adr,U16* operands);
U16 Z80_DIS_ADDIY(U32 adr,U16* operands);
U16 Z80_DIS_LDr_IY_d(U32 adr,U16* operands);
U16 Z80_DIS_LDIX_d_n(U32 adr,U16* operands);
U16 Z80_DIS_ADDA_r(U32 adr,U16* operands);
U16 Z80_DIS_RST(U32 adr,U16* operands);
U16 Z80_DIS_LDDE_A(U32 adr,U16* operands);
U16 Z80_DIS_OUTn_A(U32 adr,U16* operands);
U16 Z80_DIS_AND(U32 adr,U16* operands);
U16 Z80_DIS_DECHL(U32 adr,U16* operands);
U16 Z80_DIS_LDnn_HL(U32 adr,U16* operands);
U16 Z80_DIS_EXDE_HL(U32 adr,U16* operands);
U16 Z80_DIS_LDHL_nn(U32 adr,U16* operands);
U16 Z80_DIS_SUBA_r(U32 adr,U16* operands);
U16 Z80_DIS_RETcc(U32 adr,U16* operands);
U16 Z80_DIS_SCF(U32 adr,U16* operands);
U16 Z80_DIS_XORm(U32 adr,U16* operands);
U16 Z80_DIS_CCF(U32 adr,U16* operands);
U16 Z80_DIS_ADDm(U32 adr,U16* operands);
U16 Z80_DIS_EXSP_HL(U32 adr,U16* operands);
U16 Z80_DIS_ADCA_r(U32 adr,U16* operands);
U16 Z80_DIS_CPL(U32 adr,U16* operands);
U16 Z80_DIS_XORA_n(U32 adr,U16* operands);
U16 Z80_DIS_HALT(U32 adr,U16* operands);
U16 Z80_DIS_CALLcc(U32 adr,U16* operands);
U16 Z80_DIS_SBCA_r(U32 adr,U16* operands);
U16 Z80_DIS_SUBm(U32 adr,U16* operands);
U16 Z80_DIS_INA_n(U32 adr,U16* operands);
U16 Z80_DIS_ANDm(U32 adr,U16* operands);
U16 Z80_DIS_ORm(U32 adr,U16* operands);
U16 Z80_DIS_ADCm(U32 adr,U16* operands);
U16 Z80_DIS_LDBC_A(U32 adr,U16* operands);
U16 Z80_DIS_DAA(U32 adr,U16* operands);
U16 Z80_DIS_LDA_BC(U32 adr,U16* operands);
U16 Z80_DIS_SBCA_n(U32 adr,U16* operands);
U16 Z80_DIS_SBCm(U32 adr,U16* operands);
