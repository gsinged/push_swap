# push_swap

The essence of the project is that you need to sort the stack of integers with a limited set of instructions, using the minimum possible number of actions.

instructions | Description
---|---
sa | swap a - swap the first 2 elements at the top of stack A
sb | swap b - swap the first 2 elements at the top of stack B
ss | sa and sb at the same time
pa | push a - take the first element at the top of B and put it at the top of A
pb | push b - take the first element at the top of A and put it at the top of B
ra | rotate a - shift up all elements of stack A by 1. The first element becomes the last one
rb | rotate b - shift up all elements of stack B by 1. The first element becomes the last one
rr | ra and rb at the same time
rra | reverse rotate a - shift down all elements of stack A by 1. The last element becomes the first one
rrb | reverse rotate b - shift down all elements of stack B by 1. The last element becomes the first one
rrr | rra and rrb at the same time
