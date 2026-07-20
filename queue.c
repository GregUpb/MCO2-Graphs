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
#include "queue.h"

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
        strcpy(queue->Head, elem);
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

char *DEQUEUE(QueueType *queue)
{
    string id;

    if (queue->count == 1)
    {
        // If count is exactly one, dont remove the allocated node
        queue->count -= 1;
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

    return id;
}


char* HEADQUEUE(QueueType *queue)
{

    string id;

    if (queue->count > 0)
    {
        // Get the id of the head
        strcpy(id, queue->Head->id);
    } else
    {
        strcpy(id, "-----");
    }

    return id;

}


char* TAILQUEUE(QueueType *queue)
{

    string id;

    if (queue->count > 0)
    {
        // Get the id of the tail
        strcpy(id, queue->Tail->id);
    } else
    {
        strcpy(id, "-----");
    }

    return id;

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
    // Remove all the elements from the queue
    while (!ISEMPTY(queue))
    {
        POP(queue);
    }

}