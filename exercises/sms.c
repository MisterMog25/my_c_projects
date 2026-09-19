#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct{
    int id;
    char name[40];
    char surname[40];
    int age;
    float avg_grade;

}Student;

void addStudent(Student **students, int *count, int *capacity); // done
void findStudent_id(Student *students, int count); // done
void findStudent_name(Student *students, int count); // done
void editStudent(Student *students, int count); // done
void printAllStudents(Student *students, int count); // done
void sortStudents(Student *students, int count); // done
void deleteStudent(Student **students, int *count); // done
void saveStudents(Student *students, int count, char filename[55]); //  done
void loadStudents(Student **students, int *count, int *capacity, char path[55]); //  done

// comparators 

int compareByName(const void *a, const void *b){
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    return strcmp(s2->name, s1->name);
}

int compareByAge(const void *a, const void *b){
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    return s2->age - s1->age;
}

int compareByGrade(const void *a, const void *b){
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    if (s2->avg_grade > s1->avg_grade) return -1;
    if (s2->avg_grade < s1->avg_grade) return 1;
    return 0;
}

// main logic

int main(void){
    
    printf("*** STUDENT MANAGEMENT SYSTEM (ADMIN) ***\n");

    bool isRunning = true;
    int choice = 0;
    int count = 0;
    int capacity = 1;

    int saver = 0;
    char filename[40] = "";

    Student *students = NULL;

    while (isRunning){

        
        printf("\nChoose the action:\n"
            "1. Add student\n"
            "2. Show all students\n"
            "3. Find student by ID\n"
            "4. Find student by name\n"
            "5. Edit student by ID\n"
            "6. Sort students\n"
            "7. Delete a student\n"
            "8. Save students to file\n"
            "9. Load students from file\n"
            "10. Exit\n");
        
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addStudent(&students, &count, &capacity);
                break;

            case 2:
                printAllStudents(students, count);
                break;

            case 3:
                findStudent_id(students, count);
                break;

            case 4:
                findStudent_name(students, count);
                break;

            case 5:
                editStudent(students, count);
                break;

            case 6:
                sortStudents(students, count);
                break;

            case 7:
                deleteStudent(&students, &count);
                break;

            case 8:
                if (saver == 0){
                    getchar();
                    printf("Enter the file to save: ");
                    fgets(filename, sizeof(filename), stdin);
                    filename[strlen(filename) - 1] = '\0';
                    saver += 1;
                }

                saveStudents(students, count, filename);
                break;

            case 9:
                getchar();
                printf("Enter the file to load from: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strlen(filename) - 1] = '\0';

                loadStudents(&students, &count, &capacity, filename);
                break;

            case 10:
                printf("\nThanks for using our service!\n");
                free(students);
                students = NULL;
                isRunning = false;
                break;

            default:
                printf("Incorrect input, try again!!!\n");
        }
    }

    return 0;
}

// functions

void addStudent(Student **students, int *count, int *capacity){
 
    Student *temp = realloc(*students, sizeof(Student)*(*capacity));

    srand(time(NULL));
    int uniid = rand(); 

    if (temp == NULL){
        printf("ERROR OCCURED, returning...");
        return;
    } else{
        *students = temp;
        temp = NULL;
    }

    Student *newStudent = &(*students)[*count];

    newStudent -> id = uniid;

    getchar();
    printf("Enter the name of the student: ");
    fgets(newStudent -> name, sizeof(newStudent->name), stdin);
    newStudent->name[strlen(newStudent->name) - 1] = '\0';

    printf("Enter the surname of the student: ");
    fgets(newStudent->surname, sizeof(newStudent->surname), stdin);
    newStudent->surname[strlen(newStudent->surname) - 1] = '\0';

    printf("Enter the age of the student: ");
    scanf("%d", &newStudent->age);

    printf("Enter the grade of a student: ");
    scanf("%f", &newStudent->avg_grade);

    printf("\nSuccessfuly added %s\n", newStudent->name);

    sleep(2);

    (*count)++;  
    (*capacity)++;
}

void printAllStudents(Student *students, int count){
    printf("printing all students...\n\n");
    sleep(2);

    for (int i = 0; i < count; i++){
        printf("Student #%d (id: %d)\n", i+1, students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Surname: %s\n", students[i].surname);
        printf("Age: %d\n", students[i].age);
        printf("Avg Grade: %.2f\n\n", students[i].avg_grade);
    }

}

void findStudent_id(Student *students, int count){
    int id = 0;
    printf("Enter id of a student: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++){
        if (id == students[i].id){
            printf("Found student!\n");
            printf("Student #%d (id: %d)\n", i+1, students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Surname: %s\n", students[i].surname);
            printf("Age: %d\n", students[i].age);
            printf("Avg Grade: %.2f\n\n", students[i].avg_grade);
            return;
        }
    }
    printf("Nothing found... check the typed id again!\n");

}

void findStudent_name(Student *students, int count){
    char name[40] = "";
    getchar();
    printf("Enter the name of a student: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    for (int i = 0; i < count; i++){
        if (strcmp(name, students[i].name) == 0){
            printf("Found student!\n");
            printf("Student #%d (id: %d)\n", i+1, students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Surname: %s\n", students[i].surname);
            printf("Age: %d\n", students[i].age);
            printf("Avg Grade: %.2f\n\n", students[i].avg_grade);
        }
    }
}

void editStudent(Student *students, int count){
    int id = 0;
    printf("\nEnter id of a student: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < count; i++){
        if (id == students[i].id){
            printf("Found student!\n\n");
            printf("Student #%d (id: %d)\n", i+1, students[i].id);

            printf("Enter new name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strlen(students[i].name) - 1] = '\0';

            printf("Enter new surname: ");
            fgets(students[i].surname, sizeof(students[i].surname), stdin);
            students[i].surname[strlen(students[i].surname) - 1] = '\0';

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new avg grade: ");
            scanf("%f", &students[i].avg_grade);
            printf("\nUpdated successfuly!\n");
            return;
        }
    }
    printf("Nothing found... check the typed id again!\n");

}

void sortStudents(Student *students, int count) {
    int choice = 0;
    printf("\nSort by:\n1. Name\n2. Age\n3. Average grade\nChoice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            qsort(students, count, sizeof(Student), compareByName);
            break;
        case 2:
            qsort(students, count, sizeof(Student), compareByAge);
            break;
        case 3:
            qsort(students, count, sizeof(Student), compareByGrade);
            break;
        default:
            printf("Invalid choice\n");
            return;
    }

    printf("Sorted!\n");
}

void deleteStudent(Student **students, int *count) {

    int id = 0;
    int found = -1;
    printf("Enter the id of the student you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < (*count); i++){
        if (id == (*students)[i].id){
            printf("Found!\n");
            found = i;
            break;
        }
    }

    if (found == -1){
        printf("Nothing found... check the typed id again!\n");
        return;
    }

    Student *lastStudent = &(*students)[(*count)-1];
    Student *desiredStudent = &(*students)[found];
    // 
    *desiredStudent = *lastStudent;

    printf("Successfuly deleted!");
    (*count)--;

}

void saveStudents(Student *students, int count, char filename[55]) {
    printf("\nSaving students, wait...");
    sleep(4);

    FILE *pFile = fopen(filename, "w");

    if (pFile == NULL){
        printf("Error: could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++){
        fprintf(pFile, "Student #%d (id: %d)\n", i+1, students[i].id);
        fprintf(pFile, "Name: %s\n", students[i].name);
        fprintf(pFile, "Surname: %s\n", students[i].surname);
        fprintf(pFile, "Age: %d\n", students[i].age);
        fprintf(pFile, "Avg Grade: %.2f\n\n", students[i].avg_grade);
    }

    printf("\nFile was successfuly written!\n");

    fclose(pFile);
}

void loadStudents(Student **students, int *count, int *capacity, char path[50]){
    printf("Loading students...\n");
    sleep(4);

    FILE *pFile = fopen(path, "r");

    if (pFile == NULL) {
        printf("Error: could not open file for reading.\n");
        return;
    }

    int index;
    Student temp;

    while (fscanf(pFile, "Student #%d (id: %d)\n", &index, &temp.id) == 2){
        fscanf(pFile, "Name: %39s\n", temp.name);
        fscanf(pFile, "Surname: %39s\n", temp.surname);
        fscanf(pFile, "Age: %d\n", &temp.age);
        fscanf(pFile, "Avg Grade: %f\n", &temp.avg_grade);

        Student *tempArr = realloc(*students, sizeof(Student) * (*count + 1));
        if (tempArr == NULL){
            printf("Error: realloc failed during load.\n");
            fclose(pFile);
            return;
        }
        *students = tempArr;

        (*students)[*count] = temp;
        (*count)++;
        *capacity = *count;
    }

    fclose(pFile);
    printf("Students loaded successfully!\n");
}