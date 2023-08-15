/* Subroutines for the JIT front end on the PowerPC architecture.
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

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "target.h"
#include "tm.h"
#include "tm_jit.h"
#include "jit/jit-target.h"
#include "jit/jit-target-def.h"

/* Implement TARGET_JIT_CPU_VERSIONS for PowerPC targets.  */

void
rs6000_jit_target_versions (void)
{
  if (TARGET_64BIT)
    {
      jit_add_target_info ("target_arch", "powerpc64");
    }
  else
    jit_add_target_info ("target_arch", "powerpc");
}

/* Implement TARGET_JIT_REGISTER_CPU_TARGET_INFO.  */

extern const char *host_detect_local_cpu (int argc, const char **argv);

void
rs6000_jit_register_target_info (void)
{
  const char *params[] = {"arch"};
  const char *arch = host_detect_local_cpu (1, params);

  const char* arg = "-march=";
  const char* arg_pos = strstr(arch, arg);
  const char* arg_value = arg_pos + strlen(arg);
  const char* arg_value_end = strchr(arg_value, ' ');

  size_t len = arg_value_end - arg_value;
  char *cpu = new char[len];
  strncpy(cpu, arg_value, len);
  cpu[len] = '\0';
  jit_target_set_arch (cpu);

  jit_target_set_128bit_int_support (targetm.scalar_mode_supported_p (TImode));

  free (const_cast <char *> (arch));

  // TODO: target features
  /*
  if (TARGET_ALTIVEC)
    jit_add_target_info("target_feature", "altivec");
  */
}
