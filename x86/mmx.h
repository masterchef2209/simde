/* AUTOMATICALLY GENERATED FILE, DO NOT MODIFY */

/* :: Begin x86/mmx.h :: */
/* Copyright (c) 2017-2020 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#if !defined(SIMDE__MMX_H)
#  if !defined(SIMDE__MMX_H)
#    define SIMDE__MMX_H
#  endif
/* :: Begin simde-common.h :: */
/* Copyright (c) 2017-2019 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#if !defined(SIMDE_COMMON_H)
#define SIMDE_COMMON_H

/* :: Begin hedley.h :: */
/* Hedley - https://nemequ.github.io/hedley
 * Created by Evan Nemerson <evan@nemerson.com>
 *
 * To the extent possible under law, the author(s) have dedicated all
 * copyright and related and neighboring rights to this software to
 * the public domain worldwide. This software is distributed without
 * any warranty.
 *
 * For details, see <http://creativecommons.org/publicdomain/zero/1.0/>.
 * SPDX-License-Identifier: CC0-1.0
 */

#if !defined(HEDLEY_VERSION) || (HEDLEY_VERSION < 12)
#if defined(HEDLEY_VERSION)
#  undef HEDLEY_VERSION
#endif
#define HEDLEY_VERSION 12

#if defined(HEDLEY_STRINGIFY_EX)
#  undef HEDLEY_STRINGIFY_EX
#endif
#define HEDLEY_STRINGIFY_EX(x) #x

#if defined(HEDLEY_STRINGIFY)
#  undef HEDLEY_STRINGIFY
#endif
#define HEDLEY_STRINGIFY(x) HEDLEY_STRINGIFY_EX(x)

#if defined(HEDLEY_CONCAT_EX)
#  undef HEDLEY_CONCAT_EX
#endif
#define HEDLEY_CONCAT_EX(a,b) a##b

#if defined(HEDLEY_CONCAT)
#  undef HEDLEY_CONCAT
#endif
#define HEDLEY_CONCAT(a,b) HEDLEY_CONCAT_EX(a,b)

#if defined(HEDLEY_VERSION_ENCODE)
#  undef HEDLEY_VERSION_ENCODE
#endif
#define HEDLEY_VERSION_ENCODE(major,minor,revision) (((major) * 1000000) + ((minor) * 1000) + (revision))

#if defined(HEDLEY_VERSION_DECODE_MAJOR)
#  undef HEDLEY_VERSION_DECODE_MAJOR
#endif
#define HEDLEY_VERSION_DECODE_MAJOR(version) ((version) / 1000000)

#if defined(HEDLEY_VERSION_DECODE_MINOR)
#  undef HEDLEY_VERSION_DECODE_MINOR
#endif
#define HEDLEY_VERSION_DECODE_MINOR(version) (((version) % 1000000) / 1000)

#if defined(HEDLEY_VERSION_DECODE_REVISION)
#  undef HEDLEY_VERSION_DECODE_REVISION
#endif
#define HEDLEY_VERSION_DECODE_REVISION(version) ((version) % 1000)

#if defined(HEDLEY_GNUC_VERSION)
#  undef HEDLEY_GNUC_VERSION
#endif
#if defined(__GNUC__) && defined(__GNUC_PATCHLEVEL__)
#  define HEDLEY_GNUC_VERSION HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__GNUC__)
#  define HEDLEY_GNUC_VERSION HEDLEY_VERSION_ENCODE(__GNUC__, __GNUC_MINOR__, 0)
#endif

#if defined(HEDLEY_GNUC_VERSION_CHECK)
#  undef HEDLEY_GNUC_VERSION_CHECK
#endif
#if defined(HEDLEY_GNUC_VERSION)
#  define HEDLEY_GNUC_VERSION_CHECK(major,minor,patch) (HEDLEY_GNUC_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_GNUC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_MSVC_VERSION)
#  undef HEDLEY_MSVC_VERSION
#endif
#if defined(_MSC_FULL_VER) && (_MSC_FULL_VER >= 140000000)
#  define HEDLEY_MSVC_VERSION HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 100000, (_MSC_FULL_VER % 100000) / 100)
#elif defined(_MSC_FULL_VER)
#  define HEDLEY_MSVC_VERSION HEDLEY_VERSION_ENCODE(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, (_MSC_FULL_VER % 10000) / 10)
#elif defined(_MSC_VER)
#  define HEDLEY_MSVC_VERSION HEDLEY_VERSION_ENCODE(_MSC_VER / 100, _MSC_VER % 100, 0)
#endif

#if defined(HEDLEY_MSVC_VERSION_CHECK)
#  undef HEDLEY_MSVC_VERSION_CHECK
#endif
#if !defined(_MSC_VER)
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (0)
#elif defined(_MSC_VER) && (_MSC_VER >= 1400)
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 10000000) + (minor * 100000) + (patch)))
#elif defined(_MSC_VER) && (_MSC_VER >= 1200)
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_FULL_VER >= ((major * 1000000) + (minor * 10000) + (patch)))
#else
#  define HEDLEY_MSVC_VERSION_CHECK(major,minor,patch) (_MSC_VER >= ((major * 100) + (minor)))
#endif

#if defined(HEDLEY_INTEL_VERSION)
#  undef HEDLEY_INTEL_VERSION
#endif
#if defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE)
#  define HEDLEY_INTEL_VERSION HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, __INTEL_COMPILER_UPDATE)
#elif defined(__INTEL_COMPILER)
#  define HEDLEY_INTEL_VERSION HEDLEY_VERSION_ENCODE(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, 0)
#endif

#if defined(HEDLEY_INTEL_VERSION_CHECK)
#  undef HEDLEY_INTEL_VERSION_CHECK
#endif
#if defined(HEDLEY_INTEL_VERSION)
#  define HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (HEDLEY_INTEL_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_INTEL_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_PGI_VERSION)
#  undef HEDLEY_PGI_VERSION
#endif
#if defined(__PGI) && defined(__PGIC__) && defined(__PGIC_MINOR__) && defined(__PGIC_PATCHLEVEL__)
#  define HEDLEY_PGI_VERSION HEDLEY_VERSION_ENCODE(__PGIC__, __PGIC_MINOR__, __PGIC_PATCHLEVEL__)
#endif

#if defined(HEDLEY_PGI_VERSION_CHECK)
#  undef HEDLEY_PGI_VERSION_CHECK
#endif
#if defined(HEDLEY_PGI_VERSION)
#  define HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (HEDLEY_PGI_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_PGI_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_SUNPRO_VERSION)
#  undef HEDLEY_SUNPRO_VERSION
#endif
#if defined(__SUNPRO_C) && (__SUNPRO_C > 0x1000)
#  define HEDLEY_SUNPRO_VERSION HEDLEY_VERSION_ENCODE((((__SUNPRO_C >> 16) & 0xf) * 10) + ((__SUNPRO_C >> 12) & 0xf), (((__SUNPRO_C >> 8) & 0xf) * 10) + ((__SUNPRO_C >> 4) & 0xf), (__SUNPRO_C & 0xf) * 10)
#elif defined(__SUNPRO_C)
#  define HEDLEY_SUNPRO_VERSION HEDLEY_VERSION_ENCODE((__SUNPRO_C >> 8) & 0xf, (__SUNPRO_C >> 4) & 0xf, (__SUNPRO_C) & 0xf)
#elif defined(__SUNPRO_CC) && (__SUNPRO_CC > 0x1000)
#  define HEDLEY_SUNPRO_VERSION HEDLEY_VERSION_ENCODE((((__SUNPRO_CC >> 16) & 0xf) * 10) + ((__SUNPRO_CC >> 12) & 0xf), (((__SUNPRO_CC >> 8) & 0xf) * 10) + ((__SUNPRO_CC >> 4) & 0xf), (__SUNPRO_CC & 0xf) * 10)
#elif defined(__SUNPRO_CC)
#  define HEDLEY_SUNPRO_VERSION HEDLEY_VERSION_ENCODE((__SUNPRO_CC >> 8) & 0xf, (__SUNPRO_CC >> 4) & 0xf, (__SUNPRO_CC) & 0xf)
#endif

#if defined(HEDLEY_SUNPRO_VERSION_CHECK)
#  undef HEDLEY_SUNPRO_VERSION_CHECK
#endif
#if defined(HEDLEY_SUNPRO_VERSION)
#  define HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) (HEDLEY_SUNPRO_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_SUNPRO_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_EMSCRIPTEN_VERSION)
#  undef HEDLEY_EMSCRIPTEN_VERSION
#endif
#if defined(__EMSCRIPTEN__)
#  define HEDLEY_EMSCRIPTEN_VERSION HEDLEY_VERSION_ENCODE(__EMSCRIPTEN_major__, __EMSCRIPTEN_minor__, __EMSCRIPTEN_tiny__)
#endif

#if defined(HEDLEY_EMSCRIPTEN_VERSION_CHECK)
#  undef HEDLEY_EMSCRIPTEN_VERSION_CHECK
#endif
#if defined(HEDLEY_EMSCRIPTEN_VERSION)
#  define HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (HEDLEY_EMSCRIPTEN_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_EMSCRIPTEN_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_ARM_VERSION)
#  undef HEDLEY_ARM_VERSION
#endif
#if defined(__CC_ARM) && defined(__ARMCOMPILER_VERSION)
#  define HEDLEY_ARM_VERSION HEDLEY_VERSION_ENCODE(__ARMCOMPILER_VERSION / 1000000, (__ARMCOMPILER_VERSION % 1000000) / 10000, (__ARMCOMPILER_VERSION % 10000) / 100)
#elif defined(__CC_ARM) && defined(__ARMCC_VERSION)
#  define HEDLEY_ARM_VERSION HEDLEY_VERSION_ENCODE(__ARMCC_VERSION / 1000000, (__ARMCC_VERSION % 1000000) / 10000, (__ARMCC_VERSION % 10000) / 100)
#endif

#if defined(HEDLEY_ARM_VERSION_CHECK)
#  undef HEDLEY_ARM_VERSION_CHECK
#endif
#if defined(HEDLEY_ARM_VERSION)
#  define HEDLEY_ARM_VERSION_CHECK(major,minor,patch) (HEDLEY_ARM_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_ARM_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_IBM_VERSION)
#  undef HEDLEY_IBM_VERSION
#endif
#if defined(__ibmxl__)
#  define HEDLEY_IBM_VERSION HEDLEY_VERSION_ENCODE(__ibmxl_version__, __ibmxl_release__, __ibmxl_modification__)
#elif defined(__xlC__) && defined(__xlC_ver__)
#  define HEDLEY_IBM_VERSION HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, (__xlC_ver__ >> 8) & 0xff)
#elif defined(__xlC__)
#  define HEDLEY_IBM_VERSION HEDLEY_VERSION_ENCODE(__xlC__ >> 8, __xlC__ & 0xff, 0)
#endif

#if defined(HEDLEY_IBM_VERSION_CHECK)
#  undef HEDLEY_IBM_VERSION_CHECK
#endif
#if defined(HEDLEY_IBM_VERSION)
#  define HEDLEY_IBM_VERSION_CHECK(major,minor,patch) (HEDLEY_IBM_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_IBM_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TI_VERSION)
#  undef HEDLEY_TI_VERSION
#endif
#if \
    defined(__TI_COMPILER_VERSION__) && \
    ( \
      defined(__TMS470__) || defined(__TI_ARM__) || \
      defined(__MSP430__) || \
      defined(__TMS320C2000__) \
    )
#  if (__TI_COMPILER_VERSION__ >= 16000000)
#    define HEDLEY_TI_VERSION HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#  endif
#endif

#if defined(HEDLEY_TI_VERSION_CHECK)
#  undef HEDLEY_TI_VERSION_CHECK
#endif
#if defined(HEDLEY_TI_VERSION)
#  define HEDLEY_TI_VERSION_CHECK(major,minor,patch) (HEDLEY_TI_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TI_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TI_CL2000_VERSION)
#  undef HEDLEY_TI_CL2000_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__TMS320C2000__)
#  define HEDLEY_TI_CL2000_VERSION HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(HEDLEY_TI_CL2000_VERSION_CHECK)
#  undef HEDLEY_TI_CL2000_VERSION_CHECK
#endif
#if defined(HEDLEY_TI_CL2000_VERSION)
#  define HEDLEY_TI_CL2000_VERSION_CHECK(major,minor,patch) (HEDLEY_TI_CL2000_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TI_CL2000_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TI_CL430_VERSION)
#  undef HEDLEY_TI_CL430_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__MSP430__)
#  define HEDLEY_TI_CL430_VERSION HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(HEDLEY_TI_CL430_VERSION_CHECK)
#  undef HEDLEY_TI_CL430_VERSION_CHECK
#endif
#if defined(HEDLEY_TI_CL430_VERSION)
#  define HEDLEY_TI_CL430_VERSION_CHECK(major,minor,patch) (HEDLEY_TI_CL430_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TI_CL430_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TI_ARMCL_VERSION)
#  undef HEDLEY_TI_ARMCL_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && (defined(__TMS470__) || defined(__TI_ARM__))
#  define HEDLEY_TI_ARMCL_VERSION HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(HEDLEY_TI_ARMCL_VERSION_CHECK)
#  undef HEDLEY_TI_ARMCL_VERSION_CHECK
#endif
#if defined(HEDLEY_TI_ARMCL_VERSION)
#  define HEDLEY_TI_ARMCL_VERSION_CHECK(major,minor,patch) (HEDLEY_TI_ARMCL_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TI_ARMCL_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TI_CL6X_VERSION)
#  undef HEDLEY_TI_CL6X_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__TMS320C6X__)
#  define HEDLEY_TI_CL6X_VERSION HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(HEDLEY_TI_CL6X_VERSION_CHECK)
#  undef HEDLEY_TI_CL6X_VERSION_CHECK
#endif
#if defined(HEDLEY_TI_CL6X_VERSION)
#  define HEDLEY_TI_CL6X_VERSION_CHECK(major,minor,patch) (HEDLEY_TI_CL6X_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TI_CL6X_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TI_CL7X_VERSION)
#  undef HEDLEY_TI_CL7X_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__C7000__)
#  define HEDLEY_TI_CL7X_VERSION HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(HEDLEY_TI_CL7X_VERSION_CHECK)
#  undef HEDLEY_TI_CL7X_VERSION_CHECK
#endif
#if defined(HEDLEY_TI_CL7X_VERSION)
#  define HEDLEY_TI_CL7X_VERSION_CHECK(major,minor,patch) (HEDLEY_TI_CL7X_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TI_CL7X_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TI_CLPRU_VERSION)
#  undef HEDLEY_TI_CLPRU_VERSION
#endif
#if defined(__TI_COMPILER_VERSION__) && defined(__PRU__)
#  define HEDLEY_TI_CLPRU_VERSION HEDLEY_VERSION_ENCODE(__TI_COMPILER_VERSION__ / 1000000, (__TI_COMPILER_VERSION__ % 1000000) / 1000, (__TI_COMPILER_VERSION__ % 1000))
#endif

#if defined(HEDLEY_TI_CLPRU_VERSION_CHECK)
#  undef HEDLEY_TI_CLPRU_VERSION_CHECK
#endif
#if defined(HEDLEY_TI_CLPRU_VERSION)
#  define HEDLEY_TI_CLPRU_VERSION_CHECK(major,minor,patch) (HEDLEY_TI_CLPRU_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TI_CLPRU_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_CRAY_VERSION)
#  undef HEDLEY_CRAY_VERSION
#endif
#if defined(_CRAYC)
#  if defined(_RELEASE_PATCHLEVEL)
#    define HEDLEY_CRAY_VERSION HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, _RELEASE_PATCHLEVEL)
#  else
#    define HEDLEY_CRAY_VERSION HEDLEY_VERSION_ENCODE(_RELEASE_MAJOR, _RELEASE_MINOR, 0)
#  endif
#endif

#if defined(HEDLEY_CRAY_VERSION_CHECK)
#  undef HEDLEY_CRAY_VERSION_CHECK
#endif
#if defined(HEDLEY_CRAY_VERSION)
#  define HEDLEY_CRAY_VERSION_CHECK(major,minor,patch) (HEDLEY_CRAY_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_CRAY_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_IAR_VERSION)
#  undef HEDLEY_IAR_VERSION
#endif
#if defined(__IAR_SYSTEMS_ICC__)
#  if __VER__ > 1000
#    define HEDLEY_IAR_VERSION HEDLEY_VERSION_ENCODE((__VER__ / 1000000), ((__VER__ / 1000) % 1000), (__VER__ % 1000))
#  else
#    define HEDLEY_IAR_VERSION HEDLEY_VERSION_ENCODE(VER / 100, __VER__ % 100, 0)
#  endif
#endif

#if defined(HEDLEY_IAR_VERSION_CHECK)
#  undef HEDLEY_IAR_VERSION_CHECK
#endif
#if defined(HEDLEY_IAR_VERSION)
#  define HEDLEY_IAR_VERSION_CHECK(major,minor,patch) (HEDLEY_IAR_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_IAR_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_TINYC_VERSION)
#  undef HEDLEY_TINYC_VERSION
#endif
#if defined(__TINYC__)
#  define HEDLEY_TINYC_VERSION HEDLEY_VERSION_ENCODE(__TINYC__ / 1000, (__TINYC__ / 100) % 10, __TINYC__ % 100)
#endif

#if defined(HEDLEY_TINYC_VERSION_CHECK)
#  undef HEDLEY_TINYC_VERSION_CHECK
#endif
#if defined(HEDLEY_TINYC_VERSION)
#  define HEDLEY_TINYC_VERSION_CHECK(major,minor,patch) (HEDLEY_TINYC_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_TINYC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_DMC_VERSION)
#  undef HEDLEY_DMC_VERSION
#endif
#if defined(__DMC__)
#  define HEDLEY_DMC_VERSION HEDLEY_VERSION_ENCODE(__DMC__ >> 8, (__DMC__ >> 4) & 0xf, __DMC__ & 0xf)
#endif

#if defined(HEDLEY_DMC_VERSION_CHECK)
#  undef HEDLEY_DMC_VERSION_CHECK
#endif
#if defined(HEDLEY_DMC_VERSION)
#  define HEDLEY_DMC_VERSION_CHECK(major,minor,patch) (HEDLEY_DMC_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_DMC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_COMPCERT_VERSION)
#  undef HEDLEY_COMPCERT_VERSION
#endif
#if defined(__COMPCERT_VERSION__)
#  define HEDLEY_COMPCERT_VERSION HEDLEY_VERSION_ENCODE(__COMPCERT_VERSION__ / 10000, (__COMPCERT_VERSION__ / 100) % 100, __COMPCERT_VERSION__ % 100)
#endif

#if defined(HEDLEY_COMPCERT_VERSION_CHECK)
#  undef HEDLEY_COMPCERT_VERSION_CHECK
#endif
#if defined(HEDLEY_COMPCERT_VERSION)
#  define HEDLEY_COMPCERT_VERSION_CHECK(major,minor,patch) (HEDLEY_COMPCERT_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_COMPCERT_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_PELLES_VERSION)
#  undef HEDLEY_PELLES_VERSION
#endif
#if defined(__POCC__)
#  define HEDLEY_PELLES_VERSION HEDLEY_VERSION_ENCODE(__POCC__ / 100, __POCC__ % 100, 0)
#endif

#if defined(HEDLEY_PELLES_VERSION_CHECK)
#  undef HEDLEY_PELLES_VERSION_CHECK
#endif
#if defined(HEDLEY_PELLES_VERSION)
#  define HEDLEY_PELLES_VERSION_CHECK(major,minor,patch) (HEDLEY_PELLES_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_PELLES_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_GCC_VERSION)
#  undef HEDLEY_GCC_VERSION
#endif
#if \
  defined(HEDLEY_GNUC_VERSION) && \
  !defined(__clang__) && \
  !defined(HEDLEY_INTEL_VERSION) && \
  !defined(HEDLEY_PGI_VERSION) && \
  !defined(HEDLEY_ARM_VERSION) && \
  !defined(HEDLEY_TI_VERSION) && \
  !defined(HEDLEY_TI_ARMCL_VERSION) && \
  !defined(HEDLEY_TI_CL430_VERSION) && \
  !defined(HEDLEY_TI_CL2000_VERSION) && \
  !defined(HEDLEY_TI_CL6X_VERSION) && \
  !defined(HEDLEY_TI_CL7X_VERSION) && \
  !defined(HEDLEY_TI_CLPRU_VERSION) && \
  !defined(__COMPCERT__)
#  define HEDLEY_GCC_VERSION HEDLEY_GNUC_VERSION
#endif

#if defined(HEDLEY_GCC_VERSION_CHECK)
#  undef HEDLEY_GCC_VERSION_CHECK
#endif
#if defined(HEDLEY_GCC_VERSION)
#  define HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (HEDLEY_GCC_VERSION >= HEDLEY_VERSION_ENCODE(major, minor, patch))
#else
#  define HEDLEY_GCC_VERSION_CHECK(major,minor,patch) (0)
#endif

#if defined(HEDLEY_HAS_ATTRIBUTE)
#  undef HEDLEY_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#  define HEDLEY_HAS_ATTRIBUTE(attribute) __has_attribute(attribute)
#else
#  define HEDLEY_HAS_ATTRIBUTE(attribute) (0)
#endif

#if defined(HEDLEY_GNUC_HAS_ATTRIBUTE)
#  undef HEDLEY_GNUC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#  define HEDLEY_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) __has_attribute(attribute)
#else
#  define HEDLEY_GNUC_HAS_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_GCC_HAS_ATTRIBUTE)
#  undef HEDLEY_GCC_HAS_ATTRIBUTE
#endif
#if defined(__has_attribute)
#  define HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) __has_attribute(attribute)
#else
#  define HEDLEY_GCC_HAS_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_HAS_CPP_ATTRIBUTE)
#  undef HEDLEY_HAS_CPP_ATTRIBUTE
#endif
#if \
  defined(__has_cpp_attribute) && \
  defined(__cplusplus) && \
  (!defined(HEDLEY_SUNPRO_VERSION) || HEDLEY_SUNPRO_VERSION_CHECK(5,15,0))
#  define HEDLEY_HAS_CPP_ATTRIBUTE(attribute) __has_cpp_attribute(attribute)
#else
#  define HEDLEY_HAS_CPP_ATTRIBUTE(attribute) (0)
#endif

#if defined(HEDLEY_HAS_CPP_ATTRIBUTE_NS)
#  undef HEDLEY_HAS_CPP_ATTRIBUTE_NS
#endif
#if !defined(__cplusplus) || !defined(__has_cpp_attribute)
#  define HEDLEY_HAS_CPP_ATTRIBUTE_NS(ns,attribute) (0)
#elif \
  !defined(HEDLEY_PGI_VERSION) && \
  !defined(HEDLEY_IAR_VERSION) && \
  (!defined(HEDLEY_SUNPRO_VERSION) || HEDLEY_SUNPRO_VERSION_CHECK(5,15,0)) && \
  (!defined(HEDLEY_MSVC_VERSION) || HEDLEY_MSVC_VERSION_CHECK(19,20,0))
#  define HEDLEY_HAS_CPP_ATTRIBUTE_NS(ns,attribute) HEDLEY_HAS_CPP_ATTRIBUTE(ns::attribute)
#else
#  define HEDLEY_HAS_CPP_ATTRIBUTE_NS(ns,attribute) (0)
#endif

#if defined(HEDLEY_GNUC_HAS_CPP_ATTRIBUTE)
#  undef HEDLEY_GNUC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
#  define HEDLEY_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
#  define HEDLEY_GNUC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_GCC_HAS_CPP_ATTRIBUTE)
#  undef HEDLEY_GCC_HAS_CPP_ATTRIBUTE
#endif
#if defined(__has_cpp_attribute) && defined(__cplusplus)
#  define HEDLEY_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) __has_cpp_attribute(attribute)
#else
#  define HEDLEY_GCC_HAS_CPP_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_HAS_BUILTIN)
#  undef HEDLEY_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#  define HEDLEY_HAS_BUILTIN(builtin) __has_builtin(builtin)
#else
#  define HEDLEY_HAS_BUILTIN(builtin) (0)
#endif

#if defined(HEDLEY_GNUC_HAS_BUILTIN)
#  undef HEDLEY_GNUC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#  define HEDLEY_GNUC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
#  define HEDLEY_GNUC_HAS_BUILTIN(builtin,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_GCC_HAS_BUILTIN)
#  undef HEDLEY_GCC_HAS_BUILTIN
#endif
#if defined(__has_builtin)
#  define HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) __has_builtin(builtin)
#else
#  define HEDLEY_GCC_HAS_BUILTIN(builtin,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_HAS_FEATURE)
#  undef HEDLEY_HAS_FEATURE
#endif
#if defined(__has_feature)
#  define HEDLEY_HAS_FEATURE(feature) __has_feature(feature)
#else
#  define HEDLEY_HAS_FEATURE(feature) (0)
#endif

#if defined(HEDLEY_GNUC_HAS_FEATURE)
#  undef HEDLEY_GNUC_HAS_FEATURE
#endif
#if defined(__has_feature)
#  define HEDLEY_GNUC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
#  define HEDLEY_GNUC_HAS_FEATURE(feature,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_GCC_HAS_FEATURE)
#  undef HEDLEY_GCC_HAS_FEATURE
#endif
#if defined(__has_feature)
#  define HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) __has_feature(feature)
#else
#  define HEDLEY_GCC_HAS_FEATURE(feature,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_HAS_EXTENSION)
#  undef HEDLEY_HAS_EXTENSION
#endif
#if defined(__has_extension)
#  define HEDLEY_HAS_EXTENSION(extension) __has_extension(extension)
#else
#  define HEDLEY_HAS_EXTENSION(extension) (0)
#endif

#if defined(HEDLEY_GNUC_HAS_EXTENSION)
#  undef HEDLEY_GNUC_HAS_EXTENSION
#endif
#if defined(__has_extension)
#  define HEDLEY_GNUC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
#  define HEDLEY_GNUC_HAS_EXTENSION(extension,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_GCC_HAS_EXTENSION)
#  undef HEDLEY_GCC_HAS_EXTENSION
#endif
#if defined(__has_extension)
#  define HEDLEY_GCC_HAS_EXTENSION(extension,major,minor,patch) __has_extension(extension)
#else
#  define HEDLEY_GCC_HAS_EXTENSION(extension,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_HAS_DECLSPEC_ATTRIBUTE)
#  undef HEDLEY_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#  define HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute) __has_declspec_attribute(attribute)
#else
#  define HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute) (0)
#endif

#if defined(HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE)
#  undef HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#  define HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
#  define HEDLEY_GNUC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE)
#  undef HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE
#endif
#if defined(__has_declspec_attribute)
#  define HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) __has_declspec_attribute(attribute)
#else
#  define HEDLEY_GCC_HAS_DECLSPEC_ATTRIBUTE(attribute,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_HAS_WARNING)
#  undef HEDLEY_HAS_WARNING
#endif
#if defined(__has_warning)
#  define HEDLEY_HAS_WARNING(warning) __has_warning(warning)
#else
#  define HEDLEY_HAS_WARNING(warning) (0)
#endif

#if defined(HEDLEY_GNUC_HAS_WARNING)
#  undef HEDLEY_GNUC_HAS_WARNING
#endif
#if defined(__has_warning)
#  define HEDLEY_GNUC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
#  define HEDLEY_GNUC_HAS_WARNING(warning,major,minor,patch) HEDLEY_GNUC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_GCC_HAS_WARNING)
#  undef HEDLEY_GCC_HAS_WARNING
#endif
#if defined(__has_warning)
#  define HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) __has_warning(warning)
#else
#  define HEDLEY_GCC_HAS_WARNING(warning,major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

/* HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_ is for
   HEDLEY INTERNAL USE ONLY.  API subject to change without notice. */
#if defined(HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_)
#  undef HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_
#endif
#if defined(__cplusplus)
#  if HEDLEY_HAS_WARNING("-Wc++98-compat")
#    if HEDLEY_HAS_WARNING("-Wc++17-extensions")
#      define HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
         HEDLEY_DIAGNOSTIC_PUSH \
         _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
         _Pragma("clang diagnostic ignored \"-Wc++17-extensions\"") \
         xpr \
         HEDLEY_DIAGNOSTIC_POP
#    else
#      define HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(xpr) \
         HEDLEY_DIAGNOSTIC_PUSH \
         _Pragma("clang diagnostic ignored \"-Wc++98-compat\"") \
         xpr \
         HEDLEY_DIAGNOSTIC_POP
#    endif
#  endif
#endif
#if !defined(HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_)
#  define HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(x) x
#endif

#if defined(HEDLEY_CONST_CAST)
#  undef HEDLEY_CONST_CAST
#endif
#if defined(__cplusplus)
#  define HEDLEY_CONST_CAST(T, expr) (const_cast<T>(expr))
#elif \
  HEDLEY_HAS_WARNING("-Wcast-qual") || \
  HEDLEY_GCC_VERSION_CHECK(4,6,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_CONST_CAST(T, expr) (__extension__ ({ \
      HEDLEY_DIAGNOSTIC_PUSH \
      HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL \
      ((T) (expr)); \
      HEDLEY_DIAGNOSTIC_POP \
    }))
#else
#  define HEDLEY_CONST_CAST(T, expr) ((T) (expr))
#endif

#if defined(HEDLEY_REINTERPRET_CAST)
#  undef HEDLEY_REINTERPRET_CAST
#endif
#if defined(__cplusplus)
#  define HEDLEY_REINTERPRET_CAST(T, expr) (reinterpret_cast<T>(expr))
#else
#  define HEDLEY_REINTERPRET_CAST(T, expr) ((T) (expr))
#endif

#if defined(HEDLEY_STATIC_CAST)
#  undef HEDLEY_STATIC_CAST
#endif
#if defined(__cplusplus)
#  define HEDLEY_STATIC_CAST(T, expr) (static_cast<T>(expr))
#else
#  define HEDLEY_STATIC_CAST(T, expr) ((T) (expr))
#endif

#if defined(HEDLEY_CPP_CAST)
#  undef HEDLEY_CPP_CAST
#endif
#if defined(__cplusplus)
#  if HEDLEY_HAS_WARNING("-Wold-style-cast")
#    define HEDLEY_CPP_CAST(T, expr) \
       HEDLEY_DIAGNOSTIC_PUSH \
       _Pragma("clang diagnostic ignored \"-Wold-style-cast\"") \
       ((T) (expr)) \
       HEDLEY_DIAGNOSTIC_POP
#  elif HEDLEY_IAR_VERSION_CHECK(8,3,0)
#    define HEDLEY_CPP_CAST(T, expr) \
       HEDLEY_DIAGNOSTIC_PUSH \
       _Pragma("diag_suppress=Pe137") \
       HEDLEY_DIAGNOSTIC_POP \
#  else
#    define HEDLEY_CPP_CAST(T, expr) ((T) (expr))
#  endif
#else
#  define HEDLEY_CPP_CAST(T, expr) (expr)
#endif

#if \
  (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
  defined(__clang__) || \
  HEDLEY_GCC_VERSION_CHECK(3,0,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_IAR_VERSION_CHECK(8,0,0) || \
  HEDLEY_PGI_VERSION_CHECK(18,4,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(4,7,0) || \
  HEDLEY_TI_CL430_VERSION_CHECK(2,0,1) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,1,0) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,0,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  HEDLEY_CRAY_VERSION_CHECK(5,0,0) || \
  HEDLEY_TINYC_VERSION_CHECK(0,9,17) || \
  HEDLEY_SUNPRO_VERSION_CHECK(8,0,0) || \
  (HEDLEY_IBM_VERSION_CHECK(10,1,0) && defined(__C99_PRAGMA_OPERATOR))
#  define HEDLEY_PRAGMA(value) _Pragma(#value)
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_PRAGMA(value) __pragma(value)
#else
#  define HEDLEY_PRAGMA(value)
#endif

#if defined(HEDLEY_DIAGNOSTIC_PUSH)
#  undef HEDLEY_DIAGNOSTIC_PUSH
#endif
#if defined(HEDLEY_DIAGNOSTIC_POP)
#  undef HEDLEY_DIAGNOSTIC_POP
#endif
#if defined(__clang__)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
#elif HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("warning(push)")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("warning(pop)")
#elif HEDLEY_GCC_VERSION_CHECK(4,6,0)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_DIAGNOSTIC_PUSH __pragma(warning(push))
#  define HEDLEY_DIAGNOSTIC_POP __pragma(warning(pop))
#elif HEDLEY_ARM_VERSION_CHECK(5,6,0)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("push")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("pop")
#elif \
    HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    HEDLEY_TI_CL430_VERSION_CHECK(4,4,0) || \
    HEDLEY_TI_CL6X_VERSION_CHECK(8,1,0) || \
    HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("diag_push")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("diag_pop")
#elif HEDLEY_PELLES_VERSION_CHECK(2,90,0)
#  define HEDLEY_DIAGNOSTIC_PUSH _Pragma("warning(push)")
#  define HEDLEY_DIAGNOSTIC_POP _Pragma("warning(pop)")
#else
#  define HEDLEY_DIAGNOSTIC_PUSH
#  define HEDLEY_DIAGNOSTIC_POP
#endif

#if defined(HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED)
#  undef HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif
#if HEDLEY_HAS_WARNING("-Wdeprecated-declarations")
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
#elif HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warning(disable:1478 1786)")
#elif HEDLEY_PGI_VERSION_CHECK(17,10,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1215,1444")
#elif HEDLEY_GCC_VERSION_CHECK(4,3,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED __pragma(warning(disable:4996))
#elif \
    HEDLEY_TI_VERSION_CHECK(15,12,0) || \
    (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
    (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
    (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
    (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
    HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
    HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress 1291,1718")
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) && !defined(__cplusplus)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,E_DEPRECATED_ATT,E_DEPRECATED_ATT_MESS)")
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) && defined(__cplusplus)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("error_messages(off,symdeprecated,symdeprecated2)")
#elif HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("diag_suppress=Pe1444,Pe1215")
#elif HEDLEY_PELLES_VERSION_CHECK(2,90,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED _Pragma("warn(disable:2241)")
#else
#  define HEDLEY_DIAGNOSTIC_DISABLE_DEPRECATED
#endif

#if defined(HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS)
#  undef HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif
#if HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("clang diagnostic ignored \"-Wunknown-pragmas\"")
#elif HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("warning(disable:161)")
#elif HEDLEY_PGI_VERSION_CHECK(17,10,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 1675")
#elif HEDLEY_GCC_VERSION_CHECK(4,3,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("GCC diagnostic ignored \"-Wunknown-pragmas\"")
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS __pragma(warning(disable:4068))
#elif \
    HEDLEY_TI_VERSION_CHECK(16,9,0) || \
    HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0) || \
    HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
    HEDLEY_TI_CLPRU_VERSION_CHECK(2,3,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 163")
#elif HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress 163")
#elif HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS _Pragma("diag_suppress=Pe161")
#else
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS
#endif

#if defined(HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES)
#  undef HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES
#endif
#if HEDLEY_HAS_WARNING("-Wunknown-attributes")
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("clang diagnostic ignored \"-Wunknown-attributes\"")
#elif HEDLEY_GCC_VERSION_CHECK(4,6,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#elif HEDLEY_INTEL_VERSION_CHECK(17,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("warning(disable:1292)")
#elif HEDLEY_MSVC_VERSION_CHECK(19,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES __pragma(warning(disable:5030))
#elif HEDLEY_PGI_VERSION_CHECK(17,10,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1097")
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("error_messages(off,attrskipunsup)")
#elif \
    HEDLEY_TI_VERSION_CHECK(18,1,0) || \
    HEDLEY_TI_CL6X_VERSION_CHECK(8,3,0) || \
    HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress 1173")
#elif HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES _Pragma("diag_suppress=Pe1097")
#else
#  define HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_CPP_ATTRIBUTES
#endif

#if defined(HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL)
#  undef HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif
#if HEDLEY_HAS_WARNING("-Wcast-qual")
#  define HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("clang diagnostic ignored \"-Wcast-qual\"")
#elif HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("warning(disable:2203 2331)")
#elif HEDLEY_GCC_VERSION_CHECK(3,0,0)
#  define HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL _Pragma("GCC diagnostic ignored \"-Wcast-qual\"")
#else
#  define HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL
#endif

#if defined(HEDLEY_DEPRECATED)
#  undef HEDLEY_DEPRECATED
#endif
#if defined(HEDLEY_DEPRECATED_FOR)
#  undef HEDLEY_DEPRECATED_FOR
#endif
#if defined(__cplusplus) && (__cplusplus >= 201402L)
#  define HEDLEY_DEPRECATED(since) HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[deprecated("Since " #since)]])
#  define HEDLEY_DEPRECATED_FOR(since, replacement) HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[deprecated("Since " #since "; use " #replacement)]])
#elif \
  HEDLEY_HAS_EXTENSION(attribute_deprecated_with_message) || \
  HEDLEY_GCC_VERSION_CHECK(4,5,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_ARM_VERSION_CHECK(5,6,0) || \
  HEDLEY_SUNPRO_VERSION_CHECK(5,13,0) || \
  HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
  HEDLEY_TI_VERSION_CHECK(18,1,0) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(18,1,0) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(8,3,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,3,0)
#  define HEDLEY_DEPRECATED(since) __attribute__((__deprecated__("Since " #since)))
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__("Since " #since "; use " #replacement)))
#elif \
  HEDLEY_HAS_ATTRIBUTE(deprecated) || \
  HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_DEPRECATED(since) __attribute__((__deprecated__))
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __attribute__((__deprecated__))
#elif HEDLEY_MSVC_VERSION_CHECK(14,0,0)
#  define HEDLEY_DEPRECATED(since) __declspec(deprecated("Since " # since))
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated("Since " #since "; use " #replacement))
#elif \
  HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
  HEDLEY_PELLES_VERSION_CHECK(6,50,0)
#  define HEDLEY_DEPRECATED(since) __declspec(deprecated)
#  define HEDLEY_DEPRECATED_FOR(since, replacement) __declspec(deprecated)
#elif HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_DEPRECATED(since) _Pragma("deprecated")
#  define HEDLEY_DEPRECATED_FOR(since, replacement) _Pragma("deprecated")
#else
#  define HEDLEY_DEPRECATED(since)
#  define HEDLEY_DEPRECATED_FOR(since, replacement)
#endif

#if defined(HEDLEY_UNAVAILABLE)
#  undef HEDLEY_UNAVAILABLE
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(warning) || \
  HEDLEY_GCC_VERSION_CHECK(4,3,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_UNAVAILABLE(available_since) __attribute__((__warning__("Not available until " #available_since)))
#else
#  define HEDLEY_UNAVAILABLE(available_since)
#endif

#if defined(HEDLEY_WARN_UNUSED_RESULT)
#  undef HEDLEY_WARN_UNUSED_RESULT
#endif
#if defined(HEDLEY_WARN_UNUSED_RESULT_MSG)
#  undef HEDLEY_WARN_UNUSED_RESULT_MSG
#endif
#if (HEDLEY_HAS_CPP_ATTRIBUTE(nodiscard) >= 201907L)
#  define HEDLEY_WARN_UNUSED_RESULT HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
#  define HEDLEY_WARN_UNUSED_RESULT_MSG(msg) HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard(msg)]])
#elif HEDLEY_HAS_CPP_ATTRIBUTE(nodiscard)
#  define HEDLEY_WARN_UNUSED_RESULT HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
#  define HEDLEY_WARN_UNUSED_RESULT_MSG(msg) HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[nodiscard]])
#elif \
  HEDLEY_HAS_ATTRIBUTE(warn_unused_result) || \
  HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  (HEDLEY_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
  HEDLEY_PGI_VERSION_CHECK(17,10,0)
#  define HEDLEY_WARN_UNUSED_RESULT __attribute__((__warn_unused_result__))
#  define HEDLEY_WARN_UNUSED_RESULT_MSG(msg) __attribute__((__warn_unused_result__))
#elif defined(_Check_return_) /* SAL */
#  define HEDLEY_WARN_UNUSED_RESULT _Check_return_
#  define HEDLEY_WARN_UNUSED_RESULT_MSG(msg) _Check_return_
#else
#  define HEDLEY_WARN_UNUSED_RESULT
#  define HEDLEY_WARN_UNUSED_RESULT_MSG(msg)
#endif

#if defined(HEDLEY_SENTINEL)
#  undef HEDLEY_SENTINEL
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(sentinel) || \
  HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_ARM_VERSION_CHECK(5,4,0)
#  define HEDLEY_SENTINEL(position) __attribute__((__sentinel__(position)))
#else
#  define HEDLEY_SENTINEL(position)
#endif

#if defined(HEDLEY_NO_RETURN)
#  undef HEDLEY_NO_RETURN
#endif
#if HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_NO_RETURN __noreturn
#elif HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_NO_RETURN __attribute__((__noreturn__))
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#  define HEDLEY_NO_RETURN _Noreturn
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
#  define HEDLEY_NO_RETURN HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[noreturn]])
#elif \
  HEDLEY_HAS_ATTRIBUTE(noreturn) || \
  HEDLEY_GCC_VERSION_CHECK(3,2,0) || \
  HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_NO_RETURN __attribute__((__noreturn__))
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
#  define HEDLEY_NO_RETURN _Pragma("does_not_return")
#elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#  define HEDLEY_NO_RETURN __declspec(noreturn)
#elif HEDLEY_TI_CL6X_VERSION_CHECK(6,0,0) && defined(__cplusplus)
#  define HEDLEY_NO_RETURN _Pragma("FUNC_NEVER_RETURNS;")
#elif HEDLEY_COMPCERT_VERSION_CHECK(3,2,0)
#  define HEDLEY_NO_RETURN __attribute((noreturn))
#elif HEDLEY_PELLES_VERSION_CHECK(9,0,0)
#  define HEDLEY_NO_RETURN __declspec(noreturn)
#else
#  define HEDLEY_NO_RETURN
#endif

#if defined(HEDLEY_NO_ESCAPE)
#  undef HEDLEY_NO_ESCAPE
#endif
#if HEDLEY_HAS_ATTRIBUTE(noescape)
#  define HEDLEY_NO_ESCAPE __attribute__((__noescape__))
#else
#  define HEDLEY_NO_ESCAPE
#endif

#if defined(HEDLEY_UNREACHABLE)
#  undef HEDLEY_UNREACHABLE
#endif
#if defined(HEDLEY_UNREACHABLE_RETURN)
#  undef HEDLEY_UNREACHABLE_RETURN
#endif
#if defined(HEDLEY_ASSUME)
#  undef HEDLEY_ASSUME
#endif
#if \
  HEDLEY_MSVC_VERSION_CHECK(13,10,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_ASSUME(expr) __assume(expr)
#elif HEDLEY_HAS_BUILTIN(__builtin_assume)
#  define HEDLEY_ASSUME(expr) __builtin_assume(expr)
#elif \
    HEDLEY_TI_CL2000_VERSION_CHECK(6,2,0) || \
    HEDLEY_TI_CL6X_VERSION_CHECK(4,0,0)
#  if defined(__cplusplus)
#    define HEDLEY_ASSUME(expr) std::_nassert(expr)
#  else
#    define HEDLEY_ASSUME(expr) _nassert(expr)
#  endif
#endif
#if \
  (HEDLEY_HAS_BUILTIN(__builtin_unreachable) && (!defined(HEDLEY_ARM_VERSION))) || \
  HEDLEY_GCC_VERSION_CHECK(4,5,0) || \
  HEDLEY_PGI_VERSION_CHECK(18,10,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_IBM_VERSION_CHECK(13,1,5)
#  define HEDLEY_UNREACHABLE() __builtin_unreachable()
#elif defined(HEDLEY_ASSUME)
#  define HEDLEY_UNREACHABLE() HEDLEY_ASSUME(0)
#endif
#if !defined(HEDLEY_ASSUME)
#  if defined(HEDLEY_UNREACHABLE)
#    define HEDLEY_ASSUME(expr) HEDLEY_STATIC_CAST(void, ((expr) ? 1 : (HEDLEY_UNREACHABLE(), 1)))
#  else
#    define HEDLEY_ASSUME(expr) HEDLEY_STATIC_CAST(void, expr)
#  endif
#endif
#if defined(HEDLEY_UNREACHABLE)
#  if  \
      HEDLEY_TI_CL2000_VERSION_CHECK(6,2,0) || \
      HEDLEY_TI_CL6X_VERSION_CHECK(4,0,0)
#    define HEDLEY_UNREACHABLE_RETURN(value) return (HEDLEY_STATIC_CAST(void, HEDLEY_ASSUME(0)), (value))
#  else
#    define HEDLEY_UNREACHABLE_RETURN(value) HEDLEY_UNREACHABLE()
#  endif
#else
#  define HEDLEY_UNREACHABLE_RETURN(value) return (value)
#endif
#if !defined(HEDLEY_UNREACHABLE)
#  define HEDLEY_UNREACHABLE() HEDLEY_ASSUME(0)
#endif

HEDLEY_DIAGNOSTIC_PUSH
#if HEDLEY_HAS_WARNING("-Wpedantic")
#  pragma clang diagnostic ignored "-Wpedantic"
#endif
#if HEDLEY_HAS_WARNING("-Wc++98-compat-pedantic") && defined(__cplusplus)
#  pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#if HEDLEY_GCC_HAS_WARNING("-Wvariadic-macros",4,0,0)
#  if defined(__clang__)
#    pragma clang diagnostic ignored "-Wvariadic-macros"
#  elif defined(HEDLEY_GCC_VERSION)
#    pragma GCC diagnostic ignored "-Wvariadic-macros"
#  endif
#endif
#if defined(HEDLEY_NON_NULL)
#  undef HEDLEY_NON_NULL
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(nonnull) || \
  HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0)
#  define HEDLEY_NON_NULL(...) __attribute__((__nonnull__(__VA_ARGS__)))
#else
#  define HEDLEY_NON_NULL(...)
#endif
HEDLEY_DIAGNOSTIC_POP

#if defined(HEDLEY_PRINTF_FORMAT)
#  undef HEDLEY_PRINTF_FORMAT
#endif
#if defined(__MINGW32__) && HEDLEY_GCC_HAS_ATTRIBUTE(format,4,4,0) && !defined(__USE_MINGW_ANSI_STDIO)
#  define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(ms_printf, string_idx, first_to_check)))
#elif defined(__MINGW32__) && HEDLEY_GCC_HAS_ATTRIBUTE(format,4,4,0) && defined(__USE_MINGW_ANSI_STDIO)
#  define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(gnu_printf, string_idx, first_to_check)))
#elif \
  HEDLEY_HAS_ATTRIBUTE(format) || \
  HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_ARM_VERSION_CHECK(5,6,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __attribute__((__format__(__printf__, string_idx, first_to_check)))
#elif HEDLEY_PELLES_VERSION_CHECK(6,0,0)
#  define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check) __declspec(vaformat(printf,string_idx,first_to_check))
#else
#  define HEDLEY_PRINTF_FORMAT(string_idx,first_to_check)
#endif

#if defined(HEDLEY_CONSTEXPR)
#  undef HEDLEY_CONSTEXPR
#endif
#if defined(__cplusplus)
#  if __cplusplus >= 201103L
#    define HEDLEY_CONSTEXPR HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(constexpr)
#  endif
#endif
#if !defined(HEDLEY_CONSTEXPR)
#  define HEDLEY_CONSTEXPR
#endif

#if defined(HEDLEY_PREDICT)
#  undef HEDLEY_PREDICT
#endif
#if defined(HEDLEY_LIKELY)
#  undef HEDLEY_LIKELY
#endif
#if defined(HEDLEY_UNLIKELY)
#  undef HEDLEY_UNLIKELY
#endif
#if defined(HEDLEY_UNPREDICTABLE)
#  undef HEDLEY_UNPREDICTABLE
#endif
#if HEDLEY_HAS_BUILTIN(__builtin_unpredictable)
#  define HEDLEY_UNPREDICTABLE(expr) __builtin_unpredictable((expr))
#endif
#if \
  HEDLEY_HAS_BUILTIN(__builtin_expect_with_probability) || \
  HEDLEY_GCC_VERSION_CHECK(9,0,0)
#  define HEDLEY_PREDICT(expr, value, probability) __builtin_expect_with_probability(  (expr), (value), (probability))
#  define HEDLEY_PREDICT_TRUE(expr, probability)   __builtin_expect_with_probability(!!(expr),    1   , (probability))
#  define HEDLEY_PREDICT_FALSE(expr, probability)  __builtin_expect_with_probability(!!(expr),    0   , (probability))
#  define HEDLEY_LIKELY(expr)                      __builtin_expect                 (!!(expr),    1                  )
#  define HEDLEY_UNLIKELY(expr)                    __builtin_expect                 (!!(expr),    0                  )
#elif \
  HEDLEY_HAS_BUILTIN(__builtin_expect) || \
  HEDLEY_GCC_VERSION_CHECK(3,0,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  (HEDLEY_SUNPRO_VERSION_CHECK(5,15,0) && defined(__cplusplus)) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(4,7,0) || \
  HEDLEY_TI_CL430_VERSION_CHECK(3,1,0) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,1,0) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(6,1,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  HEDLEY_TINYC_VERSION_CHECK(0,9,27) || \
  HEDLEY_CRAY_VERSION_CHECK(8,1,0)
#  define HEDLEY_PREDICT(expr, expected, probability) \
     (((probability) >= 0.9) ? __builtin_expect((expr), (expected)) : (HEDLEY_STATIC_CAST(void, expected), (expr)))
#  define HEDLEY_PREDICT_TRUE(expr, probability) \
     (__extension__ ({ \
       double hedley_probability_ = (probability); \
       ((hedley_probability_ >= 0.9) ? __builtin_expect(!!(expr), 1) : ((hedley_probability_ <= 0.1) ? __builtin_expect(!!(expr), 0) : !!(expr))); \
     }))
#  define HEDLEY_PREDICT_FALSE(expr, probability) \
     (__extension__ ({ \
       double hedley_probability_ = (probability); \
       ((hedley_probability_ >= 0.9) ? __builtin_expect(!!(expr), 0) : ((hedley_probability_ <= 0.1) ? __builtin_expect(!!(expr), 1) : !!(expr))); \
     }))
#  define HEDLEY_LIKELY(expr)   __builtin_expect(!!(expr), 1)
#  define HEDLEY_UNLIKELY(expr) __builtin_expect(!!(expr), 0)
#else
#  define HEDLEY_PREDICT(expr, expected, probability) (HEDLEY_STATIC_CAST(void, expected), (expr))
#  define HEDLEY_PREDICT_TRUE(expr, probability) (!!(expr))
#  define HEDLEY_PREDICT_FALSE(expr, probability) (!!(expr))
#  define HEDLEY_LIKELY(expr) (!!(expr))
#  define HEDLEY_UNLIKELY(expr) (!!(expr))
#endif
#if !defined(HEDLEY_UNPREDICTABLE)
#  define HEDLEY_UNPREDICTABLE(expr) HEDLEY_PREDICT(expr, 1, 0.5)
#endif

#if defined(HEDLEY_MALLOC)
#  undef HEDLEY_MALLOC
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(malloc) || \
  HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(12,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_MALLOC __attribute__((__malloc__))
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
#  define HEDLEY_MALLOC _Pragma("returns_new_memory")
#elif HEDLEY_MSVC_VERSION_CHECK(14, 0, 0)
#  define HEDLEY_MALLOC __declspec(restrict)
#else
#  define HEDLEY_MALLOC
#endif

#if defined(HEDLEY_PURE)
#  undef HEDLEY_PURE
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(pure) || \
  HEDLEY_GCC_VERSION_CHECK(2,96,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  HEDLEY_PGI_VERSION_CHECK(17,10,0)
#  define HEDLEY_PURE __attribute__((__pure__))
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
#  define HEDLEY_PURE _Pragma("does_not_write_global_data")
#elif defined(__cplusplus) && \
    ( \
      HEDLEY_TI_CL430_VERSION_CHECK(2,0,1) || \
      HEDLEY_TI_CL6X_VERSION_CHECK(4,0,0) || \
      HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) \
    )
#  define HEDLEY_PURE _Pragma("FUNC_IS_PURE;")
#else
#  define HEDLEY_PURE
#endif

#if defined(HEDLEY_CONST)
#  undef HEDLEY_CONST
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(const) || \
  HEDLEY_GCC_VERSION_CHECK(2,5,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) || \
  HEDLEY_PGI_VERSION_CHECK(17,10,0)
#  define HEDLEY_CONST __attribute__((__const__))
#elif \
  HEDLEY_SUNPRO_VERSION_CHECK(5,10,0)
#  define HEDLEY_CONST _Pragma("no_side_effect")
#else
#  define HEDLEY_CONST HEDLEY_PURE
#endif

#if defined(HEDLEY_RESTRICT)
#  undef HEDLEY_RESTRICT
#endif
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && !defined(__cplusplus)
#  define HEDLEY_RESTRICT restrict
#elif \
  HEDLEY_GCC_VERSION_CHECK(3,1,0) || \
  HEDLEY_MSVC_VERSION_CHECK(14,0,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_PGI_VERSION_CHECK(17,10,0) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,2,4) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(8,1,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  (HEDLEY_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)) || \
  HEDLEY_IAR_VERSION_CHECK(8,0,0) || \
  defined(__clang__)
#  define HEDLEY_RESTRICT __restrict
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,3,0) && !defined(__cplusplus)
#  define HEDLEY_RESTRICT _Restrict
#else
#  define HEDLEY_RESTRICT
#endif

#if defined(HEDLEY_INLINE)
#  undef HEDLEY_INLINE
#endif
#if \
  (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
  (defined(__cplusplus) && (__cplusplus >= 199711L))
#  define HEDLEY_INLINE inline
#elif \
  defined(HEDLEY_GCC_VERSION) || \
  HEDLEY_ARM_VERSION_CHECK(6,2,0)
#  define HEDLEY_INLINE __inline__
#elif \
  HEDLEY_MSVC_VERSION_CHECK(12,0,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,1,0) || \
  HEDLEY_TI_CL430_VERSION_CHECK(3,1,0) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,2,0) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_INLINE __inline
#else
#  define HEDLEY_INLINE
#endif

#if defined(HEDLEY_ALWAYS_INLINE)
#  undef HEDLEY_ALWAYS_INLINE
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(always_inline) || \
  HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_ALWAYS_INLINE __attribute__((__always_inline__)) HEDLEY_INLINE
#elif HEDLEY_MSVC_VERSION_CHECK(12,0,0)
#  define HEDLEY_ALWAYS_INLINE __forceinline
#elif defined(__cplusplus) && \
    ( \
      HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
      HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
      HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
      HEDLEY_TI_CL6X_VERSION_CHECK(6,1,0) || \
      HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
      HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0) \
    )
#  define HEDLEY_ALWAYS_INLINE _Pragma("FUNC_ALWAYS_INLINE;")
#elif HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_ALWAYS_INLINE _Pragma("inline=forced")
#else
#  define HEDLEY_ALWAYS_INLINE HEDLEY_INLINE
#endif

#if defined(HEDLEY_NEVER_INLINE)
#  undef HEDLEY_NEVER_INLINE
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(noinline) || \
  HEDLEY_GCC_VERSION_CHECK(4,0,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(10,1,0) || \
  HEDLEY_TI_VERSION_CHECK(15,12,0) || \
  (HEDLEY_TI_ARMCL_VERSION_CHECK(4,8,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_ARMCL_VERSION_CHECK(5,2,0) || \
  (HEDLEY_TI_CL2000_VERSION_CHECK(6,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL2000_VERSION_CHECK(6,4,0) || \
  (HEDLEY_TI_CL430_VERSION_CHECK(4,0,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL430_VERSION_CHECK(4,3,0) || \
  (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) || \
  HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
  HEDLEY_TI_CLPRU_VERSION_CHECK(2,1,0)
#  define HEDLEY_NEVER_INLINE __attribute__((__noinline__))
#elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#  define HEDLEY_NEVER_INLINE __declspec(noinline)
#elif HEDLEY_PGI_VERSION_CHECK(10,2,0)
#  define HEDLEY_NEVER_INLINE _Pragma("noinline")
#elif HEDLEY_TI_CL6X_VERSION_CHECK(6,0,0) && defined(__cplusplus)
#  define HEDLEY_NEVER_INLINE _Pragma("FUNC_CANNOT_INLINE;")
#elif HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_NEVER_INLINE _Pragma("inline=never")
#elif HEDLEY_COMPCERT_VERSION_CHECK(3,2,0)
#  define HEDLEY_NEVER_INLINE __attribute((noinline))
#elif HEDLEY_PELLES_VERSION_CHECK(9,0,0)
#  define HEDLEY_NEVER_INLINE __declspec(noinline)
#else
#  define HEDLEY_NEVER_INLINE
#endif

#if defined(HEDLEY_PRIVATE)
#  undef HEDLEY_PRIVATE
#endif
#if defined(HEDLEY_PUBLIC)
#  undef HEDLEY_PUBLIC
#endif
#if defined(HEDLEY_IMPORT)
#  undef HEDLEY_IMPORT
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
#  define HEDLEY_PRIVATE
#  define HEDLEY_PUBLIC   __declspec(dllexport)
#  define HEDLEY_IMPORT   __declspec(dllimport)
#else
#  if \
    HEDLEY_HAS_ATTRIBUTE(visibility) || \
    HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
    HEDLEY_SUNPRO_VERSION_CHECK(5,11,0) || \
    HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
    HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
    ( \
      defined(__TI_EABI__) && \
      ( \
        (HEDLEY_TI_CL6X_VERSION_CHECK(7,2,0) && defined(__TI_GNU_ATTRIBUTE_SUPPORT__)) || \
        HEDLEY_TI_CL6X_VERSION_CHECK(7,5,0) \
      ) \
    )
#    define HEDLEY_PRIVATE __attribute__((__visibility__("hidden")))
#    define HEDLEY_PUBLIC  __attribute__((__visibility__("default")))
#  else
#    define HEDLEY_PRIVATE
#    define HEDLEY_PUBLIC
#  endif
#  define HEDLEY_IMPORT    extern
#endif

#if defined(HEDLEY_NO_THROW)
#  undef HEDLEY_NO_THROW
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(nothrow) || \
  HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_NO_THROW __attribute__((__nothrow__))
#elif \
  HEDLEY_MSVC_VERSION_CHECK(13,1,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0)
#  define HEDLEY_NO_THROW __declspec(nothrow)
#else
#  define HEDLEY_NO_THROW
#endif

#if defined(HEDLEY_FALL_THROUGH)
# undef HEDLEY_FALL_THROUGH
#endif
#if HEDLEY_GNUC_HAS_ATTRIBUTE(fallthrough,7,0,0) && !defined(HEDLEY_PGI_VERSION)
#  define HEDLEY_FALL_THROUGH __attribute__((__fallthrough__))
#elif HEDLEY_HAS_CPP_ATTRIBUTE_NS(clang,fallthrough)
#  define HEDLEY_FALL_THROUGH HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[clang::fallthrough]])
#elif HEDLEY_HAS_CPP_ATTRIBUTE(fallthrough)
#  define HEDLEY_FALL_THROUGH HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_([[fallthrough]])
#elif defined(__fallthrough) /* SAL */
#  define HEDLEY_FALL_THROUGH __fallthrough
#else
#  define HEDLEY_FALL_THROUGH
#endif

#if defined(HEDLEY_RETURNS_NON_NULL)
#  undef HEDLEY_RETURNS_NON_NULL
#endif
#if \
  HEDLEY_HAS_ATTRIBUTE(returns_nonnull) || \
  HEDLEY_GCC_VERSION_CHECK(4,9,0)
#  define HEDLEY_RETURNS_NON_NULL __attribute__((__returns_nonnull__))
#elif defined(_Ret_notnull_) /* SAL */
#  define HEDLEY_RETURNS_NON_NULL _Ret_notnull_
#else
#  define HEDLEY_RETURNS_NON_NULL
#endif

#if defined(HEDLEY_ARRAY_PARAM)
#  undef HEDLEY_ARRAY_PARAM
#endif
#if \
  defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) && \
  !defined(__STDC_NO_VLA__) && \
  !defined(__cplusplus) && \
  !defined(HEDLEY_PGI_VERSION) && \
  !defined(HEDLEY_TINYC_VERSION)
#  define HEDLEY_ARRAY_PARAM(name) (name)
#else
#  define HEDLEY_ARRAY_PARAM(name)
#endif

#if defined(HEDLEY_IS_CONSTANT)
#  undef HEDLEY_IS_CONSTANT
#endif
#if defined(HEDLEY_REQUIRE_CONSTEXPR)
#  undef HEDLEY_REQUIRE_CONSTEXPR
#endif
/* HEDLEY_IS_CONSTEXPR_ is for
   HEDLEY INTERNAL USE ONLY.  API subject to change without notice. */
#if defined(HEDLEY_IS_CONSTEXPR_)
#  undef HEDLEY_IS_CONSTEXPR_
#endif
#if \
  HEDLEY_HAS_BUILTIN(__builtin_constant_p) || \
  HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_TINYC_VERSION_CHECK(0,9,19) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
  HEDLEY_TI_CL6X_VERSION_CHECK(6,1,0) || \
  (HEDLEY_SUNPRO_VERSION_CHECK(5,10,0) && !defined(__cplusplus)) || \
  HEDLEY_CRAY_VERSION_CHECK(8,1,0)
#  define HEDLEY_IS_CONSTANT(expr) __builtin_constant_p(expr)
#endif
#if !defined(__cplusplus)
#  if \
       HEDLEY_HAS_BUILTIN(__builtin_types_compatible_p) || \
       HEDLEY_GCC_VERSION_CHECK(3,4,0) || \
       HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
       HEDLEY_IBM_VERSION_CHECK(13,1,0) || \
       HEDLEY_CRAY_VERSION_CHECK(8,1,0) || \
       HEDLEY_ARM_VERSION_CHECK(5,4,0) || \
       HEDLEY_TINYC_VERSION_CHECK(0,9,24)
#    if defined(__INTPTR_TYPE__)
#      define HEDLEY_IS_CONSTEXPR_(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0)), int*)
#    else
#      include <stdint.h>
#      define HEDLEY_IS_CONSTEXPR_(expr) __builtin_types_compatible_p(__typeof__((1 ? (void*) ((intptr_t) ((expr) * 0)) : (int*) 0)), int*)
#    endif
#  elif \
       ( \
          defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && \
          !defined(HEDLEY_SUNPRO_VERSION) && \
          !defined(HEDLEY_PGI_VERSION) && \
          !defined(HEDLEY_IAR_VERSION)) || \
       HEDLEY_HAS_EXTENSION(c_generic_selections) || \
       HEDLEY_GCC_VERSION_CHECK(4,9,0) || \
       HEDLEY_INTEL_VERSION_CHECK(17,0,0) || \
       HEDLEY_IBM_VERSION_CHECK(12,1,0) || \
       HEDLEY_ARM_VERSION_CHECK(5,3,0)
#    if defined(__INTPTR_TYPE__)
#      define HEDLEY_IS_CONSTEXPR_(expr) _Generic((1 ? (void*) ((__INTPTR_TYPE__) ((expr) * 0)) : (int*) 0), int*: 1, void*: 0)
#    else
#      include <stdint.h>
#      define HEDLEY_IS_CONSTEXPR_(expr) _Generic((1 ? (void*) ((intptr_t) * 0) : (int*) 0), int*: 1, void*: 0)
#    endif
#  elif \
       defined(HEDLEY_GCC_VERSION) || \
       defined(HEDLEY_INTEL_VERSION) || \
       defined(HEDLEY_TINYC_VERSION) || \
       defined(HEDLEY_TI_ARMCL_VERSION) || \
       HEDLEY_TI_CL430_VERSION_CHECK(18,12,0) || \
       defined(HEDLEY_TI_CL2000_VERSION) || \
       defined(HEDLEY_TI_CL6X_VERSION) || \
       defined(HEDLEY_TI_CL7X_VERSION) || \
       defined(HEDLEY_TI_CLPRU_VERSION) || \
       defined(__clang__)
#    define HEDLEY_IS_CONSTEXPR_(expr) ( \
         sizeof(void) != \
         sizeof(*( \
           1 ? \
             ((void*) ((expr) * 0L) ) : \
             ((struct { char v[sizeof(void) * 2]; } *) 1) \
           ) \
         ) \
       )
#  endif
#endif
#if defined(HEDLEY_IS_CONSTEXPR_)
#  if !defined(HEDLEY_IS_CONSTANT)
#    define HEDLEY_IS_CONSTANT(expr) HEDLEY_IS_CONSTEXPR_(expr)
#  endif
#  define HEDLEY_REQUIRE_CONSTEXPR(expr) (HEDLEY_IS_CONSTEXPR_(expr) ? (expr) : (-1))
#else
#  if !defined(HEDLEY_IS_CONSTANT)
#    define HEDLEY_IS_CONSTANT(expr) (0)
#  endif
#  define HEDLEY_REQUIRE_CONSTEXPR(expr) (expr)
#endif

#if defined(HEDLEY_BEGIN_C_DECLS)
#  undef HEDLEY_BEGIN_C_DECLS
#endif
#if defined(HEDLEY_END_C_DECLS)
#  undef HEDLEY_END_C_DECLS
#endif
#if defined(HEDLEY_C_DECL)
#  undef HEDLEY_C_DECL
#endif
#if defined(__cplusplus)
#  define HEDLEY_BEGIN_C_DECLS extern "C" {
#  define HEDLEY_END_C_DECLS }
#  define HEDLEY_C_DECL extern "C"
#else
#  define HEDLEY_BEGIN_C_DECLS
#  define HEDLEY_END_C_DECLS
#  define HEDLEY_C_DECL
#endif

#if defined(HEDLEY_STATIC_ASSERT)
#  undef HEDLEY_STATIC_ASSERT
#endif
#if \
  !defined(__cplusplus) && ( \
      (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) || \
      HEDLEY_HAS_FEATURE(c_static_assert) || \
      HEDLEY_GCC_VERSION_CHECK(6,0,0) || \
      HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
      defined(_Static_assert) \
    )
#  define HEDLEY_STATIC_ASSERT(expr, message) _Static_assert(expr, message)
#elif \
  (defined(__cplusplus) && (__cplusplus >= 201103L)) || \
  HEDLEY_MSVC_VERSION_CHECK(16,0,0)
#  define HEDLEY_STATIC_ASSERT(expr, message) HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(static_assert(expr, message))
#else
#  define HEDLEY_STATIC_ASSERT(expr, message)
#endif

#if defined(HEDLEY_NULL)
#  undef HEDLEY_NULL
#endif
#if defined(__cplusplus)
#  if __cplusplus >= 201103L
#    define HEDLEY_NULL HEDLEY_DIAGNOSTIC_DISABLE_CPP98_COMPAT_WRAP_(nullptr)
#  elif defined(NULL)
#    define HEDLEY_NULL NULL
#  else
#    define HEDLEY_NULL HEDLEY_STATIC_CAST(void*, 0)
#  endif
#elif defined(NULL)
#  define HEDLEY_NULL NULL
#else
#  define HEDLEY_NULL ((void*) 0)
#endif

#if defined(HEDLEY_MESSAGE)
#  undef HEDLEY_MESSAGE
#endif
#if HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#  define HEDLEY_MESSAGE(msg) \
  HEDLEY_DIAGNOSTIC_PUSH \
  HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
  HEDLEY_PRAGMA(message msg) \
  HEDLEY_DIAGNOSTIC_POP
#elif \
  HEDLEY_GCC_VERSION_CHECK(4,4,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_MESSAGE(msg) HEDLEY_PRAGMA(message msg)
#elif HEDLEY_CRAY_VERSION_CHECK(5,0,0)
#  define HEDLEY_MESSAGE(msg) HEDLEY_PRAGMA(_CRI message msg)
#elif HEDLEY_IAR_VERSION_CHECK(8,0,0)
#  define HEDLEY_MESSAGE(msg) HEDLEY_PRAGMA(message(msg))
#elif HEDLEY_PELLES_VERSION_CHECK(2,0,0)
#  define HEDLEY_MESSAGE(msg) HEDLEY_PRAGMA(message(msg))
#else
#  define HEDLEY_MESSAGE(msg)
#endif

#if defined(HEDLEY_WARNING)
#  undef HEDLEY_WARNING
#endif
#if HEDLEY_HAS_WARNING("-Wunknown-pragmas")
#  define HEDLEY_WARNING(msg) \
  HEDLEY_DIAGNOSTIC_PUSH \
  HEDLEY_DIAGNOSTIC_DISABLE_UNKNOWN_PRAGMAS \
  HEDLEY_PRAGMA(clang warning msg) \
  HEDLEY_DIAGNOSTIC_POP
#elif \
  HEDLEY_GCC_VERSION_CHECK(4,8,0) || \
  HEDLEY_PGI_VERSION_CHECK(18,4,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define HEDLEY_WARNING(msg) HEDLEY_PRAGMA(GCC warning msg)
#elif HEDLEY_MSVC_VERSION_CHECK(15,0,0)
#  define HEDLEY_WARNING(msg) HEDLEY_PRAGMA(message(msg))
#else
#  define HEDLEY_WARNING(msg) HEDLEY_MESSAGE(msg)
#endif

#if defined(HEDLEY_REQUIRE)
#  undef HEDLEY_REQUIRE
#endif
#if defined(HEDLEY_REQUIRE_MSG)
#  undef HEDLEY_REQUIRE_MSG
#endif
#if HEDLEY_HAS_ATTRIBUTE(diagnose_if)
#  if HEDLEY_HAS_WARNING("-Wgcc-compat")
#    define HEDLEY_REQUIRE(expr) \
       HEDLEY_DIAGNOSTIC_PUSH \
       _Pragma("clang diagnostic ignored \"-Wgcc-compat\"") \
       __attribute__((diagnose_if(!(expr), #expr, "error"))) \
       HEDLEY_DIAGNOSTIC_POP
#    define HEDLEY_REQUIRE_MSG(expr,msg) \
       HEDLEY_DIAGNOSTIC_PUSH \
       _Pragma("clang diagnostic ignored \"-Wgcc-compat\"") \
       __attribute__((diagnose_if(!(expr), msg, "error"))) \
       HEDLEY_DIAGNOSTIC_POP
#  else
#    define HEDLEY_REQUIRE(expr) __attribute__((diagnose_if(!(expr), #expr, "error")))
#    define HEDLEY_REQUIRE_MSG(expr,msg) __attribute__((diagnose_if(!(expr), msg, "error")))
#  endif
#else
#  define HEDLEY_REQUIRE(expr)
#  define HEDLEY_REQUIRE_MSG(expr,msg)
#endif

#if defined(HEDLEY_FLAGS)
#  undef HEDLEY_FLAGS
#endif
#if HEDLEY_HAS_ATTRIBUTE(flag_enum)
#  define HEDLEY_FLAGS __attribute__((__flag_enum__))
#endif

#if defined(HEDLEY_FLAGS_CAST)
#  undef HEDLEY_FLAGS_CAST
#endif
#if HEDLEY_INTEL_VERSION_CHECK(19,0,0)
#  define HEDLEY_FLAGS_CAST(T, expr) (__extension__ ({ \
  HEDLEY_DIAGNOSTIC_PUSH \
      _Pragma("warning(disable:188)") \
      ((T) (expr)); \
      HEDLEY_DIAGNOSTIC_POP \
    }))
#else
#  define HEDLEY_FLAGS_CAST(T, expr) HEDLEY_STATIC_CAST(T, expr)
#endif

#if defined(HEDLEY_EMPTY_BASES)
#  undef HEDLEY_EMPTY_BASES
#endif
#if HEDLEY_MSVC_VERSION_CHECK(19,0,23918) && !HEDLEY_MSVC_VERSION_CHECK(20,0,0)
#  define HEDLEY_EMPTY_BASES __declspec(empty_bases)
#else
#  define HEDLEY_EMPTY_BASES
#endif

/* Remaining macros are deprecated. */

#if defined(HEDLEY_GCC_NOT_CLANG_VERSION_CHECK)
#  undef HEDLEY_GCC_NOT_CLANG_VERSION_CHECK
#endif
#if defined(__clang__)
#  define HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) (0)
#else
#  define HEDLEY_GCC_NOT_CLANG_VERSION_CHECK(major,minor,patch) HEDLEY_GCC_VERSION_CHECK(major,minor,patch)
#endif

#if defined(HEDLEY_CLANG_HAS_ATTRIBUTE)
#  undef HEDLEY_CLANG_HAS_ATTRIBUTE
#endif
#define HEDLEY_CLANG_HAS_ATTRIBUTE(attribute) HEDLEY_HAS_ATTRIBUTE(attribute)

#if defined(HEDLEY_CLANG_HAS_CPP_ATTRIBUTE)
#  undef HEDLEY_CLANG_HAS_CPP_ATTRIBUTE
#endif
#define HEDLEY_CLANG_HAS_CPP_ATTRIBUTE(attribute) HEDLEY_HAS_CPP_ATTRIBUTE(attribute)

#if defined(HEDLEY_CLANG_HAS_BUILTIN)
#  undef HEDLEY_CLANG_HAS_BUILTIN
#endif
#define HEDLEY_CLANG_HAS_BUILTIN(builtin) HEDLEY_HAS_BUILTIN(builtin)

#if defined(HEDLEY_CLANG_HAS_FEATURE)
#  undef HEDLEY_CLANG_HAS_FEATURE
#endif
#define HEDLEY_CLANG_HAS_FEATURE(feature) HEDLEY_HAS_FEATURE(feature)

#if defined(HEDLEY_CLANG_HAS_EXTENSION)
#  undef HEDLEY_CLANG_HAS_EXTENSION
#endif
#define HEDLEY_CLANG_HAS_EXTENSION(extension) HEDLEY_HAS_EXTENSION(extension)

#if defined(HEDLEY_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE)
#  undef HEDLEY_CLANG_HAS_DECLSPEC_DECLSPEC_ATTRIBUTE
#endif
#define HEDLEY_CLANG_HAS_DECLSPEC_ATTRIBUTE(attribute) HEDLEY_HAS_DECLSPEC_ATTRIBUTE(attribute)

#if defined(HEDLEY_CLANG_HAS_WARNING)
#  undef HEDLEY_CLANG_HAS_WARNING
#endif
#define HEDLEY_CLANG_HAS_WARNING(warning) HEDLEY_HAS_WARNING(warning)

#endif /* !defined(HEDLEY_VERSION) || (HEDLEY_VERSION < X) */
/* :: End hedley.h :: */
/* :: Begin check.h :: */
/* Check (assertions)
 * Portable Snippets - https://gitub.com/nemequ/portable-snippets
 * Created by Evan Nemerson <evan@nemerson.com>
 *
 *   To the extent possible under law, the authors have waived all
 *   copyright and related or neighboring rights to this code.  For
 *   details, see the Creative Commons Zero 1.0 Universal license at
 *   https://creativecommons.org/publicdomain/zero/1.0/
 */

#if !defined(SIMDE_CHECK_H)
#define SIMDE_CHECK_H

#if !defined(SIMDE_NDEBUG) && !defined(SIMDE_DEBUG)
#  define SIMDE_NDEBUG 1
#endif

#include <stdint.h>

#if !defined(_WIN32)
#  define SIMDE_SIZE_MODIFIER "z"
#  define SIMDE_CHAR_MODIFIER "hh"
#  define SIMDE_SHORT_MODIFIER "h"
#else
#  if defined(_M_X64) || defined(__amd64__)
#    define SIMDE_SIZE_MODIFIER "I64"
#  else
#    define SIMDE_SIZE_MODIFIER ""
#  endif
#  define SIMDE_CHAR_MODIFIER ""
#  define SIMDE_SHORT_MODIFIER ""
#endif

#if defined(_MSC_VER) &&  (_MSC_VER >= 1500)
#  define SIMDE__PUSH_DISABLE_MSVC_C4127 __pragma(warning(push)) __pragma(warning(disable:4127))
#  define SIMDE__POP_DISABLE_MSVC_C4127 __pragma(warning(pop))
#else
#  define SIMDE__PUSH_DISABLE_MSVC_C4127
#  define SIMDE__POP_DISABLE_MSVC_C4127
#endif

#if !defined(simde_errorf)
#  include <stdio.h>
#  include <stdlib.h>
#  define simde_errorf(format, ...) (fprintf(stderr, format, __VA_ARGS__), abort())
#endif

#define simde_error(msg) simde_errorf("%s", msg)

#if defined(SIMDE_NDEBUG)
#  if defined(SIMDE_CHECK_FAIL_DEFINED)
#    define simde_assert(expr)
#  else
#    if defined(HEDLEY_ASSUME)
#      define simde_assert(expr) HEDLEY_ASSUME(expr)
#    elif HEDLEY_GCC_VERSION_CHECK(4,5,0)
#      define simde_assert(expr) ((void) (!!(expr) ? 1 : (__builtin_unreachable(), 1)))
#    elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#      define simde_assert(expr) __assume(expr)
#    else
#      define simde_assert(expr)
#    endif
#  endif
#  define simde_assert_true(expr) simde_assert(expr)
#  define simde_assert_false(expr) simde_assert(!(expr))
#  define simde_assert_type_full(prefix, suffix, T, fmt, a, op, b) simde_assert(((a) op (b)))
#  define simde_assert_double_equal(a, b, precision)
#  define simde_assert_string_equal(a, b)
#  define simde_assert_string_not_equal(a, b)
#  define simde_assert_memory_equal(size, a, b)
#  define simde_assert_memory_not_equal(size, a, b)
#else
#  define simde_assert(expr) \
    do { \
      if (!HEDLEY_LIKELY(expr)) { \
        simde_error("assertion failed: " #expr "\n"); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  define simde_assert_true(expr) \
    do { \
      if (!HEDLEY_LIKELY(expr)) { \
        simde_error("assertion failed: " #expr " is not true\n"); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  define simde_assert_false(expr) \
    do { \
      if (!HEDLEY_LIKELY(!(expr))) { \
        simde_error("assertion failed: " #expr " is not false\n"); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  define simde_assert_type_full(prefix, suffix, T, fmt, a, op, b)   \
    do { \
      T simde_tmp_a_ = (a); \
      T simde_tmp_b_ = (b); \
      if (!(simde_tmp_a_ op simde_tmp_b_)) { \
        simde_errorf("assertion failed: %s %s %s (" prefix "%" fmt suffix " %s " prefix "%" fmt suffix ")\n", \
                     #a, #op, #b, simde_tmp_a_, #op, simde_tmp_b_); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  define simde_assert_double_equal(a, b, precision) \
    do { \
      const double simde_tmp_a_ = (a); \
      const double simde_tmp_b_ = (b); \
      const double simde_tmp_diff_ = ((simde_tmp_a_ - simde_tmp_b_) < 0) ? \
        -(simde_tmp_a_ - simde_tmp_b_) : \
        (simde_tmp_a_ - simde_tmp_b_); \
      if (HEDLEY_UNLIKELY(simde_tmp_diff_ > 1e-##precision)) { \
        simde_errorf("assertion failed: %s == %s (%0." #precision "g == %0." #precision "g)\n", \
                     #a, #b, simde_tmp_a_, simde_tmp_b_); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  include <string.h>
#  define simde_assert_string_equal(a, b) \
    do { \
      const char* simde_tmp_a_ = a; \
      const char* simde_tmp_b_ = b; \
      if (HEDLEY_UNLIKELY(strcmp(simde_tmp_a_, simde_tmp_b_) != 0)) { \
        simde_errorf("assertion failed: string %s == %s (\"%s\" == \"%s\")\n", \
                     #a, #b, simde_tmp_a_, simde_tmp_b_); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  define simde_assert_string_not_equal(a, b) \
    do { \
      const char* simde_tmp_a_ = a; \
      const char* simde_tmp_b_ = b; \
      if (HEDLEY_UNLIKELY(strcmp(simde_tmp_a_, simde_tmp_b_) == 0)) { \
        simde_errorf("assertion failed: string %s != %s (\"%s\" == \"%s\")\n", \
                     #a, #b, simde_tmp_a_, simde_tmp_b_); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  define simde_assert_memory_equal(size, a, b) \
    do { \
      const unsigned char* simde_tmp_a_ = (const unsigned char*) (a); \
      const unsigned char* simde_tmp_b_ = (const unsigned char*) (b); \
      const size_t simde_tmp_size_ = (size); \
      if (HEDLEY_UNLIKELY(memcmp(simde_tmp_a_, simde_tmp_b_, simde_tmp_size_)) != 0) { \
        size_t simde_tmp_pos_; \
        for (simde_tmp_pos_ = 0 ; simde_tmp_pos_ < simde_tmp_size_ ; simde_tmp_pos_++) { \
          if (simde_tmp_a_[simde_tmp_pos_] != simde_tmp_b_[simde_tmp_pos_]) { \
            simde_errorf("assertion failed: memory %s == %s, at offset %" SIMDE_SIZE_MODIFIER "u\n", \
                         #a, #b, simde_tmp_pos_); \
            break; \
          } \
        } \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127

#  define simde_assert_memory_not_equal(size, a, b) \
    do { \
      const unsigned char* simde_tmp_a_ = (const unsigned char*) (a); \
      const unsigned char* simde_tmp_b_ = (const unsigned char*) (b); \
      const size_t simde_tmp_size_ = (size); \
      if (HEDLEY_UNLIKELY(memcmp(simde_tmp_a_, simde_tmp_b_, simde_tmp_size_)) == 0) { \
        simde_errorf("assertion failed: memory %s != %s (%" SIMDE_SIZE_MODIFIER "u bytes)\n", \
                     #a, #b, simde_tmp_size_); \
      } \
      SIMDE__PUSH_DISABLE_MSVC_C4127 \
    } while (0) \
    SIMDE__POP_DISABLE_MSVC_C4127
#endif

#define simde_assert_type(T, fmt, a, op, b) \
  simde_assert_type_full("", "", T, fmt, a, op, b)

#define simde_assert_char(a, op, b) \
  simde_assert_type_full("'\\x", "'", char, "02" SIMDE_CHAR_MODIFIER "x", a, op, b)
#define simde_assert_uchar(a, op, b) \
  simde_assert_type_full("'\\x", "'", unsigned char, "02" SIMDE_CHAR_MODIFIER "x", a, op, b)
#define simde_assert_short(a, op, b) \
  simde_assert_type(short, SIMDE_SHORT_MODIFIER "d", a, op, b)
#define simde_assert_ushort(a, op, b) \
  simde_assert_type(unsigned short, SIMDE_SHORT_MODIFIER "u", a, op, b)
#define simde_assert_int(a, op, b) \
  simde_assert_type(int, "d", a, op, b)
#define simde_assert_uint(a, op, b) \
  simde_assert_type(unsigned int, "u", a, op, b)
#define simde_assert_long(a, op, b) \
  simde_assert_type(long int, "ld", a, op, b)
#define simde_assert_ulong(a, op, b) \
  simde_assert_type(unsigned long int, "lu", a, op, b)
#define simde_assert_llong(a, op, b) \
  simde_assert_type(long long int, "lld", a, op, b)
#define simde_assert_ullong(a, op, b) \
  simde_assert_type(unsigned long long int, "llu", a, op, b)

#define simde_assert_size(a, op, b) \
  simde_assert_type(size_t, SIMDE_SIZE_MODIFIER "u", a, op, b)

#define simde_assert_float(a, op, b) \
  simde_assert_type(float, "f", a, op, b)
#define simde_assert_double(a, op, b) \
  simde_assert_type(double, "g", a, op, b)
#define simde_assert_ptr(a, op, b) \
  simde_assert_type(const void*, "p", a, op, b)

#define simde_assert_int8(a, op, b) \
  simde_assert_type(int8_t, PRIi8, a, op, b)
#define simde_assert_uint8(a, op, b) \
  simde_assert_type(uint8_t, PRIu8, a, op, b)
#define simde_assert_int16(a, op, b) \
  simde_assert_type(int16_t, PRIi16, a, op, b)
#define simde_assert_uint16(a, op, b) \
  simde_assert_type(uint16_t, PRIu16, a, op, b)
#define simde_assert_int32(a, op, b) \
  simde_assert_type(int32_t, PRIi32, a, op, b)
#define simde_assert_uint32(a, op, b) \
  simde_assert_type(uint32_t, PRIu32, a, op, b)
#define simde_assert_int64(a, op, b) \
  simde_assert_type(int64_t, PRIi64, a, op, b)
#define simde_assert_uint64(a, op, b) \
  simde_assert_type(uint64_t, PRIu64, a, op, b)

#define simde_assert_ptr_equal(a, b) \
  simde_assert_ptr(a, ==, b)
#define simde_assert_ptr_not_equal(a, b) \
  simde_assert_ptr(a, !=, b)
#define simde_assert_null(ptr) \
  simde_assert_ptr(ptr, ==, NULL)
#define simde_assert_not_null(ptr) \
  simde_assert_ptr(ptr, !=, NULL)
#define simde_assert_ptr_null(ptr) \
  simde_assert_ptr(ptr, ==, NULL)
#define simde_assert_ptr_not_null(ptr) \
  simde_assert_ptr(ptr, !=, NULL)

#endif /* !defined(SIMDE_CHECK_H) */
/* :: End check.h :: */
/* :: Begin simde-arch.h :: */
/* Architecture detection
 * Created by Evan Nemerson <evan@nemerson.com>
 *
 *   To the extent possible under law, the authors have waived all
 *   copyright and related or neighboring rights to this code.  For
 *   details, see the Creative Commons Zero 1.0 Universal license at
 *   <https://creativecommons.org/publicdomain/zero/1.0/>
 *
 * Different compilers define different preprocessor macros for the
 * same architecture.  This is an attempt to provide a single
 * interface which is usable on any compiler.
 *
 * In general, a macro named SIMDE_ARCH_* is defined for each
 * architecture the CPU supports.  When there are multiple possible
 * versions, we try to define the macro to the target version.  For
 * example, if you want to check for i586+, you could do something
 * like:
 *
 *   #if defined(SIMDE_ARCH_X86) && (SIMDE_ARCH_X86 >= 5)
 *   ...
 *   #endif
 *
 * You could also just check that SIMDE_ARCH_X86 >= 5 without checking
 * if it's defined first, but some compilers may emit a warning about
 * an undefined macro being used (e.g., GCC with -Wundef).
 *
 * This was originally created for SIMDe
 * <https://github.com/nemequ/simde> (hence the prefix), but this
 * header has no dependencies and may be used anywhere.  It is
 * originally based on information from
 * <https://sourceforge.net/p/predef/wiki/Architectures/>, though it
 * has been enhanced with additional information.
 *
 * If you improve this file, or find a bug, please file the issue at
 * <https://github.com/nemequ/simde/issues>.  If you copy this into
 * your project, even if you change the prefix, please keep the links
 * to SIMDe intact so others know where to report issues, submit
 * enhancements, and find the latest version. */

#if !defined(SIMDE_ARCH_H)
#define SIMDE_ARCH_H

/* Alpha
   <https://en.wikipedia.org/wiki/DEC_Alpha> */
#if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
#  if defined(__alpha_ev6__)
#    define SIMDE_ARCH_ALPHA 6
#  elif defined(__alpha_ev5__)
#    define SIMDE_ARCH_ALPHA 5
#  elif defined(__alpha_ev4__)
#    define SIMDE_ARCH_ALPHA 4
#  else
#    define SIMDE_ARCH_ALPHA 1
#  endif
#endif

/* Atmel AVR
   <https://en.wikipedia.org/wiki/Atmel_AVR> */
#if defined(__AVR_ARCH__)
#  define SIMDE_ARCH_AVR __AVR_ARCH__
#endif

/* AMD64 / x86_64
   <https://en.wikipedia.org/wiki/X86-64> */
#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X66) || defined(_M_AMD64)
#  define SIMDE_ARCH_AMD64 1
#endif

/* ARM
   <https://en.wikipedia.org/wiki/ARM_architecture> */
#if defined(__ARM_ARCH_8A__)
#  define SIMDE_ARCH_ARM 82
#elif defined(__ARM_ARCH_8R__)
#  define SIMDE_ARCH_ARM 81
#elif defined(__ARM_ARCH_8__)
#  define SIMDE_ARCH_ARM 80
#elif defined(__ARM_ARCH_7S__)
#  define SIMDE_ARCH_ARM 74
#elif defined(__ARM_ARCH_7M__)
#  define SIMDE_ARCH_ARM 73
#elif defined(__ARM_ARCH_7R__)
#  define SIMDE_ARCH_ARM 72
#elif defined(__ARM_ARCH_7A__)
#  define SIMDE_ARCH_ARM 71
#elif defined(__ARM_ARCH_7__)
#  define SIMDE_ARCH_ARM 70
#elif defined(__ARM_ARCH)
#  define SIMDE_ARCH_ARM (__ARM_ARCH * 10)
#elif defined(_M_ARM)
#  define SIMDE_ARCH_ARM (_M_ARM * 10)
#elif defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARM)
#  define SIMDE_ARCH_ARM 1
#endif

/* AArch64
   <https://en.wikipedia.org/wiki/ARM_architecture> */
#if defined(__aarch64__) || defined(_M_ARM64)
#  define SIMDE_ARCH_AARCH64 10
#endif

/* Blackfin
   <https://en.wikipedia.org/wiki/Blackfin> */
#if defined(__bfin) || defined(__BFIN__) || defined(__bfin__)
#  define SIMDE_ARCH_BLACKFIN 1
#endif

/* CRIS
   <https://en.wikipedia.org/wiki/ETRAX_CRIS> */
#if defined(__CRIS_arch_version)
#  define SIMDE_ARCH_CRIS __CRIS_arch_version
#elif defined(__cris__) || defined(__cris) || defined(__CRIS) || defined(__CRIS__)
#  define SIMDE_ARCH_CRIS 1
#endif

/* Convex
   <https://en.wikipedia.org/wiki/Convex_Computer> */
#if defined(__convex_c38__)
#  define SIMDE_ARCH_CONVEX 38
#elif defined(__convex_c34__)
#  define SIMDE_ARCH_CONVEX 34
#elif defined(__convex_c32__)
#  define SIMDE_ARCH_CONVEX 32
#elif defined(__convex_c2__)
#  define SIMDE_ARCH_CONVEX 2
#elif defined(__convex__)
#  define SIMDE_ARCH_CONVEX 1
#endif

/* Adapteva Epiphany
   <https://en.wikipedia.org/wiki/Adapteva_Epiphany> */
#if defined(__epiphany__)
#  define SIMDE_ARCH_EPIPHANY 1
#endif

/* Fujitsu FR-V
   <https://en.wikipedia.org/wiki/FR-V_(microprocessor)> */
#if defined(__frv__)
#  define SIMDE_ARCH_FRV 1
#endif

/* H8/300
   <https://en.wikipedia.org/wiki/H8_Family> */
#if defined(__H8300__)
#  define SIMDE_ARCH_H8300
#endif

/* HP/PA / PA-RISC
   <https://en.wikipedia.org/wiki/PA-RISC> */
#if defined(__PA8000__) || defined(__HPPA20__) || defined(__RISC2_0__) || defined(_PA_RISC2_0)
#  define SIMDE_ARCH_HPPA 20
#elif defined(__PA7100__) || defined(__HPPA11__) || defined(_PA_RISC1_1)
#  define SIMDE_ARCH_HPPA 11
#elif defined(_PA_RISC1_0)
#  define SIMDE_ARCH_HPPA 10
#elif defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
#  define SIMDE_ARCH_HPPA 1
#endif

/* x86
   <https://en.wikipedia.org/wiki/X86> */
#if defined(_M_IX86)
#  define SIMDE_ARCH_X86 (_M_IX86 / 100)
#elif defined(__I86__)
#  define SIMDE_ARCH_X86 __I86__
#elif defined(i686) || defined(__i686) || defined(__i686__)
#  define SIMDE_ARCH_X86 6
#elif defined(i586) || defined(__i586) || defined(__i586__)
#  define SIMDE_ARCH_X86 5
#elif defined(i486) || defined(__i486) || defined(__i486__)
#  define SIMDE_ARCH_X86 4
#elif defined(i386) || defined(__i386) || defined(__i386__)
#  define SIMDE_ARCH_X86 3
#elif defined(_X86_) || defined(__X86__) || defined(__THW_INTEL__)
#  define SIMDE_ARCH_X86 3
#endif

/* Itanium
   <https://en.wikipedia.org/wiki/Itanium> */
#if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
#  define SIMDE_ARCH_IA64 1
#endif

/* Renesas M32R
   <https://en.wikipedia.org/wiki/M32R> */
#if defined(__m32r__) || defined(__M32R__)
#  define SIMDE_ARCH_M32R
#endif

/* Motorola 68000
   <https://en.wikipedia.org/wiki/Motorola_68000> */
#if defined(__mc68060__) || defined(__MC68060__)
#  define SIMDE_ARCH_M68K 68060
#elif defined(__mc68040__) || defined(__MC68040__)
#  define SIMDE_ARCH_M68K 68040
#elif defined(__mc68030__) || defined(__MC68030__)
#  define SIMDE_ARCH_M68K 68030
#elif defined(__mc68020__) || defined(__MC68020__)
#  define SIMDE_ARCH_M68K 68020
#elif defined(__mc68010__) || defined(__MC68010__)
#  define SIMDE_ARCH_M68K 68010
#elif defined(__mc68000__) || defined(__MC68000__)
#  define SIMDE_ARCH_M68K 68000
#endif

/* Xilinx MicroBlaze
   <https://en.wikipedia.org/wiki/MicroBlaze> */
#if defined(__MICROBLAZE__) || defined(__microblaze__)
#  define SIMDE_ARCH_MICROBLAZE
#endif

/* MIPS
   <https://en.wikipedia.org/wiki/MIPS_architecture> */
#if defined(_MIPS_ISA_MIPS64R2)
#  define SIMDE_ARCH_MIPS 642
#elif defined(_MIPS_ISA_MIPS64)
#  define SIMDE_ARCH_MIPS 640
#elif defined(_MIPS_ISA_MIPS32R2)
#  define SIMDE_ARCH_MIPS 322
#elif defined(_MIPS_ISA_MIPS32)
#  define SIMDE_ARCH_MIPS 320
#elif defined(_MIPS_ISA_MIPS4)
#  define SIMDE_ARCH_MIPS 4
#elif defined(_MIPS_ISA_MIPS3)
#  define SIMDE_ARCH_MIPS 3
#elif defined(_MIPS_ISA_MIPS2)
#  define SIMDE_ARCH_MIPS 2
#elif defined(_MIPS_ISA_MIPS1)
#  define SIMDE_ARCH_MIPS 1
#elif defined(_MIPS_ISA_MIPS) || defined(__mips) || defined(__MIPS__)
#  define SIMDE_ARCH_MIPS 1
#endif

/* Matsushita MN10300
   <https://en.wikipedia.org/wiki/MN103> */
#if defined(__MN10300__) || defined(__mn10300__)
#  define SIMDE_ARCH_MN10300 1
#endif

/* POWER
   <https://en.wikipedia.org/wiki/IBM_POWER_Instruction_Set_Architecture> */
#if defined(_M_PPC)
#  define SIMDE_ARCH_POWER _M_PPC
#elif defined(_ARCH_PWR8)
#  define SIMDE_ARCH_POWER 800
#elif defined(_ARCH_PWR7)
#  define SIMDE_ARCH_POWER 700
#elif defined(_ARCH_PWR6)
#  define SIMDE_ARCH_POWER 600
#elif defined(_ARCH_PWR5)
#  define SIMDE_ARCH_POWER 500
#elif defined(_ARCH_PWR4)
#  define SIMDE_ARCH_POWER 400
#elif defined(_ARCH_440) || defined(__ppc440__)
#  define SIMDE_ARCH_POWER 440
#elif defined(_ARCH_450) || defined(__ppc450__)
#  define SIMDE_ARCH_POWER 450
#elif defined(_ARCH_601) || defined(__ppc601__)
#  define SIMDE_ARCH_POWER 601
#elif defined(_ARCH_603) || defined(__ppc603__)
#  define SIMDE_ARCH_POWER 603
#elif defined(_ARCH_604) || defined(__ppc604__)
#  define SIMDE_ARCH_POWER 604
#elif defined(_ARCH_605) || defined(__ppc605__)
#  define SIMDE_ARCH_POWER 605
#elif defined(_ARCH_620) || defined(__ppc620__)
#  define SIMDE_ARCH_POWER 620
#elif defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC) || defined(__ppc)
#  define SIMDE_ARCH_POWER 1
#endif

/* SPARC
   <https://en.wikipedia.org/wiki/SPARC> */
#if defined(__sparc_v9__) || defined(__sparcv9)
#  define SIMDE_ARCH_SPARC 9
#elif defined(__sparc_v8__) || defined(__sparcv8)
#  define SIMDE_ARCH_SPARC 8
#elif defined(__sparc_v7__) || defined(__sparcv7)
#  define SIMDE_ARCH_SPARC 7
#elif defined(__sparc_v6__) || defined(__sparcv6)
#  define SIMDE_ARCH_SPARC 6
#elif defined(__sparc_v5__) || defined(__sparcv5)
#  define SIMDE_ARCH_SPARC 5
#elif defined(__sparc_v4__) || defined(__sparcv4)
#  define SIMDE_ARCH_SPARC 4
#elif defined(__sparc_v3__) || defined(__sparcv3)
#  define SIMDE_ARCH_SPARC 3
#elif defined(__sparc_v2__) || defined(__sparcv2)
#  define SIMDE_ARCH_SPARC 2
#elif defined(__sparc_v1__) || defined(__sparcv1)
#  define SIMDE_ARCH_SPARC 1
#elif defined(__sparc__) || defined(__sparc)
#  define SIMDE_ARCH_SPARC 1
#endif

/* SuperH
   <https://en.wikipedia.org/wiki/SuperH> */
#if defined(__sh5__) || defined(__SH5__)
#  define SIMDE_ARCH_SUPERH 5
#elif defined(__sh4__) || defined(__SH4__)
#  define SIMDE_ARCH_SUPERH 4
#elif defined(__sh3__) || defined(__SH3__)
#  define SIMDE_ARCH_SUPERH 3
#elif defined(__sh2__) || defined(__SH2__)
#  define SIMDE_ARCH_SUPERH 2
#elif defined(__sh1__) || defined(__SH1__)
#  define SIMDE_ARCH_SUPERH 1
#elif defined(__sh__) || defined(__SH__)
#  define SIMDE_ARCH_SUPERH 1
#endif

/* IBM System z
   <https://en.wikipedia.org/wiki/IBM_System_z> */
#if defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#  define SIMDE_ARCH_SYSTEMZ
#endif

/* TMS320 DSP
   <https://en.wikipedia.org/wiki/Texas_Instruments_TMS320> */
#if defined(_TMS320C6740) || defined(__TMS320C6740__)
#  define SIMDE_ARCH_TMS320 6740
#elif defined(_TMS320C6700_PLUS) || defined(__TMS320C6700_PLUS__)
#  define SIMDE_ARCH_TMS320 6701
#elif defined(_TMS320C6700) || defined(__TMS320C6700__)
#  define SIMDE_ARCH_TMS320 6700
#elif defined(_TMS320C6600) || defined(__TMS320C6600__)
#  define SIMDE_ARCH_TMS320 6600
#elif defined(_TMS320C6400_PLUS) || defined(__TMS320C6400_PLUS__)
#  define SIMDE_ARCH_TMS320 6401
#elif defined(_TMS320C6400) || defined(__TMS320C6400__)
#  define SIMDE_ARCH_TMS320 6400
#elif defined(_TMS320C6200) || defined(__TMS320C6200__)
#  define SIMDE_ARCH_TMS320 6200
#elif defined(_TMS320C55X) || defined(__TMS320C55X__)
#  define SIMDE_ARCH_TMS320 550
#elif defined(_TMS320C54X) || defined(__TMS320C54X__)
#  define SIMDE_ARCH_TMS320 540
#elif defined(_TMS320C28X) || defined(__TMS320C28X__)
#  define SIMDE_ARCH_TMS320 280
#endif

/* Xtensa
   <https://en.wikipedia.org/wiki/> */
#if defined(__xtensa__) || defined(__XTENSA__)
#  define SIMDE_ARCH_XTENSA 1
#endif

#endif /* !defined(SIMDE_ARCH_H) */
/* :: End simde-arch.h :: */

#include <string.h>

#if \
  HEDLEY_HAS_ATTRIBUTE(aligned) || \
  HEDLEY_GCC_VERSION_CHECK(2,95,0) || \
  HEDLEY_CRAY_VERSION_CHECK(8,4,0) || \
  HEDLEY_IBM_VERSION_CHECK(11,1,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_PGI_VERSION_CHECK(19,4,0) || \
  HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
  HEDLEY_TINYC_VERSION_CHECK(0,9,24) || \
  HEDLEY_TI_VERSION_CHECK(8,1,0)
#  define SIMDE_ALIGN(alignment) __attribute__((aligned(alignment)))
#elif defined(_MSC_VER) && !(defined(_M_ARM) && !defined(_M_ARM64))
#  define SIMDE_ALIGN(alignment) __declspec(align(alignment))
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#  define SIMDE_ALIGN(alignment) _Alignas(alignment)
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
#  define SIMDE_ALIGN(alignment) alignas(alignment)
#else
#  define SIMDE_ALIGN(alignment)
#endif

#if \
  (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) || \
  HEDLEY_HAS_FEATURE(c11_alignof)
#  define SIMDE_ALIGN_OF(T) (_Alignof(T))
#elif \
  (defined(__cplusplus) && (__cplusplus >= 201103L)) || \
  HEDLEY_HAS_FEATURE(cxx_alignof)
#  define SIMDE_ALIGN_OF(T) (alignof(T))
#elif HEDLEY_GCC_VERSION_CHECK(2,95,0) || \
    HEDLEY_ARM_VERSION_CHECK(4,1,0) || \
    HEDLEY_IBM_VERSION_CHECK(11,1,0)
#  define SIMDE_ALIGN_OF(T) (__alignof__(T))
#endif

#if defined(SIMDE_ALIGN_OF)
#  define SIMDE_ALIGN_AS(N, T) SIMDE_ALIGN(SIMDE_ALIGN_OF(T))
#else
#  define SIMDE_ALIGN_AS(N, T) SIMDE_ALIGN(N)
#endif

#define simde_assert_aligned(alignment, val) \
  simde_assert_int(HEDLEY_REINTERPRET_CAST(uintptr_t, HEDLEY_REINTERPRET_CAST(const void*, (val))) % (alignment), ==, 0)

/* TODO: this should really do something like
   HEDLEY_STATIC_CAST(T, (simde_assert_int(alignment, v), v))
   but I need to think about how to handle it in all compilers...
   may end up moving to Hedley, too. */
#if HEDLEY_HAS_BUILTIN(__builtin_assume_aligned)
#  define SIMDE_CAST_ALIGN(alignment, T, v) HEDLEY_REINTERPRET_CAST(T, __builtin_assume_aligned(v, alignment))
#elif HEDLEY_HAS_WARNING("-Wcast-align")
#  define SIMDE_CAST_ALIGN(alignment, T, v) \
    HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wcast-align\"") \
    HEDLEY_REINTERPRET_CAST(T, (v)) \
    HEDLEY_DIAGNOSTIC_POP
#else
#  define SIMDE_CAST_ALIGN(alignment, T, v) HEDLEY_REINTERPRET_CAST(T, (v))
#endif

#if \
  (HEDLEY_HAS_ATTRIBUTE(may_alias) && !defined(HEDLEY_SUNPRO_VERSION)) || \
  HEDLEY_GCC_VERSION_CHECK(3,3,0) || \
  HEDLEY_INTEL_VERSION_CHECK(13,0,0) || \
  HEDLEY_IBM_VERSION_CHECK(13,1,0)
#  define SIMDE_MAY_ALIAS __attribute__((__may_alias__))
#else
#  define SIMDE_MAY_ALIAS
#endif

/*  Lots of compilers support GCC-style vector extensions, but many
    don't support all the features.  Define different macros depending
    on support for
    
    * SIMDE_VECTOR - Declaring a vector.
    * SIMDE_VECTOR_OPS - basic operations (binary and unary).
    * SIMDE_VECTOR_SCALAR - For binary operators, the second argument
        can be a scalar, in which case the result is as if that scalar
        had been broadcast to all lanes of a vector.
    * SIMDE_VECTOR_SUBSCRIPT - Supports array subscript notation for
        extracting/inserting a single element.=
    
    SIMDE_VECTOR can be assumed if any others are defined, the
    others are independent. */
#if !defined(SIMDE_NO_VECTOR)
#  if \
    HEDLEY_GCC_VERSION_CHECK(4,8,0)
#    define SIMDE_VECTOR(size) __attribute__((__vector_size__(size)))
#    define SIMDE_VECTOR_OPS
#    define SIMDE_VECTOR_SCALAR
#    define SIMDE_VECTOR_SUBSCRIPT
#  elif HEDLEY_INTEL_VERSION_CHECK(16,0,0)
#    define SIMDE_VECTOR(size) __attribute__((__vector_size__(size)))
#    define SIMDE_VECTOR_OPS
/* ICC only supports SIMDE_VECTOR_SCALAR for constants */
#    define SIMDE_VECTOR_SUBSCRIPT
#  elif \
    HEDLEY_GCC_VERSION_CHECK(4,1,0) || \
    HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#    define SIMDE_VECTOR(size) __attribute__((__vector_size__(size)))
#    define SIMDE_VECTOR_OPS
#  elif HEDLEY_SUNPRO_VERSION_CHECK(5,12,0)
#    define SIMDE_VECTOR(size) __attribute__((__vector_size__(size)))
#  elif HEDLEY_HAS_ATTRIBUTE(vector_size)
#    define SIMDE_VECTOR(size) __attribute__((__vector_size__(size)))
#    define SIMDE_VECTOR_OPS
#    define SIMDE_VECTOR_SUBSCRIPT
#    if HEDLEY_HAS_ATTRIBUTE(diagnose_if) /* clang 4.0 */
#      define SIMDE_VECTOR_SCALAR
#    endif
#  endif

/* GCC and clang have built-in functions to handle shuffling and
   converting of vectors, but the implementations are slightly
   different.  This macro is just an abstraction over them.  Note that
   elem_size is in bits but vec_size is in bytes. */
#  if !defined(SIMDE_NO_SHUFFLE_VECTOR) && defined(SIMDE_VECTOR_SUBSCRIPT)
#    if HEDLEY_HAS_BUILTIN(__builtin_shufflevector)
#      define SIMDE__SHUFFLE_VECTOR(elem_size, vec_size, a, b, ...) __builtin_shufflevector(a, b, __VA_ARGS__)
#    elif HEDLEY_GCC_HAS_BUILTIN(__builtin_shuffle,4,7,0) && !defined(__INTEL_COMPILER)
#      define SIMDE__SHUFFLE_VECTOR(elem_size, vec_size, a, b, ...) (__extension__ ({ \
         int##elem_size##_t SIMDE_VECTOR(vec_size) simde_shuffle_ = { __VA_ARGS__ }; \
           __builtin_shuffle(a, b, simde_shuffle_); \
         }))
#    endif
#  endif

/* TODO: this actually works on XL C/C++ without SIMDE_VECTOR_SUBSCRIPT
   but the code needs to be refactored a bit to take advantage. */
#  if !defined(SIMDE_NO_CONVERT_VECTOR) && defined(SIMDE_VECTOR_SUBSCRIPT)
#    if HEDLEY_HAS_BUILTIN(__builtin_convertvector) || HEDLEY_GCC_VERSION_CHECK(9,0,0)
/* https://gcc.gnu.org/bugzilla/show_bug.cgi?id=93557 */
#      define SIMDE__CONVERT_VECTOR(to, from) ((to) = (__extension__({ \
           __typeof__(from) from_ = (from); \
           ((void) from_); \
           __builtin_convertvector(from_, __typeof__(to)); \
         })))
#    endif
#  endif
#endif

/* Since we currently require SUBSCRIPT before using a vector in a
   union, we define these as dependencies of SUBSCRIPT.  They are
   likely to disappear in the future, once SIMDe learns how to make
   use of vectors without using the union members.  Do not use them
   in your code unless you're okay with it breaking when SIMDe
   changes. */
#if defined(SIMDE_VECTOR_SUBSCRIPT)
#  if defined(SIMDE_VECTOR_OPS)
#    define SIMDE_VECTOR_SUBSCRIPT_OPS
#  endif
#  if defined(SIMDE_VECTOR_SCALAR)
#    define SIMDE_VECTOR_SUBSCRIPT_SCALAR
#  endif
#endif

#if !defined(SIMDE_ENABLE_OPENMP) && ((defined(_OPENMP) && (_OPENMP >= 201307L)) || (defined(_OPENMP_SIMD) && (_OPENMP_SIMD >= 201307L)))
#  define SIMDE_ENABLE_OPENMP
#endif

#if !defined(SIMDE_ENABLE_CILKPLUS) && (defined(__cilk) || defined(HEDLEY_INTEL_VERSION))
#  define SIMDE_ENABLE_CILKPLUS
#endif

#if defined(SIMDE_ENABLE_OPENMP)
#  define SIMDE__VECTORIZE _Pragma("omp simd")
#  define SIMDE__VECTORIZE_SAFELEN(l) HEDLEY_PRAGMA(omp simd safelen(l))
#  define SIMDE__VECTORIZE_REDUCTION(r) HEDLEY_PRAGMA(omp simd reduction(r))
#  define SIMDE__VECTORIZE_ALIGNED(a) HEDLEY_PRAGMA(omp simd aligned(a))
#elif defined(SIMDE_ENABLE_CILKPLUS)
#  define SIMDE__VECTORIZE _Pragma("simd")
#  define SIMDE__VECTORIZE_SAFELEN(l) HEDLEY_PRAGMA(simd vectorlength(l))
#  define SIMDE__VECTORIZE_REDUCTION(r) HEDLEY_PRAGMA(simd reduction(r))
#  define SIMDE__VECTORIZE_ALIGNED(a) HEDLEY_PRAGMA(simd aligned(a))
#elif defined(__clang__)
#  define SIMDE__VECTORIZE _Pragma("clang loop vectorize(enable)")
#  define SIMDE__VECTORIZE_SAFELEN(l) HEDLEY_PRAGMA(clang loop vectorize_width(l))
#  define SIMDE__VECTORIZE_REDUCTION(r) SIMDE__VECTORIZE
#  define SIMDE__VECTORIZE_ALIGNED(a)
#elif HEDLEY_GCC_VERSION_CHECK(4,9,0)
#  define SIMDE__VECTORIZE _Pragma("GCC ivdep")
#  define SIMDE__VECTORIZE_SAFELEN(l) SIMDE__VECTORIZE
#  define SIMDE__VECTORIZE_REDUCTION(r) SIMDE__VECTORIZE
#  define SIMDE__VECTORIZE_ALIGNED(a)
#elif HEDLEY_CRAY_VERSION_CHECK(5,0,0)
#  define SIMDE__VECTORIZE _Pragma("_CRI ivdep")
#  define SIMDE__VECTORIZE_SAFELEN(l) SIMDE__VECTORIZE
#  define SIMDE__VECTORIZE_REDUCTION(r) SIMDE__VECTORIZE
#  define SIMDE__VECTORIZE_ALIGNED(a)
#else
#  define SIMDE__VECTORIZE
#  define SIMDE__VECTORIZE_SAFELEN(l)
#  define SIMDE__VECTORIZE_REDUCTION(r)
#  define SIMDE__VECTORIZE_ALIGNED(a)
#endif

#define SIMDE__MASK_NZ(v, mask) (((v) & (mask)) | !((v) & (mask)))

/* Intended for checking coverage, you should never use this in
   production. */
#if defined(SIMDE_NO_INLINE)
#  define SIMDE__FUNCTION_ATTRIBUTES HEDLEY_NEVER_INLINE static
#else
#  define SIMDE__FUNCTION_ATTRIBUTES HEDLEY_ALWAYS_INLINE static
#endif

#if HEDLEY_HAS_WARNING("-Wused-but-marked-unused")
#  define SIMDE_DIAGNOSTIC_DISABLE_USED_BUT_MARKED_UNUSED _Pragma("clang diagnostic ignored \"-Wused-but-marked-unused\"")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_USED_BUT_MARKED_UNUSED
#endif

#if defined(_MSC_VER)
#  define SIMDE__BEGIN_DECLS HEDLEY_DIAGNOSTIC_PUSH __pragma(warning(disable:4996 4204)) HEDLEY_BEGIN_C_DECLS
#  define SIMDE__END_DECLS HEDLEY_DIAGNOSTIC_POP HEDLEY_END_C_DECLS
#else
#  define SIMDE__BEGIN_DECLS \
     HEDLEY_DIAGNOSTIC_PUSH \
     SIMDE_DIAGNOSTIC_DISABLE_USED_BUT_MARKED_UNUSED \
     HEDLEY_BEGIN_C_DECLS
#  define SIMDE__END_DECLS \
     HEDLEY_END_C_DECLS \
     HEDLEY_DIAGNOSTIC_POP
#endif

#if HEDLEY_HAS_WARNING("-Wpedantic")
#  define SIMDE_DIAGNOSTIC_DISABLE_INT128 _Pragma("clang diagnostic ignored \"-Wpedantic\"")
#elif defined(HEDLEY_GCC_VERSION)
#  define SIMDE_DIAGNOSTIC_DISABLE_INT128 _Pragma("GCC diagnostic ignored \"-Wpedantic\"")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_INT128
#endif

#if defined(__SIZEOF_INT128__)
#  define SIMDE__HAVE_INT128
HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_INT128
typedef __int128 simde_int128;
typedef unsigned __int128 simde_uint128;
HEDLEY_DIAGNOSTIC_POP
#endif

/* TODO: we should at least make an attempt to detect the correct
   types for simde_float32/float64 instead of just assuming float and
   double. */

#if !defined(SIMDE_FLOAT32_TYPE)
#  define SIMDE_FLOAT32_TYPE float
#  define SIMDE_FLOAT32_C(value) value##f
#else
#  define SIMDE_FLOAT32_C(value) ((SIMDE_FLOAT32_TYPE) value)
#endif
typedef SIMDE_FLOAT32_TYPE simde_float32;
HEDLEY_STATIC_ASSERT(sizeof(simde_float32) == 4, "Unable to find 32-bit floating-point type.");

#if !defined(SIMDE_FLOAT64_TYPE)
#  define SIMDE_FLOAT64_TYPE double
#  define SIMDE_FLOAT64_C(value) value
#else
#  define SIMDE_FLOAT32_C(value) ((SIMDE_FLOAT64_TYPE) value)
#endif
typedef SIMDE_FLOAT64_TYPE simde_float64;
HEDLEY_STATIC_ASSERT(sizeof(simde_float64) == 8, "Unable to find 64-bit floating-point type.");

/* Whether to assume that the compiler can auto-vectorize reasonably
   well.  This will cause SIMDe to attempt to compose vector
   operations using more simple vector operations instead of minimize
   serial work.

   As an example, consider the _mm_add_ss(a, b) function from SSE,
   which returns { a0 + b0, a1, a2, a3 }.  This pattern is repeated
   for other operations (sub, mul, etc.).

   The naïve implementation would result in loading a0 and b0, adding
   them into a temporary variable, then splicing that value into a new
   vector with the remaining elements from a.

   On platforms which support vectorization, it's generally faster to
   simply perform the operation on the entire vector to avoid having
   to move data between SIMD registers and non-SIMD registers.
   Basically, instead of the temporary variable being (a0 + b0) it
   would be a vector of (a + b), which is then combined with a to form
   the result.

   By default, SIMDe will prefer the pure-vector versions if we detect
   a vector ISA extension, but this can be overridden by defining
   SIMDE_NO_ASSUME_VECTORIZATION.  You can also define
   SIMDE_ASSUME_VECTORIZATION if you want to force SIMDe to use the
   vectorized version. */
#if !defined(SIMDE_NO_ASSUME_VECTORIZATION) && !defined(SIMDE_ASSUME_VECTORIZATION)
#  if defined(__SSE__) || defined(__ARM_NEON) || defined(__mips_msa) || defined(__ALTIVEC__)
#    define SIMDE_ASSUME_VECTORIZATION
#  endif
#endif

#if HEDLEY_HAS_WARNING("-Wbad-function-cast")
#  define SIMDE_CONVERT_FTOI(T,v) \
    HEDLEY_DIAGNOSTIC_PUSH \
    _Pragma("clang diagnostic ignored \"-Wbad-function-cast\"") \
    HEDLEY_STATIC_CAST(T, (v)) \
    HEDLEY_DIAGNOSTIC_POP
#else
#  define SIMDE_CONVERT_FTOI(T,v) ((T) (v))
#endif


#if HEDLEY_HAS_WARNING("-Wfloat-equal")
#  define SIMDE_DIAGNOSTIC_DISABLE_FLOAT_EQUAL _Pragma("clang diagnostic ignored \"-Wfloat-equal\"")
#elif HEDLEY_GCC_VERSION_CHECK(3,0,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_FLOAT_EQUAL _Pragma("GCC diagnostic ignored \"-Wfloat-equal\"")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_FLOAT_EQUAL
#endif

/* Some algorithms are iterative, and fewer iterations means less
   accuracy.  Lower values here will result in faster, but less
   accurate, calculations for some functions. */
#if !defined(SIMDE_ACCURACY_ITERS)
#  define SIMDE_ACCURACY_ITERS 2
#endif

#if defined(SIMDE__ASSUME_ALIGNED)
#  undef SIMDE__ASSUME_ALIGNED
#endif
#if HEDLEY_INTEL_VERSION_CHECK(9,0,0)
#  define SIMDE__ASSUME_ALIGNED(ptr, align) __assume_aligned(ptr, align)
#elif HEDLEY_MSVC_VERSION_CHECK(13,10,0)
#  define SIMDE__ASSUME_ALIGNED(ptr, align) __assume((((char*) ptr) - ((char*) 0)) % (align) == 0)
#elif HEDLEY_GCC_HAS_BUILTIN(__builtin_assume_aligned,4,7,0)
#  define SIMDE__ASSUME_ALIGNED(ptr, align) (ptr = (__typeof__(ptr)) __builtin_assume_aligned((ptr), align))
#elif HEDLEY_CLANG_HAS_BUILTIN(__builtin_assume)
#  define SIMDE__ASSUME_ALIGNED(ptr, align) __builtin_assume((((char*) ptr) - ((char*) 0)) % (align) == 0)
#elif HEDLEY_GCC_HAS_BUILTIN(__builtin_unreachable,4,5,0)
#  define SIMDE__ASSUME_ALIGNED(ptr, align) ((((char*) ptr) - ((char*) 0)) % (align) == 0) ? (1) : (__builtin_unreachable(), 0)
#else
#  define SIMDE__ASSUME_ALIGNED(ptr, align)
#endif

/* This is only to help us implement functions like _mm_undefined_ps. */
#if defined(SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_)
#  undef SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_
#endif
#if HEDLEY_HAS_WARNING("-Wuninitialized")
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("clang diagnostic ignored \"-Wuninitialized\"")
#elif HEDLEY_GCC_VERSION_CHECK(4,2,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("GCC diagnostic ignored \"-Wuninitialized\"")
#elif HEDLEY_PGI_VERSION_CHECK(19,10,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("diag_suppress 549")
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,14,0) && defined(__cplusplus)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("error_messages(off,SEC_UNINITIALIZED_MEM_READ,SEC_UNDEFINED_RETURN_VALUE,unassigned)")
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,14,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("error_messages(off,SEC_UNINITIALIZED_MEM_READ,SEC_UNDEFINED_RETURN_VALUE)")
#elif HEDLEY_SUNPRO_VERSION_CHECK(5,12,0) && defined(__cplusplus)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("error_messages(off,unassigned)")
/* #elif \
     HEDLEY_TI_VERSION_CHECK(16,9,9) || \
     HEDLEY_TI_CL6X_VERSION_CHECK(8,0,0) || \
     HEDLEY_TI_CL7X_VERSION_CHECK(1,2,0) || \
     HEDLEY_TI_CLPRU_VERSION_CHECK(2,3,2)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("diag_suppress 551") */
#elif HEDLEY_INTEL_VERSION_CHECK(13,0,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ _Pragma("warning(disable:592)")
#elif HEDLEY_MSVC_VERSION_CHECK(19,0,0) && !defined(__MSVC_RUNTIME_CHECKS)
#  define SIMDE_DIAGNOSTIC_DISABLE_UNINITIALIZED_ __pragma(warning(disable:4700))
#endif

#if HEDLEY_GCC_VERSION_CHECK(8,0,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_PSABI_ _Pragma("GCC diagnostic ignored \"-Wpsabi\"")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_PSABI_
#endif

#if HEDLEY_INTEL_VERSION_CHECK(19,0,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_NO_EMMS_INSTRUCTION_ _Pragma("warning(disable:13200 13203)")
#elif defined(HEDLEY_MSVC_VERSION)
#  define SIMDE_DIAGNOSTIC_DISABLE_NO_EMMS_INSTRUCTION_ __pragma(warning(disable:4799))
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_NO_EMMS_INSTRUCTION_
#endif

#if HEDLEY_INTEL_VERSION_CHECK(18,0,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_SIMD_PRAGMA_DEPRECATED_ _Pragma("warning(disable:3948)")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_SIMD_PRAGMA_DEPRECATED_
#endif

#if \
  HEDLEY_HAS_WARNING("-Wtautological-compare") || \
  HEDLEY_GCC_VERSION_CHECK(8,0,0)
#  if defined(__cplusplus)
#    if (__cplusplus >= 201402L)
#      define SIMDE_TAUTOLOGICAL_COMPARE_(expr) \
        (([](auto expr_){ \
          HEDLEY_DIAGNOSTIC_PUSH \
          _Pragma("GCC diagnostic ignored \"-Wtautological-compare\"") \
          return (expr_); \
          HEDLEY_DIAGNOSTIC_POP \
        })(expr))
#    endif
#  else
#    define SIMDE_TAUTOLOGICAL_COMPARE_(expr) \
       (__extension__ ({ \
         HEDLEY_DIAGNOSTIC_PUSH \
         _Pragma("GCC diagnostic ignored \"-Wtautological-compare\"") \
         (expr); \
         HEDLEY_DIAGNOSTIC_POP \
     }))
#  endif
#endif
#if !defined(SIMDE_TAUTOLOGICAL_COMPARE_)
#  define SIMDE_TAUTOLOGICAL_COMPARE_(expr) (expr)
#endif

#if \
  HEDLEY_HAS_WARNING("-Wconditional-uninitialized")
#  define SIMDE_DIAGNOSTIC_DISABLE_CONDITIONAL_UNINITIALIZED_ _Pragma("clang diagnostic ignored \"-Wconditional-uninitialized\"")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_CONDITIONAL_UNINITIALIZED_
#endif

#if \
  HEDLEY_HAS_WARNING("-Wfloat-equal") || \
  HEDLEY_GCC_VERSION_CHECK(3,0,0)
#  define SIMDE_DIAGNOSTIC_DISABLE_FLOAT_EQUAL_ _Pragma("GCC diagnostic ignored \"-Wfloat-equal\"")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_FLOAT_EQUAL_
#endif

#if HEDLEY_HAS_WARNING("-Wcast-align")
#  define SIMDE_DIAGNOSTIC_DISABLE_CAST_ALIGN_ _Pragma("clang diagnostic ignored \"-Wcast-align\"")
#else
#  define SIMDE_DIAGNOSTIC_DISABLE_CAST_ALIGN_
#endif

#define SIMDE_DISABLE_UNWANTED_DIAGNOSTICS \
  SIMDE_DIAGNOSTIC_DISABLE_PSABI_ \
  SIMDE_DIAGNOSTIC_DISABLE_NO_EMMS_INSTRUCTION_ \
  SIMDE_DIAGNOSTIC_DISABLE_SIMD_PRAGMA_DEPRECATED_ \
  SIMDE_DIAGNOSTIC_DISABLE_CONDITIONAL_UNINITIALIZED_ \
  SIMDE_DIAGNOSTIC_DISABLE_FLOAT_EQUAL_

/* Sometimes we run into problems with specific versions of compilers
   which make the native versions unusable for us.  Often this is due
   to missing functions, sometimes buggy implementations, etc.  These
   macros are how we check for specific bugs.  As they are fixed we'll
   start only defining them for problematic compiler versions. */

#if !defined(SIMDE_IGNORE_COMPILER_BUGS)
#  if !HEDLEY_GCC_VERSION_CHECK(4,9,0)
#    define SIMDE_BUG_GCC_REV_208793
#  endif
#  if !HEDLEY_GCC_VERSION_CHECK(5,0,0)
#    define SIMDE_BUG_GCC_BAD_MM_SRA_EPI32 /* TODO: find relevant bug or commit */
#  endif
#  if !HEDLEY_GCC_VERSION_CHECK(4,6,0)
#    define SIMDE_BUG_GCC_BAD_MM_EXTRACT_EPI8 /* TODO: find relevant bug or commit */
#  endif
#  if !HEDLEY_GCC_VERSION_CHECK(10,0,0)
#    define SIMDE_BUG_GCC_REV_274313
#  endif
#  if defined(HEDLEY_EMSCRIPTEN_VERSION)
#    define SIMDE_BUG_EMSCRIPTEN_MISSING_IMPL /* Placeholder for (as yet) unfiled issues. */
#    define SIMDE_BUG_EMSCRIPTEN_5242
#  endif
#endif

#endif /* !defined(SIMDE_COMMON_H) */
/* :: End simde-common.h :: */

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#  if defined(SIMDE_MMX_FORCE_NATIVE)
#    define SIMDE_MMX_NATIVE
#  elif (defined(__MMX__) || (defined(_MSC_VER) && defined(_M_IX86))) && !defined(SIMDE_MMX_NO_NATIVE) && !defined(SIMDE_NO_NATIVE)
#    define SIMDE_MMX_NATIVE
#  elif defined(__ARM_NEON) && !defined(SIMDE_MMX_NO_NEON) && !defined(SIMDE_NO_NEON)
#    define SIMDE_MMX_NEON
#  endif

#  if defined(SIMDE_MMX_NATIVE)
#    include <mmintrin.h>
#  else
#    if defined(SIMDE_MMX_NEON)
#      include <arm_neon.h>
#    endif
#  endif
#  include <stdint.h>
#  include <limits.h>
#  include <stdlib.h>
#  include <string.h>

SIMDE__BEGIN_DECLS

typedef union {
#if defined(SIMDE_VECTOR_SUBSCRIPT)
  SIMDE_ALIGN(8) int8_t          i8 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) int16_t        i16 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) int32_t        i32 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) int64_t        i64 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) uint8_t         u8 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) uint16_t       u16 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) uint32_t       u32 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) uint64_t       u64 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) simde_float32  f32 SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) int_fast32_t  i32f SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
  SIMDE_ALIGN(8) uint_fast32_t u32f SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
#else
  SIMDE_ALIGN(8) int8_t          i8[8];
  SIMDE_ALIGN(8) int16_t        i16[4];
  SIMDE_ALIGN(8) int32_t        i32[2];
  SIMDE_ALIGN(8) int64_t        i64[1];
  SIMDE_ALIGN(8) uint8_t         u8[8];
  SIMDE_ALIGN(8) uint16_t       u16[4];
  SIMDE_ALIGN(8) uint32_t       u32[2];
  SIMDE_ALIGN(8) uint64_t       u64[1];
  SIMDE_ALIGN(8) simde_float32  f32[2];
  SIMDE_ALIGN(8) int_fast32_t  i32f[8 / sizeof(int_fast32_t)];
  SIMDE_ALIGN(8) uint_fast32_t u32f[8 / sizeof(uint_fast32_t)];
#endif

#if defined(SIMDE_MMX_NATIVE)
  __m64          n;
#elif defined(SIMDE_MMX_NEON)
  int8x8_t       neon_i8;
  int16x4_t      neon_i16;
  int32x2_t      neon_i32;
  int64x1_t      neon_i64;
  uint8x8_t      neon_u8;
  uint16x4_t     neon_u16;
  uint32x2_t     neon_u32;
  uint64x1_t     neon_u64;
  float32x2_t    neon_f32;
#endif
} simde__m64_private;

#if defined(SIMDE_MMX_NATIVE)
  typedef __m64 simde__m64;
#elif defined(SIMDE_MMX_NEON)
  typedef int32x2_t simde__m64;
#elif defined(SIMDE_VECTOR_SUBSCRIPT)
  typedef int32_t simde__m64 SIMDE_ALIGN(8) SIMDE_VECTOR(8) SIMDE_MAY_ALIAS;
#else
  typedef simde__m64_private simde__m64;
#endif

#if !defined(SIMDE_MMX_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
  #define SIMDE_MMX_ENABLE_NATIVE_ALIASES
  typedef simde__m64 __m64;
#endif

HEDLEY_STATIC_ASSERT(8 == sizeof(simde__m64), "__m64 size incorrect");
HEDLEY_STATIC_ASSERT(8 == sizeof(simde__m64_private), "__m64 size incorrect");
#if defined(SIMDE_CHECK_ALIGNMENT) && defined(SIMDE_ALIGN_OF)
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m64) == 8, "simde__m64 is not 8-byte aligned");
HEDLEY_STATIC_ASSERT(SIMDE_ALIGN_OF(simde__m64_private) == 8, "simde__m64_private is not 8-byte aligned");
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde__m64_from_private(simde__m64_private v) {
  simde__m64 r;
  memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64_private
simde__m64_to_private(simde__m64 v) {
  simde__m64_private r;
  memcpy(&r, &v, sizeof(r));
  return r;
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_add_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_add_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

  #if defined(SIMDE_MMX_NEON)
    r_.neon_i8 = vadd_s8(a_.neon_i8, b_.neon_i8);
  #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
    r_.i8 = a_.i8 + b_.i8;
  #else
    SIMDE__VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
      r_.i8[i] = a_.i8[i] + b_.i8[i];
    }
  #endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_paddb(a, b) simde_mm_add_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_add_pi8(a, b) simde_mm_add_pi8(a, b)
#  define _m_paddb(a, b) simde_m_paddb(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_add_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_add_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vadd_s16(a_.neon_i16, b_.neon_i16);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 + b_.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i] + b_.i16[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_paddw(a, b) simde_mm_add_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_add_pi16(a, b) mm_add_pi16(a, b)
#  define _m_add_paddw(a, b) mm_add_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_add_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_add_pi32(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vadd_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = a_.i32 + b_.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] + b_.i32[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_paddd(a, b) simde_mm_add_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_add_pi32(a, b) mm_add_pi32(a, b)
#  define _m_add_paddd(a, b) mm_add_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_adds_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i8 = vqadd_s8(a_.neon_i8, b_.neon_i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    if ((((b_.i8[i]) > 0) && ((a_.i8[i]) > (INT8_MAX - (b_.i8[i]))))) {
      r_.i8[i] = INT8_MAX;
    } else if ((((b_.i8[i]) < 0) && ((a_.i8[i]) < (INT8_MIN - (b_.i8[i]))))) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (a_.i8[i]) + (b_.i8[i]);
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_paddsb(a, b) simde_mm_adds_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pi8(a, b) mm_adds_pi8(a, b)
#  define _m_add_paddsb(a, b) mm_adds_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_adds_pu8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_u8 = vqadd_u8(a_.neon_u8, b_.neon_u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    const uint_fast16_t x = ((uint_fast16_t) a_.u8[i]) + ((uint_fast16_t) b_.u8[i]);
    if (x > UINT8_MAX)
      r_.u8[i] = UINT8_MAX;
    else
      r_.u8[i] = (uint8_t) x;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_paddusb(a, b) simde_mm_adds_pu8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pu8(a, b) mm_adds_pu8(a, b)
#  define _m_paddusb(a, b) mm_adds_pu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_adds_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vqadd_s16(a_.neon_i16, b_.neon_i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    if ((((b_.i16[i]) > 0) && ((a_.i16[i]) > (INT16_MAX - (b_.i16[i]))))) {
      r_.i16[i] = INT16_MAX;
    } else if ((((b_.i16[i]) < 0) && ((a_.i16[i]) < (SHRT_MIN - (b_.i16[i]))))) {
      r_.i16[i] = SHRT_MIN;
    } else {
      r_.i16[i] = (a_.i16[i]) + (b_.i16[i]);
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_paddsw(a, b) simde_mm_adds_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pi16(a, b) mm_adds_pi16(a, b)
#  define _m_paddsw(a, b) mm_adds_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_adds_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_adds_pu16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_u16 = vqadd_u16(a_.neon_u16, b_.neon_u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    const uint32_t x = a_.u16[i] + b_.u16[i];
    if (x > UINT16_MAX)
      r_.u16[i] = UINT16_MAX;
    else
      r_.u16[i] = (uint16_t) x;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_paddusw(a, b) simde_mm_adds_pu16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_adds_pu16(a, b) mm_adds_pu16(a, b)
#  define _m_paddusw(a, b) mm_adds_pu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_and_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_and_si64(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vand_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i64 = a_.i64 & b_.i64;
#else
  r_.i64[0] = a_.i64[0] & b_.i64[0];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pand(a, b) simde_mm_and_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_and_si64(a, b) mm_and_si64(a, b)
#  define _m_pand(a, b) mm_and_si64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_andnot_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_andnot_si64(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vbic_s32(b_.neon_i32, a_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = ~a_.i32f & b_.i32f;
#else
  r_.u64[0] = (~(a_.u64[0])) & (b_.u64[0]);
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pandn(a, b) simde_mm_andnot_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_andnot_si64(a, b) mm_andnot_si64(a, b)
#  define _m_pandn(a, b) mm_andnot_si64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpeq_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cmpeq_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i8 = vreinterpret_s8_u8(vceq_s8(a_.neon_i8, b_.neon_i8));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (a_.i8[i] == b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pcmpeqb(a, b) simde_mm_cmpeq_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_pi8(a, b) mm_cmpeq_pi8(a, b)
#  define _m_pcmpeqb(a, b) mm_cmpeq_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpeq_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cmpeq_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vreinterpret_s16_u16(vceq_s16(a_.neon_i16, b_.neon_i16));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] == b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pcmpeqw(a, b) simde_mm_cmpeq_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_pi16(a, b) mm_cmpeq_pi16(a, b)
#  define _m_pcmpeqw(a, b) mm_cmpeq_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpeq_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cmpeq_pi32(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vreinterpret_s32_u32(vceq_s32(a_.neon_i32, b_.neon_i32));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (a_.i32[i] == b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pcmpeqd(a, b) simde_mm_cmpeq_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpeq_pi32(a, b) mm_cmpeq_pi32(a, b)
#  define _m_pcmpeqd(a, b) mm_cmpeq_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpgt_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cmpgt_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i8 = vreinterpret_s8_u8(vcgt_s8(a_.neon_i8, b_.neon_i8));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = (a_.i8[i] > b_.i8[i]) ? ~INT8_C(0) : INT8_C(0);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pcmpgtb(a, b) simde_mm_cmpgt_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_pi8(a, b) mm_cmpgt_pi8(a, b)
#  define _m_pcmpgtb(a, b) mm_cmpgt_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpgt_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cmpgt_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vreinterpret_s16_u16(vcgt_s16(a_.neon_i16, b_.neon_i16));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (a_.i16[i] > b_.i16[i]) ? ~INT16_C(0) : INT16_C(0);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pcmpgtw(a, b) simde_mm_cmpgt_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_pi16(a, b) mm_cmpgt_pi16(a, b)
#  define _m_pcmpgtw(a, b) mm_cmpgt_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cmpgt_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cmpgt_pi32(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vreinterpret_s32_u32(vcgt_s32(a_.neon_i32, b_.neon_i32));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = (a_.i32[i] > b_.i32[i]) ? ~INT32_C(0) : INT32_C(0);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pcmpgtd(a, b) simde_mm_cmpgt_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cmpgt_pi32(a, b) mm_cmpgt_pi32(a, b)
#  define _m_pcmpgtd(a, b) mm_cmpgt_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int64_t
simde_mm_cvtm64_si64 (simde__m64 a) {
#if defined(SIMDE_MMX_NATIVE) && defined(SIMDE_ARCH_AMD64) && !defined(__PGI)
  return _mm_cvtm64_si64(a);
#else
  simde__m64_private a_ = simde__m64_to_private(a);
  
  #if defined(SIMDE_MMX_NEON)
    return vget_lane_s64(a_.neon_i64, 0);
  #else
    return a_.i64[0];
  #endif
#endif
}
#define simde_m_to_int64(a) simde_mm_cvtm64_si64(a)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtm64_si64(a) simde_mm_cvtm64_si64(a)
#  define _m_to_int64(a) simde_mm_cvtm64_si64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtsi32_si64 (int32_t a) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cvtsi32_si64(a);
#else
  simde__m64_private r_;

#if defined(SIMDE_MMX_NEON)
  const int32_t av[sizeof(r_.neon_i32) / sizeof(r_.neon_i32[0])] = { a, 0 };
  r_.neon_i32 = vld1_s32(av);
#else
  r_.i32[0] = a;
  r_.i32[1] = 0;
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_from_int(a) simde_mm_cvtsi32_si64(a)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi32_si64(a) mm_cvtsi32_si64(a)
#  define _m_from_int(a) mm_cvtsi32_si64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_cvtsi64_m64 (int64_t a) {
#if defined(SIMDE_MMX_NATIVE) && defined(SIMDE_ARCH_AMD64) && !defined(__PGI)
  return _mm_cvtsi64_m64(a);
#else
  simde__m64_private r_;

#if defined(SIMDE_MMX_NEON)
  r_.neon_i64 = vld1_s64(&a);
#else
  r_.i64[0] = a;
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_from_int64(a) simde_mm_cvtsi64_m64(a)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi64_m64(a) mm_cvtsi64_m64(a)
#  define _m_from_int64(a) mm_cvtsi64_m64(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_mm_cvtsi64_si32 (simde__m64 a) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_cvtsi64_si32(a);
#else
  simde__m64_private a_ = simde__m64_to_private(a);

  #if defined(SIMDE_MMX_NEON)
    return vget_lane_s32(a_.neon_i32, 0);
  #else
    return a_.i32[0];
  #endif
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_cvtsi64_si32(a) simde_mm_cvtsi64_si32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
void
simde_mm_empty (void) {
#if defined(SIMDE_MMX_NATIVE)
  _mm_empty();
#else
#endif
}
#define simde_m_empty() simde_mm_empty()
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_empty() SIMDE__M64_TO_NATIVE(simde_mm_empty())
#  define _m_empty() SIMDE__M64_TO_NATIVE(simde_mm_empty())
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_madd_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_madd_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  int32x4_t i1 = vmull_s16(a_.neon_i16, b_.neon_i16);
  r_.neon_i32 = vpadd_s32(vget_low_s32(i1), vget_high_s32(i1));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i += 2) {
    r_.i32[i / 2] = (a_.i16[i] * b_.i16[i]) + (a_.i16[i + 1] * b_.i16[i + 1]);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pmaddwd(a, b) simde_mm_madd_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_madd_pi16(a, b) mm_madd_pi16(a, b)
#  define _m_pmaddwd(a, b) mm_madd_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mulhi_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_mulhi_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  const int32x4_t t1 = vmull_s16(a_.neon_i16, b_.neon_i16);
  const uint32x4_t t2 = vshrq_n_u32(vreinterpretq_u32_s32(t1), 16);
  const uint16x4_t t3 = vmovn_u32(t2);
  r_.neon_i16 = vreinterpret_s16_u16(t3);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (int16_t) ((a_.i16[i] * b_.i16[i]) >> 16);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pmulhw(a, b) simde_mm_mulhi_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_mulhi_pi16(a, b) mm_mulhi_pi16(a, b)
#  define _m_pmulhw(a, b) mm_mulhi_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_mullo_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_mullo_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  const int32x4_t t1 = vmull_s16(a_.neon_i16, b_.neon_i16);
  const uint16x4_t t2 = vmovn_u32(vreinterpretq_u32_s32(t1));
  r_.neon_i16 = vreinterpret_s16_u16(t2);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = (int16_t) ((a_.i16[i] * b_.i16[i]) & 0xffff);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pmullw(a, b) simde_mm_mullo_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_mullo_pi16(a, b) mm_mullo_pi16(a, b)
#  define _m_pmullw(a, b) mm_mullo_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_or_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_or_si64(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vorr_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i64 = a_.i64 | b_.i64;
#else
  r_.i64[0] = a_.i64[0] | b_.i64[0];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_por(a, b) simde_mm_or_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_or_si64(a, b) mm_or_si64(a, b)
#  define _m_por(a, b) mm_or_si64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_packs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_packs_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i8 = vqmovn_s16(vcombine_s16(a_.neon_i16, b_.neon_i16));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    if (a_.i16[i] < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else if (a_.i16[i] > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else {
      r_.i8[i] = (int8_t) a_.i16[i];
    }
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    if (b_.i16[i] < INT8_MIN) {
      r_.i8[i + 4] = INT8_MIN;
    } else if (b_.i16[i] > INT8_MAX) {
      r_.i8[i + 4] = INT8_MAX;
    } else {
      r_.i8[i + 4] = (int8_t) b_.i16[i];
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_packsswb(a, b) simde_mm_packs_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_packs_pi16(a, b) mm_packs_pi16(a, b)
#  define _m_packsswb(a, b) mm_packs_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_packs_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_packs_pi32(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vqmovn_s32(vcombine_s32(a_.neon_i32, b_.neon_i32));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (8 / sizeof(a_.i32[0])) ; i++) {
    if (a_.i32[i] < SHRT_MIN) {
      r_.i16[i] = SHRT_MIN;
    } else if (a_.i32[i] > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else {
      r_.i16[i] = (int16_t) a_.i32[i];
    }
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (8 / sizeof(b_.i32[0])) ; i++) {
    if (b_.i32[i] < SHRT_MIN) {
      r_.i16[i + 2] = SHRT_MIN;
    } else if (b_.i32[i] > INT16_MAX) {
      r_.i16[i + 2] = INT16_MAX;
    } else {
      r_.i16[i + 2] = (int16_t) b_.i32[i];
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_packssdw(a, b) simde_mm_packs_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_packs_pi32(a, b) mm_packs_pi32(a, b)
#  define _m_packssdw(a, b) mm_packs_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_packs_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_packs_pu16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  const int16x8_t t1 = vcombine_s16(a_.neon_i16, b_.neon_i16);

  /* Set elements which are < 0 to 0 */
  const int16x8_t t2 = vandq_s16(t1, vreinterpretq_s16_u16(vcgezq_s16(t1)));

  /* Vector with all s16 elements set to UINT8_MAX */
  const int16x8_t vmax = vmovq_n_s16((int16_t) UINT8_MAX);

  /* Elements which are within the acceptable range */
  const int16x8_t le_max = vandq_s16(t2, vreinterpretq_s16_u16(vcleq_s16(t2, vmax)));
  const int16x8_t gt_max = vandq_s16(vmax, vreinterpretq_s16_u16(vcgtq_s16(t2, vmax)));

  /* Final values as 16-bit integers */
  const int16x8_t values = vorrq_s16(le_max, gt_max);

  r_.neon_u8 = vmovn_u16(vreinterpretq_u16_s16(values));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    if (a_.i16[i] > UINT8_MAX) {
      r_.u8[i] = UINT8_MAX;
    } else if (a_.i16[i] < 0) {
      r_.u8[i] = 0;
    } else {
      r_.u8[i] = (uint8_t) a_.i16[i];
    }
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    if (b_.i16[i] > UINT8_MAX) {
      r_.u8[i + 4] = UINT8_MAX;
    } else if (b_.i16[i] < 0) {
      r_.u8[i + 4] = 0;
    } else {
      r_.u8[i + 4] = (uint8_t) b_.i16[i];
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_packuswb(a, b) simde_mm_packs_pu16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_packs_pu16(a, b) mm_packs_pu16(a, b)
#  define _m_packuswb(a, b) mm_packs_pu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set_pi8 (int8_t e7, int8_t e6, int8_t e5, int8_t e4, int8_t e3, int8_t e2, int8_t e1, int8_t e0) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_set_pi8(e7, e6, e5, e4, e3, e2, e1, e0);
#else
  simde__m64_private r_;

#if defined(SIMDE_MMX_NEON)
  const int8_t v[sizeof(r_.i8) / sizeof(r_.i8[0])] = { e0, e1, e2, e3, e4, e5, e6, e7 };
  r_.neon_i8 = vld1_s8(v);
#else
  r_.i8[0] = e0;
  r_.i8[1] = e1;
  r_.i8[2] = e2;
  r_.i8[3] = e3;
  r_.i8[4] = e4;
  r_.i8[5] = e5;
  r_.i8[6] = e6;
  r_.i8[7] = e7;
#endif

  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set_pi8(e7, e6, e5, e4, e3, e2, e1, e0) mm_set_pi8(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_pu8 (uint8_t e7, uint8_t e6, uint8_t e5, uint8_t e4, uint8_t e3, uint8_t e2, uint8_t e1, uint8_t e0) {
  simde__m64_private r_;

#if defined(SIMDE_MMX_NATIVE)
  r_.n = _mm_set_pi8(
      HEDLEY_STATIC_CAST(int8_t, e7),
      HEDLEY_STATIC_CAST(int8_t, e6),
      HEDLEY_STATIC_CAST(int8_t, e5),
      HEDLEY_STATIC_CAST(int8_t, e4),
      HEDLEY_STATIC_CAST(int8_t, e3),
      HEDLEY_STATIC_CAST(int8_t, e2),
      HEDLEY_STATIC_CAST(int8_t, e1),
      HEDLEY_STATIC_CAST(int8_t, e0));
#elif defined(SIMDE_MMX_NEON)
  const uint8_t v[sizeof(r_.u8) / sizeof(r_.u8[0])] = { e0, e1, e2, e3, e4, e5, e6, e7 };
  r_.neon_u8 = vld1_u8(v);
#else
  r_.u8[0] = e0;
  r_.u8[1] = e1;
  r_.u8[2] = e2;
  r_.u8[3] = e3;
  r_.u8[4] = e4;
  r_.u8[5] = e5;
  r_.u8[6] = e6;
  r_.u8[7] = e7;
#endif

  return simde__m64_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set_pi16 (int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_set_pi16(e3, e2, e1, e0);
#else
  simde__m64_private r_;

#if defined(SIMDE_MMX_NEON)
  const int16_t v[sizeof(r_.i16) / sizeof(r_.i16[0])] = { e0, e1, e2, e3 };
  r_.neon_i16 = vld1_s16(v);
#else
  r_.i16[0] = e0;
  r_.i16[1] = e1;
  r_.i16[2] = e2;
  r_.i16[3] = e3;
#endif
  return simde__m64_from_private(r_);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set_pi16(e3, e2, e1, e0) mm_set_pi16(e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_pu16 (uint16_t e3, uint16_t e2, uint16_t e1, uint16_t e0) {
  simde__m64_private r_;

#if defined(SIMDE_MMX_NATIVE)
  r_.n = _mm_set_pi16(
      HEDLEY_STATIC_CAST(int16_t, e3),
      HEDLEY_STATIC_CAST(int16_t, e2),
      HEDLEY_STATIC_CAST(int16_t, e1),
      HEDLEY_STATIC_CAST(int16_t, e0)
    );
#elif defined(SIMDE_MMX_NEON)
  const uint16_t v[sizeof(r_.u16) / sizeof(r_.u16[0])] = { e0, e1, e2, e3 };
  r_.neon_u16 = vld1_u16(v);
#else
  r_.u16[0] = e0;
  r_.u16[1] = e1;
  r_.u16[2] = e2;
  r_.u16[3] = e3;
#endif

  return simde__m64_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_pu32 (uint32_t e1, uint32_t e0) {
  simde__m64_private r_;

#if defined(SIMDE_MMX_NATIVE)
  r_.n = _mm_set_pi32(
      HEDLEY_STATIC_CAST(int32_t, e1),
      HEDLEY_STATIC_CAST(int32_t, e0));
#elif defined(SIMDE_MMX_NEON)
  const uint32_t v[sizeof(r_.u32) / sizeof(r_.u32[0])] = { e0, e1 };
  r_.neon_u32 = vld1_u32(v);
#else
  r_.u32[0] = e0;
  r_.u32[1] = e1;
#endif

  return simde__m64_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set_pi32 (int32_t e1, int32_t e0) {
  simde__m64_private r_;

#if defined(SIMDE_MMX_NATIVE)
  r_.n = _mm_set_pi32(e1, e0);
#elif defined(SIMDE_MMX_NEON)
  const int32_t v[sizeof(r_.i32) / sizeof(r_.i32[0])] = { e0, e1 };
  r_.neon_i32 = vld1_s32(v);
#else
  r_.i32[0] = e0;
  r_.i32[1] = e1;
#endif

  return simde__m64_from_private(r_);
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set_pi32(e1, e0) mm_set_pi32(e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_pi64 (int64_t e0) {
  simde__m64_private r_;

#if defined(SIMDE_MMX_NEON)
  const int64_t v[sizeof(r_.i64) / sizeof(r_.i64[0])] = { e0 };
  r_.neon_i64 = vld1_s64(v);
#else
  r_.i64[0] = e0;
#endif

  return simde__m64_from_private(r_);
}


SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_x_mm_set_f32x2 (simde_float32 e1, simde_float32 e0) {
  simde__m64_private r_;

#if defined(SIMDE_MMX_NEON)
  const simde_float32 v[sizeof(r_.f32) / sizeof(r_.f32[0])] = { e0, e1 };
  r_.neon_f32 = vld1_f32(v);
#else
  r_.f32[0] = e0;
  r_.f32[1] = e1;
#endif

  return simde__m64_from_private(r_);
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set1_pi8 (int8_t a) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_set1_pi8(a);
#elif defined(SIMDE_MMX_NEON)
  simde__m64_private r_;
  r_.neon_i8 = vmov_n_s8(a);
  return simde__m64_from_private(r_);
#else
  return simde_mm_set_pi8(a, a, a, a, a, a, a, a);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set1_pi8(a) mm_set1_pi8(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set1_pi16 (int16_t a) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_set1_pi16(a);
#elif defined(SIMDE_MMX_NEON)
  simde__m64_private r_;
  r_.neon_i16 = vmov_n_s16(a);
  return simde__m64_from_private(r_);
#else
  return simde_mm_set_pi16(a, a, a, a);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set1_pi16(a) mm_set1_pi16(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_set1_pi32 (int32_t a) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_set1_pi32(a);
#elif defined(SIMDE_MMX_NEON)
  simde__m64_private r_;
  r_.neon_i32 = vmov_n_s32(a);
  return simde__m64_from_private(r_);
#else
  return simde_mm_set_pi32(a, a);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_set1_pi32(a) mm_set1_pi32(a)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setr_pi8 (int8_t e7, int8_t e6, int8_t e5, int8_t e4, int8_t e3, int8_t e2, int8_t e1, int8_t e0) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_setr_pi8(e7, e6, e5, e4, e3, e2, e1, e0);
#else
  return simde_mm_set_pi8(e0, e1, e2, e3, e4, e5, e6, e7);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setr_pi8(e7, e6, e5, e4, e3, e2, e1, e0) mm_setr_pi8(e7, e6, e5, e4, e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setr_pi16 (int16_t e3, int16_t e2, int16_t e1, int16_t e0) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_setr_pi16(e3, e2, e1, e0);
#else
  return simde_mm_set_pi16(e0, e1, e2, e3);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setr_pi16(e3, e2, e1, e0) mm_setr_pi16(e3, e2, e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setr_pi32 (int32_t e1, int32_t e0) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_setr_pi32(e1, e0);
#else
  return simde_mm_set_pi32(e0, e1);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setr_pi32(e1, e0) mm_setr_pi32(e1, e0)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setzero_si64 (void) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_setzero_si64();
#elif defined(SIMDE_MMX_NEON)
  simde__m64_private r_;
  r_.neon_u32 = vmov_n_u32(0);
  return simde__m64_from_private(r_);
#else
  return simde_mm_set_pi32(0, 0);
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_setzero_si64() SIMDE__M64_TO_NATIVE(simde_mm_setzero_si64())
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_setone_si64 (void) {
#if defined(SIMDE_SSE_NATIVE)
  __m64 t = _mm_undefined_ps();
  return _mm_andnot_ps(t, t);
#else
  simde__m64 r;
  memset(&r, ~0, sizeof(r));
  return r;
#endif
}

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sll_pi16 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sll_pi16(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vshl_s16(a_.neon_i16, vmov_n_s16((int16_t) vget_lane_u64(count_.neon_u64, 0)));
#elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i16 = a_.i16 << count_.u64[0];
#else
  if (HEDLEY_UNLIKELY(count_.u64[0] > 15)) {
    memset(&r_, 0, sizeof(r_));
    return simde__m64_from_private(r_);
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (uint16_t) (a_.u16[i] << count_.u64[0]);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psllw(a, count) simde_mm_sll_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sll_pi16(a, count) mm_sll_pi16(a, count)
#  define _m_psllw(a, count) mm_sll_pi16(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sll_pi32 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sll_pi32(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vshl_s32(a_.neon_i32, vmov_n_s32((int32_t) vget_lane_u64(count_.neon_u64, 0)));
#elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i32 = a_.i32 << count_.u64[0];
#else
  if (HEDLEY_UNLIKELY(count_.u64[0] > 31)) {
    memset(&r_, 0, sizeof(r_));
    return simde__m64_from_private(r_);
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i] << count_.u64[0];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pslld(a, count) simde_mm_sll_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sll_pi32(a, count) mm_sll_pi32(a, count)
#  define _m_pslld(a, count) mm_sll_pi32(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_slli_pi16 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return _mm_slli_pi16(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i16 = a_.i16 << count;
#elif defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vshl_s16(a_.neon_i16, vmov_n_s16((int16_t) count));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = (uint16_t) (a_.u16[i] << count);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psllwi(a, count) simde_mm_slli_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_slli_pi16(a, count) mm_slli_pi16(a, count)
#  define _m_psllwi(a, count) mm_slli_pi16(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_slli_pi32 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return _mm_slli_pi32(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i32 = a_.i32 << count;
#elif defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vshl_s32(a_.neon_i32, vmov_n_s32((int32_t) count));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i] << count;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pslldi(a, b) simde_mm_slli_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_slli_pi32(a, count) mm_slli_pi32(a, count)
#  define _m_pslldi(a, count) mm_slli_pi32(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_slli_si64 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_slli_si64(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i64 = a_.i64 << count;
#elif defined(SIMDE_MMX_NEON)
  r_.neon_i64 = vshl_s64(a_.neon_i64, vmov_n_s64((int64_t) count));
#else
  r_.u64[0] = a_.u64[0] << count;
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psllqi(a, count) simde_mm_slli_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_slli_si64(a, count) mm_slli_si64(a, count)
#  define _m_psllqi(a, count) mm_slli_si64(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sll_si64 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sll_si64(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i64 = vshl_s64(a_.neon_i64, count_.neon_i64);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i64 = a_.i64 << count_.i64;
#else
  if (HEDLEY_UNLIKELY(count_.u64[0] > 63)) {
    memset(&r_, 0, sizeof(r_));
    return simde__m64_from_private(r_);
  }

  r_.u64[0] = a_.u64[0] << count_.u64[0];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psllq(a, count) simde_mm_sll_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sll_si64(a, count) mm_sll_si64(a, count)
#  define _m_psllq(a, count) mm_sll_si64(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srl_pi16 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_srl_pi16(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.u16 = a_.u16 >> count_.u64[0];
#elif defined(SIMDE_MMX_NEON)
  r_.neon_u16 = vshl_u16(a_.neon_u16, vmov_n_s16(-((int16_t) vget_lane_u64(count_.neon_u64, 0))));
#else
  if (HEDLEY_UNLIKELY(count_.u64[0] > 15)) {
    memset(&r_, 0, sizeof(r_));
    return simde__m64_from_private(r_);
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < sizeof(r_.u16) / sizeof(r_.u16[0]) ; i++) {
    r_.u16[i] = a_.u16[i] >> count_.u64[0];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrlw(a, count) simde_mm_srl_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srl_pi16(a, count) mm_srl_pi16(a, count)
#  define _m_psrlw(a, count) mm_srl_pi16(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srl_pi32 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_srl_pi32(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.u32 = a_.u32 >> count_.u64[0];
#elif defined(SIMDE_MMX_NEON)
  r_.neon_u32 = vshl_u32(a_.neon_u32, vmov_n_s32(-((int32_t) vget_lane_u64(count_.neon_u64, 0))));
#else
  if (HEDLEY_UNLIKELY(count_.u64[0] > 31)) {
    memset(&r_, 0, sizeof(r_));
    return simde__m64_from_private(r_);
  }

  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < sizeof(r_.u32) / sizeof(r_.u32[0]) ; i++) {
    r_.u32[i] = a_.u32[i] >> count_.u64[0];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrld(a, count) simde_mm_srl_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srl_pi32(a, count) mm_srl_pi32(a, count)
#  define _m_psrld(a, count) mm_srl_pi32(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srli_pi16 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return _mm_srli_pi16(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.u16 = a_.u16 >> count;
#elif defined(SIMDE_MMX_NEON)
  r_.neon_u16 = vshl_u16(a_.neon_u16, vmov_n_s16(-((int16_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    r_.u16[i] = a_.u16[i] >> count;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrlwi(a, count) simde_mm_srli_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srli_pi16(a, count) mm_srli_pi16(a, count)
#  define _m_psrlwi(a, count) mm_srli_pi16(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srli_pi32 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return _mm_srli_pi32(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.u32 = a_.u32 >> count;
#elif defined(SIMDE_MMX_NEON)
  r_.neon_u32 = vshl_u32(a_.neon_u32, vmov_n_s32(-((int32_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u32) / sizeof(r_.u32[0])) ; i++) {
    r_.u32[i] = a_.u32[i] >> count;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrldi(a, count) simde_mm_srli_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srli_pi32(a, count) mm_srli_pi32(a, count)
#  define _m_psrldi(a, count) mm_srli_pi32(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srli_si64 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return _mm_srli_si64(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_MMX_NEON)
  r_.neon_u64 = vshl_u64(a_.neon_u64, vmov_n_s64(-count));
#elif defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.u64 = a_.u64 >> count;
#else
  r_.u64[0] = a_.u64[0] >> count;
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrlqi(a, count) simde_mm_srli_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srli_si64(a, count) mm_srli_si64(a, count)
#  define _m_psrlqi(a, count) mm_srli_si64(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srl_si64 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_srl_si64(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_u64 = vshl_u64(a_.neon_u64, vneg_s64(count_.neon_i64));
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.u64 = a_.u64 >> count_.u64;
#else
  if (HEDLEY_UNLIKELY(count_.u64[0] > 63)) {
    memset(&r_, 0, sizeof(r_));
    return simde__m64_from_private(r_);
  }

  r_.u64[0] = a_.u64[0] >> count_.u64[0];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrlq(a, count) simde_mm_srl_si64(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srl_si64(a, count) mm_srl_si64(a, count)
#  define _m_psrlq(a, count) mm_srl_si64(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srai_pi16 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return _mm_srai_pi16(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i16 = a_.i16 >> (count & 0xff);
#elif defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vshl_s16(a_.neon_i16, vmov_n_s16(-((int16_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i] >> (count & 0xff);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrawi(a, count) simde_mm_srai_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srai_pi16(a, count) mm_srai_pi16(a, count)
#  define _m_psrawi(a, count) mm_srai_pi16(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_srai_pi32 (simde__m64 a, int count) {
#if defined(SIMDE_MMX_NATIVE) && !defined(__PGI)
  return _mm_srai_pi32(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i32 = a_.i32 >> (count & 0xff);
#elif defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vshl_s32(a_.neon_i32, vmov_n_s32(-((int32_t) count)));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] >> (count & 0xff);
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psradi(a, count) simde_mm_srai_pi32(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_srai_pi32(a, count) mm_srai_pi32(a, count)
#  define _m_srai_pi32(a, count) mm_srai_pi32(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sra_pi16 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sra_pi16(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);
  const int cnt = (int) (count_.i64[0] > 15 ? 15 : count_.i64[0]);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i16 = a_.i16 >> cnt;
#elif defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vshl_s16(a_.neon_i16, vmov_n_s16(-((int16_t) vget_lane_u64(count_.neon_u64, 0))));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i] >> cnt;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psraw(a, count) simde_mm_sra_pi16(a, count)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sra_pi16(a, count) mm_sra_pi16(a, count)
#  define _m_psraw(a, count) mm_sra_pi16(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sra_pi32 (simde__m64 a, simde__m64 count) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sra_pi32(a, count);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private count_ = simde__m64_to_private(count);
  const int32_t cnt = (count_.u64[0] > 31) ? 31 : ((int32_t) count_.u64[0]);

#if defined(SIMDE_VECTOR_SUBSCRIPT_SCALAR)
  r_.i32 = a_.i32 >> cnt;
#elif defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vshl_s32(a_.neon_i32, vmov_n_s32(-((int32_t) vget_lane_u64(count_.neon_u64, 0))));
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] >> cnt;
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psrad(a, b) simde_mm_sra_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sra_pi32(a, count) mm_sra_pi32(a, count)
#  define _m_psrad(a, count) mm_sra_pi32(a, count)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sub_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sub_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i8 = vsub_s8(a_.neon_i8, b_.neon_i8);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i8 = a_.i8 - b_.i8;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    r_.i8[i] = a_.i8[i] - b_.i8[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psubb(a, b) simde_mm_sub_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_pi8(a, b) mm_sub_pi8(a, b)
#  define _m_psubb(a, b) mm_sub_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sub_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sub_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vsub_s16(a_.neon_i16, b_.neon_i16);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i16 = a_.i16 - b_.i16;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    r_.i16[i] = a_.i16[i] - b_.i16[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psubw(a, b) simde_mm_sub_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_pi16(a, b) mm_sub_pi16(a, b)
#  define _m_psubw(a, b) mm_sub_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_sub_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_sub_pi32(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = vsub_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32 = a_.i32 - b_.i32;
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) ; i++) {
    r_.i32[i] = a_.i32[i] - b_.i32[i];
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psubd(a, b) simde_mm_sub_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_sub_pi32(a, b) mm_sub_pi32(a, b)
#  define _m_psubd(a, b) mm_sub_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_subs_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i8 = vqsub_s8(a_.neon_i8, b_.neon_i8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i8) / sizeof(r_.i8[0])) ; i++) {
    if (((b_.i8[i]) > 0 && (a_.i8[i]) < INT8_MIN + (b_.i8[i]))) {
      r_.i8[i] = INT8_MIN;
    } else if ((b_.i8[i]) < 0 && (a_.i8[i]) > INT8_MAX + (b_.i8[i])) {
      r_.i8[i] = INT8_MAX;
    } else {
      r_.i8[i] = (a_.i8[i]) - (b_.i8[i]);
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psubsb(a, b) simde_mm_subs_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pi8(a, b) mm_subs_pi8(a, b)
#  define _m_psubsb(a, b) mm_subs_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pu8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_subs_pu8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_u8 = vqsub_u8(a_.neon_u8, b_.neon_u8);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u8) / sizeof(r_.u8[0])) ; i++) {
    const int32_t x = a_.u8[i] - b_.u8[i];
    if (x < 0) {
      r_.u8[i] = 0;
    } else if (x > UINT8_MAX) {
      r_.u8[i] = UINT8_MAX;
    } else {
      r_.u8[i] = (uint8_t) x;
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psubusb(a, b) simde_mm_subs_pu8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pu8(a, b) mm_subs_pu8(a, b)
#  define _m_psubusb(a, b) mm_subs_pu8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_subs_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i16 = vqsub_s16(a_.neon_i16, b_.neon_i16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.i16) / sizeof(r_.i16[0])) ; i++) {
    if (((b_.i16[i]) > 0 && (a_.i16[i]) < SHRT_MIN + (b_.i16[i]))) {
      r_.i16[i] = SHRT_MIN;
    } else if ((b_.i16[i]) < 0 && (a_.i16[i]) > INT16_MAX + (b_.i16[i])) {
      r_.i16[i] = INT16_MAX;
    } else {
      r_.i16[i] = (a_.i16[i]) - (b_.i16[i]);
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psubsw(a, b) simde_mm_subs_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pi16(a, b) mm_subs_pi16(a, b)
#  define _m_psubsw(a, b) mm_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_subs_pu16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_subs_pu16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_u16 = vqsub_u16(a_.neon_u16, b_.neon_u16);
#else
  SIMDE__VECTORIZE
  for (size_t i = 0 ; i < (sizeof(r_.u16) / sizeof(r_.u16[0])) ; i++) {
    const int x = a_.u16[i] - b_.u16[i];
    if (x < 0) {
      r_.u16[i] = 0;
    } else if (x > UINT16_MAX) {
      r_.u16[i] = UINT16_MAX;
    } else {
      r_.u16[i] = (uint16_t) x;
    }
  }
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_psubusw(a, b) simde_mm_subs_pu16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_subs_pu16(a, b) mm_subs_pu16(a, b)
#  define _m_psubusw(a, b) mm_subs_pu16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpackhi_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_unpackhi_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_i8 = vzip2_s8(a_.neon_i8, b_.neon_i8);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.i8 = SIMDE__SHUFFLE_VECTOR(8, 8, a_.i8, b_.i8, 4, 12, 5, 13, 6, 14, 7, 15);
#else
  r_.i8[0] = a_.i8[4];
  r_.i8[1] = b_.i8[4];
  r_.i8[2] = a_.i8[5];
  r_.i8[3] = b_.i8[5];
  r_.i8[4] = a_.i8[6];
  r_.i8[5] = b_.i8[6];
  r_.i8[6] = a_.i8[7];
  r_.i8[7] = b_.i8[7];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_punpckhbw(a, b) simde_mm_unpackhi_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpackhi_pi8(a, b) mm_unpackhi_pi8(a, b)
#  define _m_punpckhbw(a, b) mm_unpackhi_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpackhi_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_unpackhi_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_i16 = vzip2_s16(a_.neon_i16, b_.neon_i16);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.i16 = SIMDE__SHUFFLE_VECTOR(16, 8, a_.i16, b_.i16, 2, 6, 3, 7);
#else
  r_.i16[0] = a_.i16[2];
  r_.i16[1] = b_.i16[2];
  r_.i16[2] = a_.i16[3];
  r_.i16[3] = b_.i16[3];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_punpckhwd(a, b) simde_mm_unpackhi_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpackhi_pi16(a, b) mm_unpackhi_pi16(a, b)
#  define _m_punpckhwd(a, b) mm_unpackhi_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpackhi_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_unpackhi_pi32(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_i32 = vzip2_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.i32 = SIMDE__SHUFFLE_VECTOR(32, 8, a_.i32, b_.i32, 1, 3);
#else
  r_.i32[0] = a_.i32[1];
  r_.i32[1] = b_.i32[1];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_punpckhdq(a, b) simde_mm_unpackhi_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpackhi_pi32(a, b) mm_unpackhi_pi32(a, b)
#  define _m_punpckhdq(a, b) mm_unpackhi_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpacklo_pi8 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_unpacklo_pi8(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_i8 = vzip1_s8(a_.neon_i8, b_.neon_i8);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.i8 = SIMDE__SHUFFLE_VECTOR(8, 8, a_.i8, b_.i8, 0, 8, 1, 9, 2, 10, 3, 11);
#else
  r_.i8[0] = a_.i8[0];
  r_.i8[1] = b_.i8[0];
  r_.i8[2] = a_.i8[1];
  r_.i8[3] = b_.i8[1];
  r_.i8[4] = a_.i8[2];
  r_.i8[5] = b_.i8[2];
  r_.i8[6] = a_.i8[3];
  r_.i8[7] = b_.i8[3];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_punpcklbw(a, b) simde_mm_unpacklo_pi8(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpacklo_pi8(a, b) mm_unpacklo_pi8(a, b)
#  define _m_punpcklbw(a, b) mm_unpacklo_pi8(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpacklo_pi16 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_unpacklo_pi16(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_i16 = vzip1_s16(a_.neon_i16, b_.neon_i16);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.i16 = SIMDE__SHUFFLE_VECTOR(16, 8, a_.i16, b_.i16, 0, 4, 1, 5);
#else
  r_.i16[0] = a_.i16[0];
  r_.i16[1] = b_.i16[0];
  r_.i16[2] = a_.i16[1];
  r_.i16[3] = b_.i16[1];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_punpcklwd(a, b) simde_mm_unpacklo_pi16(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpacklo_pi16(a, b) mm_unpacklo_pi16(a, b)
#  define _m_punpcklwd(a, b) mm_unpacklo_pi16(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_unpacklo_pi32 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_unpacklo_pi32(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON) && defined(SIMDE_ARCH_AARCH64)
  r_.neon_i32 = vzip1_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE__SHUFFLE_VECTOR)
  r_.i32 = SIMDE__SHUFFLE_VECTOR(32, 8, a_.i32, b_.i32, 0, 2);
#else
  r_.i32[0] = a_.i32[0];
  r_.i32[1] = b_.i32[0];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_punpckldq(a, b) simde_mm_unpacklo_pi32(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_unpacklo_pi32(a, b) mm_unpacklo_pi32(a, b)
#  define _m_punpckldq(a, b) mm_unpacklo_pi32(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
simde__m64
simde_mm_xor_si64 (simde__m64 a, simde__m64 b) {
#if defined(SIMDE_MMX_NATIVE)
  return _mm_xor_si64(a, b);
#else
  simde__m64_private r_;
  simde__m64_private a_ = simde__m64_to_private(a);
  simde__m64_private b_ = simde__m64_to_private(b);

#if defined(SIMDE_MMX_NEON)
  r_.neon_i32 = veor_s32(a_.neon_i32, b_.neon_i32);
#elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
  r_.i32f = a_.i32f ^ b_.i32f;
#else
  r_.u64[0] = a_.u64[0] ^ b_.u64[0];
#endif

  return simde__m64_from_private(r_);
#endif
}
#define simde_m_pxor(a, b) simde_mm_xor_si64(a, b)
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _mm_xor_si64(a, b) mm_xor_si64(a, b)
#  define _m_pxor(a, b) mm_xor_si64(a, b)
#endif

SIMDE__FUNCTION_ATTRIBUTES
int32_t
simde_m_to_int (simde__m64 a) {
#if defined(SIMDE_MMX_NATIVE)
  return _m_to_int(a);
#else
  simde__m64_private a_ = simde__m64_to_private(a);

  #if defined(SIMDE_MMX_NEON)
    return vget_lane_s32(a_.neon_i32, 0);
  #else
    return a_.i32[0];
  #endif
#endif
}
#if defined(SIMDE_MMX_ENABLE_NATIVE_ALIASES)
#  define _m_to_int(a) simde_m_to_int(a)
#endif

SIMDE__END_DECLS

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE__MMX_H) */
/* :: End x86/mmx.h :: */
