#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)  //忽略4996系统认为代码不安全的错误

// Define an appropriate struct
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Define any additional variables here
FILE *inputFile;
FITNESS_DATA data[1000];
char buffer[1000];
int size = 1000;
int i = 0;
char date[11];
char time[6];
char steps[100];


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }

    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    // Open the file
    inputFile = fopen("FitnessData_2023.csv", "r");
    if (inputFile == NULL) {
        printf("Fail to open the file.\n");
        return 1;
    }

    // Read the file, and store it in a structured array
    while (fgets(buffer, size, inputFile) != NULL)
    {
        tokeniseRecord(buffer, ",", date, time, steps);
        strcpy(data[i].date, date);
        strcpy(data[i].time, time);
        data[i].steps = atoi(steps);
        i++;
    }

    // Close the file
    fclose(inputFile);

    // Use the for loop to print the first three rows of the file on the screen
    for (i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
    }

    return 0;
}