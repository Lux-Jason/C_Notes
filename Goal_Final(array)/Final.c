#include"head.h"
void ExpectedFinalGrade()
{
	printf("Enter a number and choose an operation:");
	int choice = Final_Menu();
	switch (choice)
	{
	case 1:
		AllCourses();
		break;
	case 2:
		SingleCourse();
		break;
	default:
		break;
	}

}
void AllCourses() {
	int i, p;
	char d;
	float k, m;
	while (1) {
		printf("Enter an expected course total ([0, 100]) or any negative to go back: ");
		scanf("%f", &m);

		if (m >= 0 && m <= 100) {
			printf("| (*)Danger  | Course Code  | Course Name                                        | Lowest Final for Expected Course Total   |\n");
			for (i = 0; i < num_Courses; ++i) { // Assuming num_Courses is defined and accurate
				m = 0; // Reset m for each course
				int j = 0;
				for (p = 0; p < Course_arr[i].item[j].numOfGrades; p++) {
					m += Course_arr[i].item[j].grades[p] * Course_arr[i].item[j].maxScore * Course_arr[i].item[j].percentage;
				}
				k = m * 0.01 / Course_arr[i].item[j].numOfGrades / Course_arr[i].item[j].maxScore;

				if (k > 100) {
					d = '*'; // Using single quotes for characters
				}
				else {
					d = ' '; // Using single quotes for characters
				}

				printf("| %-11c| %-12s | %-50s| %-41.2f |\n", d, Course_arr[i].courseID, Course_arr[i].coursename, k);
			}
		}
		else {
			break;
		}
	}
}
void SingleCourse() {
    int k = 0;
    int q = 0;
    float j = 0;

    printf("There're totally %d courses recorded:\n", num_Courses);

    for (int i = 0; i < num_Courses; i++) {
        printf("\n %-7d  %-20s  %-11s \n", i + 1, Course_arr[i].courseID, Course_arr[i].coursename);
    }

    printf("Enter a number to modify the related course details or any other key back: ");
    scanf("%d", &k);

    if (k < 1 || k > num_Courses) {
        // Handle invalid course number
        printf("Invalid course number entered. Exiting.\n");
        return;
    }

    printf("Enter an expected course total ([0, 100]) or any negative to go back:");
    do {
        scanf("%f", &j);

        if (j < 0 || j > 100) {
            printf("Invalid input. Expected course total must be between 0 and 100.\n");
            break;
        }

        printf("%s %s\n", Course_arr[k - 1].courseID, Course_arr[k - 1].coursename);
        printf("-----------------------------------\n");
        printf("| No.    | Item                 | Percentage | Original Average | Item Grade |\n");

        float m = 0;
        float OA = 0;
        float IG = 1; // Initializing IG to prevent multiplication from yielding zero
        int itemcode = 0;

        while (strlen(Course_arr[k - 1].item[itemcode].name) > 0) {
            itemcode++;
        }

        for (int q = 0; q < Course_arr[k - 1].data; q++) {
            for (int p = 0; p < Course_arr[k - 1].item[q].numOfGrades; p++) {
                m += Course_arr[k - 1].item[q].grades[p];
            }
            OA = m / Course_arr[k - 1].item[q].numOfGrades;
            IG *= Course_arr[k - 1].item[q].maxScore * Course_arr[k - 1].item[q].percentage / 100;

            printf("| %d | %-20s | %-11.2f | %-16.2f | %-11.2f |\n", q + 1, Course_arr[k - 1].item[q].name,
                Course_arr[k - 1].item[q].percentage, OA, IG);
        }

        float EXPECTED = (j - IG) / Course_arr[k - 1].item[q - 1].percentage;
        printf("| %-7d | %-20s | %-11.2f | %-20.2f | %-11.2f |\n", itemcode, Course_arr[k - 1].item[q - 1].name,
            Course_arr[k - 1].item[q - 1].percentage, Course_arr[k - 1].item[q - 1].maxScore, EXPECTED);

        printf("ATTENTION: The final score should pass a certain threshold to pass the course!\n");
    } while (j < 0 || j > 100);
}