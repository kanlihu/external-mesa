/*
 * Copyright © 2018 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * on the rights to use, copy, modify, merge, publish, distribute, sub
 * license, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHOR(S) AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef IRIS_DEFINES_H
#define IRIS_DEFINES_H

/**
 * @file iris_defines.h
 *
 * Random hardware #defines that we're not using GENXML for.
 */

#define MI_PREDICATE                         (0xC << 23)
# define MI_PREDICATE_LOADOP_KEEP            (0 << 6)
# define MI_PREDICATE_LOADOP_LOAD            (2 << 6)
# define MI_PREDICATE_LOADOP_LOADINV         (3 << 6)
# define MI_PREDICATE_COMBINEOP_SET          (0 << 3)
# define MI_PREDICATE_COMBINEOP_AND          (1 << 3)
# define MI_PREDICATE_COMBINEOP_OR           (2 << 3)
# define MI_PREDICATE_COMBINEOP_XOR          (3 << 3)
# define MI_PREDICATE_COMPAREOP_TRUE         (0 << 0)
# define MI_PREDICATE_COMPAREOP_FALSE        (1 << 0)
# define MI_PREDICATE_COMPAREOP_SRCS_EQUAL   (2 << 0)
# define MI_PREDICATE_COMPAREOP_DELTAS_EQUAL (3 << 0)

/* Predicate registers */
#define MI_PREDICATE_SRC0                    0x2400
#define MI_PREDICATE_SRC1                    0x2408
#define MI_PREDICATE_DATA                    0x2410
#define MI_PREDICATE_RESULT                  0x2418
#define MI_PREDICATE_RESULT_1                0x241C
#define MI_PREDICATE_RESULT_2                0x2214

#define CS_GPR(n) (0x2600 + (n) * 8)

/* MI_MATH registers */
#define MI_ALU_R0        0x00
#define MI_ALU_R1        0x01
#define MI_ALU_R2        0x02
#define MI_ALU_R3        0x03
#define MI_ALU_R4        0x04

/* MI_MATH operations */
#define MI_MATH (0x1a << 23)

#define _MI_ALU(op, x, y)  (((op) << 20) | ((x) << 10) | (y))

#define _MI_ALU0(op)       _MI_ALU(MI_ALU_##op, 0, 0)
#define _MI_ALU1(op, x)    _MI_ALU(MI_ALU_##op, x, 0)
#define _MI_ALU2(op, x, y) _MI_ALU(MI_ALU_##op, x, y)

#define MI_ALU0(op)        _MI_ALU0(op)
#define MI_ALU1(op, x)     _MI_ALU1(op, MI_ALU_##x)
#define MI_ALU2(op, x, y)  _MI_ALU2(op, MI_ALU_##x, MI_ALU_##y)

/* The number of bits in our TIMESTAMP queries. */
#define TIMESTAMP_BITS 36

#endif