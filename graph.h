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

#define MAX_VERTICES 20 // Max vertices in a graph is 20
#define MAX_ID_LENGTH 9 // Max ID length is 8, +1 to account for null

struct graphTag{
    int nVertices;                                  // Number of vertices in a graph
    char vertexNames[MAX_VERTICES][MAX_ID_LENGTH];  /*Array of vertex names that can store a maximum of 20 vertices 
                                                    and a maximum of 8 characters pero vertex*/ 
    int matrix[MAX_VERTICES][MAX_VERTICES];          //20x20 2D array that SHOULD contain 0s (walang edge) and 1s (may edge)
    
};


/*
HAS: 
- GetInput Function from .txt
- Function for Output #1 (Vertices & Edges)
- Function for Output #2 (Vertices with Degrees)
- Function for Output #3 (Adjacency List Visualization)
- Function for Output #4 (Adjacency Matrix Visualization)
*/