#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printIntegerArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]");
}

void muster(int anz_zeilen) {
    if (anz_zeilen < 3) {
        return;
    }
    for (int i = 0; i < anz_zeilen - 1; i++) {
        for (int j = 0; j < anz_zeilen - 2 - i; j++) {
            printf(" ");
        }
        for (int j = i*2; j >= 0; j--) {
            printf("+");
        }
        printf("\n");

    }
    for (int i = 0; i < anz_zeilen - 2; i++) {
        printf(" ");
    }
    printf("+\n");
}

void printMinMax(int array[], int size) {
    int min = array[0];
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }
    printIntegerArray(array, size); 
    printf(" -> Min: %d, Max: %d\n", min, max);
}

bool firstLast8 (int arr[], int n) {
    return arr[0] == 8 || arr[n - 1] == 8; 
}

int countOdds (int f[], int n) {
    int odds = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] % 2 != 0) {
            odds++;
        }
    }
    return odds;
}

bool unlucky1 (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1 && arr[i] == 1 && arr[i + 1] == 3) {
            return true;
        }
    }
    return false;
}

int kleinstes (int arr[], int n) {
    int smallestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        } 
    }
    return smallestIndex;
}

int zweitkleinstes (int arr[], int n) {
    int smallest = 0;
    int secondSmallest = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[smallest]) {
            secondSmallest = smallest;
            smallest = i;
        }
        else if (secondSmallest == -1 || arr[i] < arr[secondSmallest]) {
            secondSmallest = i;
        }
    }
    return secondSmallest;
}

void reverse (int arr[], int n) {
    printIntegerArray(arr, n);
    for (int i = 0; i < n / 2; i++) {
        arr[i] = arr[i] + arr[n - 1 - i];
        arr[n - 1 - i] = arr[i] - arr[n - 1 - i];
        arr[i] = arr[i] - arr[n - 1 - i];
    }
    printf(" -> ");
    printIntegerArray(arr, n);
    printf("\n");
}

void swap (int arr1[], int arr2[], int len) {
    printIntegerArray(arr1, len);
    printf(" ");
    printIntegerArray(arr2, len);
    // Tipp laut Aufgabenstellung: Sie benoetigen eine Hilfsvariabel
    // Tatsaechlich nicht ganz korrekt :)
    for (int i = 0; i < len; i++) {
        // Nachteil dieser Methode ist natuerlich dass bei der Addition oder
        // Subtraktion ein Integer Overflow passieren kann 
        arr1[i] = arr1[i] + arr2[i];
        arr2[i] = arr1[i] - arr2[i];
        arr1[i] = arr1[i] - arr2[i];
    }
    printf("\nSwitched: ");
    printIntegerArray(arr1, len);
    printIntegerArray(arr2, len);
    printf("\n");
}

void expect(int output, int expected) {
    if (output == expected) {
        printf("\x1b[32mpassed\x1b[0m\n");
    }
    else {
        printf("\x1b[31mFailed!\x1b[0m\n");
    }
}

int main(int argc, char *argv[]) {
    // die aufgaben nummer muss bei ausfuehrung des programmes mitgegeben werden
    // die eingegebene nummer wird dann getestet
    if (argc < 2) {
        printf("Exited without testing anything.\nEnter a number from 0 to 9 to specify what should be tested.\n");
        exit(1);
    }
    if (argv[1][0] < 48 || argv[1][0] > 57) {
        printf("Exited due to invalid input.\nEnter a number from 0 to 9 to specify what should be tested.\n");
        exit(1);
    }
    int identifier = argv[1][0] - 48;
    switch (identifier) {
        case 1: {
            muster(10);
        }
        break;
        case 2: {
            int array[] = {1,2,3,4,5};
            printMinMax(array, 5);
            int array2[] = {1, -3, 123, 234234, -234, 34};
            printMinMax(array2, 6);
        }
        break;
        case 3: {
            int one[] = {4,5,8};
            int two[] = {8, 3, 4};
            int three[] = {45, 8, 4, 5};
            expect((int) firstLast8(one, 0), 0);
            expect(firstLast8(one, 3), 1);
            expect(firstLast8(two, 3), 1);
            expect(firstLast8(three, 4), 0);
        }
        break;
        case 4: {
            int one[] = {3, 4, 5, 6, 7, 8};
            int two[] = {4};
            int three[] = {3, 3, 4, 4, 6, 6};
            expect(countOdds(one, 6), 3);
            expect(countOdds(two, 1), 0);
            expect(countOdds(three, 6), 2);
        }
        break;
        case 5: {
            int one[] = {1, 2, 3, 1, 3};
            int two[] = {1, 1, 1, 4, 2};
            expect(unlucky1(one, 5), 1);
            expect(unlucky1(two, 5), 0);
        }
        break;
        case 6: {
            int one[] = {3, 3, 4, 5};
            int two[] = {5, 10, 7, 0, -4, 100};
            int three[] = {10, 5, 13, 4, -5, 6};
            expect(kleinstes(one, 4), 0);
            expect(zweitkleinstes(one, 4), 1);
            expect(kleinstes(two, 6), 4);
            expect(zweitkleinstes(two, 6), 3);
            expect(kleinstes(three, 6), 4);
            expect(zweitkleinstes(three, 6), 3);
        }
        break;
        case 7: {
            int one[] = {1,2,3,4,5,6};
            int two[] = {1,2,3,4,5};
            int three[] = {1,2,3};
            reverse(one, 6);
            reverse(two, 5);
            reverse(three, 3);
        }
        break;
        case 8: {
            int one[] = {1,2,3,4,5,6};
            int two[] = {7,8,9,10,11,12};
            swap(one, two, 6);
        }
    }
}