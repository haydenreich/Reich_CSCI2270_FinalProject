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

void HashTable::clearTable(){
    for(int i=0; i<tableSize; i++) hashTable[i] = NULL;
    collisionCounter = 0;
}

void HashTable::setHashSelection(int selection){
    hashSelection = selection;
}

void HashTable::setTableSize(int tSize){
    tableSize = tSize;
}

void HashTable::setASize(double aSize){
    a = aSize;
}

int HashTable::hashSum(string word){
    int sum = 0;
    for(int i=0; i<word.length(); i++){
        sum = sum + word[i];
    }
    /*
    while(sum<tableSize){
        sum = sum*10;
    }
    */
    sum = sum%tableSize;
    return sum;
}

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

int HashTable::hashKnuth(string word){
    int sum = 0;
    for(int i=0; i<word.length(); i++){
        sum = sum + word[i];
    }
    sum = sum*(sum+3)%tableSize;
    return sum;
}

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

void HashTable::scoreHashFunction(int n){
    double loadFactor = (double)n/tableSize;
    cout<<"The load factor for this table is: "<<loadFactor<<endl;
    cout<<"There were: "<<collisionCounter<<" collisions."<<endl;
}
