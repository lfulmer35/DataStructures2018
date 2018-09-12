*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : 1                
*  Due Date  : Jan. 31, 2013
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a class for a guessing game which allows
a user to guess random numbers. The user chooses
what the range of numbers will be and  tries to match his guessed
numbers to the randomly generated numbers. It uses two vectors for 
guesses and randomly generated numbers. The program then compares
the two vectors using nested for loops.

Additionally, the program will print the random numbers that are generated.
This is not an error. I left it for ease of grading, so hopefully you won't
take off points.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This is the driver of the program. Very little code, but allows
the user to input the range of numbers that they would like to play 
with. This file calls all other functions.
   
Name: guess.h
This is the header file for the guess class.      

Name:  guess.cpp   
Contains function definitions for the guess class.   


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
       % unzip [fulmerHW1]

   Now you should see a directory named homework with the files:
        main.cpp
        guess.h
        guess.cpp
	makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerHW1] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerHW1]

4. Delete the obj files, executables, and core dump by
   %./make clean
