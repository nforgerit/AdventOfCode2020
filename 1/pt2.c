#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This function is blatantly stolen from 
    https://stackoverflow.com/a/3463793
*/
char* ReadFile(char *filename) {
  char *buffer = NULL;
  int string_size, read_size;
  FILE *handler = fopen(filename, "r");

  if (handler) {
    fseek(handler, 0, SEEK_END);
    string_size = ftell(handler);
    rewind(handler);

    buffer = (char*) malloc(sizeof(char) * (string_size +1));
    read_size = fread(buffer, sizeof(char), string_size, handler);
    buffer[string_size] = '\0';

    if (string_size != read_size) {
      free(buffer);
      buffer = NULL;
    }

    fclose(handler);
  }

  return buffer;
}

int SplitToNumbers(char* str, int* nums) {
  char* delim = "\r\n";

  int idx = 0;
  char* tok = strtok(str, delim);

  while (tok != NULL) {
    nums[idx] = atoi(tok);
    tok = strtok(NULL, delim);
    ++idx;
  }

  return idx;
}

int main(int argc, char* argv[]) {
  int magicNum = 200; // just enough for our puzzle

  char *string = ReadFile("input.txt");
  int nums[magicNum]; 
  int len = SplitToNumbers(string, nums);

  free(string);

  int opx, opy, opz;

  for (int i = 0; i < magicNum; ++i) {
    for (int j = 0; j < magicNum; ++j) {
      for (int k = 0; k < magicNum; ++k) {
        if (nums[i] + nums[j] + nums[k] == 2020) {
          opx = nums[i];
          opy = nums[j];
          opz = nums[k];
          goto end; // https://xkcd.com/292/
        }
      }
    }
  }
  end:;

  char buf[100];
  sprintf(buf, "Answer: %d * %d * %d = %d", opx, opy, opz, opx*opy*opz);
  puts(buf);

  return 0;
}
