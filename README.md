# TSP-Traveling-Salesman-Problem-
 
## Introduction 

The Traveling Salesman Problem is an optimization problem that involves finding the shortest path to visit each city in a given set once before returning to the starting city. It is considered one of Richard Karp's 21 NP-complete problems.

To solve this problem, two categories of methods are used: exact methods and approximate methods. In this project, we chose to solve the problem using the 2-opt algorithm, an approximate method that involves applying simple transformations to the initial path until it can no longer be improved.


## Usage

To compile the program, enter the command "make" and follow the steps displayed on the terminal.

## Project structure description

To better organize our work, we worked in a modular manner by breaking down the project into several files:

grapheadjl.c and grapheadjv.c: These files manage the two data structures used to store the graph, the adjacency list, and the adjacency vector.
opt2liste.c and opt2Vec.c: These files contain the implementation of the 2-opt algorithm.
tools.c: This file contains a mini-library that allows for managing memory allocations, time management, and other functions.
 
## Results obtained

We compared the results obtained using the two data structures, the adjacency list and the adjacency vector. We found that the list structure was more optimal in terms of execution time and memory consumption.

## Difficulties encountered

We encountered several difficulties during the realization of this project, particularly in terms of managing memory leaks and choosing the algorithm to solve the problem. We also had difficulties in terms of organization to manage our time optimally.

## Conclusion

This project allowed us to improve our skills in algorithmics and C programming. We managed to solve the Traveling Salesman Problem using the 2-opt algorithm and by comparing the performance of two different data structures. We learned the importance of organization and planning in project management.
