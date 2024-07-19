# get_next_line Project

The get_next_line project at 42 Network involves creating a function called `get_next_line` that reads a line from a file descriptor (FD). The function should be able to handle multiple file descriptors, reading from each one until the end of the file (EOF) or encountering a newline (`'\n'`).

## Table of Contents

- [Project Overview](#project-overview)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Function Description](#function-description)
- [Example Usage](#example-usage)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

The main goal of the project is to implement the `get_next_line` function that reads a line from a given file descriptor and returns it without the newline character (`'\n'`). The function should handle reading and buffering input efficiently, especially when dealing with multiple file descriptors simultaneously.

## Project Structure

The project typically consists of the following files:

1. **get_next_line.c**: Contains the implementation of the `get_next_line` function.
2. **get_next_line_utils.c**: Contains utility functions that might be useful for implementing `get_next_line`.
3. **get_next_line.h**: Header file containing function prototypes and necessary macros.
4. **main.c (optional)**: A test program to demonstrate the usage of `get_next_line`.

## Usage

To use `get_next_line` in your project, follow these steps:

1. **Clone the repository:**

    ```bash
    git clone https://github.com/ehoussa/42-Cursus---get_next_line/
    cd 42-Cursus---get_next_line
    ```

2. **Include `get_next_line` in your project:**

    Add `get_next_line.c`, `get_next_line_utils.c`, and `get_next_line.h` to your project directory.

3. **Include the header file in your source files:**

    ```c
    #include "get_next_line.h"
    ```

4. **Call `get_next_line` function to read lines:**

    ```c
    int fd;
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        // Process the line (remove '\n', manipulate data, etc.)
        printf("%s\n", line);
        free(line); // Free allocated memory for each line
    }

    // Handle EOF or error
    ```

## Function Description

The `get_next_line` function has the following signature:

```c
char *get_next_line(int fd);
