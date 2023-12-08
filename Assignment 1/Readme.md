Problem 1
Write a program that would first of all create “n” number of processes. To create “n”
number of processes, you need to follow these steps:
 Generate any random number between 10 - 99
 Multiply the generated number by last digit of your roll number.
 Now divide your roll number with the generated number.
 Once division is done, Take the mod of respective number with 25. If your number
is less than 10, add 15 to it.
 You will receive a number less than 25, now create (n x n) matrix and populate
the matrix randomly.
Once the matrix has been populated successfully and you have “n” number of
processes created, you have to save the whole matrix in a text file. Now you have to
perform matrix multiplication. Each process will perform matrix multiplication for one row
and store it in the respective text file along with its id.
Once all the processes perform their tasks, the main process will read all the text files of
the processes and display the resultant matrix.

Problem 2
Develop a chat program that uses shared memory, fork(), and exec() for interprocess communication between clients. The messages between the chat clients will be
stored in shared memory. Discuss the synchronization issues that can arise due to multiple
processes accessing shared memory concurrently.
Your program should include the following features:
 The chat program should allow multiple clients to connect and communicate with each
other.
 The messages exchanged between the clients should be stored in shared memory.
 The clients should use fork() and exec() to create child processes for communication.
 The program should discuss the synchronization issues that can arise due to multiple
processes accessing shared memory concurrently. Add the description of problem in
the code within a single block comment. e.g. /* problem */
 You are not required to solve the synchronization issues in your program, but you
should discuss the potential problems and how they could be resolved.
 You are not allowed to use pipes for communication.

Problem 3
Implement the following using bash scripting.
1. Create a new user (user name is OS_Assignment_1 and password is 12345) in Ubuntu.
2. Assign administrator privileges to it. Switch used for this task is –uc.
3. List down all of the installed application into Ubuntu. Switch used for this task is
‘–ld’.
4. Install application program like Dropbox. Switch used for this task is –ins.
5. Now, set the IP address, mask, gateway, and DNS of that machine.
 IP Address: 10.0.0.1
 Mask: 255.255.255.0
 Gateway: 10.0.0.254
 DNS: 8.8.8.8
6. Switch used for this task is –ipcon.
7. Help of all these task will also display using –help switch.
8. Whenever your shell script is run your name and roll number with this format “21—
XXXX-NAME” will display first then perform further tasks.
9. All of your tasks will performed using functions.
10.Verify your system after applying above configuration/installations to test
whether shell script is working properly.
Example:
$ ./OS_Assignment_1.sh –uc
$ Enter user: OS_Assignment_1
$ Enter password: 12345
$ User OS_Assignment_1 is created and administrator privileges are assigned.
