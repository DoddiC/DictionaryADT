//
// Chidvi Doddi
// cdoddi
// 12B
// August 11th, 2019
// Description: This C file is responsible for the hash table implementation of the Dictionary ADT.
//


// Dictionary.c


// import statements:
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>


// [imports the header file for the Dictionary ADT]:
#include "Dictionary.h" // includes the header (.h) file

// int physicalSize; // int var.

//constant:
const int tableSize = (101); // According to the lab pdf, it is required to have a constant for the size of the hash table

// METHOD FROM LAB PDF:
// rotate_left()
// this method rotate the bits in an unsigned int
//
unsigned int rotate_left(unsigned int value, int shift) { // method header
    int sizeInBits = (8) * sizeof(unsigned int);
    shift = shift & (sizeInBits - 1);
    if ( shift == 0 )
        return value;
    return (value << shift) | (value >> (sizeInBits - shift));
} // end method

// METHOD FROM LAB PDF:
// pre_hash()
// this method turns a string into an unsigned int
//
unsigned int pre_hash(char* input) { // method header
    unsigned int result = 0xBAE86554;
    
    while (*input) {
        result ^= *input++;
        result = rotate_left(result, 5);
    }
    
    return result;
} // end method

// METHOD FROM LAB PDF:
// hash()
// this method turns a string into an int in the range 0 to tableSize-1
//
int hash(char* key){ // method header
    return pre_hash(key) % (tableSize);
} // end method

// (Node) private types ----------------------------------------------------------------

// Node struct (with vars.)
//
typedef struct NodeObj{ // Node struct
    
    // variables (of char literals and a struct):
    char* nOde_key;
    char* val_noDe;
    
    struct NodeObj* next;
} NodeObj; // end NodeObj struct

// Node struct:
typedef NodeObj* Node;

// newNode() constructor
// constructor for the Node type
// return type: Node
//
Node newNode(char* k, char* v){ // newNode() constructor
    
    Node n_Ode = malloc(sizeof(NodeObj)); // creates a Node object n_Ode
    
    // NULL CHECK:
    assert(!(n_Ode == (NULL)));
    
    // n_Ode->physicalSize = Initial_len;
    n_Ode->val_noDe = v;
    n_Ode->nOde_key = k;
    
    n_Ode->next = NULL; // initial val. of this should be NULL
    
    return n_Ode; // DON'T FORGET TO RETURN NODE AT THE END OF THE METHOD
    
} // end newNode() constructor

// freeNode() destructor
// destructor for the Node type
// return type: void
//
void freeNode(Node* pN){ // freeNode() method
    
    // NULL CHECK:
    if(!((pN == NULL) || (*pN == NULL))){ // if
        
        // free(next);
        free(*pN);
        // *pN = *pN; // does this cause a segmentation fault?????
        *pN = NULL;
    } // end if
} // end freeNode() method

// DictionaryObj struct
//
typedef struct DictionaryObj{ // DictionaryObj struct
    // Node T_OP; // top/head node
    //Node middleNode;
    ///Node bottomNode;
    Node *table;
    int I_Numero; // numOfItems (in this case, the quantity of objects)
} DictionaryObj; // end struct

//private helper functions ---------------------------------------------------

////find_n0de_kEY()
////arguments: (Dictionary D) (char* k)
////function: loops goes through Dictionary LinkedList to search for Node at 'key'
////return: Node with specified key (if found), null (if not found)
//Node find_n0de_kEY(Dictionary D, char* k){
//    Node N;
//
//    N = D->table[hash(k)]; // calls the hash() function and then sets the node
//    while(!(N == NULL)){ // while
//
//        if (strcmp(N->nOde_key, k) == 0){ // if found
//            return N; //
//        }
//
//        N = N->next; // incrementer
//    } // end while
//
//    return NULL; //default return statement (could also return -1)
//} // end find_n0de_kEY() method

// (Dictionary) public functions -------------------------------------------------------


// Dictionary struct def. ((DON'T NEED))
// typedef struct DictionaryObj* Dictionary;


// newDictionary() constructor
// constructor for the Dictionary type
//
Dictionary newDictionary(){ // newDictionary() constructor
    
    Dictionary d_ict = malloc(sizeof(DictionaryObj));
    
    assert(!(d_ict == (NULL))); // checks if the Dictionary object ( created with using malloc() ) is NULL
    
    // d_ict->T_OP = calloc(Initial_len, sizeof(int)); // use calloc() cause we are creating an array
    
    d_ict->I_Numero = 0;
    
    // table var. heap memory creation:
    d_ict->table = calloc(tableSize, sizeof(Node));
    
    // d_ict->physicalSize = Initial_len;
    
    return d_ict;
} // end newDictionary() constructor


// freeDictionary()
// destructor for the Dictionary type
void freeDictionary(Dictionary* pD){ // freeDictionary() method
    
    // NULL CHECK:
    if(!((pD == NULL) || (*pD == NULL))){
        
        if( !(isEmpty(*pD)) ){ // if
            makeEmpty(*pD); // *calls the makeEmpty() method*
        }
        
        free((*pD)->table); // free the memory because of the use of calloc
        free(*pD);
        // *pD = *pD; // does this cause a segmentation fault?????
        *pD = NULL;
    }
} // end freeDictionary() method


// isEmpty() method
// Returns true (1) if S is empty
// return type: int
// pre: none
//
int isEmpty(Dictionary D){ // isEmpty() method
    
    // NULL check:
    if(!(D != NULL)){ // if
        char* isEmpty_error = "Dictionary Error: calling isEmpty() on NULL Dictionary reference\n"; // err. string literal
        
        fprintf(stderr, "%s", isEmpty_error);
        exit(EXIT_FAILURE);
        
    } // end if
    
    return (!(D->I_Numero != (0))); // returns true (1) if the condition is satisfied; returns false if this condition evaluates to false
} // end isEmpty() method

// size() method
// returns, in D, the number of (, v) pairs
// pre: none
//
int size(Dictionary D){ // size() method
    
    // NULL check:
    if(!(D != NULL)){ // if
        char* size_error = "Dictionary Error: calling size() on NULL Dictionary reference\n"; // err. string literal
        
        // error printing:
        fprintf(stderr, "%s", size_error);
        exit(EXIT_FAILURE);
        
    } // end if
    
    return (D->I_Numero);
} // end size() method

// lookup() method
// returns the value v such that (k, v) is in D, or returns NULL if no
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* k){ // lookup() method
    
    // Dictionary d;
    int y = 0;
    Node N; // node var.
    char* lookup_err_out = "Dictionary Error: calling lookup() on NULL Dictionary reference\n";
    
    // NULL check:
    if(!(D != NULL)){
        fprintf(stderr, "%s", lookup_err_out);
        exit(EXIT_FAILURE);
    } // end if
    
    N = D->table[hash(k)]; // uses the hash() function to set the node to something
    
    while(!(N == NULL)){ // while
        
        if (!(strcmp(N->nOde_key, k) != 0)){ // if found
            return N->val_noDe; //
        } // end if check (uses strcmp())
            
        N = N->next; // incrementor
    }

    y += 6;
    
    //printf(y);
    
    return NULL; // default return statement
} // end lookup() method

// insert() method
// inserts new (key,value) pair into D
// pre: lookup(D, k)==NULL
void insert(Dictionary D, char* k, char* v){ // insert() method
    // Dictionary d;
    // Node z_Node;
    Node no_N_de;
    
    // string literal:
    char* insert_er_out = "Dictionary Error: calling insert() on NULL Dictionary reference\n";
    
    char* dup_insert_er_out = "Dictionary Error: calling insert() on Duplicate key\n";

    // NULL check:
    if(!(D != NULL)){
        fprintf(stderr, "%s", insert_er_out);
        exit(EXIT_FAILURE);
    }
    
    // checks if the node is found, first:
    if(!(lookup(D, k) == NULL)){
        fprintf(stderr, "%s", dup_insert_er_out);
        exit(EXIT_FAILURE);
        
    }else{
        
        no_N_de = newNode(k, v); // creates a new Node
        
        if(!(D->table[hash(k)] == NULL)){ // if
            
            no_N_de->next = D->table[hash(k)];
            
            // z_Node = newNode(k,v); // creation of node
            
            D->table[hash(k)] = no_N_de; // sets the table to the node
        }else{
            // z_Node = NULL;
            D->table[hash(k)] = no_N_de; // sets the table to the node
        } // end if-else
        
        
        // z_Node = newNode(k,v);
        
        // D->table[h ash(k)] = (node_N);
        
        (D->I_Numero) += 1;
        // printf(D->I_Numero); // print check
        
        // z_Node = D->I_Numero;
        
        // printf(D->I_Numero); // print check
        // return; // return statement
    } // end if-else
} // end insert() method

// delete() method
// deletes the pair with the key k
// pre: !(lookup(D, k) == NULL)
//
void delete(Dictionary D, char* k){ // delete() method
    
    // Node vars.:
    Node pN; //
    Node N;
    
    // string literal:
    char* delete_err_NULL_out = "Dictionary Error: calling delete() on Dictionary reference not present\n";
    
    if(lookup(D, k) != NULL){ // if-else (nested)
        int x;
        N = D->table[hash(k)];
        x = 4;
        //printf("%s -- %s\n", N->key, k);
        if(!(strcmp(N->nOde_key, k) == 0)){
            pN = N->next;
        }else{
            //Node temp = D->top;
            D->table[hash(k)] = (N)->next; //
            freeNode(&N);
            //freeNode(&D->top);
            (D->I_Numero) -= 1;
            return;
        } // end if-else
        
        while(!(N->next == NULL)){ // while
            
            if(!(pN == NULL)){ //       if
                x = 4454;
            } // end        if
            
            if(!(strcmp(N->next->nOde_key, k) == 0)){ // if
                N = N->next; // incrementer
            }else{
                Node t_ = N->next; // temporary Node used for doing N->next
                N->next = (t_)->next; //
                freeNode(&t_);
                
                x += 5;
                
                // print(D->I_Numero);
                (D->I_Numero) -= 1; // decrement
                // print(D->I_Numero);
                return;
            }
        } // end while
    }else{
        
        // prints the error out.:
        fprintf(stderr, "%s", delete_err_NULL_out);
        exit(EXIT_FAILURE);
    }
} // end delete() method

// makeEmpty() method
// re-sets D to the empty state.
// pre: none
//
void makeEmpty(Dictionary D){ // method header
    
    Node N; // node initialized
    
    int i = 0;
    while((i < tableSize)){ // while
        
        while(!(D->table[i] == NULL)){ // while
            
            if(NULL == NULL){ // if
                N = D->table[i];
                D->table[i] = N->next;
                
                freeNode(&N); // frees the node because of the use of malloc and calloc before
                
                N = NULL;
            } // end if condition
            
        } // end while
        // incrementor:
        i += 1;
    }
    
    // reset the num. of objects:
    D->I_Numero = (0);
    
} // end method

// ctr_traverse_chars() method
// counts the number of chars using the node key and node value
//
int ctr_traverse_chars(Dictionary D){ // ctr_traverse_chars() method
    // int i;
    // printf("3333"); // test
    Node pN; // node
    int x = 0;
    
    int val_OF_sum = 0; // sum var.
    // printf("3454"); // test
    int i = 0;
    while(!(i >= tableSize)){ // while
        pN = D->table[i];
        // printf("587849"); // test
        while(!(pN == NULL)){ // while
            
            val_OF_sum = val_OF_sum + ((int) (strlen(pN->val_noDe) + 3 + strlen(pN->nOde_key)));
            val_OF_sum += 0;
            
            x = x + 9;
            
            pN = pN->next; // incrementer
        }
        
    i += 1;
        
    } // end while
    
    return val_OF_sum; // returns the sum
} // end ctr_traverse_chars() method

// DictionaryToString()
// Determines a text representation of the current state of Dictionary D. Each
// (key, value) pair is represented as the chars in key, followed by a space,
// followed by the chars in value, followed by a newline '\n' char. The pairs
// occur in the same order they were inserted into D. The function returns a
// pointer to a char array, allocated from heap memory, containing the text
// representation described above, followed by a terminating null '\0' char.
// It is the responsibility of the calling function to free this memory.
char* DictionaryToString(Dictionary D) { // DictionaryToString() method
    
    char* out; // string literal (allocated from heap)
    
    // int var.
    int length = 0;
    length  = (100 + 100);
    
    // string (char*) literal:
    char* DictTOsTRING_err = "Dictionary Error: calling DictionaryToString() on NULL Dictionary reference\n";
    
    char te_m_p[length]; // sets the temporary array to a certain length
    
    // vars.:
    Node N;
    int numOfChars; // int
    Node L;
    
    // NULL check:
    if(!(D != NULL)){ // if
        fprintf(stderr, "%s", DictTOsTRING_err);
        exit(EXIT_FAILURE);
    } // end if
    
    numOfChars = ctr_traverse_chars(D); // initializes the numOfChars var. by calling the ctr_traverse_chars() method
    
    out = calloc(((numOfChars) + 1), sizeof(char)); // allocated from heap mem.
    
    int y = 0;
    int i = 0;
    while(!(i >= tableSize)){ // while
    
        //
        L = D->table[i];
        //
        N = D->table[i];
        
        if(!(L == NULL)){ //       if
            y += 3;
        } // end        if
        
        
        while(!(N == NULL)){ // while
            sprintf(te_m_p, "%s %s\n", N->nOde_key, N->val_noDe); // include a newLine char., too
            strcat(out, te_m_p); // concat. method
            
            N = N->next; // incrementer
        } // end while
        i += 1;
    }
    
    return out; // a char* is returned
    
} // end DictionaryToString() method
