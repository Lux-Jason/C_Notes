// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_USERS 100
// #define MAX_ROOMS 100
// #define MAX_LINE_LENGTH 100

// typedef struct {
//     char username[50];
//     char password[50];
// } User;

// typedef struct {
//     char room_no[10];
//     int size;
// } Classroom;

// void load_accounts(const char *filename, User users[], int *user_count) {
//     FILE *file = fopen(filename, "r");
//     if (!file) {
//         perror("Failed to open account file");
//         exit(EXIT_FAILURE);
//     }
//     *user_count = 0;
//     while (fscanf(file, "%s %s", users[*user_count].username, users[*user_count].password) != EOF) {
//         (*user_count)++;
//     }
//     fclose(file);
// }

// void load_classrooms(const char *filename, Classroom classrooms[], int *classroom_count) {
//     FILE *file = fopen(filename, "r");
//     if (!file) {
//         perror("Failed to open classroom file");
//         exit(EXIT_FAILURE);
//     }
//     *classroom_count = 0;
//     while (fscanf(file, "%s %d", classrooms[*classroom_count].room_no, &classrooms[*classroom_count].size) != EOF) {
//         (*classroom_count)++;
//     }
//     fclose(file);
// }

// int authenticate_user(User users[], int user_count) {
//     char username[50], password[50];
//     printf("Enter username: ");
//     scanf("%s", username);
//     printf("Enter password: ");
//     scanf("%s", password);
    
//     for (int i = 0; i < user_count; i++) {
//         if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
//             return 1;
//         }
//     }
//     printf("Invalid credentials.\n");
//     return 0;
// }

// int select_date() {
//     int choice;
//     printf("Select a date:\n");
//     printf("1. Today\n");
//     printf("2. Tomorrow\n");
//     printf("3. Day after tomorrow\n");
//     printf("Enter your choice: ");
//     scanf("%d", &choice);
//     return choice;
// }

// int select_time_slot() {
//     int choice;
//     printf("Select a timeslot:\n");
//     printf("1. 09:00 - 11:00\n");
//     printf("2. 11:00 - 13:00\n");
//     printf("3. 14:00 - 16:00\n");
//     printf("Enter your choice: ");
//     scanf("%d", &choice);
//     return choice;
// }

// int prompt_classroom_size() {
//     int size;
//     printf("Input the size of classroom: ");
//     scanf("%d", &size);
//     return size;
// }

// int check_availability(const char *room_no, int date, int time_slot) {
//     // This function should check the booking status file for the room
//     // For simplicity, assume all rooms are available in this example
//     return 1;
// }

// void search_classroom(int date, int time_slot, int required_size, Classroom classrooms[], int classroom_count) {
//     int found = 0;
//     for (int i = 0; i < classroom_count; i++) {
//         if (classrooms[i].size >= required_size) {
//             if (check_availability(classrooms[i].room_no, date, time_slot)) {
//                 printf("Classroom found: %s\n", classrooms[i].room_no);
//                 found = 1;
//                 break;
//             }
//         }
//     }
//     if (!found) {
//         printf("No available room!\n");
//     }
// }
