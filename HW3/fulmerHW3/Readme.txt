*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : 3                
*  Due Date  : Feb 15, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program has a menu which allows the user to read-in
vehicles. After reading in, the user has the option to 
use recursive or iterative searches in order to search
for vehicles by year or by make. The program sorts the
vehicle vector when a search call is made.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This file contains the menu which allows the user to read
in or search the vector of cars.

Name: vehiclein.txt
Text file containing eight vehicles.

Name: vehicle.h
Header file for the vehicle class. 

Name: vehicle.cpp
Function definitions for class vehicle.


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
       % unzip [fulmerHW3]

   Now you should see a directory named homework with the files:
        main.cpp
	setInput.txt
	vehicle.h
	vehicle.cpp
	makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerHW3] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerHW3]

4. Delete the obj files, executables, and core dump by
   %./make clean
