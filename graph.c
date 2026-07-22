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
#include <string.h>
#include "graph.h"
/*
    a. Name of Programmer(s):  Jacob Miguel P. Gregorio
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: blank
    e. Return: ala talaga pre
    f. Parameters: ala
*/
void kuninInput(str30 inputFilename, graphType *graph)
{
    FILE *fp;
    graph->nVertices = 0;
    // if opening file and read mode is sucessful, program will proceed. Otherwise it will return an error message
    if (fp = fopen(inputFilename, "r"))
    {   
        int i,j,k;
        
        //Reads the first integer and stores it inside nVertices
        fscanf(fp, "%d", &graph->nVertices);

        //Initialize everything in the matrix as 0
        for (i = 0; i < graph->nVertices; i++) 
        {
            for (j = 0; j < graph->nVertices; j++) 
            {
                graph->matrix[i][j] = 0;
            }
        }

        char tempAdj[MAX_VERTICES][MAX_VERTICES][MAX_ID_LENGTH]; // Stores a 20x20 matrix that each contains a string of max 8 chars (vertex id)
        int adjCount[MAX_VERTICES] = {0}; // Tracks how many adjacent vertices each row has

        for (i = 0; i < graph->nVertices; i++) 
        {
            
            // The first string on the line is always the main vertex and not a sentinel value
            fscanf(fp, "%s", graph->vertexNames[i]);

            char temp[MAX_ID_LENGTH];

            // Read the first adjacent vertex (or sentinel) before the loop
            fscanf(fp, "%s", temp);

            // Loops until it reaches sentinel
            while (strcmp(temp, "-1") != 0) 
            {
                
                // Stores vertex id into temporary adjacency list
                strcpy(tempAdj[i][adjCount[i]], temp);
                adjCount[i]++;
                
                //Read string again before looping
                fscanf(fp, "%s", temp);
            }
        }
        
        fclose(fp);
        printf("\nSuccessfully loaded %d vertices from %s!\n", graph->nVertices, inputFilename);
        // Adjacency Matrix Mapping
        for (i = 0; i < graph->nVertices; i++) 
        {
            for (j = 0; j < adjCount[i]; j++) 
            {
                char adjName[MAX_CHAR_LENGTH];
                strcpy(adjName, tempAdj[i][j]);
                
                // Find the integer index of the adjacent vertex
                int adjId = -1;
                for (k = 0; k < graph->nVertices && adjId == -1; k++) {
                    if (strcmp(graph->vertexNames[k], adjName) == 0) {
                        adjId = k;
                    }
                }

                // If found, set the matrix to 1 for both vertices
                if (adjId != -1) {
                    graph->matrix[i][adjId] = 1;
                    graph->matrix[adjId][i] = 1;
                }
            }
        }
        printf("Sucessfully mapped vertices into the matrix!");
    }
    else
    {
        printf("Whoops! Could not open %s", inputFilename);
    }
}

/*
    a. Name of Programmer(s):  Jacob Miguel P. Gregorio
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: blank
    e. Return: ala talaga pre
    f. Parameters: ala
*/
void unangOutput(str30 inputFilename, str30 outputFilename, graphType *graph)
{
    FILE *fp;
    // Only executes if a graph was successfully loaded
    if (graph->nVertices > 0)
    {
        // if opening file and write mode is sucessful, program will proceed. Otherwise it will return an error message
        if (fp = fopen(outputFilename, "w"))
        {   
            int i,k,flag;
            str30 graphName;
            strcpy(graphName, inputFilename);
            
            flag = 0; // 0 means not found yet, 1 means found
            
            // The loop continues ONLY IF it hasn't reached the end of the string AND flag is still 0
            for (k = 0; graphName[k] != '\0' && flag == 0; k++) 
            {
                if (graphName[k] == '.') 
                {
                    graphName[k] = '\0'; // Cut off string by inserting a null terminator
                    flag = 1;        // Update flag to terminate loop
                }
            }

            //Prints Vertices
            fprintf(fp, "V(%s)={", graphName);
            for (i = 0; i < graph->nVertices; i++)
            {
                fprintf(fp, "%s", graph->vertexNames[i]);
                
                // Only print a comma if it is NOT the last vertex in the array
                if (i < graph->nVertices - 1)
                {
                    fprintf(fp, ",");
                }
            }
            fprintf(fp, "}\n");

            //Count total edges
            int totalEdges = 0;
            for (int i = 0; i < graph->nVertices; i++)
            {
                for (int j = i; j < graph->nVertices; j++)
                {
                    if (graph->matrix[i][j] == 1)
                    {
                        totalEdges++;
                    }
                }
            }

            //Print edges
            fprintf(fp, "E(%s)={ ", graphName);
            int edgesPrinted = 0;
            
            for (int i = 0; i < graph->nVertices; i++)
            {
                for (int j = i; j < graph->nVertices; j++)
                {
                    if (graph->matrix[i][j] == 1)
                    {
                        fprintf(fp, "(%s,%s)", graph->vertexNames[i], graph->vertexNames[j]);
                        edgesPrinted++;
                        
                        if (edgesPrinted < totalEdges)
                        {
                            fprintf(fp, " , ");
                        }
                    }
                }
            }
            fprintf(fp, " }\n");

            fclose(fp);
            printf("Successfully generated Output 1 in %s!\n", outputFilename);

        }
        else
        {
            printf("Output 1: Could not open %s", outputFilename);
        }
    }

}

/*
    a. Name of Programmer(s):  Jacob Miguel P. Gregorio
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: blank
    e. Return: ala talaga pre
    f. Parameters: ala
*/
void ikalawangOutput(str30 outputFilename, graphType *graph)
{
    FILE *fp;

    if (graph->nVertices > 0)
    {
        // if opening file and write mode is sucessful, program will proceed. Otherwise it will return an error message
        if (fp = fopen(outputFilename, "w"))
        {
            int i, j;
            int sortedIndices[MAX_VERTICES];
            
            // Initialize an array of indices corresponding to the vertices
            for (i = 0; i < graph->nVertices; i++)
            {
                sortedIndices[i] = i; 
            }

            // Bubble sort (ftw) the indices based on alphabetical order
            for (i = 0; i < graph->nVertices - 1; i++)
            {
                for (j = 0; j < graph->nVertices - i - 1; j++)
                {
                    int id1 = sortedIndices[j];
                    int id2 = sortedIndices[j + 1];
                    
                    // If it strcmp result in > 0 the first string comes alphabetically after the second
                    if (strcmp(graph->vertexNames[id1], graph->vertexNames[id2]) > 0)
                    {
                        // Swap the integer indices
                        int temp = sortedIndices[j];
                        sortedIndices[j] = sortedIndices[j + 1];
                        sortedIndices[j + 1] = temp;
                    }
                }
            }

            // Calcu and print the degrees in alphabetical order
            for (i = 0; i < graph->nVertices; i++)
            {
                int origId = sortedIndices[i]; 
                int degreeCount = 0;
                
                // Scan the entire row to count every connection for this specific vertex
                for (j = 0; j < graph->nVertices; j++)
                {
                    if (graph->matrix[origId][j] == 1)
                    {
                        degreeCount++;
                    }
                }
                
                // Output ex: "Bruce 1"
                fprintf(fp, "%s %d\n", graph->vertexNames[origId], degreeCount);
            }

            fclose(fp);
            printf("Successfully generated Output 2 in %s!\n", outputFilename);
        }
        else
        {
            printf("Output 2: Could not open %s", outputFilename);
        }
    }

}

/*
    a. Name of Programmer(s):  Jacob Miguel P. Gregorio
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: blank
    e. Return: ala talaga pre
    f. Parameters: ala
*/
void ikatlongOutput(str30 outputFilename, graphType *graph)
{
    FILE *fp;
    int i,j;

    if (graph->nVertices > 0)
    {
        // if opening file and write mode is sucessful, program will proceed. Otherwise it will return an error message
        if (fp = fopen(outputFilename, "w"))
        {
            // Loop through vertices in their original input sequence
            for (i = 0; i < graph->nVertices; i++)
            {
                // Print main vertex and the first arrow thingy
                fprintf(fp, "%s->", graph->vertexNames[i]);

                // Scan entire row for any connections
                for (j = 0; j < graph->nVertices; j++)
                {
                    if (graph->matrix[i][j] == 1)
                    {
                        // Print adjacent vertex and respective arrow thingy
                        fprintf(fp, "%s->", graph->vertexNames[j]);
                    }
                }

                // Print the NULL pointer representation at the end of the list
                fprintf(fp, "\\\n");
            }

            fclose(fp);
            printf("Successfully generated Output 3 in %s!\n", outputFilename);
        }
        else
        {
            printf("Output 3: Could not open %s", outputFilename);
        }
    }
}

/*
    a. Name of Programmer(s):  Jacob Miguel P. Gregorio
    b. Name of Tester(s)    :  Gabriel Angelo L. De Silva
    c. Code Type -- 100% Human Generated 
    d. Purpose: blank
    e. Return: ala talaga pre
    f. Parameters: ala
*/
void ikaapatNaOutput(str30 outputFilename, graphType *graph)
{
    FILE *fp;
    int i,j;

    if (graph->nVertices > 0)
    {
        // if opening file and write mode is sucessful, program will proceed. Otherwise it will return an error message
        if (fp = fopen(outputFilename, "w"))
        {
            // For corner space
            fprintf(fp, "        "); 

            // Print top row of labels (column)
            for (i = 0; i < graph->nVertices; i++)
            {
                // Aligns string within an 8-character wide space
                fprintf(fp, "%-8s", graph->vertexNames[i]);
            }
            fprintf(fp, "\n");

            // Print matric by row
            for (i = 0; i < graph->nVertices; i++)
            {
                // Print row label first
                fprintf(fp, "%-8s", graph->vertexNames[i]);

                // Print 1s and 0s for jth specific row
                for (j = 0; j < graph->nVertices; j++)
                {
                    // I think mag-align padin sya sa %-8s na pinag gagawa ko kanina :)
                    fprintf(fp, "%-8d", graph->matrix[i][j]);
                }
                
                fprintf(fp, "\n");
            }

            fclose(fp);
            printf("Successfully generated Output 4 in %s!\n", outputFilename);
        }
        else
        {
            printf("Output 4: Could not open %s", outputFilename);
        }
    }
}

/*
HAS: 
- GetInput Function from .txt DONE
- Function for Output #1 (Vertices & Edges)
- Function for Output #2 (Vertices with Degrees)
- Function for Output #3 (Adjacency List Visualization)
- Function for Output #4 (Adjacency Matrix Visualization)
*/