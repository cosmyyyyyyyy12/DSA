#include <iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int data){
            val = data;
            next = NULL;
        }
};

class list{
    public:
        void display(ListNode* head){
            ListNode* temp = head;
            while(temp!=NULL){
                cout << temp->val << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }
        
        ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        int node = len-n+1;
        if(node == 0){
            return NULL;
        }
        else if(len == 1){
            return NULL;
        }
        else if(node == 1){
            temp = head;
            head = head->next;
            delete(temp);
        }
        else{
            temp = head;
            for(int i=0;i<node-2;i++){
                temp = temp->next;
            }
            ListNode* next = temp->next;
            temp->next = next->next;
            delete(next);
        }
        return head;
    }
};

int main(){
    list ll;
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    headA = ll.removeNthFromEnd(headA, 2);
    ll.display(headA);
}