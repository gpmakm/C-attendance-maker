#include<stdio.h>
#include<string.h>

void main(){
    FILE *f;
    f=fopen("attendance.txt","r");
    char c[15];
    fread(c,sizeof(char),14,f);
    printf("%s",c);
    if (strcmp(c,"24153147901")==0)
    {
        fclose(f);
        f=fopen("attendance.txt","a");
        fwrite(" 1 ",sizeof(char),3,f);
    }
    fclose(f);
    
}