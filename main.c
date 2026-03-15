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
//*************Main Function*******************
int main(void){

 //Variables
 char names[STUDENTS][11];
// int scores[STUDENTS][TESTS];
int sums[STUDENTS];

// test the formating function
    char name[11] = "aLICE";
    formatName(name);
    printf("%s\n", name);
// test the sum function
 int scores[TESTS] = {10,10,10,10,10,10,10,10,10,10,10,10,10};
    printf("%d\n", calculateSum(scores));

    return 0;
}

