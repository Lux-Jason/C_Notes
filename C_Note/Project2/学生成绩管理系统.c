#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 30
#define MAX_ID_LEN 20
#define MAX_MAJOR_LEN 50
#define MAX_COURSE_LEN 50
#define GRADE_NUM 3

struct student {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    char major[MAX_MAJOR_LEN];
    float grades[GRADE_NUM];
};

struct student students[MAX_STUDENTS];
int num_students = 0;

void input_student_info();
void update_student_info();
void query_grades();
void report_grades();
void output_grades();
void help();
void exit_system();

//int main() {
//    int choice = 0;
//    while (1) {
//        printf("==== Student Grade Management System ====\n");
//        printf("1. Input Student Information\n");
//        printf("2. Update Student Information\n");
//        printf("3. Query Grades\n");
//        printf("4. Report Grades\n");
//        printf("5. Output Grades\n");
//        printf("6. Help\n");
//        printf("7. Exit\n");
//        printf("Please enter your choice (1-7):\n");
//        scanf("%d", &choice);
//        switch (choice) {
//        case 1:
//            input_student_info();
//            break;
//        case 2:
//            update_student_info();
//            break;
//        case 3:
//            query_grades();
//            break;
//        case 4:
//            report_grades();
//            break;
//        case 5:
//            output_grades();
//            break;
//        case 6:
//            help();
//            break;
//        case 7:
//            exit_system();
//            return 0;
//        default:
//            printf("Invalid choice!\n");
//            break;
//        }
//    }
//}

void input_student_info() {
    if (num_students >= MAX_STUDENTS) {
        printf("Too many students, cannot input more!\n");
        return;
    }
    struct student new_student;
    printf("Please enter the name of the student:\n");
    scanf("%s", new_student.name);
    printf("Please enter the ID of the student:\n");
    scanf("%s", new_student.id);
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, new_student.id) == 0) {
            printf("Duplicate ID, please input again!\n");
            return;
        }
    }
    printf("Please enter the major of the student:\n");
    scanf("%s", new_student.major);
    printf("Please enter the grades of the student (3 numbers separated by spaces):\n");
    scanf("%f %f %f", &new_student.grades[0], &new_student.grades[1], &new_student.grades[2]);
    students[num_students++] = new_student;
    printf("Student information input successful!\n");
}

void update_student_info() {
    char id[MAX_ID_LEN];
    printf("Please enter the ID of the student to be updated:\n");
    scanf("%s", id);
    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            printf("1. Update Name\n");
            printf("2. Update Major\n");
            printf("3. Update Grades\n");
            printf("4. Delete Student\n");
            printf("Please enter your choice (1-4):\n");
            int choice = 0;
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                printf("Please enter the new name of the student:\n");
                scanf("%s", students[i].name);
                printf("Name updated successful!\n");
                break;
            case 2:
                printf("Please enter the new major of the student:\n");
                scanf("%s", students[i].major);
                printf("Major updated successful!\n");
                break;
            case 3:
                printf("Please enter the new grades of the student (3 numbers separated by spaces):\n");
                scanf("%f %f %f", &students[i].grades[0], &students[i].grades[1], &students[i].grades[2]);
                printf("Grades updated successful!\n");
                break;
            case 4:
                for (int j = i + 1; j < num_students; j++) {
                    students[j - 1] = students[j];
                }
                num_students--;
                printf("Student deleted successful!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
            break;
        }
    }
    if (!found) {
        printf("Student not found!\n");
    }
}

void query_grades() {
    printf("1. Query by ID\n");
    printf("2. Query by Name\n");
    printf("Please enter your choice (1-2):\n");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Please enter the ID of the student:\n");
        char id[MAX_ID_LEN];
        scanf("%s", id);
        for (int i = 0; i < num_students; i++) {
            if (strcmp(students[i].id, id) == 0) {
                printf("Name: %s\n", students[i].name);
                printf("ID: %s\n", students[i].id);
                printf("Major: %s\n", students[i].major);
                printf("Grades: %.1f %.1f %.1f\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
                return;
            }
        }
        printf("Student not found!\n");
        break;
    case 2:
        printf("Please enter the name of the student:\n");
        char name[MAX_NAME_LEN];
        scanf("%s", name);
        for (int i = 0; i < num_students; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printf("Name: %s\n", students[i].name);
                printf("ID: %s\n", students[i].id);
                printf("Major: %s\n", students[i].major);
                printf("Grades: %.1f %.1f %.1f\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
                return;
            }
        }
        printf("Student not found!\n");
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
}

void report_grades() {
    printf("1. By Name\n");
    printf("2. By Major\n");
    printf("3. By Course\n");
    printf("4. By Class\n");
    printf("Please enter your choice (1-4):\n");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Report by Name:\n");
        printf("Name\tID\tGrades\tRank\n");
        for (int i = 0; i < num_students; i++) {
            float avg_grade = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2]) / 3;
            int rank = 1;
            for (int j = 0; j < num_students; j++) {
                if (i != j) {
                    float other_avg_grade = (students[j].grades[0] + students[j].grades[1] + students[j].grades[2]) / 3;
                    if (other_avg_grade > avg_grade) {
                        rank++;
                    }
                }
            }
            printf("%s\t%s\t%.1f %.1f %.1f\t%d\n", students[i].name, students[i].id, students[i].grades[0], students[i].grades[1], students[i].grades[2], rank);
        }
        break;
    case 2:
        printf("Report by Major:\n");
        printf("Major\tCount\tAverage Grade\n");
        for (int i = 0; i < num_students; i++) {
            char* major = students[i].major;
            int count = 1;
            float total_grade = students[i].grades[0] + students[i].grades[1] + students[i].grades[2];
            for (int j = i + 1; j < num_students; j++) {
                if (strcmp(students[j].major, major) == 0) {
                    count++;
                    total_grade += students[j].grades[0] + students[j].grades[1] + students[j].grades[2];
                }
            }
            float avg_grade = total_grade / (count * 3);
            printf("%s\t%d\t%.1f\n", major, count, avg_grade);
            i += count - 1;
        }
        break;
    case 3: {
        printf("Please enter the course name:\n");
        char course[MAX_COURSE_LEN];
        scanf("%s", course);
        printf("Report by Course (%s):\n", course);
        printf("Name\tID\tGrade\n");
        for (int i = 0; i < num_students; i++) {
            printf("%s\t%s\t%.1f\n", students[i].name, students[i].id, students[i].grades[choice - 1]);
        }
        break;
    }
    case 4: {
        printf("Please enter the class name:\n");
        char class_name[MAX_MAJOR_LEN];
        scanf("%s", class_name);
        printf("Report by Class (%s):\n", class_name);
        printf("Name\tID\tGrades\tRank\n");
        for (int i = 0; i < num_students; i++) {
            if (strcmp(students[i].major, class_name) == 0) {
                float avg_grade = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2]) / 3;
                int rank = 1;
                for (int j = 0; j < num_students; j++) {
                    if (i != j && strcmp(students[j].major, class_name) == 0) {
                        float other_avg_grade = (students[j].grades[0] + students[j].grades[1] + students[j].grades[2]) / 3;
                        if (other_avg_grade > avg_grade) {
                            rank++;
                        }
                    }
                }
                printf("%s\t%s\t%.1f %.1f %.1f\t%d\n", students[i].name, students[i].id, students[i].grades[0], students[i].grades[1], students[i].grades[2], rank);
            }
        }
        break;
    }
    default:
        printf("Invalid choice!\n");
        break;
    }
}

void output_grades() {
    printf("1. By ID\n");
    printf("2. By Name\n");
    printf("3. By Grade\n");
    printf("Please enter your choice (1-3):\n");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Output by ID:\n");
        for (int i = 0; i < num_students; i++) {
            printf("%s\t%s\t%.1f %.1f %.1f\n", students[i].id, students[i].name, students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        }
        break;
    case 2:
        printf("Output by Name:\n");
        for (int i = 0; i < num_students; i++) {
            printf("%s\t%s\t%.1f %.1f %.1f\n", students[i].name, students[i].id, students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        }
        break;
    case 3:
        printf("Output by Grade:\n");
        printf("Name\tID\tSum\tAverage\n");
        for (int i = 0; i < num_students; i++) {
            float sum_grade = students[i].grades[0] + students[i].grades[1] + students[i].grades[2];
            float avg_grade = sum_grade / 3;
            printf("%s\t%s\t%.1f\t%.1f\n", students[i].name, students[i].id, sum_grade, avg_grade);
        }
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
}

void help() {
    printf("Welcome to Student Grade Management System!\n");
    printf("1. Input Student Information: Input the name, ID, major and grades of a new student.\n");
    printf("2. Update Student Information: Update the name, major or grades of a student, or delete a student.\n");
    printf("3. Query Grades: Query the grades of a student by ID or name.\n");
    printf("4. Report Grades: Generate a report of the grades of all students, by name, major, course or class.\n");
    printf("5. Output Grades: Output the grades of all students, sorted by ID, name or grade.\n");
    printf("6. Help: Show this message.\n");
    printf("7. Exit: Exit the system.\n");
}

void exit_system() {
    printf("Thank you for using Student Grade Management System, see you next time!\n");
}