#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "HashTable.h"
#include "Utilities.h"

using namespace std;

int main(int argc, char *argv[])
{
    HashTable *hashTest = new HashTable;
    Utilities *utils = new Utilities;
    vector<string> words;
    string fileName;
    if(argv[1] != NULL) {
        fileName = argv[1];
        utils->readFile(fileName);
        words = utils->getWords();
    }
    int userInput;
    cout<<"Welcome to the Hash Function Test"<<endl;
    cout<<"1. Set custom table size"<<endl;
    cout<<"2. Select hash function"<<endl;
    cout<<"3. Load test table"<<endl;
    cout<<"4. Print hash table"<<endl;
    cout<<"5. Score hash function"<<endl;
    cout<<"6. Clear hash table"<<endl;
    cout<<"7. Enter table values manually"<<endl;
    cout<<"8. Load a file to test"<<endl;
    cout<<"9. Quit"<<endl;
    cin>>userInput;
    if(!cin)
    {
        cout<<"That is not a valid input. Please try again."<<endl;
        cin.clear();
        userInput = 0;
    }
    cin.ignore(10000,'\n');
    //loop only calls functions in class definition
    //all void functions, so main does nothing but the user loop
    while(userInput != 9){
        if(userInput == 1){
            int size_in;
            char yesNo;
            double a_in;
            cout<<"Please enter your desired table size: "<<endl;
            cin>>size_in;
            if(!cin)
            {
                cout<<"That is not a valid input. Please try again."<<endl;
                cin.clear();
            }
            else if(size_in < 1)
                cout<<"Table size must be greater than 0"<<endl;
            else
            {
                hashTest->setTableSize(size_in);
                cout<<"Set custom multiplication constant? y/n"<<endl;
                cin>>yesNo;
                if(yesNo == 'y'){
                    cout<<"Please enter your constant (0<x<1): "<<endl;
                    cin>>a_in;
                    if(!cin)
                    {
                        cout<<"That is not a valid input. Please try again."<<endl;
                        cin.clear();
                    }
                    else
                        hashTest->setASize(a_in);
                }
            }
        }
        if(userInput == 2){
            int select_In;
            cout<<"Please select which function you would like to test:"<<endl;
            cout<<"1. Division method (hashSum from assignment 9)"<<endl;
            cout<<"2. Multiplication method"<<endl;
            cout<<"3. Knuth Division method"<<endl;
            cout<<"4. CRC method"<<endl;
            cin>>select_In;
            if(!cin)
            {
                cout<<"That is not a valid input. Please try again."<<endl;
                cin.clear();
            }
            else if(select_In < 5 && select_In > 0)
                hashTest->setHashSelection(select_In);
            else
                cout<<"That is not a valid input. Please try again."<<endl;

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
            words.push_back(word);
        }
        if(userInput == 8){
            cout<<"Please enter a file name:"<<endl;
            getline(cin, fileName);
            utils->clearWords();
            utils->readFile(fileName);
            words.clear();
            words = utils->getWords();
        }
        cout<<"-------Main Menu-------"<<endl;
        cout<<"1. Set custom table size"<<endl;
        cout<<"2. Select hash function"<<endl;
        cout<<"3. Load test table"<<endl;
        cout<<"4. Print hash table"<<endl;
        cout<<"5. Score hash function"<<endl;
        cout<<"6. Clear hash table"<<endl;
        cout<<"7. Enter table values manually"<<endl;
        cout<<"8. Load a file to test"<<endl;
        cout<<"9. Quit"<<endl;
        cin>>userInput;
        if(!cin)
        {
            cout<<"That is not a valid input. Please try again."<<endl;
            cin.clear();
            userInput = 0;
        }
        cin.ignore(10000,'\n');
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
