#include <stdio.h>
#include <string.h>

struct student {
    char name[200];
    char sex;
    int credits;
};

int main() {
    int num_students;
    printf("How many students do you want to input?\n");
    scanf("%d", &num_students);

    struct student students[num_students];

    // Input information for each student
    for (int i = 0; i < num_students; i++) {
        printf("Please input information for student %d:\n", i + 1);
        printf("Name? ");
        scanf("%s", students[i].name);
        printf("Sex('M' or 'F')? ");
        scanf(" %c", &students[i].sex);
        printf("Credits? \n");
        scanf("%d", &students[i].credits);
    }

    int criteria;
    printf("Which of the following four groups do you want to print? (1) male students (2) female students (3) odd credits (4) even credits\n");
    scanf("%d", &criteria);

    switch (criteria) {
        case 1: //male student case
            for (int i = 0; i < num_students; i++) {
                if (students[i].sex == 'M') {
                    printf("%s is a male student with credits %d.\n", students[i].name, students[i].credits);
                }
            }
            break;
        case 2: //female student case
            for (int i = 0; i < num_students; i++) {
                if (students[i].sex == 'F') {
                    printf("%s is a female student with credits %d.\n", students[i].name, students[i].credits);
                }
            }
            break;
        case 3: //odd credits case
            for (int i = 0; i < num_students; i++) {
                if((students[i].credits%2!=0)&&(students[i].sex=='M'))
                    printf("%s is a male student with credits %d.\n",students[i].name,students[i].credits); // have to access directly 
                else if((students[i].credits%2!=0)&&students[i].sex=='F')
                    printf("%s is a female student with credits %d.\n",students[i].name,students[i].credits);
            }
            break;
        case 4: //even credits case
            for (int i = 0; i < num_students; i++) {
                if((students[i].credits%2==0)&&(students[i].sex=='M'))
                    printf("%s is a male student with credits %d.\n",students[i].name,students[i].credits);
                else if((students[i].credits%2==0)&&students[i].sex=='F')
                    printf("%s is a female student with credits %d.\n",students[i].name,students[i].credits);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}