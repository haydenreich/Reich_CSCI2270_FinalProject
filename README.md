# Reich_CSCI2270_FinalProject

#Project Summary:

This project tests different hash functions by allowing the user to compare the different load factors and collisions present in different hash tables.  It takes in a .txt file either as a command line argument or in a separate menu option, and uses the information contained within to build a hash table.  The user can select from 4 hash functions to test.  The user can also choose their desired table size, as well as the multiplication constant for the multiplication hash function.  The table can also be cleared in order to run multiple tests without exiting the program.  Constant values can be changed as often as desired.

Hash functions 1, 3 and 4 work best with a prime table size.  Hash function 2 works best with a tablesize that is a  multiple of 2. 

And don't forget to build the table before trying to print and score!

#How to Run:

This project was built as a Code Blocks console project and can be run from that program on Linux OS or from the command line.  This program takes one optional command line argument, the name of the file to test. Files needed to build the program are main.cpp, HashTable.h, and HashTable.cpp, Utilities.h, and Utilities.cpp.  The .txt files are for testing purposes only.
Must include the build option: [-std=c++0x].  In Code Blocks: Project>Build Options>Flag appropriate option.

Steps:

1. Once program has started, load the text file you wish to test. The program will store each line as a seperate string, so any .txt file formatted appropriately will work.

2. You can than choose the table size you wish. Default values are set as table size: 1024, multiplication constant: 13/32.

3. The user then selects which hash function they would like to use to calculate the indices for the hash table.\n

4. The user should then select the option to build the table.

5. Once the table is built, it can then be printed and scored.

6. If the user would like to test a different function, they can clear the table, which resets all score counters and resets the table values to NULL.

7. Be sure to rebuild the table before printing or scoring.

8. Select the number for quit to exit the program.

#Dependencies:

Reich_CSCI2270_finalProject.cbp, main.cpp, HashTable.h, and HashTable.cpp, Utilities.h, Utilities.cpp.  1000word_test.txt and Movie_test.txt files are for testing purposes only.  There are no third party libraries.

#System Requirements:

Linux OS. Must include the buildoption: [-std=c++0x].  In Code Blocks: Project>Build Options>Flag appropriate option.

#Group Members:

Solo project

#Contributors:

#Open issues/bugs:

There is a known bug with table size. The default is set at 1024, some numbers above this value cause a segmentation fault.  This occurs with both test documents.

Fixed, thanks to ridy0663 - Incorrect inputs can also cause unpredictable errors, as the program is not currently set up to check the user's input for accuracy. - Fixed

Either one of these would be a great contribution to the project.

 
