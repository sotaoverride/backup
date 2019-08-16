/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

#include <stdbool.h>

#include "time-util.h"

typedef int (*gather_stdout_callback_t)(int fd, void* arg);

enum
{
    STDOUT_GENERATE, /* from generators to helper process */
    STDOUT_COLLECT,  /* from helper process to main process */
    STDOUT_CONSUME,  /* process data in main process */
    _STDOUT_CONSUME_MAX,
};

typedef enum
{
    EXEC_DIR_NONE = 0,          /* No execdir flags */
    EXEC_DIR_PARALLEL = 1 << 0, /* Execute scripts in parallel, if possible */
    EXEC_DIR_IGNORE_ERRORS = 1
                             << 1, /* Ignore non-zero exit status of scripts */
} ExecDirFlags;

int execute_directories(
    const char* const* directories, usec_t timeout,
    gather_stdout_callback_t const callbacks[_STDOUT_CONSUME_MAX],
    void* const callback_args[_STDOUT_CONSUME_MAX], char* argv[], char* envp[],
    ExecDirFlags flags);

extern const gather_stdout_callback_t gather_environment[_STDOUT_CONSUME_MAX];
