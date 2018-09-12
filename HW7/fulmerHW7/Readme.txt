*******************************************************
*  Name      : Lucas Fulmer          
*  Student ID: 108963697                
*  Class     : CSC 2421           
*  HW#       : 7                
*  Due Date  : March 29, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
This program reads-in a list of arrival times and transaction
times. It then simulates customers arriving, waiting in line, 
conducting transactions, and departing. I used the
algorithm from the book for the basis of my program. The 
program then outputs the results in the format: customer,
arrival time, departure time, and wait time.



*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
This file contains the struct "Event" used throughout the
program. The program is entirely contained within main.


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
       % unzip [fulmerhw7]

   Now you should see a directory named homework with the files:
        main.cpp
	makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [fulmerhw7] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[fulmerhw7]

4. Delete the obj files, executables, and core dump by
   %./make clean
