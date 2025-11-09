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
        if(headA == NULL || headB == NULL){
            return NULL;
        }

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        int c1 = 0,c2 = 0;

        while(t1 != NULL){
            c1++;
            t1 = t1->next;
        }

        while(t2 != NULL){
            c2++;
            t2 = t2->next;
        }

        t1 = headA;
        t2 = headB;
        if(c1 == c2){
            if(t1->next == NULL && t1 == t2){
                return t1;
            }
        }
        else if(c1>=c2){
            c1 = c1-c2;
            for(int i=0;i<c1;i++){
                t1 = t1->next;
            }
        }

        else if(c1<c2){
            c1 = c2-c1;
            for(int i=0;i<c1;i++){
                t2 = t2->next;
            }
        }
        while(t1 != NULL){
            if(t1 == t2){
                return t1;
            }
            if(t1 != NULL){
                t1 = t1->next;
            }
            if(t2 != NULL){
                t2 = t2->next;
            }
        }
        return NULL;
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