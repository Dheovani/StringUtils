# StringUtils 🧵🔧

A collection of handy string utility functions for all your string manipulation needs! 😄

## Introduction 💡

StringUtils is a lightweight C library that provides various string utility functions to make your string operations more convenient and efficient. It includes functions for string splitting, searching, and more!

## Functions 🛠️

- `length`: Get the length of a string.
- `matrix_length`: Get the length of a matrix.
- `count`: Count the occurrences of a character in a string.
- `substr`: Get a substring of a string.
- `index_of`: Find the index of a substring in a string.
- `last_index_of`: Find the last index of a substring in a string.
- `join`: Join two strings together.
- `split`: Split a string into an array of substrings.
- `is_empty`: Check if a string is empty.
- `is_blank`: Check if a string is blank.
- `str_equals`: Check if two strings are equal.
- `str_contains`: Check if a string contains a specific substring.

## Getting Started 🚀

To get started with StringUtils, follow these simple steps:

1. Clone the repository to your local machine.
2. Include `stringutils.h` in your C project.
3. Link the `stringutils.c` file to your project.
4. You're ready to use the StringUtils functions!

## Usage 💻

```c
#include <stdio.h>
#include "stringutils.h"

int main() {
    string myString = "Hello, World!";
    int len = length(myString);
    
    printf("Length of the string: %d\n", len);

    // Use other StringUtils functions here!

    return 0;
}
```

Feel free to explore the provided functions and incorporate them into your projects!

## Contributing 🤝

Contributions are welcome! If you have any improvements, new features, or bug fixes to propose, please open an issue or create a pull request.

## License 📝

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Enjoy! 🚀