#include<stdio.h>
#include<string.h>

struct subject
{
    char name[20];
    int marks;
};

struct student
{
    char name[50];
    int rollno;
    char school[100];
};

void border()
{
    printf("**********************************************************************\n");
}

char grade(int marks)
{
    if(marks >= 90)
        return 'A';
    else if(marks >= 80)
        return 'B';
    else if(marks >= 70)
        return 'C';
    else if(marks >= 60)
        return 'D';
    else if(marks >= 50)
        return 'E';
    else 
        return 'F';
}

int main()
{
    struct student st;
    struct subject s[6];

    int i;
    int total = 0;
    float percentage;

    strcpy(s[0].name, "Telugu");
    strcpy(s[1].name, "Hindi");
    strcpy(s[2].name, "English");
    strcpy(s[3].name, "Mathematics");
    strcpy(s[4].name, "Science");
    strcpy(s[5].name, "Social");

    printf("Enter Student Name: ");
    fgets(st.name, sizeof(st.name), stdin);
    st.name[strcspn(st.name, "\n")] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &st.rollno);

    getchar();

    printf("Enter School Name: ");
    fgets(st.school, sizeof(st.school), stdin);
    st.school[strcspn(st.school, "\n")] = '\0';

    printf("\nEnter Marks\n");

    for(i=0; i<6; i++)
    {
        printf("Enter %s marks: ", s[i].name);
        scanf("%d", &s[i].marks);
    }

    for(i=0; i<6; i++)
    {
        total = total + s[i].marks;
    }

    percentage = (total/600.0) * 100;

    printf("\n");
    border();

    printf("* %-67s*\n",           "10th CLASS MARKS MEMO                ");

    border();

    printf("* %-12s : %-52s*\n", "Name", st.name);
    printf("* %-12s : %-52d*\n", "Roll No", st.rollno);
    printf("* %-12s : %-52s*\n", "School", st.school);

    border();

    printf("* %-20s %-10s %-10s %-25s*\n", "Subject", "Marks","Grade","");
    
    border();
    
    for(i=0; i<6; i++)
    {
        printf("* %-20s %-10d %-10c %-25s*\n",s[i].name, s[i].marks,grade(s[i].marks),""); 
    }

    border();

    printf("* %-12s : %-10d %-42s*\n",
            "Total", total,"/600");
    printf("* %-12s : %-10.2f %-40s*\n",
            "Percentage", percentage, "%");
    printf("* %-12s : %-10c %-42s*\n",
            "Grace", grade((int)percentage),"");
    if(percentage >= 35)
    {
        printf("* %-12s : %-10s %-42s*\n",
                "Result", "PASS","");
    }
    else
    {
        printf("* %-12s : %-10s %-42s*\n",
                "Result", "FAIL", "");
    }

    border();

    return 0;
}



