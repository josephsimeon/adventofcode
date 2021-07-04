/**
 * @file main.c
 * @author Joseph Simeon (admin@joesimeon.com)
 * @brief Day 2 of 2020 - Advent of Code
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TEXT_INPUT "../puzzle_input.txt"
#define TEXT_MODE "r"

#define MAX_STRING_LENGTH 100

int main (void)
{
    FILE *file_pointer;
    int position_requirement_one, position_requirement_two, valid_passwords = 0;
    bool b_position_requirement_one, b_position_requirement_two;
    char important_letter, array_of_chars[MAX_STRING_LENGTH] = {0};

    // opening file and checking for errors
    file_pointer = fopen(TEXT_INPUT, TEXT_MODE);
    if (file_pointer == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    // retrieving list from the file
    while (fscanf(file_pointer, "%i-%i %c: %s", &position_requirement_one, &position_requirement_two, &important_letter, &array_of_chars[0]) != EOF) {
        // check for important letter occurances
        if (important_letter == array_of_chars[position_requirement_one - 1]) {
            b_position_requirement_one = true;
        } else {
            b_position_requirement_one = false;
        }
        if (important_letter == array_of_chars[position_requirement_two - 1]) {
            b_position_requirement_two = true;
        } else {
            b_position_requirement_two = false;
        }
        
        if ((b_position_requirement_one && !b_position_requirement_two) || (!b_position_requirement_one && b_position_requirement_two)) {
            valid_passwords++;
        }

        // reset important variables
        memset(array_of_chars, 0, MAX_STRING_LENGTH);
    }

    // print the answer
    printf("Number of valid passwords: %i\n", valid_passwords);

    // close file
    fclose(file_pointer);

    return 0;
}