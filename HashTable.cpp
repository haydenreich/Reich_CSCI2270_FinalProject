#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include "HashTable.h"


using namespace std;

HashTable::HashTable(){
    tableSize = 1024;
    for(int i=0; i<tableSize; i++){
        hashTable.push_back(NULL);
    }
    a = 13.0/32.0;
    collisionCounter = 0;
}

HashTable::~HashTable(){
    //hashTable.erase(0, tableSize-1);
}
/*
This method clears the table by cyclying through the hash table and setting each value
to NULL.  It also resets the collision counter to 0 so additional tests can be run with accurate output.
*/
void HashTable::clearTable(){
    for(int i=0; i<tableSize; i++) hashTable[i] = NULL;
    collisionCounter = 0;
}
//This allows the user to set the private variable hashSelection
void HashTable::setHashSelection(int selection){
    hashSelection = selection;
}
// This allows the user to set the private variable tableSize
void HashTable::setTableSize(int tSize){
    tableSize = tSize;
}
// This allows the user to set the private variable a, used in the multiplication function
void HashTable::setASize(double aSize){
    a = aSize;
}
/*
This method calculates hash values by taking the modulo of the sum of of all characters in the string to be stored
by the table size.  This is the same function used in assignment 9, and covered in lecture.
*/
int HashTable::hashSum(string word){
    int sum = 0;
    for(int i=0; i<word.length(); i++){
        sum = sum + word[i];
    }
    sum = sum%tableSize;
    return sum;
}
/*
This method calculates the hash index by using the multiplication method described in lecture
*/
int HashTable::hashMult(string word){
    long double product;
    int sum = 0;
    for(int i=0; i<word.length(); i++)
        sum = sum+word[i];
    product = sum*a;
    //cout<<product<<endl;
    int intPart = (int)product;
    //cout<<intPart<<endl;
    double decimal = product - intPart;
    //cout<<decimal<<endl;
    int finalSum;
    finalSum = decimal*tableSize;
    return finalSum;
}
/*
This method calculates the has index using the Knuth Division method.  Similar to the first method, this takes
the sum multiplied by the sum plus three, then modulo the table size
*/
int HashTable::hashKnuth(string word){
    int sum = 0;
    for(int i=0; i<word.length(); i++){
        sum = sum + word[i];
    }
    sum = sum*(sum+3)%tableSize;
    return sum;
}
/*
Function Prototype:
int HashTable::hashCRC(string)

Function Description:
This function was taken from http://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
It takes the intended index value of h and does a 5-bit left circular shift.  It then
XOR's in each integer value from the input word.

Example:
HashTable ht;
ht.hashCRC("example");

Precondition:
User desires to find the hash index for a given string
Postcondition:
Chosen string is assigned an index location based on the private variable tableSize
*/
int HashTable::hashCRC(string word){
    unsigned int highOrder;
    unsigned int h = 0;
    highOrder = h & 0xf8000000;
    for(int i=0; i<word.length(); i++){
        h = h << 5;
        h = h ^ (highOrder >> 27);
        h = h ^ (unsigned int)word[i];
    }
    return h%tableSize;
}
/*
Function prototype:
void HashTable::insertData(string)

Function description:
This method inputs strings into the hash table.  It uses the private variables tableSize and hashSelection
in order to call the relevant hashing function.  It uses an unsorted linked list to handle collisions.

Example:
HashTable ht;
ht.insertData("hello world");

Precondition:
Unused location in hash table are NULL, locations with values stored are the head of a linked list.
Postcondition:
Function argument is stored as the value in a new StringData struct, the hash index is calculated using
the selected hasing function and the String Data struct is either stored at a new index or appended to an existing
linked list
*/
void HashTable::insertData(string word){
    StringData *newData = new StringData;
    newData->value = word;
    newData->next = NULL;
    int index;
    if(hashSelection == 1)
        index = hashSum(word);
    else if(hashSelection == 2)
        index = hashMult(word);
    else if(hashSelection == 3)
        index = hashKnuth(word);
    else if(hashSelection == 4)
        index = hashCRC(word);
    if(hashTable[index] == NULL)
        hashTable[index] = newData;
    else{
        StringData *temp = new StringData;
        temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newData;
        collisionCounter++;
    }
}
/*
This method prints the hash table.  Each occupied index is printed on its own line, linked lists are indicated
with arrows.  If the table is empty, it prints "empty".
*/
void HashTable::printTable(){
    int counter = 0;
    for(int i=0; i<tableSize; i++){
        StringData *temp = hashTable[i];
        while(temp != NULL){
            if(temp->next == NULL){
                cout<<temp->value<<endl;
            }
            else{
                cout<<temp->value<<"--->";
            }
            temp = temp->next;
            counter++;
        }
    }
    if(counter == 0){
        cout<<"empty"<<endl;
    }
}
/*
Function Prototype:
void HashTable::scoreHashFunction(int)

Function Description:
This method outputs two methods of scoring tested hash function.  First it displays the load factor for the table,
which is dependant on both the table size and the number of items in the table.  Second, it prints the number of
collisions that occured when adding all data to the table.  This is stored as a private variable and counted
during the input method.

Example:
HashTable ht; //hash table of with n items stored in it
ht.scoreHashFunction(n);

Precondition:
This method requires a hash table to be already built.  When called in main, it uses the std::vector.size() to
determine n.
Postcondition:
The hash table is not changed at all, only effect is the two values are printed to the user.
*/
void HashTable::scoreHashFunction(int n){
    double loadFactor = (double)n/tableSize;
    cout<<"The load factor for this table is: "<<loadFactor<<endl;
    cout<<"There were: "<<collisionCounter<<" collisions."<<endl;
}
