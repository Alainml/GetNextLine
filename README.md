
# Get Next Line

[42 Subject]

Function to get the next line of a file, or several on the bonus part.
It has to be able to not lose the reading thread of each fd.




-D BUFFER_SIZE = n is used on compiling to set the size of the buffer.



## Norminette

There are some peculiarities in the code due to the campus mandatory syntax
It is checked by Norminette, and makes us do less than 25 lines functions, 5 functions per file etc
## Mandatory

Function name | get_next_line | 
--- | --- | 
Prototype | char *get_next_line(int fd); | 
Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h |
Parameters  | fd: The file descriptor to read from | 
Return value | Read line: correct behavior, NULL: there is nothing else to read, or an error occurred
External functs | read, malloc, free
Description | Write a function that returns a line read from a file descriptor

## Bonus

• Develop get_next_line() using only one static variable.

• Your get_next_line() can manage multiple file descriptors at the same time.
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.


According to Francinette tester, there is an error for the bonus part, when the buffer size is 1000000 and the fd is opened, closed, and opened again.