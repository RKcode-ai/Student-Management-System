
/*
    Name: Rayyan Khattak
    Assignment number: 01
    Module: Programming in C/C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char name[70];
    int matriculation_num;
    float grades[3];
    float average;
} Student;

Student *students = NULL;
int count = 0;

//Displays the menue everytime the loop is re-run untill the user exits the program.
void menu(){
    printf("\n===== Student Record Management System =====\n");
    printf("1. Add Students\n");
    printf("2. Display All Students\n");
    printf("3. Search by Matriculation Number\n");
    printf("4. Update Student Record\n");
    printf("5. Delete a Student\n");
    printf("6. Sort by Average Marks\n");
    printf("7. Exit\n");
    printf("============================================\n");
}

//Find the average of the grades for each student.
float get_avg(float g1,float g2,float g3){
    return (g1 + g2 + g3) / 3.0 ;
}

//Check if the matriculation number is unique.
bool isMatricUnique(int mat_num){
    for (int i = 0; i < count; i++){
        if(students[i].matriculation_num == mat_num){
            return false;
        }
    }
    return true;
}

// Add students to the system depending upon how much the user wants to add everytime.
void add_Student() {
    int num;
    printf("How many students do you want to add? -> ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input!\n");
        while ((getchar() != '\n'));
        return;
    }
    while ((getchar() != '\n'));

    if (num <= 0) {
        printf("Number of students must be positive!");
        return;
    }

    Student *temp = realloc(students, (count + num) * sizeof(Student));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    students = temp;

    int *current_batch = calloc(num, sizeof(int));
    if (current_batch == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < num; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Name: ");
        fgets(students[count + i].name, 70, stdin);
        students[count + i].name[strcspn(students[count + i].name, "\n")] = 0;

        int mat_num;
        bool valid = false;
        while (!valid) {
            printf("\nMatriculation Number: ");
            if (scanf("%d", &mat_num) != 1) {
                printf("Invalid Input!\n");
                while ((getchar() != '\n'));
                continue;
            }

            // Check both existing students and the current batch
            bool unique_main = isMatricUnique(mat_num);
            bool unique_batch = true;
            for (int k = 0; k < i; k++) {
                if (current_batch[k] == mat_num) {
                    unique_batch = false;
                    break;
                }
            }

            if (unique_main && unique_batch) {
                students[count + i].matriculation_num = mat_num;
                current_batch[i] = mat_num;
                valid = true;
            } else {
                printf("Matriculation number already exists! Try again.\n");
            }
            while ((getchar() != '\n'));
        }

        printf("Grade 1: ");
        scanf("%f", &students[count + i].grades[0]);
        printf("Grade 2: ");
        scanf("%f", &students[count + i].grades[1]);
        printf("Grade 3: ");
        scanf("%f", &students[count + i].grades[2]);
        while ((getchar() != '\n'));

        students[count + i].average = get_avg(
            students[count + i].grades[0],
            students[count + i].grades[1],
            students[count + i].grades[2]
        );
    }

    count += num;
    free(current_batch);
    printf("\nAdded %d students!\n", num);
}


//Display all the students in the system in a table format.
void display(){
    if (count == 0){
        printf("No students in record to show!");
        printf("\n");
        return;
    }
    printf("\n                         ===== All Students =====\n");
    printf("\n");
    printf("%-20s %-12s %-8s %-8s %-8s %-10s\n", 
            "Name", "Matric no.", "Subj1", "Subj2", "Subj3", "Average");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20.20s %-12d %-8.2f %-8.2f %-8.2f %-10.2f\n",
           students[i].name, students[i].matriculation_num,
           students[i].grades[0], students[i].grades[1], students[i].grades[2],
           students[i].average);
    }
}

//Searches the records via matriculation number and displays the result if found.
void search(){
    if(count == 0){
        printf("No students in the record!\n");
        return;
    }

    int mat_num;
    printf("Enter the matriculation number: ");
    //validate input
    if(scanf("%d", &mat_num) != 1){
        printf("Invalid Input!");
        while ((getchar() != '\n'));
        return;
    }
    while ((getchar() != '\n'));

    for (int i = 0; i < count; i++){
        if (students[i].matriculation_num == mat_num){
            printf("\nName: %s\n", students[i].name);
            printf("Matric: %d\n", students[i].matriculation_num);
            printf("Mark 1: %.2f\n", students[i].grades[0]);
            printf("Mark 2: %.2f\n", students[i].grades[1]);
            printf("Mark 3: %.2f\n", students[i].grades[2]);
            printf("Average: %.2f\n", students[i].average);
            return;
        }
    }
    printf("Not found!");
}

//updates the grades and average of a partiular student.
void update(){
    if(count == 0){
        printf("No students in the records!\n");
        return;
    }

    int mat_num;
    printf("Enter the matriculation number: ");
    //validate input
    if(scanf("%d", &mat_num) != 1){
        printf("Invalid Input!\n");
        while ((getchar() != '\n'));
        return;
    }
    while ((getchar() != '\n'));

    for (int i = 0; i < count; i++) {
        if (students[i].matriculation_num == mat_num) {
            printf("Mark 1: ");
            scanf("%f", &students[i].grades[0]);
            printf("Mark 2: ");
            scanf("%f", &students[i].grades[1]);
            printf("Mark 3: ");
            scanf("%f", &students[i].grades[2]);
            getchar();
            
            students[i].average = get_avg(students[i].grades[0], students[i].grades[1], students[i].grades[2]);
            printf("\n");
            printf("Updated the record for your student!\n");
            return;
        }
    }
    printf("\n");
    printf("Student not found to update record for!");
}

//Deletes a studetns record from the system.
void delete_Student(){
    if(count == 0){
        printf("No students in the records!\n");
        return;
    }

    int mat_num;
    printf("Enter the matriculation number: ");
    //validate input
    if(scanf("%d", &mat_num) != 1){
        printf("Invalid Input!\n");
        while ((getchar() != '\n'));
        return;
    }
    while ((getchar() != '\n'));

    for (int i = 0; i < count; i++) {
        if (students[i].matriculation_num == mat_num) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student Deleted!\n");
            display();
            return;
        }
    }
    printf("Not found!\n");
}

//sorts the records in descending order by average.
void sort(){
    if(count == 0){
        printf("No students in the records!\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    display();
}


int main(){
    int choice;
    while (1){

        menu();
        //validate input
        if (scanf("%d", &choice) != 1){
            printf("Invalid input!");
            while ((getchar() != '\n'));
            continue;
        }
        while ((getchar() != '\n'));

        switch (choice){
            case 1:
                add_Student();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                delete_Student();
                break;
            case 6:
                sort();
                break;
            case 7:
                free(students);
                students = NULL;
                printf("Bye! See you next time!\n");
                printf("\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


