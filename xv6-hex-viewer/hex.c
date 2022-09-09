#include "types.h"
#include "stat.h"
#include "user.h"

char buf[16];

void
hex(int fd)
{
  int n;
  int h = 0;

  printf(1, "%x	:", h);
  while((n = read(fd, buf, sizeof(buf))) > 0){
      for(int i=0; i<n; ++i){
      	printf(1, "%x ", buf[i]);
        }
        printf(1, "\n");
        h=h+16;		
        printf(1, "%x	:", h);
  }
  if(n < 0){
    printf(1, "hex: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    hex(0);
    exit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "hex: cannot open %s\n", argv[i]);
      exit();
    }
    hex(fd);
    close(fd);
  }
  exit();
}
