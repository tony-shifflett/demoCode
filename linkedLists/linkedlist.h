/*
 * Charles Shifflett
 * Coding 05
 * Linked Lists
 */

#ifndef Linked_List_H
#define Linked_List_H
#include <iostream>
#include "data.h"

using std::cout; 


    class LinkedList {

        public:
        LinkedList();
        ~LinkedList();

        bool addNode(int, string*); 
        bool deleteNode(int);
        bool getNode(int, Data*);
        void printList(bool = false); 
        int getCount();
        bool clearList();
        bool exists(int);

        private:
        Node *head; 
        
    };


#endif 