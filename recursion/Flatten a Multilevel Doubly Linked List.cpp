#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* child;
        Node* prev;
        Node(int val){
            data = val;
            next = NULL;
            child = NULL;
            prev = NULL;
        }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* curr = head;
        Node* Next;
        while(curr != NULL){
            if(curr->child != NULL){
                Next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                while(curr->next != NULL){
                    curr = curr->next;
                }
                if(Next != NULL){
                        curr->next = Next;
                        Next->prev = curr;
                    }
            }
            curr = curr->next;
        }
        return head;
    }
};