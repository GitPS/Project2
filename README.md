#### CS 441 Project 2 Part 1 ####

__Authors__

Ryan Gittins and Phillip Sime

2013-10-14

__Summary__

__Build__

To build this software, simply navigate to the directory containing the Makefile and all other included files on a unix-based machine or virtual machine. Type the command `make` into the terminal to trigger the build. This will cause the gcc build commands listed in the Makefile to execute, compiling the source code into an executable file.

__Usage__

To use this software, simply run the command `./bounded-buffer [Time to Live] [Producer Threads] [ Consumer Threads] ( Buffer Size )`  Where items in brackets are required and items in parentheses are optional.  The first argument is the length, in seconds, you wish the program to run for.  The second argument is the number of producer threads you wish the program to create and use.  The third argument is the number of consumer threads you wish the program to create and use.  The final argument, which is optional, is the size of the buffer.

__Test Cases__

__Examples__

This example runs the program with `./bounded-buffer 2 4 6` to show how the program will execute using the default buffer size. 
````
shell$ ./bounded-buffer 2 4 6
Buffer Size               :  10
Time To Live (seconds)    :   2
Number of Producer threads:   4
Number of Consumer threads:   6
-------------------------------
Initial Buffer:               [  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1 ]
Producer    1: Produced 8     [   8v  -1^  -1  -1  -1  -1  -1  -1  -1  -1 ]
Producer    3: Produced 6     [   8v   6  -1^  -1  -1  -1  -1  -1  -1  -1 ]
Consumer    3: Consumed 8     [  -1   6v  -1^  -1  -1  -1  -1  -1  -1  -1 ]
Consumer    0: Consumed 6     [  -1  -1  -1^v  -1  -1  -1  -1  -1  -1  -1 ]
Producer    0: Produced 3     [  -1  -1   3v  -1^  -1  -1  -1  -1  -1  -1 ]
Consumer    2: Consumed 3     [  -1  -1  -1  -1^v  -1  -1  -1  -1  -1  -1 ]
Producer    1: Produced 2     [  -1  -1  -1   2v  -1^  -1  -1  -1  -1  -1 ]
Consumer    4: Consumed 2     [  -1  -1  -1  -1  -1^v  -1  -1  -1  -1  -1 ]
Producer    0: Produced 0     [  -1  -1  -1  -1   0v  -1^  -1  -1  -1  -1 ]
Consumer    0: Consumed 0     [  -1  -1  -1  -1  -1  -1^v  -1  -1  -1  -1 ]
Producer    2: Produced 9     [  -1  -1  -1  -1  -1   9v  -1^  -1  -1  -1 ]
Consumer    1: Consumed 9     [  -1  -1  -1  -1  -1  -1  -1^v  -1  -1  -1 ]
Producer    1: Produced 5     [  -1  -1  -1  -1  -1  -1   5v  -1^  -1  -1 ]
Consumer    3: Consumed 5     [  -1  -1  -1  -1  -1  -1  -1  -1^v  -1  -1 ]
Producer    3: Produced 6     [  -1  -1  -1  -1  -1  -1  -1   6v  -1^  -1 ]
Consumer    5: Consumed 6     [  -1  -1  -1  -1  -1  -1  -1  -1  -1^v  -1 ]
Producer    1: Produced 9     [  -1  -1  -1  -1  -1  -1  -1  -1   9v  -1^ ]
Consumer    2: Consumed 9     [  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1^v ]
Producer    0: Produced 4     [  -1^  -1  -1  -1  -1  -1  -1  -1  -1   4v ]
Consumer    4: Consumed 4     [  -1^v  -1  -1  -1  -1  -1  -1  -1  -1  -1 ]
Producer    2: Produced 0     [   0v  -1^  -1  -1  -1  -1  -1  -1  -1  -1 ]
Producer    0: Produced 5     [   0v   5  -1^  -1  -1  -1  -1  -1  -1  -1 ]
Consumer    5: Consumed 0     [  -1   5v  -1^  -1  -1  -1  -1  -1  -1  -1 ]
Consumer    0: Consumed 5     [  -1  -1  -1^v  -1  -1  -1  -1  -1  -1  -1 ]
Producer    1: Produced 2     [  -1  -1   2v  -1^  -1  -1  -1  -1  -1  -1 ]
Consumer    1: Consumed 2     [  -1  -1  -1  -1^v  -1  -1  -1  -1  -1  -1 ]
Producer    1: Produced 8     [  -1  -1  -1   8v  -1^  -1  -1  -1  -1  -1 ]
Consumer    0: Consumed 8     [  -1  -1  -1  -1  -1^v  -1  -1  -1  -1  -1 ]
Producer    3: Produced 0     [  -1  -1  -1  -1   0v  -1^  -1  -1  -1  -1 ]
Consumer    3: Consumed 0     [  -1  -1  -1  -1  -1  -1^v  -1  -1  -1  -1 ]
Producer    2: Produced 1     [  -1  -1  -1  -1  -1   1v  -1^  -1  -1  -1 ]
Consumer    5: Consumed 1     [  -1  -1  -1  -1  -1  -1  -1^v  -1  -1  -1 ]
````

This example runs the program with `./bounded-buffer 2 3 3 5` to show how the program will execute when providing a buffer size. 
````
shell$ ./bounded-buffer 2 3 3 5
Buffer Size               :   5
Time To Live (seconds)    :   2
Number of Producer threads:   3
Number of Consumer threads:   3
-------------------------------
Initial Buffer:               [  -1^v  -1  -1  -1  -1 ]
Producer    0: Produced 0     [   0v  -1^  -1  -1  -1 ]
Consumer    1: Consumed 0     [  -1  -1^v  -1  -1  -1 ]
Producer    0: Produced 2     [  -1   2v  -1^  -1  -1 ]
Producer    1: Produced 2     [  -1   2v   2  -1^  -1 ]
Producer    1: Produced 0     [  -1   2v   2   0  -1^ ]
Consumer    2: Consumed 2     [  -1  -1   2v   0  -1^ ]
Consumer    0: Consumed 2     [  -1  -1  -1   0v  -1^ ]
Producer    2: Produced 9     [  -1^  -1  -1   0v   9 ]
Producer    0: Produced 6     [   6  -1^  -1   0v   9 ]
Consumer    1: Consumed 0     [   6  -1^  -1  -1   9v ]
Consumer    1: Consumed 9     [   6v  -1^  -1  -1  -1 ]
Consumer    2: Consumed 6     [  -1  -1^v  -1  -1  -1 ]
Producer    2: Produced 2     [  -1   2v  -1^  -1  -1 ]
Producer    1: Produced 7     [  -1   2v   7  -1^  -1 ]
Producer    1: Produced 9     [  -1   2v   7   9  -1^ ]
Consumer    0: Consumed 2     [  -1  -1   7v   9  -1^ ]
Producer    0: Produced 8     [  -1^  -1   7v   9   8 ]
Producer    1: Produced 6     [   6  -1^   7v   9   8 ]
Consumer    1: Consumed 7     [   6  -1^  -1   9v   8 ]
Consumer    2: Consumed 9     [   6  -1^  -1  -1   8v ]
````

__Question Answers__

This is only applicable to part 2.

__Known Bugs and Problem Areas__
