#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H
#include <string.h>
#include <stdio.h>
#include "exec.h"
#include "tools.h"
#include "../nonce/nonce.h"


int command(int argc, char **argv);
void error_display(int error);

#endif