/**
 * @file main.c
 * @author Joseph Simeon (admin@joesimeon.com)
 * @brief Day 1 of 2020 - Advent of Code
 * @version 0.1
 * @date 2021-07-03
 * 
 * @par
 * Day 1: Report Repair
 * 
 * Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input);
 * apparently, something isn't quite adding up.
 * 
 * Specifically, they need you to find the two entries that sum to 2020 and then multiply those two numbers 
 * together.
 * 
 * For example, suppose your expense report contained the following:
 * 1721, 979, 366, 299, 675, 1456
 * 
 * In this list, the two entries that sum to 2020 are 1721 and 299. Multipling them together produces 
 * 1721 * 299 = 514579, so the correct answer is 514579.
 * 
 * Of course, your expense report is much larger. Find the two entires that sum to 2020; what do you get
 * if you multiply them together?
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define TEXT_INPUT "../puzzle_input.txt"
#define TEXT_MODE "r"

int main(void)
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