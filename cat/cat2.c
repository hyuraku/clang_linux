#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
  int i;

  for(i = 1; i< argc; i++){
    FILE *f;
    int c;

    int line = 0;

    f = fopen(argv[i], "r");
    if(!f){
      perror(argv[i]);
      exit(1);
    }
    while((c = fgetc(f)) != EOF){

      if (c == '\t')
      {
        printf("\\t");
      }
      if (c == '\n'){
        line++;
        printf("$\n");
      }

      if(putchar(c)<0) exit(1);
    }
    printf("%d\n", line);
    fclose(f);
  }
  exit(0);
}
