
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

  if (argc == 1){
    printf("%s", "wgrep: searchterm [file ...]\n");
    return(1);
  }
  char* target = argv[1];

  if (argc == 2){
    char line[1000];
    
    while(fgets(line, 1000, stdin)){
      if(strstr(line, target)){
        printf("%s", line);
      }
    }
  }

  for (int i = 2; i < argc; i++){
    char* file_name = argv[i];

    FILE* file = fopen(file_name, "r");

    if (file == NULL){
      printf("%s", "wgrep: cannot open file\n");
      return 1;
    }
    
    char* line;
    size_t len = 0;
    while(getline(&line, &len, file) != -1){
      if(strstr(line, target)){
        printf("%s", line);
      }
    }
    free(line);
  }
  
  return 0;
}
