*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : 5                
*  Due Date  : March 1, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a Linked List. It has functions which 
allow the user to input at the front, back, or a chosen
position; as well as deleting front, back, or chosen
position. It contains a clear function which deletes all
elements of the list and has an overloaded <<operator 
allowing the user to print the linked list.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This file calls all functions and displays the functionality
of the lined list.

Name: analysis.txt
Text file which provides "Big O" analysis of the program.

Name: LinkedList.h
Header file for LinkedList class as well as the Node struct. 

Name: LinkedList.cpp
Function definitions for MyVector class.


*******************************************************
*  Circumstances of programs
*******************************************************

The program compiles and runs.
   
The program was developed on Visual Studio 2017.  It was 
compiled, run, and tested on cse grid.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [fulmerhw4]

   Now you should see a directory named homework with the files:
        main.cpp
	LinkedList.h
	LinkedList.cpp
	makefile
        Readme.txt
	analysis.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerhw5] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerhw5]

4. Delete the obj files, executables, and core dump by
   %./make clean
