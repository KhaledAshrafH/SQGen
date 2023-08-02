# Generic Stack and Queue Implementation in c++

## Introduction

This project demonstrates the use of inheritance, templates and exceptions in C++ to implement two data structures: stacks and queues. Stacks are based on the LIFO (last in- first out) principle, while queues are based on the FIFO (first in- first out) principle. The project also shows how to make the stack and queue resizable, such that they can store any number of elements of any type.

## Classes

The project consists of four classes and their implementation:

- **Rectangle**: A class that represents a rectangle with length, width and area.
- **MyList**: An abstract class template that stores an array of generic-typed elements with a capacity.
- **MyStack**: A subclass of MyList that implements a stack data structure.
- **MyQueue**: A subclass of MyList that implements a queue data structure.

## Main Function

The main function interacts with the user through console input and output. It performs the following steps:

- First, it asks the user whether to use stacks or queues (S/Q).
- Second, it asks whether the user wants to store integers, strings or rectangles (1/2/3).
- Third, it loops for adding elements to the chosen data structure until the user enters N for no more elements.
- Fourth, it displays all the elements stored in the data structure by calling the getElem method until it is empty.

The main function also handles exceptions that might occur because of a wrong input from the user.

## How to Run

To run this project, you need to have a C++ compiler installed on your system. You can use any IDE or command-line tool to compile and run the source code files.

Copy
g++ Rectangle.cpp MyList.cpp MyStack.cpp MyQueue.cpp main.cpp -o main ./main
