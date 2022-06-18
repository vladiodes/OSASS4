#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  if (!(argc == 3 || argc == 4))
  {
    printf("Bad usage\n");
    exit(1);
  }
  if (strcmp(argv[1], "-s") == 0)
  {
    if (symlink(argv[2], argv[3]) < 0)
      printf("Creating symlink failed...\n");
  }
  else
  {
    if (link(argv[1], argv[2]) < 0)
      fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
  }
  exit(0);
}
