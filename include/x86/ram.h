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

#ifndef hyperx86_ram_h
#define hyperx86_ram_h

#pragma once

#include <stdint.h>

#define _1kB    1024
#define _1MB    1024 * _1kB

#define RAM_SIZE    _1MB

typedef uint32_t    ram_addr_t;
extern  uint8_t     emulated_ram[RAM_SIZE];

extern uint8_t get_byte_from_ram __P((ram_addr_t addr));
extern uint16_t get_word_from_ram __P((ram_addr_t addr));
extern uint32_t get_long_from_ram __P((ram_addr_t addr));

extern void put_byte_to_ram __P((ram_addr_t addr, uint8_t c));
extern void put_word_to_ram __P((ram_addr_t addr, uint16_t c));
extern void put_long_to_ram __P((ram_addr_t addr, uint32_t c));

extern void ram_subsystem_initialize __P((void));
extern void ram_subsystem_verify_functionality __P((void));

#endif
