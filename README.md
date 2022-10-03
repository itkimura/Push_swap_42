# Push_swap

The **Push_swap** project is a very simple and highly effective algorithm project: data will
need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.

Write 2 programs in C:

- The first, named checker which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.

- The second one called push_swap which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts inte-
ger arguments received.


## Makefile help
How to see the make command options:
```
make help
```
![Screenshot 2022-10-03 at 16 53 36](https://user-images.githubusercontent.com/61685238/193595018-e146bf74-543a-4ca3-8e33-61259d6d5108.png)

## Programmes
### Double linked list
The two stacks are implemented with double linked list. The double linked list start with dummy node to reach the top and the last node easily.
![My first board - Frame 1](https://user-images.githubusercontent.com/61685238/193664179-ddb92d1d-8e26-4181-a724-f0ab0ddae977.jpg)


## Algorithm


## Bonus: Visualizer


https://user-images.githubusercontent.com/61685238/193667484-22919b1a-fd21-4db0-ab76-b738367523eb.mov



## Flowchart
```mermaid
  graph TD;
      main-->validate_args;
      validate_args-->|All inputs are valid|init_numbers;
      init_numbers-->|No duplication and all numbers are valid as int. Insert all into int string |init_stack;
```





