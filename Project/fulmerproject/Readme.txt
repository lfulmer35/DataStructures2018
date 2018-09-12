*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : Final Project                
*  Due Date  : May 2, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
This program contains two simple database (Actor/Picture).
It allows the user to add, search, delete, modify movie
and actor files. The program uses various ADTs including
binary search trees and vectors. The databases can be printed
to a file, if the user desires.

Of note, the search functions are all case sensitive.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This file reads-in the two databases and calls the menu
function for the selected database.

Name: functions.h
Function declarations for menu functions.

Name: functions.cpp
Contains the functions for specific menus. Contains the
major driver functions for the program.

Name: actor.h
Header file for the Actor class.

Name: actor.cpp
Contains function definitions for the Actor class.

Name: pictures.h
Header file for Picture class.

Name: pictures.cpp
Contains function definitions for the Picture class.

Name: Node.h
Contains declarations and definitions for the Node class.

Name: BSTree.h
Header file for binary search tree(BST) class.

Name: BSTree.hpp
Contains function implementation for the BSTree class.

Name: actor-actress.csv
File containing actor/actress entries. This file is read-
in to the actor database.

Name: Pictures.csv
File containing picture entries. This file is read-in
to the picture database.


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
	functions.h
	functions.cpp
	Node.h
	actor.h
	actor.cpp
	pictures.h
	pictures.cpp
	BSTree.h
	BSTree.hpp
	actor-actress.csv
	pictures.csv
	makefile
	fulmerproject design document
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
