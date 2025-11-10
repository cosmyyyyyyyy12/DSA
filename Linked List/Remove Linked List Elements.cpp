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
        ListNode* del(ListNode* head, int val){
            ListNode* temp = head;
            if(temp->val == val){
                head = head->next;
                temp->next = NULL;
                delete (temp);
            }
            else{
                while(temp->next->val != val){
                    temp = temp->next;
                }
                ListNode* Next = temp->next;
                temp->next = Next->next;
                Next->next = NULL;
                delete(Next);
                }
            return head;
        }

        void display(ListNode* head){
            ListNode* temp = head;
            while(temp!=NULL){
                cout << temp->val << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }

        ListNode* removeElements(ListNode* head, int val) {
            ListNode* temp = head;
            int cnt = 0;
            int len = 0;
            while(temp != NULL){
                if(temp->val == val){
                    cnt++;
                }
                len++; 
                temp = temp->next;
            } 
            if(len == 0){
                return NULL;
            }
            else if(len == cnt){
                return NULL;
            }
            else{
                for(int i=0;i<cnt;i++){
                    head = del(head,val);
                }
                return head;
            }
        }       
};

int main(){
    list ll;
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(6);
    headA->next->next->next = new ListNode(3);
    headA->next->next->next->next = new ListNode(4);
    headA->next->next->next->next->next = new ListNode(5);
    headA->next->next->next->next->next->next = new ListNode(6);
    headA = ll.removeElements(headA, 6);
    ll.display(headA);
}