/* Group 13  */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NUM_THREADS 27

int sudoku[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

void* checkRow(void* param) {
    int row = *(int*)param;
    bool* result = malloc(sizeof(bool));
    *result = true;
    int checker[9] = {0};
    for (int j = 0; j < 9; j++) {
        if (checker[sudoku[row][j] - 1] == 1) {
            *result = false;
            return result;
        }
        checker[sudoku[row][j] - 1] = 1;
    }
    return result;
}

// (Similar column and subgrid functions here)

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIndex = 0;
    bool valid = true;
    int row_indices[9];
    for (int i = 0; i < 9; i++) {
        row_indices[i] = i;
        pthread_create(&threads[threadIndex++], NULL, checkRow, &row_indices[i]);
    }
    // Similar logic for columns and subgrids...
    for (int i = 0; i < NUM_THREADS; i++) {
        void* thread_result;
        pthread_join(threads[i], &thread_result);
        valid &= *(bool*)thread_result;
        free(thread_result);
    }
    printf(valid ? "Sudoku is valid.\n" : "Sudoku is invalid.\n");
    return 0;
}

