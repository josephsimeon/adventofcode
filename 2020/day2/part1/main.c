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

#define TEXT_INPUT "../puzzle_input.txt"
#define TEXT_MODE "r"

#define MAX_STRING_LENGTH 100

int main (void)
{
    FILE *file_pointer;
    int minimum_req, maximum_req, letter_occurances = 0, valid_passwords = 0;
    char important_letter, array_of_chars[MAX_STRING_LENGTH] = {0};

    // opening file and checking for errors
    file_pointer = fopen(TEXT_INPUT, TEXT_MODE);
    if (file_pointer == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    // retrieving list from the file
    while (fscanf(file_pointer, "%i-%i %c: %s", &minimum_req, &maximum_req, &important_letter, &array_of_chars[0]) != EOF) {
        // check for important letter occurances
        for (int i = 0; i < MAX_STRING_LENGTH; i++) {
            if (important_letter == array_of_chars[i]) {
                letter_occurances++;
            }

            if (array_of_chars[i] == 0) {
                break;
            }
        }
        
        if (letter_occurances >= minimum_req && letter_occurances <= maximum_req) {
            valid_passwords++;
        }

        // reset important variables
        memset(array_of_chars, 0, MAX_STRING_LENGTH);
        letter_occurances = 0;
    }

    // print the answer
    printf("Number of valid passwords: %i\n", valid_passwords);

    // close file
    fclose(file_pointer);

    return 0;
}