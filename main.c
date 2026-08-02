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
    FILE *fp;
    graphType graph;
    str30 input;

    printf("Input filename: ");
    scanf("%s", input);
    if ((fp = fopen(input, "r"))) // opens and reads the file with the matching name inputted
    {
        fclose(fp);
        kuninInput(input, &graph); // verifies the input

        str30 nameOnly, out1, out2, out3, out4, out5, out6, startVertex;
        int i;
        int dotFound = 0; //if '.' is found
        int vertFound = 0;

        strcpy(nameOnly, input);

        for (i = 0; nameOnly[i] != '\0' && dotFound == 0; i++) // loops through the string until it sees a '.'
        {   // this loop removes the file extension
            if (nameOnly[i] == '.')
            {
                nameOnly[i] = '\0'; // replaces the '.' with a null byte to end the string there
                dotFound = 1;
            }
        }
        strcpy(out1, nameOnly); // takes the file name e.g. "G"
        strcat(out1, "-SET.TXT"); // adds the file extension to the file name e.g. "G-SET.TXT"

        strcpy(out2, nameOnly); // takes the file name e.g. "G"
        strcat(out2, "-DEGREE.TXT"); // adds the file extension to the file name e.g. "G-DEGREE.TXT"

        strcpy(out3, nameOnly); // takes the file name e.g. "G" 
        strcat(out3, "-LIST.TXT"); // adds the file extension to the file name e.g. "G-LIST.TXT"

        strcpy(out4, nameOnly); // takes the file name e.g. "G"
        strcat(out4, "-MATRIX.TXT"); // adds the file extension to the file name e.g. "G-MATRIX.TXT"

        // calls the output functions to produce a text file
        unangOutput(input, out1, &graph); 
        ikalawangOutput(out2, &graph);
        ikatlongOutput(out3, &graph);
        ikaapatNaOutput(out4, &graph);

        printf("Input start vertex for the traversal: ");
        scanf("%s", startVertex);

        for (i = 0; i < graph.nVertices; i++) // loops through all the vertices
        {
            if (strcmp(startVertex, graph.vertexNames[i]) == 0) // checks if a specified vertix is found
            {
                vertFound = 1;
            }
            
        }
        if (vertFound == 0) // NOT found
        {
            printf("Vertex %s not found.\n", startVertex); // error message
            return 0;
        }
        if (vertFound == 1) // vert is valid and is found
        {
            strcpy(out5, nameOnly);  // takes the file name e.g. "G"
            strcat(out5, "-BFS.TXT"); // adds the file extension to the file name e.g. "G-BFS.TXT"

            strcpy(out6, nameOnly);  // takes the file name e.g. "G"
            strcat(out6, "-DFS.TXT"); // adds the file extension to the file name e.g. "G-DFS.TXT"

            ikalimangOutput(out5, &graph, startVertex);
            ikaanimNaOutput(out6, &graph, startVertex);
        }
    }
    else
    {
        printf("File %s not found.", input); // error message
        return 0; // terminates the program
    }

    return 0;
}