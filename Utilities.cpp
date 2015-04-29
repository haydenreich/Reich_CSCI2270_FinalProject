#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "Utilities.h"

using namespace std;

Utilities::Utilities(){}
Utilities::~Utilities(){}

void Utilities::readFile(string fileName){
    string strLine;
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
}

vector<string> Utilities::getWords(){
    return words;
}

void Utilities::clearWords(){
    words.clear();
}
