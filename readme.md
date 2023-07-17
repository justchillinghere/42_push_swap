# Push swap project

## Short description

You have 2 stacks named a and b.
At the beginning of the program, The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. The stack b is empty. The goal is to sort in ascending order numbers into stack a. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.

## TODO

### Base stack implementation

- [x] Implemet stack
- [x] Implement stack operations:
  - [x] push
  - [x] pop
  - [x] print
  - [x] is_empty
  - [x] size # TODO: test
  - [x] free
  - [x] rotate
  - [x] reverse rotate

### Rules to implement

- [x] sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- [x] sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- [x] ss : sa and sb at the same time.
- [x] pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- [x] pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- [x] ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- [x] rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- [x] rr : ra and rb at the same time.
- [x] rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- [x] rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- [x] rrr : rra and rrb at the same time.

### Error check

- [ ] Check for non-digit/negative numbers/space characters
- [ ] Check for non-integer values
- [ ] Check for duplicate values

## Test coverage

- [ ] Integrate criterion testing framework
- [ ] Get test coverage of stackfunctions:
  - [x] Push
  - [x] Pop
  - [x] Rotate
  - [x] Reverse rotate
  - [ ] Swap
  - [x] Free
  - [x] Create

## Algorithm

First, check if the stack is already sorted. If it is, do nothing. If it's not, then we need to sort it.
Then, there're sevearal cases to consider:

- [ ] 3 numbers and less
- [ ] 5 numbers and less
- [ ] 100 numbers and less
- [ ] 500 numbers and less

### 3 numbers and less

If there're 3 numbers or less, the algorithm is pretty simple:

1. Find max value in the stack (TODO: parse max value to the structure field later)
2. If max value on top -> rotate to bottom
3. If max value in the middle -> reverse rotate bottom element to the top of the stack
4. Swap first two elements if they are unordered
