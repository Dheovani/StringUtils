#pragma once

#define NOT_FOUND 0

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char* string;

/**
 * Prints a new line to the console
 * @param string str
 */
void println(string str);

/**
 * Returns the length of a given string
 * @param string str
 * @return size_t
 */
size_t length(string str);

/**
 * Counts the amount of times a char is found in a given string (considering case)
 * @param string str
 * @param char search
 * @return int
 */
int count(string str, char search);

/**
 * Returns a part of a string given the begin and end indexes
 * Since this method allocates memoty to create the string,
 * it is necessary to call 'free()' on the pointer returned by this function
 * @param unsigned int begin
 * @param unsigned int end
 * @param string str
 * @return string
 */
string substr(unsigned int begin, unsigned int end, string str);

/**
 * Returns the length of a given string
 * @param string str
 * @param string search
 * @param unsigned int offset - index where verification starts
 * @return int
 */
int index_of(string str, string search, unsigned int offset);

/**
 * Returns the last index of a character in a given string
 * @param string str
 * @param string search
 * @return int
 */
int last_index_of(string str, string search);

/**
 * Joins a string to a buffer. Since this method allocates memoty to create the string,
 * it is necessary to call 'free()' on the pointer returned by this function
 * @param string str1
 * @param string str2
 * @return string - the buffer that will receive the joined values. Must have the size of both strings combined
 */
string join(string str1, string str2);

/**
 * Splits a string into an array of substrings based on a separator
 * Since this method allocates memory to create the array of strings,
 * it is necessary to call 'free()' on the pointer returned by this function
 * and each one of it's values
 * @param string str
 * @param char separator
 * @return string* - buffer that will receive the spread values (an array of strings, wich is char**)
 */
string* split(string str, char separator);

/**
 * Verifies if a string is empty. Returns true if it's length is 0
 * @param string str
 * @return bool
 */
bool is_empty(string str);

/**
 * Verifies if a string is blank
 * Returns true if the string is empty or if it only contains white spaces
 * @param string str
 * @return bool
 */
bool is_blank(string str);

/**
 * Checks if two strings are equal
 * @param string str1
 * @param string str2
 * @return bool
 */
bool str_equals(string str1, string str2);

/**
 * Checks if a string contains a determined preffix
 * @param string str1
 * @param string str2
 * @return bool
 */
bool str_contains(string str1, string str2);
