# Course Project - Classroom Booking

*For Foundation of C Programming - 2024 Fall*

**Deadline: 11:55 pm, 20 December 2024.**

-------

## Before the project

This is a teamwork. The contribution of each member will be put in the excel file released with this document. You must write the code alone by yourself, no talking with friends not in your group, no copying from the Internet or other resources (except the code for time mentioned later in the requirements). If a group copies any piece of code from another group, both groups are given 0, no matter whether the copied one knows or not. It is student’s responsibility to prevent his work from being copied.
Please read the whole document before you start. This project needs the knowledge from the lecture File. You can understand the requirements first. After you learned the lecture File, you can start programming.

## System Requirements

In this project, you are going to develop a software system that can help users to book classrooms in UIC.

### 1

Only authorized users can use this system to book the classrooms. Therefore, when a user uses this system, he/she needs to provide the user’s name and password. If the user provides wrong user name or password, a corresponding warning "Invalid account name or password!" is given. The user is given another chance to try. He/she can try at most three times. If the user still fails after three tries, the system gives a warning "You have failed three times!" and then exits. If the user input correct user name and password, then go to next step.

### 2

The system will display a menu as below for the user to choose from. 

	1.Date (today)
	2.Date (tomorrow)
	3.Date (the day after tomorrow)
	4.Exit

The user can input 1-3 to choose a date if he/she wants to book classroom on that day, or 4 to quit the booking system. Here Date in the menu should be replaced by real day. For example, if today is 20 December 2024, you should put 20/12/2024 or 2024.12.20 there.

### 3

After the user chooses a date, the system will display the timeslots in which the user can book. A user can book the timeslots from 9 am to 5 pm, one hour one timeslot. 

	a. If the user chooses today, he/she can choose the timeslot after the timeslot of the current time. 
	
	For example, if the current time is 11:05, the timeslots before 12:00 pm cannot be booked.
	
	b. If the user chooses Exit, the system quits.

### 4

Once the user chooses a date, the system should list the timeslots for the user to choose from. 

	1. 9:00 am – 9:50 am
	2. 10:00 am – 10:50 am
	3. 11:00 am – 11:50 am
	4. 12:00 pm – 12:50 pm
	5. 13:00 pm – 13:50 pm
	6. 14:00 pm – 14:50 pm
	7. 15:00 pm – 15:50 pm
	8. 16:00 pm – 16:50 pm
	9. Exit

a. The user should choose a timeslot or Exit through the index number in the menu. 

b. To simplify the development, we assume that a user can book only one timeslot at one time.

**Attention: If the user chose “today” in the upper menu, there might be less timeslots in this menu.**

### 5

After the user chooses a timeslot, the system should prompt a message "Input the size of classroom: " to ask the user to input the expected classroom size. The system will search for an available classroom with least size that can satisfy the requirement. 

	a. If there is no classroom available, show a message "No available room!" to user too. 

	b. If a room can be found, show the user classroom no. 

No matter whether the room search is successful or not, The system should then ask the user if he wants to continue by prompting a message "Continue (y/n)? ".

		a. If the user inputs 'y', the system will go back to step 2 showing the date menu for user to choose from. 

		b. If the user inputs 'n', the system will exit.

In this system, two files have been provided: account.txt and classroom_info.txt. The contents are as follows. The file account.txt includes user names and passwords. The file classroom_info.txt contains classroom no. and size. However, when you write the program, your program should be able to handle more users and classrooms. 

<table>
	<tr>
		<td>account.txt</td>
		<td>classroom_info.txt</td>
	</tr>
	<tr>
		<td>
			alice 1111<br>
			tony 2222<br>
			jane 3333<br>
		</td>
		<td>
			C1 30<br>
			C2 30<br>
			C3 50<br>
			C4 50<br>
			C5 50<br>
			C6 70<br>
			C7 80<br>
			C8 80<br>
			C9 80<br>
			C10 100<br>
			C11 100<br>
			C12 100<br>
		</td>
	</tr>
</table>
	
Your program should produce a text file for each classroom, recording its current booking status that will be used to decide if it can be booked. Previous booking information should be removed, i.e., it stores only the booking information for today, tomorrow and the day after tomorrow. You can decide the format of these files.


## Non-System Requirements

1. Each classroom’s status information should include classroom no, timeslots and its booking status, and user names who booked the timeslots. The information should be stored in structure type.
2. The program UI must be user-friendly.
3. The program should be well structured, composed of one main function and some sub-functions. 

**Hints:**

1. To get the current day and time, you can use the tm structure and time functions which are defined in time.h. Code below is an example. However, you are not limited to the functions below. You can search in the Internet for the day and time related code.

```c
#include <stdio.h>
#include <time.h>
int main(void)
{
	struct tm *tblock;
	time_t current_time;
  
	time(&current_time);
  	tblock = localtime(&current_time);
  	printf("%d %d %d\n",tblock->tm_year, tblock->tm_mon, tblock->tm_mday);
  	return 0;
}
```

The struct `tm` has following members:
```c
struct tm {
	int tm_sec; /* second: [0,59] */
	int tm_min; /* minute: [0,59] */
	int tm_hour; /* hour : [0,23] */
	int tm_mday; /* day in a month: [1,31] */
	int tm_mon; /* month: [0,11] */
	int tm_year; /* year - 1900 */
	int tm_wday; /* weekday: [0,6] */
	int tm_yday; /* day in a year: [0,365] */
	int tm_isdst; /* Daylight Saving Time Identifier */
	long int tm_gmtoff; /* Dateline */
	const char *tm_zone; /*Timezone*/
};
```

2. When you assign the functions for each team member, you should clearly declare the prototype of each function so the functions can be integrated together later.

3. You can decide the files that record classroom’s booking status at a format that is easier to access the information.

## Submission

1. You should submit a compressed file (with name Group##.zip, where ## is replaced by your group number) that includes the following files.

	a. code files: .c files and .h files (if you declared .h files),

	b. generated .txt files that record each room’s status, i.e., C1.txt, C2.txt, …, and so on, totally 12 files. A file can be empty if it has no been booked for any timeslot.

	c. an excel file (the file name of the excel is Group_##.xlsx, template is given by teacher, replace ## with the group name) to indicate each student’s contribution in your group. You do not need to give the exact contribution percentage. Instead, you simply use 2 to indicate "normal", 1 for "rare", and 0 for "none".

2. Deadline: 11:55 p.m., 20 December 2024
