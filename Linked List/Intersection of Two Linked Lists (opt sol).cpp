#include <iostream>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode* next;
        ListNode(int val){
            data = val;
            next = NULL;
        }
};

class list{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* la = headA;
            ListNode* lb = headB;

            while(la != lb){
                if(la != NULL){
                    la = la->next;
                }
                else{
                    la = headB;
                }
                if(lb != NULL){
                    lb = lb->next;
                }
                else{
                    lb = headA;
                }
            }
            return la;
        }        
};

int main(){
    list ll;
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = headA->next->next;
    ListNode* ans = ll.getIntersectionNode(headA,headB);
    if(ans == NULL){
        cout << "0";
    }
    else{
        cout << ans->data;
    }
}