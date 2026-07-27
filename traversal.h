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
#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "graph.h"
#include "dataStruct.h"

int getIndex(graphType graph, int num);
int getVertexIndex(graphType graph, char id[]);
int isPresent(char ID[], list dfsList, int vertexListed);
void dfs(graphType graph, list result, char startVertex[], int *finalCount);
void bfs(graphType graph, list result, char startVertex[], int *finalCount);
void ikalimangOutput(str30 outputFilename, graphType *graph, char startVertex[]);
void ikaanimNaOutput(str30 outputFilename, graphType *graph, char startVertex[]);
#endif