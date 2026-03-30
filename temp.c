#include<stdio.h>
#include<string.h>
void main(){
    char value[4];
    char result[5]="Hii";
    strcat(result,"A");
    printf("%s",result);
    
    sprintf(value,"%d",2024);
    //printf("Type of variable is ",typeof(value));
    printf("%s",value);
}