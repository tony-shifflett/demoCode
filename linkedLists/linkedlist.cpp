/*
 * Charles Shifflett
 * Coding 05
 * Linked Lists
 */

#include "linkedlist.h"

LinkedList::LinkedList(){
    Node *head = NULL; 
};

LinkedList::~LinkedList(){
    clearList();
};

//add node
bool LinkedList::addNode(int id, string* data){
    bool added = false;
    string userData = *data; 
    bool foundDuplicate = false;

    //check the id is positive and data non-empty
    if(id > 0 && userData!=""){
        //empty list, meaning no duplication is possible
        if (!head){

            Node *newNode;
            newNode = new Node;
            newNode->data.id = id; 
            newNode->data.data = userData; 
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            added = true;
        }
        Node* currentNode = head;
        while (!foundDuplicate && !added){
            //list not empty
            
            //id is less than head id
            if(id < currentNode->data.id){
                //create new node
                Node *newNode;
                newNode = new Node;
                newNode->data.id = id; 
                newNode->data.data = userData; 
                //if note is head
                if (currentNode == head){
                    newNode->next = currentNode;
                    currentNode->prev = newNode;
                    newNode->prev = NULL;
                }
                //if node is not head
                else{
                    //new node comes before current node and after current-prev
                    newNode->next = currentNode;
                    newNode->prev = currentNode->prev;
                    currentNode->prev->next = newNode; 
                    currentNode->prev = newNode;
                }
                added = true;

            }
            //id is equal to head id
            else if (id == currentNode->data.id){
                foundDuplicate = true;
            }
            else if (id > currentNode->data.id){
                if (currentNode->next){
                    currentNode = currentNode->next;
                }
                else{
                    Node *newNode;
                    newNode = new Node;
                    newNode->data.id = id; 
                    newNode->data.data = userData;
                    newNode->prev = currentNode;
                    newNode->next = NULL;
                    currentNode->next = newNode;
                    added = true;
                    Node *printNode = head;
                    while (printNode){
                        std::cout << printNode->data.id << " "; 
                        printNode = printNode->next;
                    }
                }
            }

        }
    }

    return added;
};
bool LinkedList::deleteNode(int id){
    bool deleted = false; 
    Node *deleteNode = head; 
    while (deleteNode && !deleted){
        if (deleteNode->data.id==id){
            //connect previous and next nodes to each other before deleting current 
            if (deleteNode == head){
                if(deleteNode->next){
                    head = deleteNode->next;
                    deleteNode->next->prev = NULL; 
                }
                else{
                    head = NULL; 
                }
            }
            else if (!deleteNode->next){
                deleteNode->prev->next = NULL; 
            }
            else{
                deleteNode->prev->next = deleteNode->next; 
                deleteNode->next->prev = deleteNode->prev;   
            }
            delete deleteNode;
            deleted = true; 
        }
        else{
            deleteNode = deleteNode->next; 
        }
    }
    return deleted; 

};

bool LinkedList::getNode(int id, Data* temp){
    bool found = false; 
    Node *currentNode = head; 
    while (currentNode && !found){
        if(currentNode->data.id != id){
            currentNode = currentNode->next;
        }
        else{
            temp->data = currentNode->data.data;
            temp->id = currentNode->data.id;
            found = true;
        }
    }
    if (!found){
        temp->data = "";
        temp->id = -1;
    }

    return found; 
};

void LinkedList::printList(bool backwards){
    Node* currentNode = head; 
    if (backwards){
        while (currentNode->next){
            currentNode = currentNode->next;
        }
        while (currentNode){
            std::cout << currentNode->data.id << " : " << currentNode->data.data << std::endl; 
            currentNode = currentNode->prev;
        }
    }
    else{
        while (currentNode){
            std::cout << currentNode->data.id << " : " << currentNode->data.data << std::endl; 
            currentNode = currentNode->next;
        }  
    }

}; 

int LinkedList::getCount(){
    int count = 0; 
    Node *countNode = head;
    while (countNode){
        count +=1; 
        countNode = countNode->next; 
    }
    return count; 
};

bool LinkedList::clearList(){
    bool deleted = false; 
    Node *deleteNode = head; 
    Node *placeHolder;
    while(deleteNode->next){
        deleteNode = deleteNode->next;
    }
    //deleteNode is now final node, or head if head is the only node
    while (deleteNode->prev){
        deleteNode->prev->next = NULL;
        placeHolder = deleteNode->prev; 
        delete deleteNode; 
        deleteNode = placeHolder;  
    }
    head = NULL; 
    // delete deleteNode;
    delete placeHolder; 
    return deleted;  
};

bool LinkedList::exists(int id){
    bool found = false; 
    Node *current = head; 
    while (current){
        if (current->data.id == id){
            found = true;
        } else{
            current = current->next;
        }
    }

    return found; 
};