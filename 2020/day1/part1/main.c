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
    FILE *file_pointer;
    int *number_list, sum;
    unsigned int list_counter = 1;

    // opening puzzle input and checking error
    file_pointer = fopen(TEXT_INPUT, TEXT_MODE);
    if (file_pointer == NULL) {
        printf("Error in opening file.\n");
        exit(1);
    }

    // create an array based on the input
    for (char buf = getc(file_pointer); buf != EOF; buf = getc(file_pointer)) {
        if (buf == '\n') {
            list_counter++;
        }
    }

    // reset file pointer
    fseek(file_pointer, 0, SEEK_SET);

    // set the array full of puzzle input values
    number_list = (int *) malloc(sizeof(int) * list_counter);
    for (int i = 0; i < list_counter; i++) {
        fscanf(file_pointer, "%i", &number_list[i]);
    }

    // find the product and sum
    for (int i = 0; i < list_counter; i++) {
        for (int j = 0; j < list_counter; j++) {
            sum = number_list[i] + number_list[j];
            if (sum == 2020) {
                printf("%i * %i = %i\n", number_list[i], number_list[j], number_list[i] * number_list[j]);

                break;
            }
        }
        if (sum == 2020) break;
    }

    // close file and free dynamic memory
    free(number_list);
    fclose(file_pointer);

    return 0;
}
