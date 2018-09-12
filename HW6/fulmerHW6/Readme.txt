*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : 6                
*  Due Date  : March 8, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program creates a class Dictionary which contains a 
stl<list> of type DictEntry. It reads-in a list of 
DictEntries from a .txt file and sorts them. The program
then reads-in a second list and compares the two lists.
The program then prints the words that were found in both
lists and the number of searches that were necessary to 
find the matching words. The list is searched forwards
and in reverse. Lastly the list is written to a .txt 
file in reverse (descending) order.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This file calls all functions and displays the functionality
of the program.

Name: dictionary.txt
Text file which is read-in to our dictionary list.

Name: findwords.txt
Text file containing list of words to search for. 

Name: dictionary.h
Header file for dictionary class.

Name: dictionray.cpp
Function definitions for dictionary class

Name: DictEntry.h
Header file with inline definitions for DictEntry class.

Name: DictEntry.cpp
Contains definition for friend function which overloads
the operator<< in order to print objects.


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
	dictionary.h
	dictionary.cpp
	DictEntry.h
	DictEntry.cpp
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
