#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return (c == ' ' || c == '\t') ? 1:0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  return (c != ' ' && c != '\t' && c != '\0') ? 1:0;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  while(space_char(*str)){
    str++;
  }
  //Return a zero pointer
  if(*str == '\0'){
    return NULL;
  }
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int count = 0;
  //Create start token and call token_start method
  char *start = token_start(str);
  while(start != NULL){
    count++;
        
    //Find where token ends by calling token_terminator
    char *end = token_terminator(start);
        
    // Find where next token starts by calling token_start
    start = token_start(end);
  }
  return count;
}
  
  

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  //Use memory allocation
  char *copy = malloc(len + 1);
  for(int i = 0; i < len; i++){
    copy[i] = inStr[i];
  }
    
  // Add null terminator
  copy[len] = '\0';
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int numTokens = count_tokens(str);
    
  //Use memory allocation
  char **tokens = malloc((numTokens + 1) * sizeof(char *));
  int i = 0;
  char *start = token_start(str);
  while(start != NULL){
    //Find where the token ends
    char *end = token_terminator(start);
        
    //Get token length
    int len = end - start;
        
    //Copy
    tokens[i] = copy_str(start, len);
    i++;
    // Find next token
    start = token_start(end);
  }
    
  //Null terminator
  tokens[i] = '\0';
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  for(int i = 0; tokens[i] != NULL; i++){
    printf("%s\n", tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  //Free individual tokens
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
    
  //Free array
  free(tokens);
}
