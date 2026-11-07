// Please download last release version currently the code is broken and in Development and Commit of next version
/*
 * Copyright (c) 2026 Devesh Kachhawaha (SyscallX-18113)
 *
 * Licensed under the Apache License, Version 2.0.
 * See the LICENSE file in the project root for license information.
 */


#ifndef KEYTESTER_H
#define KEYTESTER_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "network.h"
#include <unistd.h>
#include <termios.h>

#define BUF_SIZE 8096

int input_1(char *key, size_t size);

int api_tester(int command, int argc);

typedef struct
        {
            const char *description;
            const char *urls;
        } urls;

#endif
