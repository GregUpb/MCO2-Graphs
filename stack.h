/*

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 18 (2 digits)

    ACOSTA, JOHN HAYDEN         S09
    DE SILVA, GABRIEL ANGELO    S09
    GREGORIO, JACOB MIGUEL      S09
 

    PURPOSE OF THIS FILE: to show an example of a C header file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS:
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    3. Do NOT use global variables!  NON-COMPLIANCE WILL RESULT INTO A 10 POINT DEDUCTION!
*/

/*
    You may encode any of the following below this comment the following:   
    1. #define directives
    2. typedef alias(es) 
    3. declaration of your user-defined struct data type(s)
    4. typedef alias(es) for your struct data type(s) -- you have to put an inline comment 
       for each struct member as part of the documentation. 

    The header should NOT include the codes for any function definitions.  

    Function definitions should be encoded in your C source file only!
*/
#ifndef STACKH
#define STACKH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// you may include other header files

#define MAXSTACKSIZE 32768


typedef char string[512];

/* Point (x,y) */
struct PointTag
{
    double x,y;
};

typedef struct PointTag pointType;

/* Single Linked List */
struct node {

    pointType value;             // The value
    struct node *previous;      // A pointer to the previous node

};

struct stackTag {

    string name;              // name of the stack
    struct node *Head;        // the top node
    int count;

};

typedef struct stackTag stackType;
  
stackType CREATE(char name[]);
void PUSH(stackType *stack, pointType elem);
pointType POP(stackType *stack);
pointType TOP(stackType *stack);
int ISFULL(stackType *stack);
int ISEMPTY(stackType *stack);
pointType NEXTTOTOP(stackType *stack);
void FREESTACK(stackType *stack);

#endif