#include "key_extension/key_extension.h"
#include "tools/exec.h"
#include "tools/command_line.h"


int main(int argc, char **argv)
{
     int error = command(argc, argv);
     error_display(error);


     int foo[3][2] = {{1,2},{3},{5,6}};
     

     for (size_t i = 0; i < 3; i++)
     {
          for (size_t j = 0; j < 2; j++)
          {

          }
          
     }
     


     return 0;
}