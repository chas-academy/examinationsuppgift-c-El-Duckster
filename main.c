//Write your code in this file
//*************Libraries*************
#include <stdio.h>
#include <ctype.h>

//**********Constants*****************
#define STUDENTS 5 // # of students
#define TESTS 13 // # of tests per students
#define NAME_LEN 11  // Max name length (10 chars + 1 for '\0')

// ************Helper Functions***************
//name formatting
void formatName(char name[]) {
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

// sum up student scores
int calculateSum(int scores[]) {
    int sum = 0;
    for (int i = 0; i < TESTS; i++) {
        sum += scores[i];
    }
    return sum;
}

// Average calculation
double calculateAverage(int sum) {
    return (double)sum / TESTS;
}
//*************Main Function*******************
int main(void){

 //Variables
    char names[STUDENTS][11];
    int scores[STUDENTS][TESTS];
    int sums[STUDENTS];

    int totalSum = 0;
    int bestIndex = 0;

    //scan and print all students and their sums
for (int i = 0; i < STUDENTS; i++) {
    scanf("%10s", names[i]);
    formatName(names[i]);

    for (int j = 0; j < TESTS; j++) {
        scanf("%d", &scores[i][j]);
    }

    sums[i] = calculateSum(scores[i]);
     totalSum += sums[i];

     //compare and set best student
        if (sums[i] > sums[bestIndex]) {
        bestIndex = i;
    }

}

//print stutents + sum
for (int i = 0; i < STUDENTS; i++) {
    printf("%s %d\n", names[i], sums[i]);
}
//print the name of best student
printf("%s\n", names[bestIndex]);

//calculate and group average
double groupAverage = (double)totalSum / STUDENTS / TESTS;
printf("%.2f\n", groupAverage);

//print students' names below group average
    for (int i = 0; i < STUDENTS; i++) {
        double studentAverage = calculateAverage(sums[i]);

        if (studentAverage < groupAverage) {
            printf("%s %.2f\n", names[i], studentAverage);
        }
    }
    return 0;
}

