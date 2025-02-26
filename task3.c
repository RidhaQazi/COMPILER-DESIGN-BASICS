#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100


const char *keywords[] = {    // List of C keywords
    "auto", "double", "int", "struct", "break", "else", "long", "switch",
    "case", "enum", "register", "typedef", "char", "extern", "return", "union",
    "const", "float", "short", "unsigned", "continue", "for", "signed", "void",
    "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"
};
int keywordCount = sizeof(keywords) / sizeof(keywords[0]);


const char *operators[] = {    // List of operators
    "+", "-", "*", "/", "%", "=", "<", ">", "<=", ">=", "==", "!=", "&&", "||", "+=", "-=", "*=", "/=", "%=", "++", "--"
};
int operCount = sizeof(operators) / sizeof(operators[0]);


void lexicalAnalyzer(const char*);
int isKeyword(char*);
int isOper(const char*);


int main() {
    char fileName[MAX_LENGTH];
    printf("Enter file name(with .c extension): ");
    scanf("%s", fileName);
    lexicalAnalyzer(fileName);
    return 0;
}

void lexicalAnalyzer(const char* fileName) {
    FILE *ftp = fopen(fileName, "r");
    if (ftp == NULL) {
        printf("%s file not found! \n", fileName);
        return;
    }

    char ch, keywordOrId[MAX_LENGTH];
    int i = 0;
    printf("Tokens: \n");

    while ((ch = fgetc(ftp)) != EOF) {

        if (isalpha(ch) || ch == '_') {   //for keyword and identifier
            keywordOrId[i++] = ch;
            while (isalnum(ch = fgetc(ftp)) || ch == '_') {
                keywordOrId[i++] = ch;
            }
            keywordOrId[i] = '\0';

            i = 0;

            if (isKeyword(keywordOrId)) {
                printf("(Keyword): %s \n\n", keywordOrId);
            }
            else {
                printf("(Idendifier): %s \n\n", keywordOrId);
            }

            ungetc(ch, ftp);
        }

        else if (ispunct(ch)) {   //for operators
            char oper[3] = {ch, fgetc(ftp), '\0'};
            if (isOper(oper)) {
                printf("(Operator): %s \n\n", oper);
            }
            else {
                ungetc(oper[1], ftp);
                oper[1] = '\0';
                if (isOper(oper)) {
                    printf("(Operator): %s \n\n", oper);
                }
            }
        }
    }

    fclose(ftp);
}


int isKeyword(char *word) {
    for (int i = 0; i< keywordCount; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


int isOper(const char *oper) {
    for (int i = 0; i< operCount; i++) {
        if (strcmp(oper, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

