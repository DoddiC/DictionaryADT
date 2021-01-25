//
// Chidvi Doddi
// cdoddi
// 12B
// July 27th, 2019
// Description: This file is responsible for testing the Dictionary ADT files for errors, etc.
//


// DictionaryTest.c


// (required) import statements:
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// includes the header file
#include "Dictionary.h"

int main(int argc, char* argv[]){ // main method (to test if the Dictionary ADT works)
    
    Dictionary d = newDictionary(); // creates an object of the Dictionary class to help for testing methods, etc.
    
    char* s = "";
    
    //size() method test:
    printf("What's the size of the dictionary? %d", size(d)); // OUTPUT: What's the size of the dictionary? 0
    
    //Testing lookup() method:
    printf("What is the value? %s", lookup(d, "6")); // OUTPUT: What is the value? null
    
    //insert() method test:
    insert(d, "3", "rte"); // [it was inserted successfully]
    
    //isEmpty() method test:
    printf("Is the dictionary empty? %d", isEmpty(d)); // OUTPUT: Is
    //toString method test: the dictionary empty? false (correct because something was inserted)
    
     //toString method test:
    printf("Printing entire dictionary: "); // OUTPUT: Printing entire dictionary: \n 3 rte
    s = DictionaryToString(d); // prints the entire dictionary so far
     // printf(d->I_Numero);
    printf("%s\n", s);
    free(s);
    
    //size() method test:
    printf("What is the size of the dictionary? %d", size(d)); // OUTPUT: What is the size of the dictionary? 1
    
    //isEmpty() method test:
    printf("So is the dictionary empty? %d", isEmpty(d)); // OUTPUT: So is the dictionary empty? false
    
    //lookup() method test:
    printf("What is the value? %s", lookup(d, "10")); // OUTPUT: What is the value? null
    
    //another lookup() method test:
    printf("What is the value? %s", lookup(d, "3")); // OUTPUT: What is the value? rte
    
    //insert() method test:
    // OUTPUT: Exception in thread "main" DuplicateKeyException: Cannot insert duplicate keys
    insert(d, "50", "wow"); // if I put 5 of these lines, an exception should be thrown
    // insert(d, "50", "wow");
    // insert(d, "50", "wow");
    // insert(d, "50", "wow");
    // insert(d, "50", "wow");
    
    //toString method test:
    printf("Printing entire dictionary: "); // OUTPUT: Printing entire dictionary: 3 rte \n 20 def
    
    s = DictionaryToString(d); // prints the entire dictionary so far
    printf("%s\n", s);
    // printf(d->I_Numero);
    free(s);
    
    //size() method test:
    printf("What is the size of the dictionary? %d", size(d)); // OUTPUT: What is the size of the dictionary? 2
    
    //Negation of the isEmpty() method test:
    printf("Is the dictionary not empty? %d", !isEmpty(d)); // OUTPUT: Is the dictionary not empty? true
    
    //lookup() method test:
    printf("What is the value? %s", lookup(d, "20")); // OUTPUT: What is the value? null [correct output because nothing is there]
    
    //delete() method test:
    delete(d, "50");
    
    //toString method test:
    printf("Printing entire dictionary: "); // OUTPUT: Printing entire dictionary: 3 rte [correct output because an element got removed]
    s = DictionaryToString(d); // prints the entire dictionary so far
    printf("%s\n", s);
    // printf(d->I_Numero);
    free(s);
    
    printf("What is the size of the dictionary? %d", size(d)); // OUTPUT: What is the size of the dictionary? 1
    
    //delete() method test:
    // OUTPUT: Exception in thread "main" KeyNotFoundException: Cannot delete non-existent key
    // delete(d, "4");
    
    //delete() method test:
    delete(d, "3");
    
    //toString method test:
    printf("Printing entire dictionary: "); // OUTPUT: Printing entire dictionary: [the dictionary is empty again because all the elements were altered]
    // printDictionary(stdin, d);
    
    //size() method test:
    printf("What is the size of the dictionary? %d", size(d)); // OUTPUT: What is the size of the dictionary? 0
    
} // ends the main method

