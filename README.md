# Reich_CSCI2270_FinalProject

#Project Summary:

This project tests different hash functions by allowing the user to compare the different load factors and collisions
present in different hash tables.  It takes in a .txt file and uses the information contained within to build a hash table.  The user can select from 3(to start) hash functions to test.  The user can also choose their desired table size, as well as the multiplication constant for the multiplication hash function.  The table can also be cleared in order to run multiple tests without exiting the program.  Constant values can be changed as often as desired.

#How to Run:

This project was built as a Code Blocks console project and can be run from that program on Linux OS or from the command line.  This program takes no adiitional command line arguments. Files needed to build the program are main.cpp, HashTable.h, and HashTable.cpp.  The .txt files are for testing purposes only.

#Dependencies:

Reich_CSCI2270_finalProject.cbp, main.cpp, HashTable.h, and HashTable.cpp.  1000word_test.txt and Movie_test.txt files are for testing purposes only.

#System Requirements:

Linux OS

#Group Members:

Solo project

#Contributors:

#Open issues/bugs:

There is a known bug with table size. The default is set at 1024, prime numbers above this value cause a segmentation fault.  This is primarily with the 1000 word test document, large table sizes are untested 
with the smaller movie document.
Incorrect inputs can also cause unpredictable errors, as the program is not currently set up to check the 
users input for accuracy.
Either one of these would be a great contribution to the project.

