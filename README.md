# COMPILER-DESIGN-BASICS

COMPANY: CODETECH IT SOLUTIONS

NAME: RIDHA QAZI

INTERN ID: CODHC68

DOMAIN: C PROGRAMMING

DURATION: 4 WEEKS

MENTOR: NEELA SANTOSH

A lexical analyzer is the first phase of a compiler, responsible for scanning the source code and breaking it into meaningful tokens such as keywords, operators, and identifiers. In this task, I built a simple lexical analyzer in C that reads a .c source file and identifies these tokens. To develop this program, I used Visual Studio Code as my editor, which provided syntax highlighting and debugging features. I compiled and executed the program using the GCC compiler on a Windows OS. 

The program takes an input C source file (e.g., sample.c) and analyzes its contents to extract tokens. It follows a structured approach, first reading the file name from the user and then processing each character to categorize it as a keyword, operator, or identifier. The program maintains predefined lists of C keywords and operators, which are stored in arrays and used for token matching. The core of the program is the lexicalAnalyzer() function, which reads characters from the input file and determines their type. When encountering alphabetic characters or underscores (_), the program assumes the beginning of a keyword or identifier. It continues reading until a non-alphanumeric character is found, then checks if the extracted word matches any of the predefined C keywords using the isKeyword() function. If a match is found, the token is classified as a keyword; otherwise, it is classified as an identifier. When encountering punctuation symbols, the program assumes an operator and checks for multi-character operators (such as <=, >=, +=, etc.) using the isOper() function. If a valid operator is found, it is printed as an operator token; otherwise, the program processes it as a single-character operator. 

I tested the program using a sample input file (sample.c), which contained a simple C program. The lexical analyzer correctly identified and categorized the tokens, producing output like (Keyword): int, (Identifier): sum, (Operator): +=, and so on.

## See sample.c file

During development, I handled cases such as underscore-prefixed identifiers (_var), multi-character operators, and non-alphanumeric symbols. One challenge was ensuring that operators were correctly recognized, especially when combining symbols (e.g., differentiating between + and +=). To address this, I implemented lookahead techniques using ungetc() etc, allowing the program to inspect the next character before making a decision. This lexical analyzer is a crucial step in compiler design, as it forms the foundation for more complex analysis like syntax and semantic analysis. It has applications in compilers, interpreters, and code analysis tools, where source code needs to be parsed and understood. This task enhanced my understanding of tokenization, string processing, and file handling in C, and laid the groundwork for exploring parsing, symbol tables, and code generation, which are essential components of compiler construction.

## Output
