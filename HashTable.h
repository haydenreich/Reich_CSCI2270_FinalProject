#include <string>
#include <vector>
#ifndef HASHTABLE_H
#define HASHTABLE_H

struct StringData{
    std::string value;
    StringData *next;
};

class HashTable
{
    public:
        HashTable();
        ~HashTable();
        void setHashSelection(int selection);
        void setTableSize(int tSize);
        void setASize(double aSize);
        int hashSum(std::string word);
        int hashMult(std::string word);
        int hashKnuth(std::string word);
        int hashCRC(std::string word);
        void hashStepByStep(std::string word);
        void insertData(std::string word);
        void scoreHashFunction(int n);
        void printTable();
        void clearTable();
    protected:
    private:
        int tableSize;
        double a;
        int hashSelection;
        int collisionCounter;
        std::vector<StringData*> hashTable;

};

#endif // HASHTABLE_H
