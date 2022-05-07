#include "key_extension/key_extension.h"
#include "tools/exec.h"
#include "tools/command_line.h"


int main(int argc, char **argv)
{
     int error = command(argc, argv);
     error_display(error);
     return 0;
}