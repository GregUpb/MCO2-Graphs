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
#include "traversal.h"

int main()
{
    graphType graph;
    list result;

    graph.nVertices = 6;

    // Deliberately NOT alphabetically ordered
    strcpy(graph.vertexNames[0], "B");
    strcpy(graph.vertexNames[1], "F");
    strcpy(graph.vertexNames[2], "A");
    strcpy(graph.vertexNames[3], "E");
    strcpy(graph.vertexNames[4], "D");
    strcpy(graph.vertexNames[5], "C");

    // Initialize matrix to 0
    for (int i = 0; i < graph.nVertices; i++)
    {
        for (int j = 0; j < graph.nVertices; j++)
        {
            graph.matrix[i][j] = 0;
        }
    }

    // Get indices
    int A = getVertexIndex(graph, "A");
    int B = getVertexIndex(graph, "B");
    int C = getVertexIndex(graph, "C");
    int D = getVertexIndex(graph, "D");
    int E = getVertexIndex(graph, "E");
    int F = getVertexIndex(graph, "F");

    // Undirected graph
    graph.matrix[A][B] = graph.matrix[B][A] = 1;
    graph.matrix[A][C] = graph.matrix[C][A] = 1;
    graph.matrix[B][D] = graph.matrix[D][B] = 1;
    graph.matrix[B][E] = graph.matrix[E][B] = 1;
    graph.matrix[C][F] = graph.matrix[F][C] = 1;

    dfs(graph, result);

    printf("DFS Result:\n");

    for (int i = 0; i < graph.nVertices; i++)
    {
        printf("%s ", result[i]);
    }

    printf("\n");

    return 0;
}