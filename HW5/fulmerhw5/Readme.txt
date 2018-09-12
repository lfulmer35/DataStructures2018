*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSCI 2312           
*  HW#       : 5                
*  Due Date  : April 2, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a class "Animal" as well as derived
classes for different animal species. It then reads-in
files for each specific species using exception handling
and outputs the animals that were read-in. After this, 
the program modifies three animals and prints the new
values within these modified objects.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This is the driver of the program. All function calls are
made in main, in order to print the assignment's required
output.
   
Name: animals.h
This is the header file for the Animal class as well as
the specific species classes.      

Name: Animals.cpp
Contains the class definitions for all parent and derived
classes.

Name: Dog.csv
Contains data for Dog object.

Name: Fish.csv
Contains data for Fish object.

Name: Horse.csv
Contains data for Horse object.

Name: Lizard.csv
Contains data for Lizard object.

Name: Monkey.csv
Contains data for Monkey object.


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
       % unzip [fulmerhw5]

   Now you should see a directory named homework with the files:
        main.cpp
        animals.cpp
	animals.h
	Dog.csv
	Fish.csv
	Horse.csv
	Lizard.csv
	Monkey.csv
	makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerhw5] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerhw5]

4. Delete the obj files, executables, and core dump by
   %./make clean
