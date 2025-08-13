#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIMESLOTS 8
#define MAX_USERS 3
#define MAX_CLASSROOMS 12

struct login {
    char user_name[50];
    char password[50];
};

struct classroom {
    char room_no[5];
    int size;
    int booked[MAX_TIMESLOTS]; // 0 = available, 1 = booked
};

// Function prototypes
int load_user_info(struct login users[MAX_USERS]);
void load_classroom_info(struct classroom classrooms[MAX_CLASSROOMS]);
void save_classroom_status(struct classroom classrooms[MAX_CLASSROOMS]);
void show_timeslot_menu(int day, struct classroom classrooms[MAX_CLASSROOMS]);

// Load user info from file
int load_user_info(struct login users[MAX_USERS]) {
    FILE* file = fopen("account.txt", "r");
    if (!file) {
        printf("Error opening account.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %s", users[i].user_name, users[i].password) == 2) {
        i++;
    }
    fclose(file);
    return i; // Return number of users
}

// Load classroom info from file
void load_classroom_info(struct classroom classrooms[MAX_CLASSROOMS]) {
    FILE* file = fopen("classroom_info.txt", "r");
    if (!file) {
        printf("Error opening classroom_info.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %d", classrooms[i].room_no, &classrooms[i].size) == 2) {
        for (int j = 0; j < MAX_TIMESLOTS; j++) {
            classrooms[i].booked[j] = 0; // Initially all slots are available
        }
        i++;
    }
    fclose(file);
}

// Save classroom booking status to text files
void save_classroom_status(struct classroom classrooms[MAX_CLASSROOMS]) {
    for (int i = 0; i < MAX_CLASSROOMS; i++) {
        FILE* file = fopen(classrooms[i].room_no, "w");
        if (!file) {
            printf("Error opening file %s\n", classrooms[i].room_no);
            continue;
        }
        fprintf(file, "Room: %s\n", classrooms[i].room_no);
        for (int j = 0; j < MAX_TIMESLOTS; j++) {
            fprintf(file, "Timeslot %d: %d - %d: %s\n", j + 9, 9 + j, 9 + j + 1,
                classrooms[i].booked[j] ? "Booked" : "Available");
        }
        fclose(file);
    }
}

// Show timeslot menu for user to select booking timeslot
void show_timeslot_menu(int day, struct classroom classrooms[MAX_CLASSROOMS]) {
    printf("Available timeslots for booking:\n");
    // Show available timeslots based on the current date
    for (int i = 0; i < MAX_TIMESLOTS; i++) {
        printf("%d. %d:00 - %d:50\n", i + 1, 9 + i, 9 + i + 1);
    }

    int choice;
    printf("Enter your choice (1-%d): ", MAX_TIMESLOTS);
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_TIMESLOTS) {
        printf("Invalid choice!\n");
        return;
    }

    // Get classroom size
    int size;
    printf("Enter required classroom size: ");
    scanf("%d", &size);

    // Find an available classroom
    int room_found = 0;
    for (int i = 0; i < MAX_CLASSROOMS; i++) {
        if (classrooms[i].size >= size && classrooms[i].booked[choice - 1] == 0) {
            classrooms[i].booked[choice - 1] = 1;
            printf("Classroom %s booked for %d:00 - %d:50.\n", classrooms[i].room_no, 9 + choice - 1, 9 + choice);
            room_found = 1;
            break;
        }
    }

    if (!room_found) {
        printf("No available classroom!\n");
    }

    // Save classroom status
    save_classroom_status(classrooms);
}

int main() {
    struct login users[MAX_USERS];
    struct classroom classrooms[MAX_CLASSROOMS];

    int user_count = load_user_info(users);
    load_classroom_info(classrooms);

    // Login process
    char username[50], password[50];
    for (int i = 0; i < 3; i++) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        int valid = 0;
        for (int i = 0; i < user_count; i++) {
            if (strcmp(username, users[i].user_name) == 0 && strcmp(password, users[i].password) == 0) {
                valid = 1;
                break;
            }
        }

        if (valid) {
            printf("Login successful!\n");
            break;
        }
        else {
            printf("Invalid username or password!\n");
        }
    }

    // Menu for selecting date and timeslot
    int day = 1; // Example: 1 = today
    show_timeslot_menu(day, classrooms);

    return 0;
}
