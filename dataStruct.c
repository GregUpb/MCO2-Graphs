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

#include <stdio.h>
#include <stdlib.h>

// include your own stack header file
#include "dataStruct.h"

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will create a brand new empty stack, ready to use and complete with proper memory allocation
    e. Return: stack
    f. Parameters: name is an Array of characters that acts as a string to provide a name or a label for the new stack
*/
stackType CREATESTACK(char name[])
{
    // Initialize a new stack
    stackType stack;

    strcpy(stack.name, name);   // Provides the name for the stack
    
    stack.Head = malloc(sizeof(struct node));   // allocates memory to the stack

    stack.Head->previous = NULL;    // Set the previous pointer of the head to NULL

    stack.count = 0;    // New stack has nothing stored so it's still empty

    return stack; // returns the newly created stack, ready to use

}

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will insert a new node at the top of the stack and increment the addition
    e. Return: None
    f. Parameters: stack is a pointer to the stackType structure, enabling the modifications to be saved in the structure.
    -> elem is a string structure that represents the date of the node that is being added to the stack.
*/
void PUSHSTACK(stackType *stack, string elem)
{
    // Initialize a new node
    struct node *newNode;

    // Check if count is 0, less than MAX (32768), or above or equal to MAX (32768)
    if (stack->count == 0)
    {
        // Set the id to the head
        strcpy(stack->Head->id, elem);
        stack->count += 1;

    } else if (stack->count < MAXSIZE)
    {
        newNode = malloc(sizeof(struct node));  // Allocate memory to the new node
    
        strcpy(newNode->id, elem);  // Set the id to the new node
    
        newNode->previous = stack->Head;    // Set the previous pointer to the head
    
        stack->Head = newNode;  // Make the new node as the head

        stack->count += 1;  // Increment
    } else
    {
        printf("Stack %s is already full.", stack->name);
    }

}

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will take the previous node, delete the current head, and replace it as the new head of the stack, decrementing 
    e. Return: id
    f. Parameters: stack is a pointer to the stackType structure, enabling the modifications to be saved in the structure.
*/
void POPSTACK(stackType *stack, string id)
{
    struct node *temp = stack->Head->previous;  // Make a temporary node and make it the previous pointer of the head

    // Get the id of the current head
    strcpy(id, stack->Head->id);

    // Remove the head
    free(stack->Head);
    stack->count -= 1;  // Decrement

    // Set the previous pointer as the new head
    stack->Head = temp;

}

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will return the id of the head, a.k.a the top element of the stack
    e. Return: stack->Head->id // the id of the current head of the stack
    f. Parameters: stack is a pointer to the stackType structure, using previously saved modifications in the structure.
*/
void TOPSTACK(stackType *stack, string id)
{
    // Only returns the id of the head
    strcpy(id, stack->Head->id);

}

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will check the count of the stack if it is full or not, and returns 1 if it is full, or 0 if it isn't.
    e. Return: isFull
    f. Parameters: stack is a pointer to the stackType structure, using previously saved modifications in the structure.
*/
int ISFULLSTACK(stackType *stack)
{

    int isFull;

    // Checks if the stack is full or not
    if (stack->count == MAXSIZE)
    {
        isFull = 1;
    } else
    {
        isFull = 0;
    }

    return isFull;

}

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will check the count of the stack if it is empty or not, and returns 1 if it is empty, or 0 if it isn't.
    e. Return: isEmpty
    f. Parameters: stack is a pointer to the stackType structure, using previously saved modifications in the structure.
*/
int ISEMPTYSTACK(stackType *stack)
{

    int isEmpty;

    // Checks if the stack is empty or not
    if (stack->count == 0)
    {
        isEmpty = 1;
    } else
    {
        isEmpty = 0;
    }

    return isEmpty;

}

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will return the id of the node that is next to the head node (2nd one from the top).
    e. Return: stack->Head->previous->id // the id of the node after the current head in the stack
    f. Parameters: stack is a pointer to the stackType structure, using previously saved modifications in the structure.
*/
void NEXTTOTOPSTACK(stackType *stack, string id)
{
    // Returns the id next to the top;
    strcpy(id, stack->Head->previous->id);
}

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will remove all elements inside a stack, making it empty.
    e. Return: None
    f. Parameters: stack is a pointer to the stackType structure, using previously saved modifications in the structure.
*/
void FREESTACK(stackType *stack)
{
    string temp;
    // Remove all the elements from the stack
    while (!ISEMPTYSTACK(stack))
    {
        POPSTACK(stack, temp);
    }
}


/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will create a brand new empty stack, ready to use and complete with proper memory allocation
    e. Return: stack
    f. Parameters: name is an Array of characters that acts as a string to provide a name or a label for the new stack
*/
QueueType CREATEQUEUE(char name[])
{

    QueueType queue;    // Initialize a new queue

    strcpy(queue.name, name);   // Set the queue name

    // Allocate a new node as the head and tail
    queue.Head = malloc(sizeof(struct node));
    queue.Head->previous = NULL;
    queue.Tail = queue.Head;

    queue.count = 0;

    return queue;

}



void ENQUEUE(QueueType *queue, string elem)
{
    // Create a new node
    struct node *newnode;

    if (queue->count == 0)
    {
        // Place the id to the first node
        strcpy(queue->Head->id, elem);
        queue->Head = queue->Tail;
        queue->count += 1;
    } else if (queue->count < MAXSIZE)
    {
        // Allocate memory for the new node
        newnode = malloc(sizeof(struct node));
        strcpy(newnode->id, elem);
        newnode->previous = NULL;

        // Add the new node at the end
        queue->Tail->previous = newnode;
        queue->Tail = newnode;

        queue->count += 1;  // Increment
    } else
    {
        printf("Queue is already full");
    }

}

void DEQUEUE(QueueType *queue, string id)
{
    if (queue->count == 1)
    {
        // If count is exactly one, dont remove the allocated node
        queue->count -= 1;
        strcpy(id, queue->Head->id);
        
    } else if (queue->count > 0)
    {
        // Create a temporary node
        struct node *temp = queue->Head->previous;
        strcpy(id, queue->Head->id);

        // Free up the head node
        free(queue->Head);
        queue->count -= 1;

        // Make the next node of the former head as the new head
        queue->Head = temp;

    } else
    {
        strcpy(id, "-----");
    }

}


void HEADQUEUE(QueueType *queue, string id)
{

    if (queue->count > 0)
    {
        // Get the id of the head
        strcpy(id, queue->Head->id);
    } else
    {
        strcpy(id, "-----");
    }

}


void TAILQUEUE(QueueType *queue, string id)
{

    if (queue->count > 0)
    {
        // Get the id of the tail
        strcpy(id, queue->Tail->id);
    } else
    {
        strcpy(id, "-----");
    }

}



int ISFULLQUEUE(QueueType *queue)
{
    int isFull;

    // Check if the queue is full
    if (queue->count == MAXSIZE)
    {
        isFull = 1;
    } else
    {
        isFull = 0;
    }

    return isFull;
}



int ISEMPTYQUEUE(QueueType *queue)
{

    int isEmpty;

    // Check if the queue is emptty
    if (queue->count == 0)
    {
        isEmpty = 1;
    } else
    {
        isEmpty = 0;
    }

    return isEmpty;

}



void FREEQUEUE(QueueType *queue)
{
    string temp;

    // Remove all the elements from the queue
    while (!ISEMPTYQUEUE(queue))
    {
        DEQUEUE(queue, temp);
    }

}