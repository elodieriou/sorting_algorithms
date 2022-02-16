![Holberton France Logo](https://images.squarespace-cdn.com/content/v1/60bf70d860f31b4f60455443/1625061110826-904UGWRZ9PX81YWARXMT/HolbertonFRANCEFichier+16.png?format=1500w)

# 0x1B. C - Sorting algorithms & Big O

![Holberton France Logo](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/248/willy-wonka.png)

## Background Context
This project is meant to be done by groups of two students. Each group of two should pair program for at least the mandatory part.

## Resources
### Before coding:
[Sorting algorithm](https://intranet.hbtn.io/rltoken/tmzgO7xhCpNgPUxVhLKibw)

[Big O notation](https://intranet.hbtn.io/rltoken/XrLMaOhUMHfwsFEz15TVow)

[Sorting algorithms animations](https://intranet.hbtn.io/rltoken/kJ7rgWoqdLnxSnSEoAiFCQ)

[15 sorting algorithms in 6 minutes](https://intranet.hbtn.io/rltoken/RdvoGNMTJ6Hq34aJ_HmCqA) (WARNING: The following video can trigger seizure/epilepsy. It is not required for the project, as it is only a funny visualization of different sorting algorithms)

### Task #0 Bubble sort
[Geek for Geek](https://www.geeksforgeeks.org/bubble-sort/)

### Task #1 Insertion sort
Personal inspiration :blush:

### Task #2 Selection sort
[Programiz](https://www.programiz.com/dsa/selection-sort)

### Task #3 Quick sort - Lomuto partition
[Geek for Geek](https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/)

### Task #4 Shell sort - Knuth Sequence
[Programiz](https://www.programiz.com/dsa/shell-sort)

### Task #5 Cocktail shaker sort
Personal inspiration :grin:

### Task #6 Counting sort
[Programiz](https://www.programiz.com/dsa/counting-sort)

### Task #7 Merge sort
[Programiz](https://www.programiz.com/dsa/merge-sort)

### Task #8 Heap sort
[Youtube](https://www.youtube.com/watch?v=cCiyQ1Z_NBY&t=728s)
[Geek for Geek](https://www.geeksforgeeks.org/heap-sort/)

### Task #9 Radix sort
[Programiz](https://www.programiz.com/dsa/radix-sort)

### Task #10 Bitonic sort
[Geek for Geek](https://www.geeksforgeeks.org/bitonic-sort/)

### Task #11 Quick sort - Hoare partition
We have validated half of the checks :neutral_face:

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General
- At least four different sorting algorithms
- What is the Big O notation, and how to evaluate the time complexity of an algorithm
- How to select the best sorting algorithm for a given input
- What is a stable sorting algorithm

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called sort.h
- Don’t forget to push your header file
- All your header files should be include guarded
- A list/array does not need to be sorted if its size is less than 2.

### GitHub
**There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.**

## More Info
### Data Structure and Functions
For this project you are given the following ```print_array```, and ```print_list``` functions:
```asm
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```
```asm
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```
- Our files print_array.c and print_list.c (containing the print_array and print_list functions) will be compiled with your functions during the correction.
- Please declare the prototype of the functions print_array and print_list in your sort.h header file
- Please use the following data structure for doubly linked list:
```asm
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```
Please, note this format is used for Quiz and Task questions.
- ```O(1)```
- ```O(n)```
- ```O(n!)```
- n square -> ```O(n^2)```
- log(n) -> ```O(log(n))```
- n * log(n) -> ```O(nlog(n))```
- n + k -> ```O(n+k)```
- …

Please use the “short” notation (don’t use constants). Example: ```O(nk)``` or ```O(wn)``` should be written ```O(n)```. If an answer is required within a file, all your answers files must have a newline at the end.

### Tests
Here is a quick tip to help you test your sorting algorithms with big sets of random integers: [Random.org](https://intranet.hbtn.io/rltoken/KkFXByKWf55lTK32JnY62w)

## Summary
![Complexity Big O](https://i.ytimg.com/vi/47GRtdHOKMg/maxresdefault.jpg)

This graph present the different complexity of program with the notation Big O. 
From the best O(1) to the worse 0(n!).

### O(1)
```asm
void f(int n)
{
    printf("n = %d\n", n);
}
```

### O(log(n))
```asm
void f(unsigned int n)
{
    int i;

    for (i = 1; i < n; i = i * 2)
    {
        printf("[%d]\n", i);
    }
}
```

### 0(n)
```asm
void f(int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("[%d]\n", i);
    }
}
```

### O(nlog(n))
```asm
void f(unsigned int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j = j * 2)
        {
            printf("[%d] [%d]\n", i, j);
        }
    }
}
```

### O(n^2)
```asm
void f(int n)
{
     int i;
     int j;

     for (i = 0; i < n; i++)
     {
          for (j = i + 1; j < n; j++)
          {
               printf("[%d] [%d]\n", i, j);
          }
     }
}
```

### O(2^n)
```asm
int Fibonacci(int number)
{
    if (number <= 1) return number;

    return Fibonacci(number - 2) + Fibonacci(number - 1);
}
```

### O(n!)
No example because we don't do it!!! 

## Cloning the repo
To clone this repository, run the command:
```
git clone git@github.com:rmarcais/sorting_algorithms.git
```

## Authors

| Élodie Riou | Rémi Marçais |
|:---:|:---:|
|<a href="https://www.linkedin.com/in/%C3%A9lodie-riou-41a43aa8/"> <img alt="Élodie Riou Linkedin" width="40px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/768px-LinkedIn_logo_initials.png"> <a href="https://github.com/elodieriou"> <img alt="Élodie Riou Github" width="40px" src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png"> | <a href="https://www.linkedin.com/in/r%C3%A9mi-mar%C3%A7ais-274a4421a/"> <img alt="Rémi Marçais Linkedin" width="40px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/768px-LinkedIn_logo_initials.png"> <a href="https://github.com/rmarcais"> <img alt="Elodie RIOU Github" width="40px" src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png"> |
