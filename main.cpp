#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "HashTable.h"

using namespace std;

int main(int argc, char *argv[])
{
    HashTable *hashTest = new HashTable;
    string fileName;
    cout<<"Enter a file to test: "<<endl;
    getline(cin, fileName);
    vector<string> words;
    string strLine;
    int userInput;
    ifstream inFile;
    inFile.open(fileName);
    if(inFile.fail()){
        cout<<"The file did not open successfully"<<endl;
    }
    else{
        while(!inFile.eof()){
            getline(inFile, strLine);
            words.push_back(strLine);
        }
    }
    inFile.close();
    cout<<"Welcome to the Hash Function Test"<<endl;
    cout<<"1. Set custom table size"<<endl;
    cout<<"2. Select hash function"<<endl;
    cout<<"3. Load test table"<<endl;
    cout<<"4. Print hash table"<<endl;
    cout<<"5. Score hash function"<<endl;
    cout<<"6. Clear hash table"<<endl;
    cout<<"7. Enter table values manually"<<endl;
    cout<<"8. Quit"<<endl;
    cin>>userInput;
    cin.ignore(10000,'\n');
    //loop only calls functions in class definition
    //all void functions, so main does nothing but the user loop
    while(userInput != 8){
        if(userInput == 1){
            int size_in;
            char yesNo;
            double a_in;
            cout<<"Please enter your desired table size: "<<endl;
            cin>>size_in;
            hashTest->setTableSize(size_in);
            cout<<"Set custom multiplication constant? y/n"<<endl;
            cin>>yesNo;
            if(yesNo == 'y'){
                cout<<"Please enter your constant (0<x<1): "<<endl;
                cin>>a_in;
                hashTest->setASize(a_in);
            }
        }
        if(userInput == 2){
            int select_In;
            cout<<"Please select which function you would like to test:"<<endl;
            cout<<"1. Division method (hashSum from assignment 9)"<<endl;
            cout<<"2. Multiplication method"<<endl;
            cout<<"3. Knuth Division method"<<endl;
            cin>>select_In;
            hashTest->setHashSelection(select_In);

        }
        if(userInput == 3){
            for(int i=0; i<words.size(); i++){
                hashTest->insertData(words[i]);
            }
        }
        if(userInput == 4){
            hashTest->printTable();
        }
        if(userInput == 5){
            hashTest->scoreHashFunction(words.size());
        }
        if(userInput == 6){
            hashTest->clearTable();
        }
        if(userInput == 7){
            string word;
            cout<<"Enter a word to add: "<<endl;
            getline(cin, word);
            hashTest->insertData(word);
        }
        cout<<"-------Main Menu-------"<<endl;
        cout<<"1. Set custom table size"<<endl;
        cout<<"2. Select hash function"<<endl;
        cout<<"3. Load test table"<<endl;
        cout<<"4. Print hash table"<<endl;
        cout<<"5. Score hash function"<<endl;
        cout<<"6. Clear hash table"<<endl;
        cout<<"7. Enter table values manually"<<endl;
        cout<<"8. Quit"<<endl;
        cin>>userInput;
        cin.ignore(10000,'\n');
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
