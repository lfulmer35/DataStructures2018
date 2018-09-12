*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : 2                
*  Due Date  : Feb 7, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program uses existing "ArrayBag" class. It creates a Union
by overloading the + operator and creates a difference by 
overloading the - operator. The program also contains a 
"Remove Duplicate" function. Running the program prints the 
values of each bag, quantity inside a Union bag and Difference
bag.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
File read in and all function calls come from this file.
This file also prints the contents of each type of bag.
   
Name: Functions.h
This is the header file for the overloaded operators. It
is a friend to class ArrayBag.      

Name:  Functions.cpp   
Contains function definitions overloaded operators.   

Name: setInput.txt
Text file containing intergers which are read-in to the program.

Name: ArrayBag.h
Header file for the ArrayBag class. Changes to the class have been
annotated with comments.

Name: ArrayBag.cpp
Function definitions for class ArrayBag.


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
       % unzip [fulmerHW2]

   Now you should see a directory named homework with the files:
        main.cpp
        Functions.h
        Functions.cpp
		setInput.txt
		ArrayBag.h
		ArrayBag.cpp
		makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerHW2] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerHW2]

4. Delete the obj files, executables, and core dump by
   %./make clean
