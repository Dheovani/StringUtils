#include <stdio.h>
#include "stringutils.h"

int main()
{
	// Testing length
	string testLength = "Twenty five characters!?!";
	assert(length(testLength) == 25);
	println("Lenght test sucessfully completed!");

	// Testing matrix_length
	string testMatrixLength[3];
	testMatrixLength[0] = "testMatrixLength";
	testMatrixLength[1] = "testMatrixLength";
	testMatrixLength[2] = NULL;
	assert(matrix_length(testMatrixLength) == 2);
	println("Matrix_length test sucessfully completed!");

	// Testing count
	string testCount = "Letter e four times";
	assert(count(testCount, 'e') == 4);
	println("Count test sucessfully completed!");

	// Testing substr
	string testSubstr = "Testing substr";
	string test1 = substr(4, 9, testSubstr);
	assert(str_equals(test1, "ing s"));
	free(test1);

	string test2 = substr(0, (unsigned int)length(testSubstr), testSubstr);
	assert(str_equals(test2, testSubstr));
	free(test2);
	println("Substr test sucessfully completed!");

	// Testing index_of
	string testIndexOf = "Testing the index_of method";
	assert(index_of(testIndexOf, "index_of", 0) == 12);
	assert(index_of(testIndexOf, "addasfss", 0) == NOT_FOUND);

	string testIndexOffset = "Testing the index_of method setting an offset value";
	assert(index_of(testIndexOffset, "of", 6) == 18);
	assert(index_of(testIndexOffset, "of", 15) == 18);
	assert(index_of(testIndexOffset, "of", 25) == 39);
	println("Indef_of test sucessfully completed!");

	// Testing last_index_of
	string testLastIndexOf = "Testing the last_indef_of function";
	assert(last_index_of(testLastIndexOf, "n") == 33);
	assert(last_index_of(testLastIndexOf, "e") == 20);
	assert(last_index_of(testLastIndexOf, "asasdad") == NOT_FOUND);
	println("Last_indef_of test sucessfully completed!");

	// Testing join
	string str1 = "Hello,";
	string str2 = " world!";
	string result = join(str1, str2);
	assert(str_equals(result, "Hello, world!"));
	free(result);
	println("Join test sucessfully completed!");

	// Testing split
	string testSplit = "String to split";
	string* splitted = split(testSplit, ' ');
	assert(str_equals(splitted[0], "String"));
	free(splitted[0]);
	assert(str_equals(splitted[1], "to"));
	free(splitted[1]);
	assert(str_equals(splitted[2], "split"));
	free(splitted[2]);
	free(splitted);
	println("Split test sucessfully completed!");

	// Testing is_empty
	assert(!is_empty(" "));
	assert(is_empty(""));
	assert(is_empty("\0"));
	println("Is_empty test sucessfully completed!");

	// Testing is_blank
	assert(is_blank("         "));
	assert(is_blank(" "));
	assert(is_blank(""));
	assert(is_blank("\0"));
	assert(!is_blank("a"));
	println("Is_blank test sucessfully completed!");

	// Testing str_equals
	assert(str_equals("aaa", "aaa"));
	assert(str_equals("Testing str_equals", "Testing str_equals"));
	assert(!str_equals("aab", "aaa"));
	assert(!str_equals("aaa", "aaaa"));
	assert(!str_equals("Testing str_equals!", "Testing str_equals"));
	println("Str_equals test sucessfully completed!");

	// Testing str_contains
	assert(str_contains("Testing str_contains", "Testing str_contains"));
	assert(str_contains("Testing str_contains", "Testing"));
	assert(str_contains("Testing str_contains", "a"));
	assert(str_contains("Testing str_contains", " "));
	assert(!str_contains("Testing str_contains", "  "));
	assert(!str_contains("Testing str_contains", ";"));
	println("Str_contains test sucessfully completed!");

	return EXIT_SUCCESS;
}