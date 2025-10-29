#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
};

class Linkedlist{
    public:
        Node* head;
        Linkedlist(){
            head = NULL;
        }
        void insertatbegin(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout << temp->data << " -> ";
                temp=temp->next;
            }
            cout << "NULL";
        }
};
int main(){
    Linkedlist list;
    list.insertatbegin(10);
    list.insertatbegin(20);
    list.insertatbegin(30);
    list.insertatbegin(40);
    list.insertatbegin(50);
    cout << "Linkedlist" << endl;
    list.display();
}
