#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int printStudentDetails()
{
    int year, branch, college, regno, srl;
    char yearx[4], branchx[3], collegex[3], regnox[3];
    int students[5][11];
    do
    {
        printf("Enter 0 to close and 1 to enter details: ");
        scanf("%d", &srl);
        if (srl == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 11; i++)
                {
                    printf("Enter the codes for the following details student %d : \nyear \tbranch code \tcollege code \t regno :: --", i + 1);
                    scanf("%d %d %d %d", year, branch, college, regno);
                    sprintf(yearx, "%d", year);
                    sprintf(branchx, "%d", branch);
                    sprintf(collegex, "%d", collegex);
                    sprintf(regnox, "%d", regno);
                    // char dtl1[5] = strcat(yearx, branchx);
                    // char dtl2[5] = strcat(collegex, regnox);
                    // students[i][j] = strcat(dtl1, dtl2);
                    students[i][j]=year+""+branch+""+college+""+regno;
                }
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
        fprintf(f, "\tPresent");
    }
    else
    {
        fprintf(f, "\tAbsent");
    }

    // fprintf(f, " \tPresent\t ");

    fclose(f);

    printf("\nData written successfully.\n");

    int data[5][11];
   if (data==0)
   {
    printf("Nothing found!!");
   }
   else
   {
     data = printStudentDetails();
    for (int i = 0; i < 5; i++)
    {
        printf("%d", data[i][j]);
    }
   }
   

    return 0;
}