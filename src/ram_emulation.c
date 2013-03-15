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

uint8_t emulated_ram[RAM_SIZE];

uint8_t get_byte_from_ram(ram_addr_t addr)
{
    return *(uint8_t*)(emulated_ram + addr);
}

uint16_t get_word_from_ram(ram_addr_t addr)
{
    return *(uint16_t*)(emulated_ram + addr);
}

uint32_t get_long_from_ram(ram_addr_t addr)
{
    return *(uint32_t*)(emulated_ram + addr);
}

void put_byte_to_ram(ram_addr_t addr, uint8_t c)
{
    uint32_t    *ea;
    
    ea = (uint32_t*)(emulated_ram + addr);
    *ea = c;
    
    return;
}

void put_word_to_ram(ram_addr_t addr, uint16_t c)
{
    uint32_t    *ea;
    
    ea = (uint32_t*)(emulated_ram + addr);
    *ea = c;
    
    return;
}

void put_long_to_ram(ram_addr_t addr, uint32_t c)
{
    uint32_t    *ea;
    
    ea = (uint32_t*)(emulated_ram + addr);
    *ea = c;
    
    return;
}

void ram_subsystem_verify_functionality(void)
{
    uint32_t    _long;
    uint16_t    _short;
    uint8_t     _byte;

    put_long_to_ram(0x0, 0xdeadbeef);
    _long = get_long_from_ram(0x0);
    assert(_long == 0xdeadbeef);
    put_long_to_ram(0x0, 0x0);
    DPRINT("Passed LONG test.\n");
    
    put_word_to_ram(0x0, 0xbeef);
    _short = get_word_from_ram(0x0);
    assert(_short == 0xbeef);
    put_word_to_ram(0x0, 0x0);
    DPRINT("Passed WORD test.\n");
    
    put_byte_to_ram(0x0, 0xcc);
    _byte = get_byte_from_ram(0x0);
    assert(_byte == 0xcc);
    put_byte_to_ram(0x0, 0x0);
    DPRINT("Passed BYTE test.\n");
    
    return;
}

void ram_subsystem_initialize(void)
{
    bzero(emulated_ram, RAM_SIZE);
    
    DPRINT("Zeroed out %d bytes of RAM\n", RAM_SIZE);
    
    DPRINT("RAM base at %p\n", emulated_ram);
    
    return;
}

__END_DECLS
