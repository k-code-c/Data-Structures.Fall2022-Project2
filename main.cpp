//
//  main.cpp
//  project10
//
//  Created by Kc Ashiogwu on 10/14/22.
#include "HashTable_Chaining.h"
#include "HashTable_Quadratic.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
int main(int argc, char** argv){

     
    //this all works
    //
    fstream dictionaryFile(argv[1]);
    fstream inputFile(argv[2]);
    if(!dictionaryFile || !inputFile){
        cout << "Error in opening file of letters";
        return 1; //checks if the file openes
    }
    else {
        cout << "File opened" << endl;
        vector<string> Dictionary;
        vector<string> Input;
        string ToLoad;
        
        while (dictionaryFile >> ToLoad ) {
            Dictionary.push_back(ToLoad);
        }
        while(inputFile >> ToLoad){
            Input.push_back(ToLoad);
        }
        
        //CHAINING HASHTABLE
        HashTable_Chaining HC(Dictionary.size());
        //start timer construction
        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
        for(int i = 0; i<Dictionary.size(); i++){
            HC.insertItem(Dictionary.at(i));
        }
        //end timer construction
        chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
        //start timer spell check
        
        chrono::steady_clock::time_point t3 = chrono::steady_clock::now();
        
        int countChainingMisspelled = 0;
        for(int i = 0; i<Input.size(); i++){
            //I tried to implement it but I kept on getting errors
            //originalWord = input.at(i)
            //newWord = ""
            //for (char c: originalWord)
                //if (isalpha(c) || isdigit(c)
                    //newWord += tolower(c)
            
            //change line below to HC.searchTable(newWord)
            //TODO: Do the same thing for the probing one
            bool isFound = HC.searchTable(Input.at(i));
            if(isFound == false){
                countChainingMisspelled++;
            }
            
        }
        //end timer spell check
        chrono::steady_clock::time_point t4 = chrono::steady_clock::now();
        
        //Probing HASHTABLE
        HashTable_Quadratic HQ(Dictionary.size());
        //start timer construction
        chrono::steady_clock::time_point t5 = chrono::steady_clock::now();
        for(int i = 0; i<Dictionary.size(); i++){
            HQ.insertItem(Dictionary.at(i));
        }
        //end timer construction
        chrono::steady_clock::time_point t6 = chrono::steady_clock::now();
        //start timer spell check
        chrono::steady_clock::time_point t7 = chrono::steady_clock::now();
        int countProbingMisspelled = 0;
        for(int i = 0; i<Input.size(); i++){
            bool isFound = HQ.searchTable(Input.at(i));
            if(isFound == false){
                countProbingMisspelled++;
            }
            
        }
        //end timer spell check
        chrono::steady_clock::time_point t8 = chrono::steady_clock::now();
        
        unsigned long Chaining_insertTime = chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
        
        unsigned long Chaining_SpellCheck = chrono::duration_cast<chrono::nanoseconds>(t4-t3).count();
        
        unsigned long Probing_insertTime = chrono::duration_cast<chrono::nanoseconds>(t6-t5).count();
        
        unsigned long Probing_SpellCheck = chrono::duration_cast<chrono::nanoseconds>(t8-t7).count();
        /* Print out time taken to construct hashtable1.
         3. Perform spell check of inputFile. Keep track of the number of misspelled words.
         4. Print out time taken to perform spell checking with hashtable1 (i.e., time for Step 3).
         5. Print out the total number of words that hashtable1 considers misspelled. */
        
        cout << "Time to Construct HashTable1: " << Chaining_insertTime << endl;
        
        cout << "Time to Spell check Hashtable1: " << Chaining_SpellCheck << endl;
        
        cout << "The Number of misspelled words in HashTable1: " << countChainingMisspelled << endl;

        
        cout << "Time to Construct HashTable2: " << Probing_insertTime << endl;
        
        cout << "Time to Spell Check HashTable2: " << Probing_SpellCheck << endl;
        
        cout << "The Number of misspelled words in HashTable2: " << countProbingMisspelled << endl;

    }
    
    //int s;
    string S1; //string for the words
    //readfile is a stream of characters
    //you want to read
    //read file stores the elements inside the txt file and inserts it into the S1 string
    //a while loop to insert the items into the hashtable.
    
        
    //1 create Dictionary Vector
    //2 create Input Vector
    //Load words from dictionary file to dictionary vector
    //Load words from input file to input vector
    //Create the chaining hashtable
    //load the dictionary vector into the chaining hashtable
    //perform spell check of input file by searching for each value in input vector
    //do the same thing for the probing hashtable
        

    }
    

   
    
   // steady_clock::time_point t2 = steady_clock::now();
    
   // unsigned long insertTime = chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
    


