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

/*
    a. Name of Programmer(s):  John Hayden R. Acosta
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function will create a brand new empty stack, ready to use and complete with proper memory allocation
    e. Return: stack
    f. Parameters: name is an Array of characters that acts as a string to provide a name or a label for the new stack
*/
#include "traversal.h"

int getIndex(graphType graph, int num)
{
    list sorted;
    char temp[MAX_ID_LENGTH];
    int index = 0;
    int i;
    int found = 0;

    // Copy all the vertex
    for (int i = 0; i < graph.nVertices; i++)
    {
        strcpy(sorted[i], graph.vertexNames[i]);
    }

    // Sort
    for (int i = 0; i < graph.nVertices-1; i++)
    {
        for (int j = i+1; j < graph.nVertices; j++)
        {
            if (strcmp(sorted[i], sorted[j]) > 0)
            {
                strcpy(temp, sorted[i]);
                strcpy(sorted[i], sorted[j]);
                strcpy(sorted[j], temp);
            }
        }
    }

    // Find
    i = 0;
    while (!(found) && i < graph.nVertices)
    {
        if (strcmp(graph.vertexNames[i], sorted[num]) == 0)
        {
            index = i;
            found = 1;
        }
        i++;
    }

    return index;

}

int getVertexIndex(graphType graph, char id[])
{
    int index;
    int found = 0;
    int i = 0;
    while(!(found) && i < graph.nVertices)
    {
        if (strcmp(graph.vertexNames[i], id) == 0)
        {
            index = i;
            found = 1;
        }

        i++;
    }

    return index;
}

int isPresent(char ID[], list dfsList, int vertexListed)
{
    int isPresent = 0;

    for (int i = 0; i < vertexListed; i++)
    {
        if (strcmp(dfsList[i], ID) == 0)
        {
            isPresent = 1;
        }
    }

    return isPresent;
}

void dfs(graphType graph, list result, char startVertex[], int *finalCount)
{
    int resultCount = 0;
    int next;
    int found = 0;
    int i, j, x;
    string temp;

    stackType stack;
    stack = CREATESTACK("stack");

    // Push the user-specified START VERTEX 
    PUSHSTACK(&stack, startVertex);

    while (!ISEMPTYSTACK(&stack))
    {
        i = 0;
        found = 0;
        // Loop until we have the index
        while (!(found) && i < graph.nVertices)
        {
            TOPSTACK(&stack, temp);
            if (strcmp(graph.vertexNames[i], temp) == 0)
            {
                x = i;
                found = 1;
            }
            i++;
        }

        // Visit the vertex if it hasn't been visited yet
        if (!isPresent(graph.vertexNames[x], result, resultCount))
        {
            strcpy(result[resultCount], graph.vertexNames[x]);
            resultCount++;
        }

        found = 0;

        // Search neighbors in alphabetical order
        j = 0;
        while (!(found) && j < graph.nVertices)
        {
            next = getIndex(graph, j);

            if (graph.matrix[x][next] == 1)
            {
                if (!isPresent(graph.vertexNames[next], result, resultCount))
                {
                    PUSHSTACK(&stack, graph.vertexNames[next]);
                    found = 1;
                }
            }
            j++;
        }

        // No neighbor found -> backtrack
        if (!found)
        {
            POPSTACK(&stack, temp);
        }
    }

    FREESTACK(&stack);
    *finalCount = resultCount; // Pass the count back to the output function
}

void bfs(graphType graph, list result, char startVertex[], int *finalCount)
{
    int resultCount = 0;
    int next = 0;
    int i, j, x;
    string temp;

    QueueType queue;
    queue = CREATEQUEUE("queue");

    // Enqueue the user-specified START VERTEX 
    ENQUEUE(&queue, startVertex);

    while (!ISEMPTYQUEUE(&queue))
    {
        // Get the front vertex
        DEQUEUE(&queue, temp);

        // Skip if already visited
        if (!(isPresent(temp, result, resultCount)))
        {
            strcpy(result[resultCount], temp);
            resultCount++;

            // Convert ID to matrix index
            x = getVertexIndex(graph, temp);

            // Visit neighbors in alphabetical order
            for (j = 0; j < graph.nVertices; j++)
            {
                next = getIndex(graph, j);

                if (graph.matrix[x][next] == 1)
                {
                    if (!isPresent(graph.vertexNames[next], result, resultCount))
                    {
                        ENQUEUE(&queue, graph.vertexNames[next]);
                    }
                }
            }
        }
    }

    FREEQUEUE(&queue);
    *finalCount = resultCount; // Pass the count back to the output function
}

/*
    a. Name of Programmer(s):  Jacob Miguel P. Gregorio
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: To output the BFS traversal sequence to a text file.
    e. Return: ala talaga pre
    f. Parameters: outputFilename for the destination file, graph for the graph data, startVertex for the origin
*/
void ikalimangOutput(str30 outputFilename, graphType *graph, char startVertex[])
{
    FILE *fp;

    if (graph->nVertices > 0)
    {
        if (fp = fopen(outputFilename, "w"))
        {
            list result;
            int resultCount = 0;
            int i;

            // Call the BFS function with the start vertex
            bfs(*graph, result, startVertex, &resultCount);

            // Prints the sequence with spaces for every vertex
            for (i = 0; i < resultCount; i++)
            {
                fprintf(fp, "%s", result[i]);
                
                // Add a space after every vertex EXCEPT the last vertex
                if (i < resultCount - 1)
                {
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");

            fclose(fp);
            printf("Successfully generated Output 5 in %s!\n", outputFilename);
        }
        else
        {
            printf("Output 5: Could not open %s\n", outputFilename);
        }
    }
}

/*
    a. Name of Programmer(s):  Jacob Miguel P. Gregorio
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: To output the DFS traversal sequence to a text file.
    e. Return: ala talaga pre
    f. Parameters: outputFilename for the destination file, graph for the graph data, startVertex for the origin
*/
void ikaanimNaOutput(str30 outputFilename, graphType *graph, char startVertex[])
{
    FILE *fp;

    if (graph->nVertices > 0)
    {
        if (fp = fopen(outputFilename, "w"))
        {
            list result;
            int resultCount = 0;
            int i;

            // Call the DFS function with the start vertex
            dfs(*graph, result, startVertex, &resultCount);

            // Prints the sequence with spaces for every vertex
            for (i = 0; i < resultCount; i++)
            {
                fprintf(fp, "%s", result[i]);
                
                // Add a space after every vertex EXCEPT the last vertex
                if (i < resultCount - 1)
                {
                    fprintf(fp, " ");
                }
            }
            fprintf(fp, "\n");

            fclose(fp);
            printf("Successfully generated Output 6 in %s!\n", outputFilename);
        }
        else
        {
            printf("Output 6: Could not open %s\n", outputFilename);
        }
    }
}