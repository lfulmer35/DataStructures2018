*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSCI 2312           
*  HW#       : 2                
*  Due Date  : FEB 6, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates three vectors and displays them in the form of three grids.
The grid are populated after taking user input for the number of rows and columns.
The program then fills one third of the positions with the number 1. 

After populating, the program compares the first two grids and creates a third grid
that displays where the first two grids had matching positions.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This is the driver of the program. Very little code, but allows
the user to input the number of rows and columns. It then calls
all other necessary functions to complete the program.
   
Name: grid.h
This is the header file for the grid class.      

Name:  grid.cpp   
Contains function definitions for the grid class.   


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
        grid.h
        grid.cpp
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
