*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSCI 2312           
*  HW#       : 3                
*  Due Date  : FEB 21, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a version of the Battleship game.
It allows the user to place ships on the 10x10 board and
then fires 15 randomly generated torpedoes. The program
will calculate the number of hits as well as if any ships
were sunk.

The program uses two classes: WaterVehicle and Grid.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This is the driver of the program. Contains a menu to 
allow the user to play the game or edit ship lengths.
   
Name: WaterVehicle.h
This is the header file for the WaterVehicle and Grid class.      

Name:  grid.cpp   
Contains function definitions for the grid class which
creates the 10x10 game board.

Name:  WaterVehicle.cpp
Contains function definitions for the WaterVehicle class
as well as friend functions and operator overloads.   


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
       % unzip [fulmerhw3]

   Now you should see a directory named homework with the files:
        main.cpp
        WaterVehicle.h
	WaterVehicle.cpp
        grid.cpp
	makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerhw3] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerhw3]

4. Delete the obj files, executables, and core dump by
   %./make clean
