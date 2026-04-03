#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* printStudentDetails()
{
    
    int srl;
    char yearx[4], branchx[4], collegex[4], regnox[4];
    long long int *students = malloc(5 * sizeof(long long int));
    do
    {
        printf("Enter 0 to close and 1 to enter details: ");
        scanf("%d", &srl);
        if (srl == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                
                    printf("Enter the codes for the following details student %d : \nyear \tbranch code \tcollege code \t regno :: --", i + 1);
                    scanf("%2s %3s %3s %3s", yearx, branchx, collegex, regnox);
                    
                    char final[150];
                    snprintf(final,sizeof(final),"%s%s%s%s",yearx,branchx,collegex,regnox);
                    printf("\nprocessing details");
                    
                    
                    printf("\nConcatenated value is %s\n",final);
                    students[i]=atoll(final);
                
            }
        }
        // for (int i = 0; i < 5; i++)
        // {
        //    printf("%lld\n", students[i]);
        // }
        
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

    long long int *data;
    
     data = printStudentDetails();
  
    for (int i = 0; i < 5; i++)
    {
        printf("%lld", data[i]);
    }
   
   

    return 0;
}