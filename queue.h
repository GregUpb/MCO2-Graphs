/**

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 18  (2 digits)

    ACOSTA, JOHN HAYDEN         S09
    DE SILVA, GABRIEL ANGELO    S09
    GREGORIO, JACOB MIGUEL      S09

    PURPOSE OF THIS FILE: to show an example of a C source file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/
#include "node.h"

struct QueueTag {

    string name;                    // name of the stack
    struct node *Head;        // the first node
    struct node *Tail;        // the last node
    int count;

};

typedef struct QueueTag QueueType;
  
QueueType CREATEQUEUE(char name[]);
void PUSHQUEUE(QueueType *queue, string elem);
char* POPQUEUE(QueueType *queue);
char* TOPQUEUE(QueueType *queue);
int ISFULLQUEUE(QueueType *queue);
int ISEMPTYQUEUE(QueueType *queue);
char* NEXTTOTOPQUEUE(QueueType *queue);
void FREEQUEUE(QueueType *queue);