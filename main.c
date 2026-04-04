#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* printStudentDetails()
{
    
    int srl;
    char yearx[4], branchx[4], collegex[4], regnox[4];
    long long int *students = malloc(70 * sizeof(long long int));
    do
    {
        printf("Enter 0 to close and 1 to enter details: ");
        scanf("%d", &srl);
        if (srl == 1)
        {
            for (int i = 0; i < 70; i++)
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

void eraseData(){
    FILE *nf;
    nf=open("attendance.txt","w");
    fprintf(nf,"");
    fclose(nf);
}

void registerStudents(){
      long long int *data;
      FILE f;
      f=open("attendance.txt","w");
      
      
    
     data = printStudentDetails();
  
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        fprintf(f, "%lld", data[i]);
    }
    fclose(f);
}

void writeData(){
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


}

int main()
{
    FILE *f;
    char c[100];
    printf("Welcome to the attendance management system\n \nSelect an option: \n1. Register students \n2. Mark attendance \n3. View attendance\n4. Erase data\n5. Exit\n");
    short int option;
    scanf("%hd", &option);
    switch (option)
    {
    case 1:
        registerStudents();
        break;
    case 2:
        writeData();
        break;
    case 3:
        // View attendance logic
        break;
    case 4:
        eraseData();
        break;
    case 5:
        exit(0);
    default:
        break;
    }

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
    
  
   
   

    return 0;
}