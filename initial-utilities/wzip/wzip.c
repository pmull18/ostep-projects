#include <stdio.h>
#include <stdbool.h>


int main(int argc, char *argv[]){
  if (argc == 1){
    printf("%s", "wzip: file1 [file2 ...]\n");
    return 1;
  }

  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen = 0;
  
  char current_char;
  int current_count = 0;
  bool is_first_char = 1;

  for (int i = 1; i < argc; ++i){
    char* file_name = argv[i];
    FILE* file = fopen(file_name, "r");

    if(!file){
      printf("%s", "wzip: cannot open file\n");
      return 1;
    }

    while((linelen = getline(&line, &linecap, file)) > 0){
      if (is_first_char){
        current_char = line[0];
        is_first_char = 0;
      }
      for (int i = 0; i < linelen; ++i){
        
        if (current_char != line[i]){
          fwrite(&current_count, sizeof(current_count), 1, stdout);
          fwrite(&current_char, sizeof(current_char), 1, stdout);
          current_char = line[i];
          current_count = 1;
        } else {
          ++current_count;
        }
      }
    }
  }

  fwrite(&current_count, sizeof(current_count), 1, stdout);
  fwrite(&current_char, sizeof(current_char), 1, stdout);
}
