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

#ifndef hyperx86_cpu_h
#define hyperx86_cpu_h

#pragma once

#define WIDTH_BIT       0x1
#define DIRECTION_BIT   0x2
#define SIGN_BIT        0x2

extern void cpu_subsystem_initialize __P((void));
extern void cpu_dump_registers __P((void));
extern void cpu_begin_emulation __P((void));

extern char* opcode_table_1[];
extern char* opcode_table_2[];

typedef uint32_t (*opcode_decode_t)(void);
typedef uint32_t (*opcode_function_t)(void);

typedef struct {
    uint8_t     function_index;
    uint8_t     format_type;
} opcode_control_table_t;

typedef enum {
    x86_aaa_op,     /* ASCII */
    x86_aad_op,
    x86_aam_op,
    x86_aas_op,
    x86_daa_op,
    x86_das_op,
    x86_add_op,
    x86_or_op,      /* Group1 */
    x86_adc_op,
    x86_sbb_op,
    x86_and_op,
    x86_sub_op,
    x86_xor_op,
    x86_cmp_op,
    x86_rol_op,     /* Group2 */
    x86_ror_op,
    x86_rcl_op,
    x86_rcr_op,
    x86_shl_op,
    x86_shr_op,
    x86_fill0_op,
    x86_sar_op,
    x86_test_op,    /* Group3 */
    x86_fill1_op,
    x86_not_op,
    x86_neg_op,
    x86_mul_op,
    x86_imulx_op,
    x86_div_op,
    x86_idiv_op,
    x86_inc_op,     /* Group4/5 */
    x86_dec_op,
    x86_call_op,
    x86_fill2_op,
    x86_jmp_op,
    x86_fill3_op,
    x86_push_op,
    x86_fill4_op,
    x86_bt_op,      /* Group8 */
    x86_bts_op,
    x86_btr_op,
    x86_btc_op,
    x86_pop_op,     /* stack */
    x86_pusha_op,
    x86_popa_op,
    x86_jxx_op,     /* jump */
    x86_loop_op,
    x86_jcxz_op,
    x86_enter_op,   /* gencontrol */
    x86_hlt_op,
    x86_int_op,
    x86_iret_op,
    x86_leave_op,
    x86_ret_op,
    x86_sxx_op,     /* set on conditional value */
    x86_cmc_op,     /* condition operators */
    x86_clc_op,
    x86_stc_op,
    x86_cli_op,
    x86_sti_op,
    x86_cld_op,
    x86_std_op,
    x86_lahf_op,
    x86_sahf_op,
    x86_mov_op,     /* general moves */
    x86_xchg_op,
    x86_cbw_op,     /* conversions */
    x86_cwd_op,
    x86_imul_op,    /* multiply */
    x86_cmps_op,    /* strings */
    x86_ins_op,
    x86_lods_op,
    x86_movs_op,
    x86_outs_op,
    x86_scas_op,
    x86_stos_op,
    x86_bound_op,   /* EA operators */
    x86_lea_op,
    x86_shld_op,    /* dblshift */
    x86_shrd_op,
    x86_in_op,      /* port io */
    x86_out_op,
    x86_bsf_op,     /* bitscan operaots */
    x86_bsr_op,
    x86_bswap_op,   /* bswap */
    x86_xadd_op,    /* add/compare/xchg */
    x86_cmpxchg_op,
    x86_nop_op,     /* no op */
    x86_ill_op,
    x86_max_op
} function_table_index;

typedef enum {
    x86_es_op = es,
    x86_cs_op = cs,
    x86_ss_op = ss,
    x86_ds_op = ds,
    x86_fs_op = fs,
    x86_gs_op = gs,
    x86_lock_op,
    x86_adsz_op,
    x86_opsz_op,
    x86_repz_op,
    x86_repnz_op
} prefix_function_index;

typedef enum {
    format_seg_es,
    format_seg_cs,
    format_seg_ss,
    format_seg_ds,
    format_seg_fs,
    format_seg_gs,
    format_seg_load_es,
    format_seg_load_cs,
    format_seg_load_ss,
    format_seg_load_ds,
    format_seg_load_fs,
    format_seg_load_gs,
    format_group_1_general,
    format_group_1_immediate,
    format_group_2_by_1,
    format_group_2_by_cl,
    format_group_2_by_byte,
    format_group_3_general,
    format_group_4_general,
    format_group_5_general,
    format_group_8_bit_offset,
    format_group_opcode_register,
    format_opcode_register,
    format_long_jump,
    format_short_jump,
    format_set_cc_byte,
    format_accum_immediate,
    format_accum_register,
    format_move_general,
    format_move_immediate,
    format_move_reg_immediate,
    format_segment_offset,
    format_move_segment,
    format_move_xx_general,
    format_flags_register,
    format_push_immediate,
    format_pop_general,
    format_imul_immediate,
    format_string_operands,
    format_effective_offset,
    format_immediate_jump,
    format_immediate_enter,
    format_general_bit_offset,
    format_shift_double,
    format_port_immediate,
    format_port_dx,
    format_bit_scan_general,
    format_byte_immediate,
    format_xlat_opcode,
    format_general_register,
    format_no_operands,
    format_opcode_escape,
    format_prefix_opcode
} format_type;

#endif
