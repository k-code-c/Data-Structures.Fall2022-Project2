/*1. Store lexicon in hashtable1, which uses chaining to handle collisions.
2. Print out time taken to construct hashtable1.
3. Perform spell check of inputFile. Keep track of the number of misspelled words.
4. Print out time taken to perform spell checking with hashtable1 (i.e., time for Step 3).
5. Print out the total number of words that hashtable1 considers misspelled.
6. Store lexicon in hashtable2, which uses quadratic probing to handle collisions.
7. Print out time taken to construct hashtable2.
8. Perform spell check of inputFile. Keep track of the number of misspelled words.
9. Print out time taken to perform spell checking with hashtable2 (i.e., time for Step 8).
10.  Print out the total number of words that hashtable2 considers misspelled. NOTE: this
number should be the same as the number for hashtable1.
11.  Print a final output that states which hash table was more time efficient.
No other outputs should be observed.
*/

#include<iostream>
#include<list>
#include<cstring>
#include<fstream>

using namespace std;

//chaining
class Node{
    public:
        Node* next;
        string word;

        Node();
        Node(string word); //overloaded constructor
};

class HashTable_Chaining{
private:
    Node**table;
    int hashGroups; //number of elements in the hash table
    // do not assingn a number bc the file is being read in
    int hashFunction(string key);
    void appendWord(int hashKey, string newWord); //append word to the end of a buckets linked list
public:
    HashTable_Chaining(int size); //constrcutor
    ~HashTable_Chaining(); //destrcutor
    //checks if the table is empty
    //ool isEmpty() const;
    //inserts a key into the hashtable
    void insertItem(string key);

    //deletes a key from the hash table
    //void deleteItem(int key);

    //hash function to map values to key
    
    bool searchTable(string key); //checks if the word exists true or false
    //displays the items in the hashtable
    
};

Node::Node(){ //tells an object how to build itself
    next = NULL;
    word = "";
}

Node::Node(string word){ //allows for specific attributes
    next = NULL;
    this->word = word; //setting the private data member equal to parameter
}


HashTable_Chaining::~HashTable_Chaining(){
    //TODO: IMPLEMENT THIS
    for(int i = 0; i < hashGroups; i++){
        Node* temp = table[i];
        while(temp!= NULL){
            Node* deleteme = temp;
            temp = temp->next;
            delete deleteme;
        }
    }
}

HashTable_Chaining::HashTable_Chaining(int size){ //constructor
    table = new Node*[size];//allaocting an array of the given size of pointers and those pointers are pointers to nodes
    for(int i = 0; i < size; i++){
        table[i] = NULL;
    }
    hashGroups = size; //setting the size
}

//ask for help with this
void HashTable_Chaining::insertItem(string newWord){ //working
    int key = hashFunction(newWord);
    appendWord(key, newWord);
}

//we dont count lines we count words
void HashTable_Chaining::appendWord(int hashKey, string newWord){
    //TODO: implement
    Node* temp = table [hashKey]; //it will give us the memory address for the linked list
    while(temp!=NULL && temp->next != NULL) {
        temp = temp->next; //moving the temp pointer
    }
    Node* newNode = new Node(newWord); //creating a
    if(temp!=NULL)
        temp->next = newNode;
    else
        table[hashKey] = newNode;
}
//an array of pointers
int HashTable_Chaining::hashFunction(const string key){ //works
    unsigned int hashValue = 0;
    for(char ch: key){
        hashValue = 37* hashValue + ch;
    }
    return hashValue % hashGroups;
}

bool HashTable_Chaining::searchTable(string key){
    //goes through each element to check if it exists
    int index = hashFunction(key);
    Node* temp = table[index];
    while(temp!= NULL){
        if(temp->word == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
    //1 hash the key to get index
    //2 get the pointer to the beginning of chain at that index
    //3 loop through "chain" (linked list)
    //4 check every node in the linked list for the key
    //5 if we find it, return true
    //6 if we loop through entire chain and don't find it, return false
}
