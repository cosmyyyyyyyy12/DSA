#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

node* buildTree(node* root){
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    
    cout << "Enter data for inserting in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void reverse_levelordertraversal(node* root){
    if(root == NULL){
        return;
    }
    
    queue <node*> q;
    stack <node*> s;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        s.push(temp);
        
        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        
        else{
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }
    
    while (!s.empty()) {
        if(s.top() != NULL){
            cout << s.top()->data << " ";
        }
        else{
            cout << endl;
        }
        s.pop();
    }
}

int main() {
    node* root = NULL;
    root = buildTree(root);
    reverse_levelordertraversal(root);
    return 0;
}