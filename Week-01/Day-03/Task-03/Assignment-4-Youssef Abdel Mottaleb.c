/*
Write C code that manage a small school. The school has 3 classes each class
contains 10 students. Define three arrays for the three classes each one with a
length of 10. Save a random numbers in all array elements to indicate the
students grade. The program will calculate and display the following statistics:
1- Number of passed students
2- Number of Failed students
3- Highest grade
4- Lowest grade
5- Average grade
Knowing that the total grade is from 100 and the minimum passing grade is 50.
*/
#include <stdio.h>

int main() {
    int class1[10] = {23, 52, 66, 97, 45, 76, 80, 37, 99, 60};
    int class2[10] = {23, 50, 66, 66, 45, 76, 80, 100, 99, 21};
    int class3[10] = {12, 52, 10, 88, 45, 76, 80, 66, 99, 60};

    int passedStudents = 0, failedStudents = 0, highestGrade = 0, lowestGrade = 100, totalGrade = 0;

    for (int classIdx = 0; classIdx < 3; classIdx++) {
        int *currentClass;

        if (classIdx == 0) {
            currentClass = class1;
        } else if (classIdx == 1) {
            currentClass = class2;
        } else {
            currentClass = class3;
        }

        for (int i = 0; i < 10; i++) {
            if (currentClass[i] >= 50 && currentClass[i] <= 100) {
                passedStudents++;
            } else {
                failedStudents++;
            }

            if (currentClass[i] > highestGrade) {
                highestGrade = currentClass[i];
            }

            if (currentClass[i] < lowestGrade) {
                lowestGrade = currentClass[i];
            }

            totalGrade += currentClass[i];
        }
    }

    float averageGrade = (float)totalGrade / 30; // Total grades from all classes

    printf("Number of passed students: %d\n", passedStudents);
    printf("Number of failed students: %d\n", failedStudents);
    printf("Highest grade: %d\n", highestGrade);
    printf("Lowest grade: %d\n", lowestGrade);
    printf("Average grade: %.2f\n", averageGrade);

    return 0;
}