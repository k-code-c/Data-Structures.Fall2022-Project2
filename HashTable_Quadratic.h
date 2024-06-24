#include <iostream>
using namespace std;

class HashTable_Quadratic{
private:
    string* array;
    int size;
    int hashFunction(string key);
    bool isPrime(int n);
    int findNextLargestPrime(int LP);
public:
    HashTable_Quadratic(); //default constructor
    HashTable_Quadratic(int size); //constructor
    ~HashTable_Quadratic(); //destructor
    
    void insertItem(string key);
    
    bool searchTable(string key);
};
//idk if it should be in hashtable instead or not int needed. 
int HashTable_Quadratic::hashFunction(string key){
    unsigned int hashValue = 0;
    for(char ch: key){
        hashValue = 37* hashValue + ch;
    }
    return hashValue % size;
}

HashTable_Quadratic::HashTable_Quadratic(){
    array = new string[2]; //the size of the array always has to be a prime number
    size = 2;
}

HashTable_Quadratic::HashTable_Quadratic(int size){
    int ClosestPrime = findNextLargestPrime(size * 2);
    array = new string[ClosestPrime];
    this->size = ClosestPrime;
}
bool HashTable_Quadratic::isPrime(int n){
//helper function for findNextLargestPrime
    //edge cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    //This is checked so that we can skip
    //middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i+2) == 0)
            return false;

    return true;

}

int HashTable_Quadratic::findNextLargestPrime(int LP){//
    bool PrimeFound = isPrime(LP);
    while(PrimeFound!= true){
        LP = LP + 1;
        PrimeFound = isPrime(LP);
    }
    return LP;
    
}
//review these last lines
HashTable_Quadratic::~HashTable_Quadratic(){
    //TODO: Implement
    delete [] array;
}

void HashTable_Quadratic::insertItem(string key){
    //TODO: Implement
    //square the index to figure out where to go
    //check the lectures
    //take your key hash it and figure out where it should be and check if something is already there
    
    int pos = hashFunction(key);
    int i = 0;
    int ProbedIndex = pos;
    while(array[ProbedIndex]!= ""){
        ProbedIndex = (pos + i*i) % size;
        i++;
    }
    array[ProbedIndex] = key;
}

bool HashTable_Quadratic::searchTable(string key){
    //TODO: Implement
    
    int pos = hashFunction(key);
    int i = 0;
    int ProbedIndex = pos;
    while(array[ProbedIndex]!= ""){
        if(array[ProbedIndex] == key){
            return true;
        }
        ProbedIndex = (pos + i*i) % size;
        i++;
        
    }
    return false;
    
    
    
}
