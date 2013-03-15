/*
 * Copyright (c) 2013 rms. <rms@velocitylimitless.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "hyperx86.h" 

__BEGIN_DECLS

opcode_control_table_t control_table_1[] = {
    {x86_add_op,   format_group_1_general},     // 0x00 - add Eb,Gb
    {x86_add_op,   format_group_1_general},     // 0x01 - add Ev,Gv
    {x86_add_op,   format_group_1_general},     // 0x02 - add Gb,Eb
    {x86_add_op,   format_group_1_general},     // 0x03 - add Gv,Ev
    {x86_add_op,   format_accum_immediate},     // 0x04 - add AL,Ib
    {x86_add_op,   format_accum_immediate},     // 0x05 - add eAX,Iv
    {x86_push_op,  format_seg_es},              // 0x06 - push ES
    {x86_pop_op,   format_seg_es},              // 0x07 - pop  ES
    {x86_or_op,    format_group_1_general},     // 0x08 - or Eb,Gb
    {x86_or_op,    format_group_1_general},     // 0x09 - or Ev,Gv
    {x86_or_op,    format_group_1_general},     // 0x0a - or Gb,Eb
    {x86_or_op,    format_group_1_general},     // 0x0b - or Gv,Ev
    {x86_or_op,    format_accum_immediate},     // 0x0c - or AL,Ib
    {x86_or_op,    format_accum_immediate},     // 0x0d - or eAX,Iv
    {x86_push_op,  format_seg_cs},              // 0x0e - push CS
    {0,            format_opcode_escape},       // 0x0f - escape:
    {x86_adc_op,   format_group_1_general},     // 0x10 - adc Eb,Gb
    {x86_adc_op,   format_group_1_general},     // 0x11 - adc Ev,Gv
    {x86_adc_op,   format_group_1_general},     // 0x12 - adc Gb,Eb
    {x86_adc_op,   format_group_1_general},     // 0x13 - adc Gv,Ev
    {x86_adc_op,   format_accum_immediate},     // 0x14 - adc AL,Ib
    {x86_adc_op,   format_accum_immediate},     // 0x15 - adc eAX,Iv
    {x86_push_op,  format_seg_ss},              // 0x16 - push SS
    {x86_pop_op,   format_seg_ss},              // 0x17 - pop  SS
    {x86_sbb_op,   format_group_1_general},     // 0x18 - sbb Eb,Gb
    {x86_sbb_op,   format_group_1_general},     // 0x19 - sbb Ev,Gv
    {x86_sbb_op,   format_group_1_general},     // 0x1a - sbb Gb,Eb
    {x86_sbb_op,   format_group_1_general},     // 0x1b - sbb Gv,Ev
    {x86_sbb_op,   format_accum_immediate},     // 0x1c - sbb AL,Ib
    {x86_sbb_op,   format_accum_immediate},     // 0x1d - sbb eAX,Iv
    {x86_push_op,  format_seg_ds},              // 0x1e - push DS
    {x86_pop_op,   format_seg_ds},              // 0x1f - pop  DS
    {x86_and_op,   format_group_1_general},     // 0x20 - and Eb,Gb
    {x86_and_op,   format_group_1_general},     // 0x21 - and Ev,Gv
    {x86_and_op,   format_group_1_general},     // 0x22 - and Gb,Eb
    {x86_and_op,   format_group_1_general},     // 0x23 - and Gv,Ev
    {x86_and_op,   format_accum_immediate},     // 0x24 - and AL,Ib
    {x86_and_op,   format_accum_immediate},     // 0x25 - and eAX,Iv
    {x86_es_op,    format_prefix_opcode},       // 0x26 - ES:
    {x86_daa_op,   format_no_operands},         // 0x27 - daa
    {x86_sub_op,   format_group_1_general},     // 0x28 - sub Eb,Gb
    {x86_sub_op,   format_group_1_general},     // 0x29 - sub Ev,Gv
    {x86_sub_op,   format_group_1_general},     // 0x2a - sub Gb,Eb
    {x86_sub_op,   format_group_1_general},     // 0x2b - sub Gv,Ev
    {x86_sub_op,   format_accum_immediate},     // 0x2c - sub AL,Ib
    {x86_sub_op,   format_accum_immediate},     // 0x2d - sub eAX,Iv
    {x86_cs_op,    format_prefix_opcode},       // 0x2e - CS:
    {x86_das_op,   format_no_operands},         // 0x2f - das
    {x86_xor_op,   format_group_1_general},     // 0x30 - xor Eb,Gb
    {x86_xor_op,   format_group_1_general},     // 0x31 - xor Ev,Gv
    {x86_xor_op,   format_group_1_general},     // 0x32 - xor Gb,Eb
    {x86_xor_op,   format_group_1_general},     // 0x33 - xor Gv,Ev
    {x86_xor_op,   format_accum_immediate},     // 0x34 - xor AL,Ib
    {x86_xor_op,   format_accum_immediate},     // 0x35 - xor eAX,Iv
    {x86_ss_op,    format_prefix_opcode},       // 0x36 - SS:
    {x86_aaa_op,   format_no_operands},         // 0x37 - aaa
    {x86_cmp_op,   format_group_1_general},     // 0x38 - cmp Eb,Gb
    {x86_cmp_op,   format_group_1_general},     // 0x39 - cmp Ev,Gv
    {x86_cmp_op,   format_group_1_general},     // 0x3a - cmp Gb,Eb
    {x86_cmp_op,   format_group_1_general},     // 0x3b - cmp Gv,Ev
    {x86_cmp_op,   format_accum_immediate},     // 0x3c - cmp AL,Ib
    {x86_cmp_op,   format_accum_immediate},     // 0x3d - cmp eAX,Iv
    {x86_ds_op,    format_prefix_opcode},       // 0x3e - DS:
    {x86_aas_op,   format_no_operands},         // 0x3f - aas
    {x86_inc_op,   format_opcode_register},     // 0x40 - inc eAX
    {x86_inc_op,   format_opcode_register},     // 0x41 - inc eCX
    {x86_inc_op,   format_opcode_register},     // 0x42 - inc eDX
    {x86_inc_op,   format_opcode_register},     // 0x43 - inc eBX
    {x86_inc_op,   format_opcode_register},     // 0x44 - inc eSP
    {x86_inc_op,   format_opcode_register},     // 0x45 - inc eBP
    {x86_inc_op,   format_opcode_register},     // 0x46 - inc eSI
    {x86_inc_op,   format_opcode_register},     // 0x47 - inc eDI
    {x86_dec_op,   format_opcode_register},     // 0x48 - dec eAX
    {x86_dec_op,   format_opcode_register},     // 0x49 - dec eCX
    {x86_dec_op,   format_opcode_register},     // 0x4a - dec eDX
    {x86_dec_op,   format_opcode_register},     // 0x4b - dec eBX
    {x86_dec_op,   format_opcode_register},     // 0x4c - dec eSP
    {x86_dec_op,   format_opcode_register},     // 0x4d - dec eBP
    {x86_dec_op,   format_opcode_register},     // 0x4e - dec eSI
    {x86_dec_op,   format_opcode_register},     // 0x4f - dec eDI
    {x86_push_op,  format_opcode_register},     // 0x50 - push eAX
    {x86_push_op,  format_opcode_register},     // 0x51 - push eCX
    {x86_push_op,  format_opcode_register},     // 0x52 - push eDX
    {x86_push_op,  format_opcode_register},     // 0x53 - push eBX
    {x86_push_op,  format_opcode_register},     // 0x54 - push eSP
    {x86_push_op,  format_opcode_register},     // 0x55 - push eBP
    {x86_push_op,  format_opcode_register},     // 0x56 - push eSI
    {x86_push_op,  format_opcode_register},     // 0x57 - push eDI
    {x86_pop_op,   format_opcode_register},     // 0x58 - pop eAX
    {x86_pop_op,   format_opcode_register},     // 0x59 - pop eCX
    {x86_pop_op,   format_opcode_register},     // 0x5a - pop eDX
    {x86_pop_op,   format_opcode_register},     // 0x5b - pop eBX
    {x86_pop_op,   format_opcode_register},     // 0x5c - pop eSP
    {x86_pop_op,   format_opcode_register},     // 0x5d - pop eBP
    {x86_pop_op,   format_opcode_register},     // 0x5e - pop eSI
    {x86_pop_op,   format_opcode_register},     // 0x5f - pop eDI
    {x86_pusha_op, format_no_operands},         // 0x60 - pusha
    {x86_popa_op,  format_no_operands},         // 0x61 - popa
    {x86_bound_op, format_effective_offset},    // 0x62 - bound Gv,Ma
    {x86_ill_op,   format_no_operands},         // 0x63 - arpl Ew,Rw
    {x86_fs_op,    format_prefix_opcode},       // 0x64 - FS:
    {x86_gs_op,    format_prefix_opcode},       // 0x65 - GS:
    {x86_opsz_op,  format_prefix_opcode},       // 0x66 - opsize
    {x86_adsz_op,  format_prefix_opcode},       // 0x67 - opaddr
    {x86_push_op,  format_push_immediate},      // 0x68 - push iv
    {x86_imul_op,  format_imul_immediate},      // 0x69 - imul
    {x86_push_op,  format_push_immediate},      // 0x6a - push ib
    {x86_imul_op,  format_imul_immediate},      // 0x6b - imul
    {x86_ins_op,   format_port_dx},             // 0x6c - insb
    {x86_ins_op,   format_port_dx},             // 0x6d - insw/d
    {x86_outs_op,  format_port_dx},             // 0x6e - outsb
    {x86_outs_op,  format_port_dx},             // 0x6f - outsw/d
    {x86_jxx_op,   format_short_jump},          // 0x70 - jo   jb
    {x86_jxx_op,   format_short_jump},          // 0x71 - jno  jb
    {x86_jxx_op,   format_short_jump},          // 0x72 - jb   jb
    {x86_jxx_op,   format_short_jump},          // 0x73 - jnb  jb
    {x86_jxx_op,   format_short_jump},          // 0x74 - jz   jb
    {x86_jxx_op,   format_short_jump},          // 0x75 - jnz  jb
    {x86_jxx_op,   format_short_jump},          // 0x76 - jbe  jb
    {x86_jxx_op,   format_short_jump},          // 0x77 - jnbe jb
    {x86_jxx_op,   format_short_jump},          // 0x78 - js   jb
    {x86_jxx_op,   format_short_jump},          // 0x79 - jns  jb
    {x86_jxx_op,   format_short_jump},          // 0x7a - jp   jb
    {x86_jxx_op,   format_short_jump},          // 0x7b - jnp  jb
    {x86_jxx_op,   format_short_jump},          // 0x7c - jl   jb
    {x86_jxx_op,   format_short_jump},          // 0x7d - jnl  jb
    {x86_jxx_op,   format_short_jump},          // 0x7e - jle  jb
    {x86_jxx_op,   format_short_jump},          // 0x7f - jnle jb
    {x86_add_op,   format_group_1_immediate},   // 0x80 - group1 Eb,Ib
    {x86_add_op,   format_group_1_immediate},   // 0x81 - group1 Ev,Iv
    {x86_ill_op,   format_no_operands},         // 0x82 - illegal
    {x86_add_op,   format_group_1_immediate},   // 0x83 - group1 Ev,Ib
    {x86_test_op,  format_group_1_general},     // 0x84 - test Eb,Gb
    {x86_test_op,  format_group_1_general},     // 0x85 - test Ev,Gv
    {x86_xchg_op,  format_group_1_general},     // 0x86 - xchg Eb,Gb
    {x86_xchg_op,  format_group_1_general},     // 0x87 = xchg Ev,Gv
    {x86_mov_op,   format_move_general},        // 0x88 - mov Eb,Gb
    {x86_mov_op,   format_move_general},        // 0x89 - mov Ev,Gv
    {x86_mov_op,   format_move_general},        // 0x8a - mov Gb,Eb
    {x86_mov_op,   format_move_general},        // 0x8b - mov Gv,Ev
    {x86_mov_op,   format_move_segment},        // 0x8c - mov Ew,Sw
    {x86_lea_op,   format_effective_offset},    // 0x8d - lea Gv,Ma
    {x86_mov_op,   format_move_segment},        // 0x8e - mov Sw,Ew
    {x86_pop_op,   format_pop_general},         // 0x8f - pop Ev
    {x86_nop_op,   format_no_operands},         // 0x90 - nop
    {x86_xchg_op,  format_accum_register},      // 0x91 - xchg eCX,eAX
    {x86_xchg_op,  format_accum_register},      // 0x92 - xchg eDX,eAX
    {x86_xchg_op,  format_accum_register},      // 0x93 - xchg eBX,eAX
    {x86_xchg_op,  format_accum_register},      // 0x94 - xchg eSP,eAX
    {x86_xchg_op,  format_accum_register},      // 0x95 - xchg eBP,eAX
    {x86_xchg_op,  format_accum_register},      // 0x96 - xchg eSI,eAX
    {x86_xchg_op,  format_accum_register},      // 0x97 - xchg eDI,eAX
    {x86_cbw_op,   format_no_operands},         // 0x98 - cbw
    {x86_cwd_op,   format_no_operands},         // 0x99 - cwd
    {x86_call_op,  format_immediate_jump},      // 0x9a - call Ap
    {x86_nop_op,   format_no_operands},         // 0x9b - wait
    {x86_push_op,  format_flags_register},      // 0x9c - pushf
    {x86_pop_op,   format_flags_register},      // 0x9d - popf
    {x86_sahf_op,  format_no_operands},         // 0x9e - sahf
    {x86_sahf_op,  format_no_operands},         // 0x9f - lahf
    {x86_mov_op,   format_segment_offset},      // 0xa0 - mov AL,Ob
    {x86_mov_op,   format_segment_offset},      // 0xa1 - mov eAX,Ov
    {x86_mov_op,   format_segment_offset},      // 0xa2 - mov Ob,AL
    {x86_mov_op,   format_segment_offset},      // 0xa3 - mov Ov,eAX
    {x86_movs_op,  format_string_operands},     // 0xa4 - movsb
    {x86_movs_op,  format_string_operands},     // 0xa5 - movsw/d
    {x86_cmps_op,  format_string_operands},     // 0xa6 - cmpsb
    {x86_cmps_op,  format_string_operands},     // 0xa7 - cmpsw/d
    {x86_test_op,  format_accum_immediate},     // 0xa8 - test AL,Ib
    {x86_test_op,  format_accum_immediate},     // 0xa9 - test eAX,Iv
    {x86_stos_op,  format_string_operands},     // 0xaa - stosb
    {x86_stos_op,  format_string_operands},     // 0xab - stosw/d
    {x86_lods_op,  format_string_operands},     // 0xac - lodsb
    {x86_lods_op,  format_string_operands},     // 0xad - lodsw.d
    {x86_scas_op,  format_string_operands},     // 0xae - scasb
    {x86_scas_op,  format_string_operands},     // 0xaf - scasw/d
    {x86_mov_op,   format_move_reg_immediate},  // 0xb0 mov AL,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb1 mov Cl,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb2 mov DL,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb3 mov BL,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb4 mov AH,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb5 mov CH,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb6 mov DH,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb7 mov BH,Ib
    {x86_mov_op,   format_move_reg_immediate},  // 0xb8 mov eAX,Iv
    {x86_mov_op,   format_move_reg_immediate},  // 0xb9 mov eCX,Iv
    {x86_mov_op,   format_move_reg_immediate},  // 0xba mov eDX,Iv
    {x86_mov_op,   format_move_reg_immediate},  // 0xbb mov eBX,Iv
    {x86_mov_op,   format_move_reg_immediate},  // 0xbc mov eSP,Iv
    {x86_mov_op,   format_move_reg_immediate},  // 0xbd mov eBP,Iv
    {x86_mov_op,   format_move_reg_immediate},  // 0xbe mov eSI,Iv
    {x86_mov_op,   format_move_reg_immediate},  // 0xbf mov eDI,Iv
    {x86_rol_op,   format_group_2_by_byte},     // 0xc0 - group2 Eb,Ib
    {x86_rol_op,   format_group_2_by_byte},     // 0xc1 - group2 Ev,Ib
    {x86_ret_op,   format_no_operands},         // 0xc2 - ret Iw (near)
    {x86_ret_op,   format_no_operands},         // 0xc3 - ret (near)
    {x86_mov_op,   format_seg_load_es},         // 0xc4 - les Gv,Mp
    {x86_mov_op,   format_seg_load_ds},         // 0xc5 - lds Gv,Mp
    {x86_mov_op,   format_move_immediate},     // 0xc6 - mov Eb,Ib
    {x86_mov_op,   format_move_immediate},     // 0xc7 - mov Ev,Iv
    {x86_enter_op, format_immediate_enter},    // 0xc8 - enter Iw,Ib
    {x86_leave_op, format_no_operands},        // 0xc9 - leave
    {x86_ret_op,   format_no_operands},        // 0xca - ret Iw (far)
    {x86_ret_op,   format_no_operands},        // 0xcb - ret (far)
    {x86_int_op,   format_no_operands},        // 0xcc - int 3
    {x86_int_op,   format_byte_immediate},     // 0xcd - int Ib
    {x86_int_op,   format_no_operands},        // 0xce - into
    {x86_iret_op,  format_no_operands},        // 0xcf - iret
    {x86_rol_op,   format_group_2_by_1},       // 0xd0 - group2 Eb,1
    {x86_rol_op,   format_group_2_by_1},       // 0xd1 - group2 Ev,1
    {x86_rol_op,   format_group_2_by_cl},      // 0xd2 - group2 Eb,CL
    {x86_rol_op,   format_group_2_by_cl},      // 0xd3 - group2 Ev,CL
    {x86_aam_op,   format_byte_immediate},     // 0xd4 - aam
    {x86_aad_op,   format_byte_immediate},     // 0xd5 - aad
    {x86_ill_op,   format_no_operands},        // 0xd6 - illegal
    {x86_mov_op,   format_xlat_opcode},        // 0xd7 - xlat
    {x86_ill_op,   format_no_operands},        // 0xd8 - esc0
    {x86_ill_op,   format_no_operands},        // 0xd9 - esc1
    {x86_ill_op,   format_no_operands},        // 0xda - esc2
    {x86_ill_op,   format_no_operands},        // 0xdb - esc3
    {x86_ill_op,   format_no_operands},        // 0xdc - esc4
    {x86_ill_op,   format_no_operands},        // 0xdd - esc5
    {x86_ill_op,   format_no_operands},        // 0xde - esc6
    {x86_ill_op,   format_no_operands},        // 0xdf - esc7
    {x86_loop_op,  format_short_jump},         // 0xe0 - loopnz
    {x86_loop_op,  format_short_jump},         // 0xe1 - loopz
    {x86_loop_op,  format_short_jump},         // 0xe2 - loop
    {x86_jcxz_op,  format_short_jump},         // 0xe3 - jcxz
    {x86_in_op,    format_port_immediate},     // 0xe4 - inb AL,Ib
    {x86_in_op,    format_port_immediate},     // 0xe5 - inw/d eAX,Ib
    {x86_out_op,   format_port_immediate},     // 0xe6 - outb Ib,AL
    {x86_out_op,   format_port_immediate},     // 0xe7 - outw/d Ib,eAX
    {x86_call_op,  format_long_jump},          // 0xe8 - call Jv
    {x86_jmp_op,   format_long_jump},          // 0xe9 - jmp Jv
    {x86_jmp_op,   format_immediate_jump},     // 0xea - jmp Ap
    {x86_jmp_op,   format_short_jump},         // 0xeb - jmp Jb
    {x86_in_op,    format_port_dx},            // 0xec - inb AL,DX
    {x86_in_op,    format_port_dx},            // 0xed - inw/d eAX,DX
    {x86_out_op,   format_port_dx},            // 0xee - outb Ib,DX
    {x86_out_op,   format_port_dx},            // 0xef - outw/d eAX,DX
    {x86_lock_op,  format_prefix_opcode},      // 0xf0 - lock
    {x86_ill_op,   format_no_operands},        // 0xf1 - illegal
    {x86_repnz_op, format_prefix_opcode},      // 0xf2 - repnz
    {x86_repz_op,  format_prefix_opcode},      // 0xf3 - repz
    {x86_hlt_op,   format_no_operands},        // 0xf4 - hlt
    {x86_cmc_op,   format_no_operands},        // 0xf5 - cmc
    {x86_test_op,  format_group_3_general},    // 0xf6 - group3 Eb,?
    {x86_test_op,  format_group_3_general},    // 0xf7 - group3 Ev,?
    {x86_clc_op,   format_no_operands},        // 0xf8 - clc
    {x86_stc_op,   format_no_operands},        // 0xf9 - stc
    {x86_cli_op,   format_no_operands},        // 0xfa - cli
    {x86_sti_op,   format_no_operands},        // 0xfb - sti
    {x86_cld_op,   format_no_operands},        // 0xfc - cld
    {x86_std_op,   format_no_operands},        // 0xfd - std
    {x86_inc_op,   format_group_4_general},    // 0xfe - group4 Eb
    {x86_inc_op,   format_group_5_general},    // 0xff - group5 Ev
};


opcode_control_table_t control_table_2[] = {
    {x86_ill_op,   format_no_operands},         // 0x00 - group6
    {x86_ill_op,   format_no_operands},         // 0x01 - group7
    {x86_ill_op,   format_no_operands},         // 0x02 - lar
    {x86_ill_op,   format_no_operands},         // 0x03 - lsl
    {x86_ill_op,   format_no_operands},         // 0x04 - illegal
    {x86_ill_op,   format_no_operands},         // 0x05 - illegal
    {x86_ill_op,   format_no_operands},         // 0x06 - clts
    {x86_ill_op,   format_no_operands},         // 0x07 - illegal
    {x86_ill_op,   format_no_operands},         // 0x08 - illegal
    {x86_ill_op,   format_no_operands},         // 0x09 - illegal
    {x86_ill_op,   format_no_operands},         // 0x0a - illegal
    {x86_ill_op,   format_no_operands},         // 0x0b - illegal
    {x86_ill_op,   format_no_operands},         // 0x0c - illegal
    {x86_ill_op,   format_no_operands},         // 0x0d - illegal
    {x86_ill_op,   format_no_operands},         // 0x0e - illegal
    {x86_ill_op,   format_no_operands},         // 0x0f - illegal
    {x86_ill_op,   format_no_operands},         // 0x10 - illegal
    {x86_ill_op,   format_no_operands},         // 0x11 - illegal
    {x86_ill_op,   format_no_operands},         // 0x12 - illegal
    {x86_ill_op,   format_no_operands},         // 0x13 - illegal
    {x86_ill_op,   format_no_operands},         // 0x14 - illegal
    {x86_ill_op,   format_no_operands},         // 0x15 - illegal
    {x86_ill_op,   format_no_operands},         // 0x16 - illegal
    {x86_ill_op,   format_no_operands},         // 0x17 - illegal
    {x86_ill_op,   format_no_operands},         // 0x18 - illegal
    {x86_ill_op,   format_no_operands},         // 0x19 - illegal
    {x86_ill_op,   format_no_operands},         // 0x1a - illegal
    {x86_ill_op,   format_no_operands},         // 0x1b - illegal
    {x86_ill_op,   format_no_operands},         // 0x1c - illegal
    {x86_ill_op,   format_no_operands},         // 0x1d - illegal
    {x86_ill_op,   format_no_operands},         // 0x1e - illegal
    {x86_ill_op,   format_no_operands},         // 0x1f - illegal
    {x86_ill_op,   format_no_operands},         // 0x20 - illegal
    {x86_ill_op,   format_no_operands},         // 0x21 - illegal
    {x86_ill_op,   format_no_operands},         // 0x22 - illegal
    {x86_ill_op,   format_no_operands},         // 0x23 - illegal
    {x86_ill_op,   format_no_operands},         // 0x34 - illegal
    {x86_ill_op,   format_no_operands},         // 0x25 - illegal
    {x86_ill_op,   format_no_operands},         // 0x26 - illegal
    {x86_ill_op,   format_no_operands},         // 0x27 - illegal
    {x86_ill_op,   format_no_operands},         // 0x28 - illegal
    {x86_ill_op,   format_no_operands},         // 0x29 - illegal
    {x86_ill_op,   format_no_operands},         // 0x2a - illegal
    {x86_ill_op,   format_no_operands},         // 0x2b - illegal
    {x86_ill_op,   format_no_operands},         // 0x2c - illegal
    {x86_ill_op,   format_no_operands},         // 0x2d - illegal
    {x86_ill_op,   format_no_operands},         // 0x2e - illegal
    {x86_ill_op,   format_no_operands},         // 0x2f - illegal
    {x86_ill_op,   format_no_operands},         // 0x30 - illegal
    {x86_ill_op,   format_no_operands},         // 0x31 - illegal
    {x86_ill_op,   format_no_operands},         // 0x32 - illegal
    {x86_ill_op,   format_no_operands},         // 0x33 - illegal
    {x86_ill_op,   format_no_operands},         // 0x34 - illegal
    {x86_ill_op,   format_no_operands},         // 0x35 - illegal
    {x86_ill_op,   format_no_operands},         // 0x36 - illegal
    {x86_ill_op,   format_no_operands},         // 0x37 - illegal
    {x86_ill_op,   format_no_operands},         // 0x38 - illegal
    {x86_ill_op,   format_no_operands},         // 0x39 - illegal
    {x86_ill_op,   format_no_operands},         // 0x3a - illegal
    {x86_ill_op,   format_no_operands},         // 0x3b - illegal
    {x86_ill_op,   format_no_operands},         // 0x3c - illegal
    {x86_ill_op,   format_no_operands},         // 0x3d - illegal
    {x86_ill_op,   format_no_operands},         // 0x3e - illegal
    {x86_ill_op,   format_no_operands},         // 0x3f - illegal
    {x86_ill_op,   format_no_operands},         // 0x40 - illegal
    {x86_ill_op,   format_no_operands},         // 0x41 - illegal
    {x86_ill_op,   format_no_operands},         // 0x42 - illegal
    {x86_ill_op,   format_no_operands},         // 0x43 - illegal
    {x86_ill_op,   format_no_operands},         // 0x44 - illegal
    {x86_ill_op,   format_no_operands},         // 0x45 - illegal
    {x86_ill_op,   format_no_operands},         // 0x46 - illegal
    {x86_ill_op,   format_no_operands},         // 0x47 - illegal
    {x86_ill_op,   format_no_operands},         // 0x48 - illegal
    {x86_ill_op,   format_no_operands},         // 0x49 - illegal
    {x86_ill_op,   format_no_operands},         // 0x4a - illegal
    {x86_ill_op,   format_no_operands},         // 0x4b - illegal
    {x86_ill_op,   format_no_operands},         // 0x4c - illegal
    {x86_ill_op,   format_no_operands},         // 0x4d - illegal
    {x86_ill_op,   format_no_operands},         // 0x4e - illegal
    {x86_ill_op,   format_no_operands},         // 0x4f - illegal
    {x86_ill_op,   format_no_operands},         // 0x50 - illegal
    {x86_ill_op,   format_no_operands},         // 0x51 - illegal
    {x86_ill_op,   format_no_operands},         // 0x52 - illegal
    {x86_ill_op,   format_no_operands},         // 0x53 - illegal
    {x86_ill_op,   format_no_operands},         // 0x54 - illegal
    {x86_ill_op,   format_no_operands},         // 0x55 - illegal
    {x86_ill_op,   format_no_operands},         // 0x56 - illegal
    {x86_ill_op,   format_no_operands},         // 0x57 - illegal
    {x86_ill_op,   format_no_operands},         // 0x58 - illegal
    {x86_ill_op,   format_no_operands},         // 0x59 - illegal
    {x86_ill_op,   format_no_operands},         // 0x5a - illegal
    {x86_ill_op,   format_no_operands},         // 0x5b - illegal
    {x86_ill_op,   format_no_operands},         // 0x5c - illegal
    {x86_ill_op,   format_no_operands},         // 0x5d - illegal
    {x86_ill_op,   format_no_operands},         // 0x5e - illegal
    {x86_ill_op,   format_no_operands},         // 0x5f - illegal
    {x86_ill_op,   format_no_operands},         // 0x60 - illegal
    {x86_ill_op,   format_no_operands},         // 0x61 - illegal
    {x86_ill_op,   format_no_operands},         // 0x62 - illegal
    {x86_ill_op,   format_no_operands},         // 0x63 - illegal
    {x86_ill_op,   format_no_operands},         // 0x64 - illegal
    {x86_ill_op,   format_no_operands},         // 0x65 - illegal
    {x86_ill_op,   format_no_operands},         // 0x66 - illegal
    {x86_ill_op,   format_no_operands},         // 0x67 - illegal
    {x86_ill_op,   format_no_operands},         // 0x68 - illegal
    {x86_ill_op,   format_no_operands},         // 0x69 - illegal
    {x86_ill_op,   format_no_operands},         // 0x6a - illegal
    {x86_ill_op,   format_no_operands},         // 0x6b - illegal
    {x86_ill_op,   format_no_operands},         // 0x6c - illegal
    {x86_ill_op,   format_no_operands},         // 0x6d - illegal
    {x86_ill_op,   format_no_operands},         // 0x6e - illegal
    {x86_ill_op,   format_no_operands},         // 0x6f - illegal
    {x86_ill_op,   format_no_operands},         // 0x70 - illegal
    {x86_ill_op,   format_no_operands},         // 0x71 - illegal
    {x86_ill_op,   format_no_operands},         // 0x72 - illegal
    {x86_ill_op,   format_no_operands},         // 0x73 - illegal
    {x86_ill_op,   format_no_operands},         // 0x74 - illegal
    {x86_ill_op,   format_no_operands},         // 0x75 - illegal
    {x86_ill_op,   format_no_operands},         // 0x76 - illegal
    {x86_ill_op,   format_no_operands},         // 0x77 - illegal
    {x86_ill_op,   format_no_operands},         // 0x78 - illegal
    {x86_ill_op,   format_no_operands},         // 0x79 - illegal
    {x86_ill_op,   format_no_operands},         // 0x7a - illegal
    {x86_ill_op,   format_no_operands},         // 0x7b - illegal
    {x86_ill_op,   format_no_operands},         // 0x7c - illegal
    {x86_ill_op,   format_no_operands},         // 0x7d - illegal
    {x86_ill_op,   format_no_operands},         // 0x7e - illegal
    {x86_ill_op,   format_no_operands},         // 0x7f - illegal
    {x86_jxx_op,   format_long_jump},           // 0x80 - jo   jv
    {x86_jxx_op,   format_long_jump},           // 0x81 - jno  jv
    {x86_jxx_op,   format_long_jump},           // 0x82 - jb   jv
    {x86_jxx_op,   format_long_jump},           // 0x83 - jnb  jv
    {x86_jxx_op,   format_long_jump},           // 0x84 - jz   jv
    {x86_jxx_op,   format_long_jump},           // 0x85 - jnz  jv
    {x86_jxx_op,   format_long_jump},           // 0x86 - jbe  jv
    {x86_jxx_op,   format_long_jump},           // 0x87 - jnbe jv
    {x86_jxx_op,   format_long_jump},           // 0x88 - js   jv
    {x86_jxx_op,   format_long_jump},           // 0x89 - jns  jv
    {x86_jxx_op,   format_long_jump},           // 0x8a - jp   jv
    {x86_jxx_op,   format_long_jump},           // 0x8b - jnp  jv
    {x86_jxx_op,   format_long_jump},           // 0x8c - jl   jv
    {x86_jxx_op,   format_long_jump},           // 0x8d - jnl  jv
    {x86_jxx_op,   format_long_jump},           // 0x8e - jle  jv
    {x86_jxx_op,   format_long_jump},           // 0x8f - jnle jv
    {x86_sxx_op,   format_set_cc_byte},         // 0x90 - seto   Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x91 - setno  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x92 - setb   Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x93 - setnb  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x94 - setz   Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x95 - setnz  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x96 - setbe  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x97 - setnbe Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x98 - sets   Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x99 - setns  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x9a - setp   Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x9b - setnp  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x9c - setl   Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x9d - setnl  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x9e - setle  Eb
    {x86_sxx_op,   format_set_cc_byte},         // 0x9f - setnle Eb
    {x86_push_op,  format_seg_fs},              // 0xa0 - push FS
    {x86_pop_op,   format_seg_fs},              // 0xa1 - pop  FS
    {x86_ill_op,   format_no_operands},         // 0xa2 - illegal
    {x86_bt_op,    format_general_bit_offset},  // 0xa3 - bt Ev,Gv
    {x86_shld_op,  format_shift_double},        // 0xa4 - shld Ev,Gv,Ib
    {x86_shld_op,  format_shift_double},        // 0xa5 - shld Ev,Gv,cl
    {x86_ill_op,   format_no_operands},         // 0xa6 - illegal
    {x86_ill_op,   format_no_operands},         // 0xa6 - illegal
    {x86_push_op,  format_seg_gs},              // 0xa8 - push GS
    {x86_pop_op,   format_seg_gs},              // 0xa9 - pop  GS
    {x86_ill_op,   format_no_operands},         // 0xaa - illegal
    {x86_bts_op,   format_general_bit_offset},  // 0xab - bts Ev,Gv
    {x86_shrd_op,  format_shift_double},        // 0xac - shdr Ev,Gv,Ib
    {x86_shrd_op,  format_shift_double},        // 0xad - shdr Rv,Gv,cl
    {x86_ill_op,   format_no_operands},         // 0xae - illegal
    {x86_imul_op,  format_group_1_general},     // 0xaf - imul Gv,Ev
    {x86_cmpxchg_op, format_group_1_general},   // 0xb0 - cmpxchg Eb,Gb
    {x86_cmpxchg_op, format_group_1_general},   // 0xb1 - cmpxchg Ev,Gv
    {x86_mov_op,   format_seg_load_ss},         // 0xb2 - lss Gv,Mp
    {x86_btr_op,   format_general_bit_offset},  // 0xb3 - btr Ev,Gv
    {x86_mov_op,   format_seg_load_fs},         // 0xb4 - lfs Gv,Mp
    {x86_mov_op,   format_seg_load_gs},         // 0xb5 - lgd Gv,Mp
    {x86_mov_op,   format_move_xx_general},     // 0xb6 - movzb Gv,Eb
    {x86_mov_op,   format_move_xx_general},     // 0xb7 - movsw Gv,Ew
    {x86_ill_op,   format_no_operands},         // 0xb8 - illegal
    {x86_ill_op,   format_no_operands},         // 0xb9 - illegal
    {x86_bt_op,    format_group_8_bit_offset},  // 0xba - group8 Ev,Ib
    {x86_btc_op,   format_general_bit_offset},  // 0xbb - btc Ev,Gv
    {x86_bsf_op,   format_bit_scan_general},    // 0xbc - bsf Gv,Ev
    {x86_bsr_op,   format_bit_scan_general},    // 0xbd - bsr Gv,Ev
    {x86_mov_op,   format_move_xx_general},     // 0xbe - movsb Gv,Eb
    {x86_mov_op,   format_move_xx_general},     // 0xbf - movsw Gv,Ew
    {x86_xadd_op,  format_group_1_general},     // 0xc0 - xadd Eb,Gb
    {x86_xadd_op,  format_group_1_general},     // 0xc1 - xadd Ev,Gv
    {x86_ill_op,   format_no_operands},         // 0xc2 - illegal
    {x86_ill_op,   format_no_operands},         // 0xc3 - illegal
    {x86_ill_op,   format_no_operands},         // 0xc4 - illegal
    {x86_ill_op,   format_no_operands},         // 0xc5 - illegal
    {x86_ill_op,   format_no_operands},         // 0xc6 - illegal
    {x86_ill_op,   format_no_operands},         // 0xc7 - illegal
    {x86_bswap_op, format_general_register},    // 0xc8 - bswap Gv
    {x86_ill_op,   format_no_operands},         // 0xc9 - illegal
    {x86_ill_op,   format_no_operands},         // 0xca - illegal
    {x86_ill_op,   format_no_operands},         // 0xcb - illegal
    {x86_ill_op,   format_no_operands},         // 0xcc - illegal
    {x86_ill_op,   format_no_operands},         // 0xcd - illegal
    {x86_ill_op,   format_no_operands},         // 0xce - illegal
    {x86_ill_op,   format_no_operands},         // 0xcf - illegal
    {x86_ill_op,   format_no_operands},         // 0xd0 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd1 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd2 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd3 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd4 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd5 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd6 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd7 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd8 - illegal
    {x86_ill_op,   format_no_operands},         // 0xd9 - illegal
    {x86_ill_op,   format_no_operands},         // 0xda - illegal
    {x86_ill_op,   format_no_operands},         // 0xdb - illegal
    {x86_ill_op,   format_no_operands},         // 0xdc - illegal
    {x86_ill_op,   format_no_operands},         // 0xdd - illegal
    {x86_ill_op,   format_no_operands},         // 0xde - illegal
    {x86_ill_op,   format_no_operands},         // 0xdf - illegal
    {x86_ill_op,   format_no_operands},         // 0xe0 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe1 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe2 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe3 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe4 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe5 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe6 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe7 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe8 - illegal
    {x86_ill_op,   format_no_operands},         // 0xe9 - illegal
    {x86_ill_op,   format_no_operands},         // 0xea - illegal
    {x86_ill_op,   format_no_operands},         // 0xeb - illegal
    {x86_ill_op,   format_no_operands},         // 0xec - illegal
    {x86_ill_op,   format_no_operands},         // 0xed - illegal
    {x86_ill_op,   format_no_operands},         // 0xee - illegal
    {x86_ill_op,   format_no_operands},         // 0xef - illegal
    {x86_ill_op,   format_no_operands},         // 0xf0 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf1 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf2 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf3 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf4 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf5 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf6 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf7 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf8 - illegal
    {x86_ill_op,   format_no_operands},         // 0xf9 - illegal
    {x86_ill_op,   format_no_operands},         // 0xfa - illegal
    {x86_ill_op,   format_no_operands},         // 0xfb - illegal
    {x86_ill_op,   format_no_operands},         // 0xfc - illegal
    {x86_ill_op,   format_no_operands},         // 0xfd - illegal
    {x86_ill_op,   format_no_operands},         // 0xfe - illegal
    {x86_ill_op,   format_no_operands}          // 0xff - illegal
};



char* opcode_table_1[] = {
    "add Eb,Gb    ", // 0x00
    "add Ev,Gv    ", // 0x01
    "add Gb,Eb    ", // 0x02
    "add Gv,Ev    ", // 0x03
    "add AL,Ib    ", // 0x04
    "add eAX,Iv   ", // 0x05
    "push ES      ", // 0x06
    "pop  ES      ", // 0x07
    "or  Eb,Gb    ", // 0x08
    "or  Ev,Gv    ", // 0x09
    "or  Gb,Eb    ", // 0x0a
    "or  Gv,Ev    ", // 0x0b
    "or  AL,Ib    ", // 0x0c
    "or  eAX,Iv   ", // 0x0d
    "push CS      ", // 0x0e
    "escape:      ", // 0x0f
    "adc Eb,Gb    ", // 0x10
    "adc Ev,Gv    ", // 0x11
    "adc Gb,Eb    ", // 0x12
    "adc Gv,Ev    ", // 0x13
    "adc AL,Ib    ", // 0x14
    "adc eAX,Iv   ", // 0x15
    "push SS      ", // 0x16
    "pop  SS      ", // 0x17
    "sbb Eb,Gb    ", // 0x18
    "sbb Ev,Gv    ", // 0x19
    "sbb Gb,Eb    ", // 0x1a
    "sbb Gv,Ev    ", // 0x1b
    "sbb AL,Ib    ", // 0x1c
    "sbb eAX,Iv   ", // 0x1d
    "push DS      ", // 0x1e
    "pop  DS      ", // 0x1f
    "and Eb,Gb    ", // 0x20
    "and Ev,Gv    ", // 0x21
    "and Gb,Eb    ", // 0x22
    "and Gv,Ev    ", // 0x23
    "and AL,Ib    ", // 0x24
    "and eAX,Iv   ", // 0x25
    "ES:          ", // 0x26
    "daa          ", // 0x27
    "sub Eb,Gb    ", // 0x28
    "sub Ev,Gv    ", // 0x29
    "sub Gb,Eb    ", // 0x2a
    "sub Gv,Ev    ", // 0x2b
    "sub AL,Ib    ", // 0x2c
    "sub eAX,Iv   ", // 0x2d
    "CS:          ", // 0x2e
    "das          ", // 0x2f
    "xor Eb,Gb    ", // 0x30
    "xor Ev,Gv    ", // 0x31
    "xor Gb,Eb    ", // 0x32
    "xor Gv,Ev    ", // 0x33
    "xor AL,Ib    ", // 0x34
    "xor eAX,Iv   ", // 0x35
    "SS:          ", // 0x36
    "aaa          ", // 0x37
    "cmp Eb,Gb    ", // 0x38
    "cmp Ev,Gv    ", // 0x39
    "cmp Gb,Eb    ", // 0x3a
    "cmp Gv,Ev    ", // 0x3b
    "cmp AL,Ib    ", // 0x3c
    "cmp eAX,Iv   ", // 0x3d
    "DS:          ", // 0x3e
    "aas          ", // 0x3f
    "inc eAX      ", // 0x40
    "inc eCX      ", // 0x41
    "inc eDX      ", // 0x42
    "inc eBX      ", // 0x43
    "inc eSP      ", // 0x44
    "inc eBP      ", // 0x45
    "inc eSI      ", // 0x46
    "inc eDI      ", // 0x47
    "dec eAX      ", // 0x48
    "dec eCX      ", // 0x49
    "dec eDX      ", // 0x4a
    "dec eBX      ", // 0x4b
    "dec eSP      ", // 0x4c
    "dec eBP      ", // 0x4d
    "dec eSI      ", // 0x4e
    "dec eDI      ", // 0x4f
    "push eAX     ", // 0x50
    "push eCX     ", // 0x51
    "push eDX     ", // 0x52
    "push eBX     ", // 0x53
    "push eSP     ", // 0x54
    "push eBP     ", // 0x55
    "push eSI     ", // 0x56
    "push eDI     ", // 0x57
    "pop eAX      ", // 0x58
    "pop eCX      ", // 0x59
    "pop eDX      ", // 0x5a
    "pop eBX      ", // 0x5b
    "pop eSP      ", // 0x5c
    "pop eBP      ", // 0x5d
    "pop eSI      ", // 0x5e
    "pop eDI      ", // 0x5f
    "pusha        ", // 0x60
    "popa         ", // 0x61
    "bound Gv,Ma  ", // 0x62
    "arpl Ew,Rw   ", // 0x63
    "FS:          ", // 0x64
    "GS:          ", // 0x65
    "opsize:      ", // 0x66
    "opaddr:      ", // 0x67
    "push Iv      ", // 0x68
    "imul Gv,Ev,Iv ", // 0x69
    "push Ib      ", // 0x6a
    "imul Gv,Ev,Ib ", // 0x6b
    "insb         ", // 0x6c
    "insw/d       ", // 0x6d
    "outsb        ", // 0x6e
    "outsw/d      ", // 0x6f
    "jo Jb        ", // 0x70
    "jno Jb       ", // 0x71
    "jb Jb        ", // 0x72
    "jnb Jb       ", // 0x73
    "jz Jb        ", // 0x74
    "jnz Jb       ", // 0x75
    "jbe Jb       ", // 0x76
    "jnbe Jb      ", // 0x77
    "js Jb        ", // 0x78
    "jns Jb       ", // 0x79
    "jp Jb        ", // 0x7a
    "jnp Jb       ", // 0x7b
    "jl Jb        ", // 0x7c
    "jnl Jb       ", // 0x7d
    "jle Jb       ", // 0x7e
    "jnle Jb      ", // 0x7f
    "group1 Eb,Ib ", // 0x80
    "group1 Ev,Ib ", // 0x81
    "illegal      ", // 0x82
    "group1 Ev,Ib ", // 0x83
    "test Eb,Gb   ", // 0x84
    "test Ev,Gv   ", // 0x85
    "xchg Eb,Gb   ", // 0x86
    "xchg Ev,Gv   ", // 0x87
    "mov Eb,Gb    ", // 0x88
    "mov Ev,Gv    ", // 0x89
    "mov Gb,Eb    ", // 0x8a
    "mov Gv,Ev    ", // 0x8b
    "mov Ew,Sw    ", // 0x8c
    "lea Gv,Ma    ", // 0x8d
    "mov Sw,Ew    ", // 0x8e
    "pop Ev       ", // 0x8f
    "nop          ", // 0x90
    "xchg eCX,eAX ", // 0x91
    "xchg eDX,eAX ", // 0x92
    "xchg eBX,eAX ", // 0x93
    "xchg eSP,eAX ", // 0x94
    "xchg eBP,eAX ", // 0x95
    "xchg eSI,eAX ", // 0x96
    "xchg eDI,eAX ", // 0x97
    "cbw          ", // 0x98
    "cwd          ", // 0x99
    "call Ap      ", // 0x9a
    "wait         ", // 0x9b
    "pushf        ", // 0x9c
    "popf         ", // 0x9d
    "sahf         ", // 0x9e
    "lahf         ", // 0x9f
    "mov AL,Ob    ", // 0xa0
    "mov eAX,Ov   ", // 0xa1
    "mov Ob,AL    ", // 0xa2
    "mov Ov,eAX   ", // 0xa3
    "movsb        ", // 0xa4
    "movsw/d      ", // 0xa5
    "cmpsb        ", // 0xa6
    "cmpsw/d      ", // 0xa7
    "test AL,Ib   ", // 0xa8
    "test eAX,Iv  ", // 0xa9
    "stosb        ", // 0xaa
    "stosw/d      ", // 0xab
    "lodsb        ", // 0xac
    "lodsw/d      ", // 0xad
    "scasb        ", // 0xae
    "scasw/d      ", // 0xaf
    "mov AL,Ib    ", // 0xb0
    "mov Cl,Ib    ", // 0xb1
    "mov DL,Ib    ", // 0xb2
    "mov BL,Ib    ", // 0xb3
    "mov AH,Ib    ", // 0xb4
    "mov CH,Ib    ", // 0xb5
    "mov DH,Ib    ", // 0xb6
    "mov BH,Ib    ", // 0xb7
    "mov eAX,Iv   ", // 0xb8
    "mov eCX,Iv   ", // 0xb9
    "mov eDX,Iv   ", // 0xba
    "mov eBX,Iv   ", // 0xbb
    "mov eSP,Iv   ", // 0xbc
    "mov eBP,Iv   ", // 0xbd
    "mov eSI,Iv   ", // 0xbe
    "mov eDI,Iv   ", // 0xbf
    "group2 Eb,Ib ", // 0xc0
    "group2 Ev,Ib ", // 0xc1
    "ret Iw near  ", // 0xc2
    "ret near     ", // 0xc3
    "les Gv,Mp    ", // 0xc4
    "lds Gv,Mp    ", // 0xc5
    "mov Eb,Ib    ", // 0xc6
    "mov Ev,Iv    ", // 0xc7
    "enter Iw,Ib  ", // 0xc8
    "leave        ", // 0xc9
    "ret Iw far   ", // 0xca
    "ret far      ", // 0xcb
    "int 3        ", // 0xcc
    "int Ib       ", // 0xcd
    "into         ", // 0xce
    "iret         ", // 0xcf
    "group2 Eb,1  ", // 0xd0
    "group2 Ev,1  ", // 0xd1
    "group2 Eb,CL ", // 0xd2
    "group2 Ev,Cl ", // 0xd3
    "aam          ", // 0xd4
    "aad          ", // 0xd5
    "illegal      ", // 0xd6
    "xlat         ", // 0xd7
    "illegal      ", // 0xd8
    "illegal      ", // 0xd9
    "illegal      ", // 0xda
    "illegal      ", // 0xdb
    "illegal      ", // 0xdc
    "illegal      ", // 0xdd
    "illegal      ", // 0xde
    "illegal      ", // 0xdf
    "loopnz       ", // 0xe0
    "loopz        ", // 0xe1
    "loop         ", // 0xe2
    "jcxz         ", // 0xe3
    "inb AL,Ib    ", // 0xe4
    "inw/d eAX,Ib ", // 0xe5
    "outb Ib,AL   ", // 0xe6
    "outw/d Ib,eAX ", // 0xe7
    "call Jv      ", // 0xe8
    "jmp Jv       ", // 0xe9
    "jmp Ap       ", // 0xea
    "jmp Jb       ", // 0xeb
    "inb AL,DX    ", // 0xec
    "inw/d Ib,DX  ", // 0xed
    "outb DX,AL   ", // 0xee
    "outw/d DX,eAX ", // 0xef
    "lock:        ", // 0xf0
    "illegal      ", // 0xf1
    "repnz:       ", // 0xf2
    "repz:        ", // 0xf3
    "hlt          ", // 0xf4
    "cmc          ", // 0xf5
    "group3 Eb,?  ", // 0xf6
    "group3 Ev,?  ", // 0xf7
    "clc          ", // 0xf8
    "stc          ", // 0xf9
    "cli          ", // 0xfa
    "sti          ", // 0xfb
    "cld          ", // 0xfc
    "std          ", // 0xfd
    "group4 Eb    ", // 0xfe
    "group5 Ev    "  // 0xff
};

char* opcode_table_2[] = {
    "group6       ", // 0x00
    "group7       ", // 0x01
    "lar          ", // 0x02
    "lsl          ", // 0x03
    "illegal      ", // 0x04
    "illegal      ", // 0x05
    "clts         ", // 0x06
    "illegal      ", // 0x07
    "illegal      ", // 0x08
    "illegal      ", // 0x09
    "illegal      ", // 0x0a
    "illegal      ", // 0x0b
    "illegal      ", // 0x0c
    "illegal      ", // 0x0d
    "illegal      ", // 0x0e
    "illegal      ", // 0x0f
    "illegal      ", // 0x10
    "illegal      ", // 0x11
    "illegal      ", // 0x12
    "illegal      ", // 0x13
    "illegal      ", // 0x14
    "illegal      ", // 0x15
    "illegal      ", // 0x16
    "illegal      ", // 0x17
    "illegal      ", // 0x18
    "illegal      ", // 0x19
    "illegal      ", // 0x1a
    "illegal      ", // 0x1b
    "illegal      ", // 0x1c
    "illegal      ", // 0x1d
    "illegal      ", // 0x1e
    "illegal      ", // 0x1f
    "mov Cd,Rd    ", // 0x20
    "mov Dd,Rd    ", // 0x21
    "mov Rd,Cd    ", // 0x22
    "mov Rd,Dd    ", // 0x23
    "mov Td,Rd    ", // 0x24
    "illegal      ", // 0x25
    "mov Rd,Td    ", // 0x26
    "illegal      ", // 0x27
    "illegal      ", // 0x28
    "illegal      ", // 0x29
    "illegal      ", // 0x2a
    "illegal      ", // 0x2b
    "illegal      ", // 0x2c
    "illegal      ", // 0x2d
    "illegal      ", // 0x2e
    "illegal      ", // 0x2f
    "illegal      ", // 0x30
    "illegal      ", // 0x31
    "illegal      ", // 0x32
    "illegal      ", // 0x33
    "illegal      ", // 0x34
    "illegal      ", // 0x35
    "illegal      ", // 0x36
    "illegal      ", // 0x37
    "illegal      ", // 0x38
    "illegal      ", // 0x39
    "illegal      ", // 0x3a
    "illegal      ", // 0x3b
    "illegal      ", // 0x3c
    "illegal      ", // 0x3d
    "illegal      ", // 0x3e
    "illegal      ", // 0x3f
    "illegal      ", // 0x40
    "illegal      ", // 0x41
    "illegal      ", // 0x42
    "illegal      ", // 0x43
    "illegal      ", // 0x44
    "illegal      ", // 0x45
    "illegal      ", // 0x46
    "illegal      ", // 0x47
    "illegal      ", // 0x48
    "illegal      ", // 0x49
    "illegal      ", // 0x4a
    "illegal      ", // 0x4b
    "illegal      ", // 0x4c
    "illegal      ", // 0x4d
    "illegal      ", // 0x4e
    "illegal      ", // 0x4f
    "illegal      ", // 0x50
    "illegal      ", // 0x51
    "illegal      ", // 0x52
    "illegal      ", // 0x53
    "illegal      ", // 0x54
    "illegal      ", // 0x55
    "illegal      ", // 0x56
    "illegal      ", // 0x57
    "illegal      ", // 0x58
    "illegal      ", // 0x59
    "illegal      ", // 0x5a
    "illegal      ", // 0x5b
    "illegal      ", // 0x5c
    "illegal      ", // 0x5d
    "illegal      ", // 0x5e
    "illegal      ", // 0x5f
    "illegal      ", // 0x60
    "illegal      ", // 0x61
    "illegal      ", // 0x62
    "illegal      ", // 0x63
    "illegal      ", // 0x64
    "illegal      ", // 0x65
    "illegal      ", // 0x66
    "illegal      ", // 0x67
    "illegal      ", // 0x68
    "illegal      ", // 0x69
    "illegal      ", // 0x6a
    "illegal      ", // 0x6b
    "illegal      ", // 0x6c
    "illegal      ", // 0x6d
    "illegal      ", // 0x6e
    "illegal      ", // 0x6f
    "illegal      ", // 0x70
    "illegal      ", // 0x71
    "illegal      ", // 0x72
    "illegal      ", // 0x73
    "illegal      ", // 0x74
    "illegal      ", // 0x75
    "illegal      ", // 0x76
    "illegal      ", // 0x77
    "illegal      ", // 0x78
    "illegal      ", // 0x79
    "illegal      ", // 0x7a
    "illegal      ", // 0x7b
    "illegal      ", // 0x7c
    "illegal      ", // 0x7d
    "illegal      ", // 0x7e
    "illegal      ", // 0x7f
    "jo Jv        ", // 0x80
    "jno Jv       ", // 0x81
    "jb Jv        ", // 0x82
    "jnb Jv       ", // 0x83
    "jz Jv        ", // 0x84
    "jnz Jv       ", // 0x85
    "jbe Jv       ", // 0x86
    "jnbe Jv      ", // 0x87
    "js Jv        ", // 0x88
    "jns Jv       ", // 0x89
    "jp Jv        ", // 0x8a
    "jnp Jv       ", // 0x8b
    "jl Jv        ", // 0x8c
    "jnl Jv       ", // 0x8d
    "jle Jv       ", // 0x8e
    "jnle Jv      ", // 0x8f
    "seto         ", // 0x90
    "setno        ", // 0x91
    "setb         ", // 0x92
    "setnb        ", // 0x93
    "setz         ", // 0x94
    "setnz        ", // 0x95
    "setbe        ", // 0x96
    "setnbe       ", // 0x97
    "sets         ", // 0x98
    "setns        ", // 0x99
    "setp         ", // 0x9a
    "setnp        ", // 0x9b
    "setl         ", // 0x9c
    "setnl        ", // 0x9d
    "setle        ", // 0x9e
    "setnle       ", // 0x9f
    "push FS      ", // 0xa0
    "pop FS       ", // 0xa1
    "illegal      ", // 0xa2
    "bt Ev,Gv     ", // 0xa3
    "shld Ev,Gv,Ib ", // 0xa4
    "Shld Ev,Gv,vl ", // 0xa5
    "illegal      ", // 0xa6
    "illegal      ", // 0xa7
    "push GS      ", // 0xa8
    "pop GS       ", // 0xa9
    "illegal      ", // 0xaa
    "bts Ev,Gv    ", // 0xab
    "shrd Ev,Gv,Ib ", // 0xac
    "shrd Ev,Gv,cl ", // 0xad
    "illegal      ", // 0xae
    "imul Gv,Ev   ", // 0xaf
    "cmpxchg Eb,Gv ", // 0xb0
    "cmpxchg Ev,Gv ", // 0xb1
    "lss Gv,Mp    ", // 0xb2
    "btr Ev,Gv    ", // 0xb3
    "lfs Gv,Mp    ", // 0xb4
    "lgs Gv,Mp    ", // 0xb5
    "movzb Gv,Eb  ", // 0xb6
    "movzw Gv,Ew  ", // 0xb7
    "illegal      ", // 0xb8
    "illegal      ", // 0xb9
    "group8 Ev,Ib ", // 0xba
    "btc Ev,Gv    ", // 0xbb
    "bsf Gv,Ev    ", // 0xbc
    "bsr Gv,Ev    ", // 0xbd
    "movsb Gv,Eb  ", // 0xbe
    "movsw Gv,Ew  ", // 0xbf
    "xadd Eb,Gb   ", // 0xc0
    "xadd Ev,Gv   ", // 0xc1
    "illegal      ", // 0xc2
    "illegal      ", // 0xc3
    "illegal      ", // 0xc4
    "illegal      ", // 0xc5
    "illegal      ", // 0xc6
    "illegal      ", // 0xc7
    "bswap Gv     ", // 0xc8
    "illegal      ", // 0xc9
    "illegal      ", // 0xca
    "illegal      ", // 0xcb
    "illegal      ", // 0xcc
    "illegal      ", // 0xcd
    "illegal      ", // 0xce
    "illegal      ", // 0xcf
    "illegal      ", // 0xd0
    "illegal      ", // 0xd1
    "illegal      ", // 0xd2
    "illegal      ", // 0xd3
    "illegal      ", // 0xd4
    "illegal      ", // 0xd5
    "illegal      ", // 0xd6
    "illegal      ", // 0xd7
    "illegal      ", // 0xd8
    "illegal      ", // 0xd9
    "illegal      ", // 0xda
    "illegal      ", // 0xdb
    "illegal      ", // 0xdc
    "illegal      ", // 0xdd
    "illegal      ", // 0xde
    "illegal      ", // 0xdf
    "illegal      ", // 0xe0
    "illegal      ", // 0xe1
    "illegal      ", // 0xe2
    "illegal      ", // 0xe3
    "illegal      ", // 0xe4
    "illegal      ", // 0xe5
    "illegal      ", // 0xe6
    "illegal      ", // 0xe7
    "illegal      ", // 0xe8
    "illegal      ", // 0xe9
    "illegal      ", // 0xea
    "illegal      ", // 0xeb
    "illegal      ", // 0xec
    "illegal      ", // 0xed
    "illegal      ", // 0xee
    "illegal      ", // 0xef
    "illegal      ", // 0xf0
    "illegal      ", // 0xf1
    "illegal      ", // 0xf2
    "illegal      ", // 0xf3
    "illegal      ", // 0xf4
    "illegal      ", // 0xf5
    "illegal      ", // 0xf6
    "illegal      ", // 0xf7
    "illegal      ", // 0xf8
    "illegal      ", // 0xf9
    "illegal      ", // 0xfa
    "illegal      ", // 0xfb
    "illegal      ", // 0xfc
    "illegal      ", // 0xfd
    "illegal      ", // 0xfe
    "illegal      "  // 0xff
};


__END_DECLS
