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

#define BIOS_BEGIN      0xFFFF0

register_context_t emulation_context;   /* There should only be one of me. */

void cpu_subsystem_initialize(void)
{
    /* set eip for bios begin */
    emulation_context.eip = BIOS_BEGIN;
    
    /* zero out the four main gprs */
    emulation_context.basic_registers[eax].exx = 0;
    emulation_context.basic_registers[ebx].exx = 0;
    emulation_context.basic_registers[ecx].exx = 0;
    emulation_context.basic_registers[edx].exx = 0;
    
    /* zero out bp, sp */
    emulation_context.basic_registers[ebp].exx = 0;
    emulation_context.basic_registers[esp].exx = 0;
    emulation_context.basic_registers[edi].exx = 0;
    emulation_context.basic_registers[esi].exx = 0;
    
    /* segment registers */
    emulation_context.segment_registers[cs] = 0;
    emulation_context.segment_registers[ds] = 0;
    emulation_context.segment_registers[es] = 0;
    emulation_context.segment_registers[fs] = 0;
    emulation_context.segment_registers[gs] = 0;
    emulation_context.segment_registers[ss] = 0;
    
    emulation_context.all_flags = 0;
}

void cpu_dump_registers(void)
{
    DPRINT("eax: 0x%08x   ebx: 0x%08x   ecx: 0x%08x   edx: 0x%08x\n",
           emulation_context.basic_registers[eax].exx,
           emulation_context.basic_registers[ebx].exx,
           emulation_context.basic_registers[ecx].exx,
           emulation_context.basic_registers[edx].exx);
    
    DPRINT("ebp: 0x%08x   esp: 0x%08x   edi: 0x%08x   esi: 0x%08x\n",
           emulation_context.basic_registers[ebp].exx,
           emulation_context.basic_registers[esp].exx,
           emulation_context.basic_registers[edi].exx,
           emulation_context.basic_registers[esi].exx);
    
    DPRINT("cs: 0x%04x   ds: 0x%04x   es: 0x%04x\n",
           emulation_context.segment_registers[cs],
           emulation_context.segment_registers[ds],
           emulation_context.segment_registers[es]);
    
    DPRINT("fs: 0x%04x   gs: 0x%04x   ss: 0x%04x\n",
           emulation_context.segment_registers[fs],
           emulation_context.segment_registers[gs],
           emulation_context.segment_registers[ss]);
    
    DPRINT("eip: 0x%08x    flags: 0x%04x\n",
           emulation_context.eip,
           emulation_context.all_flags);
    
    DPRINT("flagbits: %c%c%c%c%c%c%c%c%c%c%c\n",
           emulation_context.eflags.CF ? 'C' : '-',
           emulation_context.eflags.PF ? 'P' : '-',
           emulation_context.eflags.AF ? 'A' : '-',
           emulation_context.eflags.ZF ? 'Z' : '-',
           emulation_context.eflags.TF ? 'T' : '-',
           emulation_context.eflags.IF ? 'I' : '-',
           emulation_context.eflags.DF ? 'D' : '-',
           emulation_context.eflags.OF ? 'O' : '-',
           emulation_context.eflags.RF ? 'R' : '-',
           emulation_context.eflags.IOPL ? '1' : '-',
           emulation_context.eflags.NT ? '2' : '-');
}

__END_DECLS