#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* printStudentDetails()
{
    //int year, branch, college, regno,
    int srl;
    char yearx[4], branchx[3], collegex[3], regnox[3];
    int students[5];
    do
    {
        printf("Enter 0 to close and 1 to enter details: ");
        scanf("%d", &srl);
        if (srl == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                
                    printf("Enter the codes for the following details student %d : \nyear \tbranch code \tcollege code \t regno :: --", i + 1);
                    scanf("%s %s %s %s", yearx, branchx, collegex, regnox);
                    // sprintf(yearx, "%d", year);
                    // sprintf(branchx, "%d", branch);
                    // sprintf(collegex, "%d", collegex);
                    // sprintf(regnox, "%d", regno);
                    char *details;
                    char part1[6]=yearx, part2[7]=collegex;
                    printf("\nprocessing details");
                    
                    strcat(part1,branchx);
                    printf("\nConcatenated value is %s",part1);
                    strcat(part2, regnox);
                    printf("\nConcatenated value is %s",part2);
                    printf("\nConcated first part");
                    // strcat(part2, collegex);
                    // strcat(part2, regnox);
                    strcat(details, part1);
                    strcat(details, part2);
                    printf("\nConcatenated value is %s",details);
                    students[i]=atoi(details);
                
            }
        }
        return students;

    } while (srl == 1);

    return 0;
}

int main()
{
    FILE *f;
    char c[100];

    // Open file for reading
    f = fopen("attendance.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file for reading!\n");
        return 1;
    }

    // Read and print file content
    while (fgets(c, sizeof(c), f) != NULL)
    {
        printf("%s", c);
    }

    fclose(f);

    // Open file for appending
    f = fopen("attendance.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // Write to file
    char status;
    printf("\nEnter the present status of student: ");
    scanf("%c", &status);
    if (status == 'p')
    {
        fprintf(f, "\t \tPresent");
    }
    else
    {
        fprintf(f, "\t \tAbsent");
    }

    // fprintf(f, " \tPresent\t ");

    fclose(f);

    printf("\nData written successfully.\n");

    int *data;
    
     data = printStudentDetails();
   if (sizeof(data)/sizeof(data[0])==0)
   {
    printf("Nothing found!!");
   }
   else
   {
    for (int i = 0; i < 5; i++)
    {
        printf("%d", data[i]);
    }
   }
   

    return 0;
}