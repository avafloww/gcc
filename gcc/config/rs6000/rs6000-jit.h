/* Definitions for the jit front end on the PowerPC architecture.
   Copyright (C) 2023 Free Software Foundation, Inc.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* In rs6000-jit.cc  */
extern void rs6000_jit_target_versions (void);
extern void rs6000_jit_register_target_info (void);
extern bool rs6000_jit_has_stdcall_convention (unsigned int *, unsigned int *);

/* Target hooks for jit language.  */
#define TARGET_JIT_CPU_VERSIONS rs6000_jit_target_versions
#define TARGET_JIT_REGISTER_CPU_TARGET_INFO rs6000_jit_register_target_info
#define TARGET_JIT_HAS_STDCALL_CONVENTION rs6000_jit_has_stdcall_convention
