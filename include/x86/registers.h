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

#ifndef _x86_registers_h_
#define _x86_registers_h_

#pragma once

#include <stdint.h>

/* Main GPR type */
typedef uint32_t gpr_t;     /*
                             * I know, we're going to not be dealing with
                             * the Exx registers, but keep it this way
                             * so I don't have to make stupid shitty additions
                             * in the future. 
                             *
                             * Will need to extend for amd64, but I don't really
                             * give a crap right now. It's late at night.
                             */

/* register definitions */
typedef union {
    uint32_t exx;
    union {
        uint16_t xx;
        struct {
            uint8_t xl;
            uint8_t xh;
        };
    };
} e_gpr_t;

typedef uint16_t    segment_registers_t;

typedef enum {
    al,
    cl,
    dl,
    bl,
    ah,
    ch,
    dh,
    bh
} x86_8_bit_registers;

typedef enum {
    ax,
    cx,
    dx,
    bx,
    sp,
    bp,
    si,
    di
} x86_16_bit_registers;

typedef enum {
    eax,
    ecx,
    edx,
    ebx,
    esp,
    ebp,
    esi,
    edi
} x86_32_bit_registers;

typedef enum {
    es,
    cs,
    ss,
    ds,
    fs,
    gs
} x86_segment_registers;

typedef struct {
    e_gpr_t             basic_registers[8];
    segment_registers_t segment_registers[6];
    uint16_t            segment_limits[6];

    uint16_t            destination_segment;

    union {
        uint8_t     *dst_byte;
        uint16_t    *dst_word;
        uint32_t    *dst_long;
    };

    union {
        uint8_t     *src_byte;
        uint16_t    *src_word;
        uint32_t    *src_long;
    };

    union {
        uint8_t     _byte;
        uint32_t    _long;
        uint16_t    _word;
    } dest_value;

    union {
        uint8_t     _byte;
        uint32_t    _long;
        uint16_t    _short;
    } src_value;

    uint32_t        data_segment;
    uint32_t        data_type;

    bool            lock_prefix_active;
    bool            opaddr_prefix_active;
    bool            opsize_prefix_active;
    bool            repeat_prefix_active;
    bool            segment_prefix_active;
    uint8_t         repeat_zflag;

    uint32_t        register_offset;
    uint32_t        compute_offset;

    /* processor flags */
    union {
        uint8_t ah_flags;
        uint16_t flags;
        uint32_t all_flags;
        struct {
            uint32_t CF : 1;
            uint32_t MBO : 1;
            uint32_t PF : 1;
            uint32_t SBZ0 : 1;
            uint32_t AF : 1;
            uint32_t SBZ1 : 1;
            uint32_t ZF : 1;
            uint32_t TF : 1;
            uint32_t IF : 1;
            uint32_t DF : 1;
            uint32_t OF : 1;
            uint32_t IOPL : 1;
            uint32_t NT : 1;
            uint32_t SBZ2 : 1;
            uint32_t RF : 1;
            uint32_t VM : 1;
            uint32_t AC : 1;
            uint32_t SBZ3 : 13;
        } eflags;
    };
    
    /* @TODO: xmmi, xmmi64, cr, dr, msrs */
} register_context_t;

/* EFLAGs definition */

extern register_context_t   emulation_context;  /* There can only be ONE of me. */

/*
 * The plan is to actually define a simple emulator that can be
 * extended by adding additional opcodes and processor features.
 *
 * The initial implementation will be incredibly simple.
 *
 * Remove this when the time comes.
 */

#endif
