#pragma once

#include <stdint.h>
#include <stdlib.h>

/**
 * Find the first occurence of character c in the string s.
 * @param s The given string
 * @param c The given character
 * @return The pointer to the first occurence.
 */
char *mystrchr(const char *s, int c);

/**
 * Find the last occurence of character c in the string s.
 * @param s The given string
 * @param c The given character
 * @return The pointer to the last occurence.
 */
char *mystrrchr(const char *s, int c);

/**
 * Calculate the length of the maximum initial segment of string s that consists of only characters from string accept.
 * @param s The given string
 * @param accept The given string of characters
 * @return The length of the maximum initial segment.
 */
size_t mystrspn(const char *s, const char *accept);

/**
 * Calculate the length of the maximum initial segment of string s that consists of only characters not from string reject.
 * @param s The given string
 * @param reject The given string of characters
 * @return The length of the maximum initial segment.
 */
size_t mystrcspn(const char *s, const char *reject);

/**
 * Find the first occurence of any character from string accept in the string s.
 * @param s The given string
 * @param accept The given string of characters
 * @return The pointer to the first occurence.
 */
char *mystrpbrk(const char *s, const char *accept);

/**
 * Find the first occurence of string needle in the string haystack.
 * @param haystack The given string
 * @param needle The given string
 * @return The pointer to the first occurence.
 */
char *mystrstr(const char *haystack, const char *needle);

/**
 * Break string str into a series of tokens using the delimiter string delim.
 * @param str The given string
 * @param delim The given delimiter string
 * @return The pointer to the next token.
 */
char *mystrtok(char *str, const char *delim);
