#include <iostream>
using namespace std;

// creating a node
class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int data){
            val = data;
            next = NULL;
        }
};

// making list 
class list{
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL || head->next == NULL || k == 0){
                return head;
            }
            ListNode* curr = head;
            int cnt = 0;
            while(curr != NULL){
                cnt++;
                curr = curr->next;
            }
            int rotate;
            if(cnt < k){
                rotate = k%cnt;
            }
            else if(cnt == k){
                rotate = cnt-k;
            }
            else{
                rotate = k;
            }
            if(rotate == 0){
                return head;
            }
            int r = cnt - rotate;
            curr = head;
            for(int i=1;i<r;i++){
                curr = curr->next;
            }
            ListNode* Next = curr->next;
            curr->next = NULL;
            curr = Next;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = head;
            return Next;
        }

        void display(ListNode* head){
                ListNode* temp = head;
                while(temp!=NULL){
                    cout << temp->val << "->";
                    temp = temp->next;
                }
                cout << "NULL";
        }
};

int main(){
    list ll;
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    
    
    headA = ll.rotateRight(headA,2);
    ll.display(headA);
}