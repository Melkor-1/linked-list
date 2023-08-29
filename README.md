# Linked List Library

This is a simple linked list library written in C that provides various operations for creating, manipulating, and managing linked lists.

## Features

- Create linked lists.
- Append, insert, and delete nodes.
- Search, count, and manipulate list items.
- Reverse, remove duplicates, and perform other list operations.

## Getting Started

### Prerequisites

To compile and test the library, you'll need the [Criterion](https://github.com/Snaipe/Criterion) testing framework. Make sure you have it installed on your system.

### Building the Library

1. Clone this repository:
~~~
git clone https://github.com/your-username/linked-list-library.git
cd linked-list-library
~~~

2. Build the library:
~~~
make
~~~

This will compile the library and generate the static library `lib/libslist.a` and dynamic library `lib/libslist.so` in the `lib` directory.

### Running Tests

1. Make sure you have the library built.

2. Run the tests:
~~~
make test
~~~

This will compile and run the tests from the `tests` directory using the Criterion framework.

## Usage

To use the linked list library in your own projects:

1. Include the library header file `list.h` in your source code:

~~~
#include "list.h"
~~~

Link your project with the compiled library `lib/list.a`.

Refer to the documentation in the header file for information on available functions and their usage.

## Contributing
Contributions are welcome! If you find any issues or want to add new features or improvements, feel free to open a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
