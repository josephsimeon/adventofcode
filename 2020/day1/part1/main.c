/**
 * @file main.c
 * @author Joseph Simeon (admin@joesimeon.com)
 * @brief Day 1 of 2020 - Advent of Code
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define TEXT_INPUT "../puzzle_input.txt"
#define TEXT_MODE "r"

int main (void)
{
    FILE *file_pointer, *loop_pointer;
    int first_number, second_number;

    // opening puzzle input and checking error
    file_pointer = fopen(TEXT_INPUT, TEXT_MODE);
    if (file_pointer == NULL) {
        printf("Error in opening file.\n");
        exit(1);
    }

    // check how many numbers there are and malloc the needed amount
    while (fscanf(file_pointer, "%i", &first_number) != EOF) {
        loop_pointer = fopen(TEXT_INPUT, TEXT_MODE);
        while (fscanf(loop_pointer, "%i", &second_number) != EOF) {
            // check numbers
            if ((first_number + second_number) == 2020) {
                printf("%i * %i = %i\n", first_number, second_number, first_number * second_number);
            }
        }
    }

    fclose(file_pointer);
    fclose(loop_pointer);

    return 0;
}