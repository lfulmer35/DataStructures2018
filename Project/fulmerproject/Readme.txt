*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSCI 2312           
*  HW#       : Battleship Project                
*  Due Date  : April 9, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a Battleship style game using three
separate classes as well as two derived classes. It allows
the user to place his/her ships by reading in ship locations
from a .csv file or by placing them manually. Then the game
alternates between the player and the computer opponent
firing torpedoes at each other. The game ends when one
player has sunk all of the opponents ships.

Completed extra credit part 1: Players must hit each 
location of a ship in order to sink it.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This file contains declarations and calls the playgame() 
function which drives the program.
   
Name: player.h
Header file for class Player. 

Name: player.cpp
Contains function definitions for class Player. This class
has two derived classes (HumanPlayer and Computer Player).

Name: WaterVehicle.h
Header file for class WaterVehicle.

Name: WaterVehicle.cpp
Contains member function definitions for the class.

Name: grid.h
Header file for class Grid.

Name: grid.cpp
Contains function definitions for class Grid. This class
creates the 10 x 10 grids used for the battleship board.

Name: ship_placement.csv
Contains ship starting locations for the user.

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
       % unzip [fulmerproject]

   Now you should see a directory named homework with the files:
        main.cpp
       	player.h
	player.cpp
	watervehicle.h
	WaterVehicle.cpp
	grid.h
	grid.cpp
	makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerproject] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerproject]

4. Delete the obj files, executables, and core dump by
   %./make clean
