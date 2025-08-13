// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>

// #define MAX_USERS 100
// #define MAX_CLASSROOMS 12
// #define MAX_BOOKINGS 100
// #define MAX_TIMESLOTS 8

// // 全局声明 timeslots
// char timeslots[MAX_TIMESLOTS][20] = {
//     "9:00 am - 9:50 am",
//     "10:00 am - 10:50 am",
//     "11:00 am - 11:50 am",
//     "12:00 pm - 12:50 pm",
//     "13:00 pm - 13:50 pm",
//     "14:00 pm - 14:50 pm",
//     "15:00 pm - 15:50 pm",
//     "16:00 pm - 16:50 pm"
// };

// // 用户结构体
// struct User {
//     char username[50];
//     char password[50];
// };

// // 教室结构体
// struct Classroom {
//     char number[10];
//     int size;
//     int booked[3][MAX_TIMESLOTS]; // 3 days, 8 timeslots each
// };

// // 预订记录结构体
// struct Booking {
//     char classroom_no[10];
//     char date[20];
//     char timeslot[20];
//     char username[50];
// };

// // 函数声明
// void read_users(struct User users[], int *user_count);
// int login(struct User users[], int user_count);
// void load_classrooms(struct Classroom classrooms[], int *classroom_count);
// void display_date_options(struct Classroom classrooms[], int classroom_count, struct User users[], int user_index, struct Booking bookings[], int *booking_count);
// void show_timeslot_menu(struct Classroom classrooms[], int classroom_count, int day, char username[], struct User users[], int user_index, struct Booking bookings[], int *booking_count);
// void record_booking(struct Booking bookings[], int *booking_count, char classroom_no[], char date[], char timeslot[], char username[]);
// void save_bookings(struct Booking bookings[], int booking_count);
// struct tm *get_selected_day(int day);
// void save_classroom_status(struct Classroom classrooms[], int classroom_count, struct Booking bookings[], int booking_count);

// int main() {
//     struct User users[MAX_USERS];
//     int user_count = 0;
//     read_users(users, &user_count);

//     int user_index = login(users, user_count);

//     struct Classroom classrooms[MAX_CLASSROOMS];
//     int classroom_count = 0;
//     load_classrooms(classrooms, &classroom_count);

//     struct Booking bookings[MAX_BOOKINGS];
//     int booking_count = 0;

//     display_date_options(classrooms, classroom_count, users, user_index, bookings, &booking_count);

//     save_classroom_status(classrooms, classroom_count, bookings, booking_count);
//     save_bookings(bookings, booking_count);

//     return 0;
// }

// void read_users(struct User users[], int *user_count) {
//     FILE *file = fopen("account.txt", "r");
//     if (file == NULL) {
//         printf("Failed to open account file.\n");
//         exit(1);
//     }

//     *user_count = 0;
//     while (fscanf(file, "%s %s", users[*user_count].username, users[*user_count].password) == 2) {
//         (*user_count)++;
//     }
//     fclose(file);
// }

// int login(struct User users[], int user_count) {
//     char input_username[50];
//     char input_password[50];

//     printf("You have three attempts.\n");
//     for (int i = 0; i < 3; i++) {
//         printf("Enter username: ");
//         scanf("%s", input_username);
//         printf("Enter password: ");
//         scanf("%s", input_password);

//         for (int j = 0; j < user_count; j++) {
//             if (strcmp(input_username, users[j].username) == 0 && strcmp(input_password, users[j].password) == 0) {
//                 printf("Login successful! Welcome to the system.\n");
//                 return j;
//             }
//         }
//         printf("Invalid account name or password!\n");
//     }
//     printf("Warning! You have failed three times!\n");
//     exit(1);
// }

// void load_classrooms(struct Classroom classrooms[], int *classroom_count) {
//     FILE *file = fopen("classroom_info.txt", "r");
//     if (file == NULL) {
//         printf("Failed to open classroom info file.\n");
//         exit(1);
//     }

//     *classroom_count = 0;
//     while (fscanf(file, "%s %d", classrooms[*classroom_count].number, &classrooms[*classroom_count].size) == 2) {
//         for (int day = 0; day < 3; day++) {
//             for (int slot = 0; slot < MAX_TIMESLOTS; slot++) {
//                 classrooms[*classroom_count].booked[day][slot] = 0;
//             }
//         }
//         (*classroom_count)++;
//     }
//     fclose(file);
// }

// struct tm *get_selected_day(int day) {
//     time_t now;
//     struct tm *current_time;
//     time(&now);
//     current_time = localtime(&now);

//     struct tm *selected_day = malloc(sizeof(struct tm));
//     memcpy(selected_day, current_time, sizeof(struct tm));
//     selected_day->tm_mday += day;
//     mktime(selected_day);

//     return selected_day;
// }

// void display_date_options(struct Classroom classrooms[], int classroom_count, struct User users[], int user_index, struct Booking bookings[], int *booking_count) {
//     printf("Select a date:\n");
//     printf("1. Today\n");
//     printf("2. Tomorrow\n");
//     printf("3. The day after tomorrow\n");
//     printf("4. Exit\n");
//     printf("Please input your choice: ");
//     int choice;
//     scanf("%d", &choice);

//     switch (choice) {
//         case 1:
//             show_timeslot_menu(classrooms, classroom_count, 0, users[user_index].username, users, user_index, bookings, booking_count);
//             break;
//         case 2:
//             show_timeslot_menu(classrooms, classroom_count, 1, users[user_index].username, users, user_index, bookings, booking_count);
//             break;
//         case 3:
//             show_timeslot_menu(classrooms, classroom_count, 2, users[user_index].username, users, user_index, bookings, booking_count);
//             break;
//         case 4:
//             printf("Exiting the system.\n");
//             save_bookings(bookings, *booking_count);
//             exit(0);
//         default:
//             printf("Invalid choice. Please choose again.\n");
//             display_date_options(classrooms, classroom_count, users, user_index, bookings, booking_count);
//     }
// }

// void show_timeslot_menu(struct Classroom classrooms[], int classroom_count, int day, char username[], struct User users[], int user_index, struct Booking bookings[], int *booking_count) {
//     char timeslots[MAX_TIMESLOTS][20] = {
//         "9:00 am - 9:50 am",
//         "10:00 am - 10:50 am",
//         "11:00 am - 11:50 am",
//         "12:00 pm - 12:50 pm",
//         "13:00 pm - 13:50 pm",
//         "14:00 pm - 14:50 pm",
//         "15:00 pm - 15:50 pm",
//         "16:00 pm - 16:50 pm"
//     };

//     struct tm *selected_day = get_selected_day(day);
//     char date_str[20];
//     strftime(date_str, sizeof(date_str), "%Y-%m-%d", selected_day);

//     if (day == 0) {
//         time_t now;
//         struct tm *current_time;
//         time(&now);
//         current_time = localtime(&now);

//         int current_time_minutes = current_time->tm_hour * 60 + current_time->tm_min;

//         printf("Available time slots for %s:\n", date_str);
//         for (int i = 0; i < MAX_TIMESLOTS; i++) {
//             int timeslot_start = 9 + i;
//             int timeslot_minutes = timeslot_start * 60;
//             if (timeslot_minutes >= current_time_minutes) {
//                 printf("%d. %s\n", i + 1, timeslots[i]);
//             }
//         }
//     } else {
//         printf("Available time slots for %s:\n", date_str);
//         for (int i = 0; i < MAX_TIMESLOTS; i++) {
//             printf("%d. %s\n", i + 1, timeslots[i]);
//         }
//     }

//     printf("%d. Exit\n", MAX_TIMESLOTS + 1);
//     printf("Please choose a time slot (1-%d or %d to exit): ", MAX_TIMESLOTS, MAX_TIMESLOTS + 1);
//     int choice;
//     scanf("%d", &choice);

//     if (choice == MAX_TIMESLOTS + 1) {
//         printf("Exiting the system.\n");
//         save_bookings(bookings, *booking_count);
//         exit(0);
//     }

//     if (choice < 1 || choice > MAX_TIMESLOTS) {
//         printf("Invalid choice, please try again.\n");
//         return;
//     }

//     int selected_slot = choice - 1;

//     // 查找最小满足条件的教室
//     struct Classroom *selected_classroom = NULL;
//     int required_size;
//     printf("Enter the required classroom size: ");
//     scanf("%d", &required_size);

//     for (int i = 0; i < classroom_count; i++) {
//         if (classrooms[i].size >= required_size && classrooms[i].booked[day][selected_slot] == 0) {
//             if (selected_classroom == NULL || classrooms[i].size < selected_classroom->size) {
//                 selected_classroom = &classrooms[i];
//             }
//         }
//     }

//     if (selected_classroom == NULL) {
//         printf("No available room with the required size!\n");
//     } else {
//         printf("Classroom %s booked successfully.\n", selected_classroom->number);
//         selected_classroom->booked[day][selected_slot] = 1;
//         // 记录预订信息
//         record_booking(bookings, booking_count, selected_classroom->number, date_str, timeslots[selected_slot], username);
//     }

//     // 询问是否继续
//     char continue_choice;
//     printf("Continue (y/n)? ");
//     scanf(" %c", &continue_choice);
//     if (continue_choice == 'y') {
//         display_date_options(classrooms, classroom_count, users, user_index, bookings, booking_count);
//     } else {
//         printf("Exiting the system.\n");
//         save_bookings(bookings, *booking_count);
//         exit(0);
//     }
// }

// void record_booking(struct Booking bookings[], int *booking_count, char classroom_no[], char date[], char timeslot[], char username[]) {
//     if (*booking_count < MAX_BOOKINGS) {
//         strcpy(bookings[*booking_count].classroom_no, classroom_no);
//         strcpy(bookings[*booking_count].date, date);
//         strcpy(bookings[*booking_count].timeslot, timeslot);
//         strcpy(bookings[*booking_count].username, username);
//         (*booking_count)++;
//     } else {
//         printf("Booking list is full. Cannot record booking.\n");
//     }
// }

// void save_bookings(struct Booking bookings[], int booking_count) {
//     for (int i = 0; i < booking_count; i++) {
//         char filename[30];
//         snprintf(filename, sizeof(filename), "%s.txt", bookings[i].classroom_no);
//         FILE *file = fopen(filename, "a");
//         if (file == NULL) {
//             printf("Failed to open file %s for writing.\n", filename);
//             continue;
//         }
//         fprintf(file, "Room: %s\n", bookings[i].classroom_no);
//         fprintf(file, "Timeslot %d: %s: Booked by %s on %s at %s\n", 
//                 atoi(bookings[i].timeslot), bookings[i].timeslot, bookings[i].username, bookings[i].date, bookings[i].timeslot);
//         fclose(file);
//     }
// }

// void save_classroom_status(struct Classroom classrooms[], int classroom_count, struct Booking bookings[], int booking_count) {
//     for (int i = 0; i < classroom_count; i++) {
//         char filename[30];
//         snprintf(filename, sizeof(filename), "%s.txt", classrooms[i].number);
//         FILE *file = fopen(filename, "w");
//         if (file == NULL) {
//             printf("Failed to open file %s for writing.\n", filename);
//             continue;
//         }

//         fprintf(file, "Room: %s\n", classrooms[i].number);

//         for (int day = 0; day < 3; day++) {
//             struct tm *selected_day = get_selected_day(day);
//             char date_str[20];
//             strftime(date_str, sizeof(date_str), "%Y-%m-%d", selected_day);

//             for (int slot = 0; slot < MAX_TIMESLOTS; slot++) {
//                 char timeslot_start[10], timeslot_end[10];
//                 int hour = 9 + slot;
//                 sprintf(timeslot_start, "%02d:00", hour);
//                 sprintf(timeslot_end, "%02d:50", hour);
//                 char timeslot_str[20];
//                 sprintf(timeslot_str, "%s - %s", timeslot_start, timeslot_end);

//                 int booked = 0;
//                 int j;
//                 for (j = 0; j < booking_count; j++) {
//                     if (strcmp(bookings[j].classroom_no, classrooms[i].number) == 0 &&
//                         strcmp(bookings[j].date, date_str) == 0 &&
//                         strcmp(bookings[j].timeslot, timeslots[slot]) == 0) {
//                         booked = 1;
//                         break;
//                     }
//                 }

//                 if (booked) {
//                     fprintf(file, "Timeslot %d: %s - %s: Booked by %s on %s at %s\n",
//                             slot + 9, timeslot_start, timeslot_end, bookings[j].username, date_str, timeslot_str);
//                 } else {
//                     fprintf(file, "Timeslot %d: %s - %s: Available\n",
//                             slot + 9, timeslot_start, timeslot_end);
//                 }
//             }
//         }
//         fclose(file);
//     }
// }