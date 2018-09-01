

/**
lightweight vanilla bf to c compiler, gets code from stdin and outputs to stdout.
you can redirect the the input and/or output to files using a 'pipe' (added example in the batch file).
or type/paste the code directly to the console, and get the output of the c code directly to the console.
*/


#ifndef BF_H
#define BF_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**errors may occur if you try to compile non-vanilla bf */
#define MEMORY 30000

/**errors may occur if a file exceeds this limit, simply increase it*/
#define BF_CODE_BUFFER 50000


void init_file()
{
    printf("int main()\n");
    printf("{\n");
    printf("\tchar mem[%d],*pointer=mem;\n",MEMORY);
    printf("\tint i;for(i=0;i<%d;i++)mem[i]=0;\n",MEMORY);
}

void BF(char *code)
{
    int i;
    for(i=0;code[i]!='\0';i++)
    {
        switch(code[i])
        {
            case '>': printf("\tpointer++;\n");break;
            case '<': printf("\tpointer--;\n");break;
            case '+': printf("\t++*pointer;\n");break;
            case '-': printf("\t--*pointer;\n");break;
            case '[': printf("\twhile(*pointer)\n\t{\n");break;
            case ']': printf("\t}\n");break;
            case '.': printf("\tputchar(*pointer);\n");break;
            case ',': printf("\t*pointer=getchar();\n");break;
        }
    }

}
void end_file()
{
    printf("\treturn *pointer;\n");
    printf("}\n");
}

void compile()
{
    char bf_code[BF_CODE_BUFFER];
    fread(bf_code,BF_CODE_BUFFER,1,stdin);
    init_file();
    BF(bf_code);
    end_file();
}

#endif // BF_H
