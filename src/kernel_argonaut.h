/*
 * Centaurean libssc
 * http://www.libssc.net
 *
 * Copyright (c) 2013, Guillaume Voirin
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
 * 25/10/13 23:02
 */

#ifndef SHARC_ARGONAUT_H
#define SHARC_ARGONAUT_H

#include <stdint.h>

//#ifdef SHARC_ARGONAUT_POST_PROCESSING
#define SHARC_ARGONAUT_SUFFIX                                      post_processing
#define SHARC_ARGONAUT_ENCODE_PROCESS_LETTERS
//#else
//#define SSC_ARGONAUT_SUFFIX                                      default
//#endif

#define PASTER(x,y) x ## _ ## y
#define EVALUATOR(x,y)  PASTER(x,y)
#define ARGONAUT_NAME(function) EVALUATOR(function, SHARC_ARGONAUT_SUFFIX)

#define SHARC_ARGONAUT_HASH_BITS                            16
#define SHARC_ARGONAUT_HASH_OFFSET_BASIS                    (uint32_t)(2885564586)
#define SHARC_ARGONAUT_HASH_PRIME                           16777619

//typedef uint64_t                                            ssc_hash_signature;

typedef struct {
    uint_fast32_t code;
    uint_fast8_t bitSize;
} sharc_argonaut_huffman_code;

#endif