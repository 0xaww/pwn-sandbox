#ifndef PROTECT_H
#define PROTECT_H
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/user.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/uio.h>

#include "defs.h"

#define PROTECT_BUFSIZE 16384

void get_arch(pid_t pid);
void pwn_preprotect(pid_t pid, long syscall);
void pwn_postprotect(pid_t pid, long syscall, long retval);
void set_logfile_path(char *filepath);
void set_logfile_prefix(char *prefix);

extern uint32_t *const i386_esp_ptr;
extern uint64_t *const x86_64_rsp_ptr;


#define ARCH_REGS_FOR_GETREGSET x86_regs_union
#define ARCH_IOVEC_FOR_GETREGSET x86_io
#define ARCH_PC_REG (x86_io.iov_len == sizeof(i386_regs) ? i386_regs.eip : x86_64_regs.rip)

#endif