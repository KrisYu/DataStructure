#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

// pass head by reference, since the head will be changed
void insertFront(node *&head, int n){
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;
    
    if (head == NULL) {
        head = tmp;
    } else {
        tmp->next = head;
        head = tmp;
    }
}

void display(node* head){
    while (head) {
        cout << head->data <<" ";
        head = head->next;
    }
    cout << endl;
    cout << endl;
}

void traverse(node* head){
    for (node* curr = head; curr != NULL; curr = curr->next)
        cout << curr->data << " ";
    cout << endl;
}

void traverseRec(node* head){
    if (head == NULL) return;
    cout << head->data << " ";
    traverseRec(head->next);
}

bool findVal(node *head, int val){
    if (head == NULL) return false;
    if (head->data == val) return true;
    return findVal(head->next,val);
}

node* find(node *head, int val){
    if (head == NULL) return NULL;
    if (head->data == val) return head;
    return find(head->next,val);
}

int count(node* head){
    if (head == NULL) return 0;
    return 1 + count(head->next);
}

void deleteNode(node *&head, int n){
    //if not found, just return;
    if (!findVal(head,n)) return;
    
    node* prev = NULL;
    node* curr = head;
    // the delete node is at head
    if (head->data == n){
        head = head->next;
        delete curr;
    } else {
        while (curr->data != n) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }
}

void reverseList(node *&head){
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverseListRec(node* &head){
    node* first;
    node* rest;
    
    if (head == NULL) return;
    
    first = head;
    rest = first->next;
    
    if (rest == NULL) return;
    
    reverseListRec(rest);
    
    first->next->next = first;
    
    first->next = NULL;
    head = rest;
    
}

int main(){
    node* head = NULL;
    
    insertFront(head,10);
    display(head);
    
    insertFront(head,20);
    display(head);
    
    insertFront(head,30);
    display(head);
    
    insertFront(head,35);
    display(head);
    
    insertFront(head,40);
    display(head);
    
    insertFront(head,5);
    display(head);
    
    traverse(head);
    traverseRec(head);
    
    cout << endl << "reverseList "<<endl;
    reverseList(head);
    traverse(head);
    
    cout <<endl << "find things" << endl;
    
    cout << findVal(head, 5)<<endl;
    cout << findVal(head, 45)<<endl;
    
    cout << find(head, 5) << endl;
    cout << find(head, 45) <<endl;
    
    cout << "number of nodes " << count(head) << endl;
    
    cout << "delete node 5 \n";
    deleteNode(head,5);
    traverse(head);
    
    cout << "delete node 40 \n";
    deleteNode(head,40);
    traverse(head);
    
    cout << "delete node 70 \n";
    deleteNode(head,70);
    traverse(head);
    
    cout << "delete node 10 \n";
    deleteNode(head,10);
    traverse(head);
    
    
}
