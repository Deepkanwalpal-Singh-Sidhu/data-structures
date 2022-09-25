#include <iostream>
using namespace std;

class Node{
public:
    string name;
    int age;
    Node* prev;
    Node* next;
    Node(string s,int a){
        age = a;
        name = s;
        prev = NULL;
        next = NULL;
    }
};

void insertFamily(Node*& head,Node*& current){
    if(head==NULL){
        head = current;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = current;
    current->prev = temp;
    return;
}

void printFamily(Node* head){
    while(head!=NULL){
        cout<<"name of the member:"<<head->name<<endl<<"age of the member:"<<head->age<<endl;
        head = head->next;
    }
    return;
}

int main(){
    Node* head = NULL;
    int n;
    cout<<"Enter the number of family members:";
    cin>>n;
    for(int i=0;i<n;i++){
        int age;
        string name;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
        Node* curr = new Node(name,age);
        insertFamily(head,curr);
    }
    printFamily(head);
    return 0;
}