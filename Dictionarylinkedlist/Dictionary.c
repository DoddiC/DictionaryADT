//
// Chidvi Doddi
// cdoddi
// 12B
// July 27th, 2019
// Description: This C file is responsible for the linked list implementation of the Dictionary ADT.
//


// Dictionary.c


// (required) import statements:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

// [imports the header file for the Dictionary ADT]:
#include "Dictionary.h" // includes the header (.h) file

// int physicalSize;

// (Node) private types ----------------------------------------------------------------

// Node struct
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
    Node T_OP; // top/head node
    Node middleNode;
    Node bottomNode;
    
    int I_Numero; // numOfItems
} DictionaryObj; // end struct

//private helper functions ---------------------------------------------------

//find_n0de_kEY()
//arguments: (Dictionary D) (char* k)
//function: loops goes through Dictionary LinkedList to search for Node at 'key'
//return: Node with specified key (if found), null (if not found)
Node find_n0de_kEY(Dictionary D, char* k){
    Node N;
    
    N = D->T_OP; // sets the Node N to be the topNode
    while(!(N == NULL)){ // while
        
        if (strcmp(N->nOde_key, k) == 0){ // if found
            return N;
        }
        
        N = N->next; // incrementer
    } // end while

    return NULL; //default return statement (could also return -1)
} // end find_n0de_kEY() method

// (Dictionary) public functions -------------------------------------------------------


// Dictionary struct def. ((DON'T NEED))
// typedef struct DictionaryObj* Dictionary;


// newDictionary() constructor
// constructor for the Dictionary type
//
Dictionary newDictionary(void){ // newDictionary() constructor
    
    Dictionary d_ict = malloc(sizeof(DictionaryObj));
    
    assert(!(d_ict == (NULL))); // checks if the Dictionary object ( created with using malloc() ) is NULL
    
    // d_ict->T_OP = calloc(Initial_len, sizeof(int)); // use calloc() cause we are creating an array
    
    d_ict->I_Numero = 0;
    
    d_ict->T_OP = NULL;
    
    // d_ict->physicalSize = Initial_len;
    
    return d_ict;
} // end newDictionary() constructor


// freeDictionary()
// destructor for the Dictionary type
void freeDictionary(Dictionary* pD){ // freeDictionary() method
    
    // NULL CHECK:
    if(!((pD == NULL) || (*pD == NULL))){
        
        if( !(isEmpty(*pD)) ){
            makeEmpty(*pD); // calls the makeEmpty() method
        }
        
        // free(d_ict);
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
    // if(D == NULL){
    //     fprintf(stderr,
    //         "Dictionary Error: calling isEmpty() on NULL Dictionary reference\n");
    //     exit(EXIT_FAILURE);
    // }
    return (!(D->I_Numero != (0))); // returns true (1) if the condition is satisfied; returns false if this condition evaluates to false
} // end isEmpty() method

// size() method
// returns, in D, the number of (, v) pairs
// pre: none
//
int size(Dictionary D){ // size() method
    // if(D == NULL){
    //     fprintf(stderr,
    //         "Dictionary Error: calling size() on NULL Dictionary reference\n");
    //     exit(EXIT_FAILURE);
    // }
    return D->I_Numero;
} // end size() method

// lookup() method
// returns the value v such that (k, v) is in D, or returns NULL if no
// such value v exists.
// pre: none
char* lookup(Dictionary D, char* k){ // lookup() method
    
    // Dictionary d;
    Node node_N; // node var.
    char* lookup_err_out = "Dictionary Error: calling lookup() on NULL Dictionary reference\n";
    
    // NULL check:
    if(!(D != NULL)){
        fprintf(stderr, "%s", lookup_err_out);
        exit(EXIT_FAILURE);
    }
    
    int y = 0;
    if(find_n0de_kEY(D, k) != NULL){
        y += 2;
        
        node_N = find_n0de_kEY(D, k);
        // print(findNode_Key(D, k));
        return node_N->val_noDe;
        // free(node_N);
    }else{
        return NULL;
    } // end if-else loop
    
    return NULL; // default return statement
} // end lookup() method

// insert() method
// inserts new (key,value) pair into D
// pre: lookup(D, k)==NULL
void insert(Dictionary D, char* k, char* v){
    // Dictionary d;
    Node z_Node;
    Node node_N;
    
    // string literal:
    char* insert_er_out = "Dictionary Error: calling insert() on NULL Dictionary reference\n";
    
    // checks if the node is found, first:
    if(!(lookup(D, k) == NULL)){
        fprintf(stderr, "%s", insert_er_out);
        exit(EXIT_FAILURE);
        
    }else{
        node_N = newNode(k, v); // creates a new Node
        
        node_N->next = D->T_OP;
        //
        z_Node = newNode(k,v);
        //
        D->T_OP = (node_N);
        // printf(D->I_Numero); // print check
        z_Node = NULL;
        (D->I_Numero) += 1;
        // printf(D->I_Numero); // print check
        return; // return statement
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
        Node Ln;
        N = D->T_OP;
        Ln = NULL;
        //printf("%s -- %s\n", N->key, k);
        if(!(strcmp(N->nOde_key, k) == 0)){
            pN = N->next;
        }else{
            //Node temp = D->top;
            D->T_OP = (N)->next; //
            freeNode(&N);
            //freeNode(&D->top);
            (D->I_Numero) -= 1;
            return;
        } // end if-else
        
        while(!(N->next == NULL)){ // while
            
            pN = N->next;
            if(!(strcmp(N->next->nOde_key, k) == 0)){ // if
                N = N->next; // incrementer
            }else{
                Node t_ = N->next; // temporary Node used for doing N->next
                N->next = (t_)->next; //
                freeNode(&t_);
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
void makeEmpty(Dictionary D){ // makeEmpty() method
    
    // string literals:
    char* makeEMPTYerr_NULL_out = "Dictionary Error: calling makeEmpty() on NULL Dictionary reference";
    char* makeEMPTYerr_out = "Dictionary Error: calling makeEmpty() on empty Dictionary";
    
    // NULL check:
    if(!(D != NULL)){
        fprintf(stderr, "%s", makeEMPTYerr_NULL_out);
        exit(EXIT_FAILURE);
    }
    
    // [2ND] NULL check:
    if((!(D->I_Numero != 0))){
        fprintf(stderr, "%s", makeEMPTYerr_out);
        exit(EXIT_FAILURE);
    } // end if
    
    //Dictionary temp = D;
    D->T_OP = NULL;
    D->I_Numero = 0;
    
} // end makeEmpty() method

// ctr_traverse_chars() method
// counts the number of chars using the node key and node value
//
int ctr_traverse_chars(Dictionary D){ // ctr_traverse_chars() method
    
    Node pN; // node
    int x = 0;
    
    int val_OF_sum = 0; // sum var.
    
    pN = D->T_OP; // sets the node to the top Node
    
    while(!(pN == NULL)){ // while
        
        val_OF_sum = (int) (strlen(pN->val_noDe) + 3 + strlen(pN->nOde_key));
        val_OF_sum += 0;
        
        x = x + 9;
        
        pN = pN->next; // incrementer
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
    //
    L = D->T_OP;
    //
    N = D->T_OP;
    while(!(N == NULL)){ // while
        sprintf(te_m_p, "%s %s\n", N->nOde_key, N->val_noDe); // include a newLine char., too
        strcat(out, te_m_p); // concat. method
        
        N = N->next; // incrementer
    } // end while

    return out; // a char* is returned
    
} // end DictionaryToString() method
