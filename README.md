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
How to see the mmake command options:
```
make help
```

## Variables
| Name | Description |
| --- | --- |
| t_dlst | double linked list for stack |

## Files
All source files are in ./srcs/
| Name | Description |
| --- | --- |
| push_swap.c | main for push_swap |
| validate_arg.c | validate inputs as integers |
| checker.c | source file for checker |


## Flowchart
```mermaid
  graph TD;
      push_swap-->validate_args;
      validate_args-->|All inputs are valid|init_numbers;
      init_numbers-->|No duplication and all numbers are valid as int. Insert all into int string |init_stack;
```

