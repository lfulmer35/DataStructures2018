*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : 4                
*  Due Date  : Feb 22, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a dynamic array container called
"MyVector." The container has seven functions which allow
the user to add to, remove, check size, check empty, 
search for a value, and navigate through elements of the 
container. The main function displays the functionality 
of the container.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This file calls all functions. It allows the user to 
input three numbers and then displays each function.

Name: analysis.txt
Text file which provides "Big O" analysis of the program.

Name: MyVector.h
Header file for MyVector class. 

Name: vehicle.cpp
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
	MyVector.h
	MyVector.cpp
	makefile
        Readme.txt
	analysis.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerhw4] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerhw4]

4. Delete the obj files, executables, and core dump by
   %./make clean
