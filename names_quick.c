/*
Q7. Write a C program to sort N names given by user in an array, using Quick sort technique. 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAMES 100
#define MAX_LENGTH 50

void quickSort(char names[][MAX_LENGTH], int low, int high);
int partition(char names[][MAX_LENGTH], int low, int high);
void swap(char* str1, char* str2);

int main() 
{
    int n;
    char names[MAX_NAMES][MAX_LENGTH];
    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar(); // To clear the buffer after scanf

    printf("Enter the names:\n");
    for (int i = 0; i < n; i++) 
        fgets(names[i], MAX_LENGTH, stdin);
    for (int i = 0; i < n; i++) 
    {
        size_t len = strlen(names[i]);
        if (len > 0 && names[i][len - 1] == '\n') 
            names[i][len - 1] = '\0';
    }
    quickSort(names, 0, n - 1);
    printf("\nSorted names are:\n");
    for (int i = 0; i < n; i++) 
        printf("%s\n", names[i]);
    return 0;
}

void quickSort(char names[][MAX_LENGTH], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(names, low, high);
        quickSort(names, low, pi - 1);
        quickSort(names, pi + 1, high);
    }
}
int partition(char names[][MAX_LENGTH], int low, int high) 
{
    char pivot[MAX_LENGTH];
    strcpy(pivot, names[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (strcmp(names[j], pivot) < 0) 
        {
            i++;
            swap(names[i], names[j]);
        }
    }
    swap(names[i + 1], names[high]);
    return i + 1;
}

void swap(char* str1, char* str2) 
{
    char temp[MAX_LENGTH];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
