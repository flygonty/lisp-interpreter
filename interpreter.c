#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*
LISP GRAMMAR
s_expression = atomic_symbol \
               / "(" s_expression "."s_expression ")" \
               / list 
   
list = "(" s_expression < s_expression > ")"

atomic_symbol = letter atom_part

atom_part = empty / letter atom_part / number atom_part

letter = "a" / "b" / " ..." / "z"

number = "1" / "2" / " ..." / "9"

empty = " "
*/

/*input buffer from stdin*/
static char input[2048];

/*token structure*/
typedef struct {
    char *type;
    char *value;
} Token;

typedef struct TokenNode {
    Token token;
    struct TokenNode *next;
} TokenNode;

/*tokenize function*/
TokenNode *tokenize(char *input) {
    /*Loop for getting a token from input*/
    TokenNode *token = (TokenNode *)malloc(sizeof(TokenNode));
    if (token == NULL) {
        assert("malloc failed");
        return NULL;
    } // if

    char* delim = " \t\n()";
    char* token_str = strtok(input, delim);
    while (token_str != NULL) {
        printf("Your token: %s\n", token_str);
        token_str = strtok(NULL, delim);
    } // while()
} // TreeNode *tokenize()

int main() {
    /*Wellcome Prompt*/
    puts("Welcome to the Lisp interpreter!");
    puts("Press Ctrl+C to exit.");

    while(1) {
        printf("lisp> ");
        fgets(input, 2048, stdin);
        if (feof(stdin)) {
            break; // exit on Ctrl+D
        } // if
        tokenize(input);
        fflush(stdout);
    } // while()
    
    return 0;
} // main()