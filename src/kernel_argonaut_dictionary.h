/*
 * Centaurean Density
 *
 * Copyright (c) 2015, Guillaume Voirin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Centaurean nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * 12/02/15 23:09
 *
 * ------------------
 * Argonaut algorithm
 * ------------------
 *
 * Author(s)
 * Guillaume Voirin (https://github.com/gpnuma)
 *
 * Description
 * Multiform compression algorithm
 */

#ifndef DENSITY_ARGONAUT_DICTIONARY_H
#define DENSITY_ARGONAUT_DICTIONARY_H

#include "globals.h"
#include "kernel_argonaut.h"

#include <string.h>

#pragma pack(push)
#pragma pack(4)
typedef struct {
    uint8_t letter;
    uint32_t usage;
    uint8_t rank;
} density_argonaut_dictionary_letter_entry;

typedef struct {
    uint32_t chunk_a;
    uint32_t chunk_b;
} density_argonaut_dictionary_chunk_entry;

typedef struct {
    uint32_t next_chunk_prediction;
} density_argonaut_dictionary_prediction_entry;

typedef struct {
    density_argonaut_dictionary_letter_entry letters[1 << 8];
    density_argonaut_dictionary_letter_entry *letterRanks[1 << 8];
    density_argonaut_dictionary_chunk_entry entries[1 << DENSITY_ARGONAUT_HASH_BITS];
    density_argonaut_dictionary_prediction_entry prediction_entries[1 << DENSITY_ARGONAUT_HASH_BITS];
} density_argonaut_dictionary;
#pragma pack(pop)

void density_argonaut_dictionary_reset(density_argonaut_dictionary *);

#endif