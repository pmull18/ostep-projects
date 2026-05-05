
#include <stdio.h>


int main(int argc, char *argv[]){  

  for (int i = 1; i < argc; ++i){
    char* current_file_name = argv[i];

    FILE *current_file = fopen(current_file_name, "r");

    if(!current_file){
      printf("%s", "wcat: cannot open file\n");
      return 1;
    }
    
    char current_line[1000];
    while(fgets(current_line, 1000, current_file)){
      printf("%s", current_line);
    }
  }

}

