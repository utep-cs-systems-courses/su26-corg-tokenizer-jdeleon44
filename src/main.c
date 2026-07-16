#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  //Maximum characters the user can input
  char input[100];
  List *history = init_history();
    
  while(1){
    printf("$ ");
    if(fgets(input, sizeof(input), stdin) == NULL){
      //End of file error
      break;
    }
    /*printf("space_char: = %d\n", space_char(input[0]));
    printf("non_space_char: = %d\n", non_space_char(input[0]));
    char *start = token_start(input);
    if(start != NULL){
      printf("First token starts at: '%c'\n", *start);
    }else{
      printf("No tokens found\n");
    }
    if(start != NULL){
      char *end = token_terminator(start);
      printf("First token ends at character: '%c' (or space/null)\n", *end);
    }
    //Test count_tokens
    int count = count_tokens(input);
    printf("Number of tokens: %d\n", count);*/
    
    
    //Remove newline
    int i = 0;
    while(input[i] != '\0'){
      if(input[i] == '\n'){
	input[i] = '\0';
        break;
      }
      i++;
    }
        
    //Check if user wants to view history
    int is_history = 1;
    char *history_str = "history";
    while(history_str[i] != '\0'){
      //Checks if input matches character
      if(input[i] != history_str[i]){
	is_history = 0;
        break;
      }
      i++;
    }
    if(input[i] != '\0'){
      is_history = 0;
    }      
    if(is_history){
      print_history(history);
      continue;
    }
        
    //Recall specific token
    if(input[0] == '!'){
      int id = 0;
      i = 1;
      while(input[i] >= '0'){
	      id = id * 10 + (input[i] - '0');
        i++;
      }
      //Check for valid ID
      if(id > 0){
	      char *recalled = get_history(history, id);
        if(recalled != NULL){
	        printf("Recalling: %s\n", recalled);
	        char **tokens = tokenize(recalled);
          print_tokens(tokens);
          free_tokens(tokens);
        }else{
	        printf("History item %d not found\n", id);
        }
        continue;
      }
    }

    //UI test
    //printf("%s", input);
        
    // Add to history
    add_history(history, input);
    char **tokens = tokenize(input);
    print_tokens(tokens);
    free_tokens(tokens);
  }
  free_history(history);
  return 0;
}
