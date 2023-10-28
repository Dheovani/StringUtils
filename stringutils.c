#include "stringutils.h"

void println(string str)
{
	printf("%s\n", str);
}

size_t length(string str)
{
	int i = 0;
	while (str && str[i] && str[i] != '\0')
		i++;

	return i;
}

string substr(unsigned int begin, unsigned int end, string str)
{
	assert(begin >= 0 && end <= length(str));

	string buffer = (string)malloc(end - begin + 1);

	for (unsigned int i = begin; i < end; i++) {
		buffer[i - begin] = str[i];
	}

	buffer[end - begin] = '\0';
	return buffer;
}

int count(string str, char search)
{
	int i, c = NOT_FOUND;

	for (i = 0; i < length(str); i++) {
		if (str[i] == search)
			c++;
	}

	return c;
}

int index_of(string str, string search, unsigned int offset)
{
	assert(length(str) >= offset);

	size_t size_buffer = length(search);
	string buffer = (string)malloc((sizeof(char) * size_buffer) + 1);

	for (int i = offset; i < length(str); i++) {
		for (int j = 0; j < size_buffer; j++) {
			buffer[j] = str[j + i];
		}

		buffer[size_buffer] = '\0';

		if (str_equals(buffer, search)) {
			free(buffer);
			return i;
		}

		// Check if there's enough chars remaining in 'str' to match the 'buffer's size
		if (length(str) - i <= size_buffer)
			break;
	}

	free(buffer);
	return NOT_FOUND;
}

int last_index_of(string str, string search)
{
	int index = 0, result = NOT_FOUND;
	const size_t len = length(str);

	do {
		index = index_of(str, search, index + 1);

		if (index >= (int)len)
			index = NOT_FOUND;

		if (index != NOT_FOUND)
			result = index;
	} while (index != NOT_FOUND);

	return result;
}

string join(string str1, string str2)
{
	const size_t str1_size = length(str1), str2_size = length(str2);
	string buffer = (string)malloc(str1_size + str2_size + 1);

	int cont = 0;
	while (cont < str1_size) {
		buffer[cont] = str1[cont];
		cont++;
	}

	while (cont < str1_size + str2_size) {
		buffer[cont] = str2[cont - str1_size];
		cont++;
	}

	buffer[str1_size + str2_size] = '\0';
	return buffer;
}

string* split(string str, char separator)
{
	int cont = count(str, separator);
	if (cont == NOT_FOUND)
		printf("Couldn't split the string. Separator %c not found\n", separator), exit(EXIT_FAILURE);

	string* tokens = (string*)malloc((cont + 1) * sizeof(string));
	if (!tokens)
		println("Error allocating memory."), exit(EXIT_FAILURE);

	string strSep = (string)malloc(2 * sizeof(char));
	strSep[0] = separator;
	strSep[1] = '\0';

	int index = 0;
	for (int i = 0; i <= cont; i++) {
		int oldIndex = index;
		index = index_of(str, strSep, index);

		if (index == NOT_FOUND)
			index = (int)length(str);

		tokens[i] = substr(oldIndex, index, str);
		index++;
	}

	tokens[cont] = '\0';

	free(strSep);
	return tokens;
}


bool is_empty(string str)
{
	return length(str) == 0;
}

bool is_blank(string str)
{
	bool is_blank = true;

	for (size_t i = 0; i < length(str); i++) {
		is_blank = str[i] == ' ';
	}

	return is_blank;
}

bool str_equals(string str1, string str2) {
	bool equals = length(str1) == length(str2);

	for (int i = 0; i < length(str1); i++) {
		equals &= str1[i] == str2[i];
	}

	return equals;
}

bool str_contains(string str1, string str2) {
	size_t size_buffer = length(str2);
	string buffer = (string)malloc((sizeof(char) * size_buffer) + 1);

	for (int i = 0; i < length(str1); i++) {
		for (int j = 0; j < size_buffer; j++) {
			buffer[j] = str1[j + i];
		}
		
		buffer[size_buffer] = '\0';
		
		if (str_equals(buffer, str2)) {
			free(buffer);
			return true;
		}
		
		// Check if there's enough chars remaining in 'str' to match the 'buffer's size
		if (length(str1) - i <= size_buffer)
			break;
	}

	free(buffer);
	return false;
}
