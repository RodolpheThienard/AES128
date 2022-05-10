#include "key_extension/key_extension.h"
#include "tools/exec.h"
#include "tools/command_line.h"


int main(int argc, char **argv)
{
     error_display(command(argc, argv));
     return 0;
}