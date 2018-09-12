*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSCI 2312           
*  HW#       : 6                
*  Due Date  : April 25, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a LinkedList class and uses struct
Node and Struct student. The program also uses templates
for the Node and LinkedList data structures. It then 
demonstrates the functionality of the linked list. Lastly,
it reads-in a binary file containing student entries.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This is the driver of the program. Demonstration of 
functionality takes place in main.
   
Name: LinkedList.h
Declarations for the LinkedList class and Node struct

Name: LinkedList.hpp
Contains function definitions for LinkedList class.
Contains constructor, copy constructor, destructor, and
overloaded = operator for LinkedList class.

Name: Student.h
Declaration of Student structure. Contains overloaded <<
operator for Student objects.

Name: students.dat
Binary file containing three Student entries.

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
       % unzip [fulmerhw6]

   Now you should see a directory named homework with the files:
        main.cpp
        LinkedList.h
	LinkedList.hpp
	Student.h
	makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerhw6] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerhw6]

4. Delete the obj files, executables, and core dump by
   %./make clean
