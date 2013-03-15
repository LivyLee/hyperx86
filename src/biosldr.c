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

void bios_load(const char* restrict filename)
{
    int fd, err;
    off_t size;
    struct stat buf;
    char *bios;
    
    fd = open(filename, O_RDONLY);
    if(fd <= -1) {
        char cwd[512];
        getcwd(cwd, 512);
        perror("open");
        DIE("Fatal error loading BIOS image from %s (cwd: %s)\n", filename, cwd);
    }
    
    err = stat(filename, &buf);
    if(err <= -1) {
        perror("stat");
        DIE("Fatal error during stat() of BIOS image\n");
    }
    
    size = buf.st_size;
    
    if(size > 65536) {
        DIE("Size of ROM image is WAY TOO LARGE BRO.\n");
    }
    
    bios = malloc(size);
    if(!bios) {
        DIE("Failed to allocate memory for bios\n");
    }
    
    bzero(bios, size);
    read(fd, bios, size);
    
    bcopy(bios, (void*)(emulated_ram + RAM_SIZE - size), size);

    free(bios);
    close(fd);
}

__END_DECLS