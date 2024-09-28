#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    FILE *inp, *outp;
    int c;
    if((inp=fopen("in.txt","r")) == NULL)
        return -1;
    
    if((outp=fopen("out.txt","w")) == NULL)
        return -2;
    
    while((c=fgetc(inp)) != EOF && c!='\n'){
        cout << c << " ";
        fputc(c,outp);
    }

    fclose(inp);
    fclose(outp);
    return 0;
}