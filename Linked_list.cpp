#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

Node(int val){
    data= val;
    next = NULL;

}

};

class List{
public:
    Node* head;
    Node* tail;

    List(){
    head = tail = NULL;
    }


    void push_front(int value){
        Node* newNode = new Node(value);
        if (head == NULL){
            head = tail = newNode;
        }
       else{
            newNode->next=head;
            head = newNode;
        }
    }
    void push_back(int v){
    Node* newNode = new Node(v);
    if (head == NULL){
        head = tail = newNode;

    }else{
        tail->next = newNode;
        tail = newNode;

    }


    }

void insert(int val,int pos){
if(pos<0){
    cout<<"invalid position";
    return;
}

if (pos == 0){
    push_front(val);
    return ;
}

Node* temp = head;
for(int i = 0;i<pos-1;i++)
{
    temp=temp->next;
}

Node* newNode = new Node(val);
newNode-> next = temp->next;
temp->next = newNode;
}


void pop_front(){

    if(head == NULL){
        cout<<"Linked List is Empty !!";
        return ;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}
void pop_back(){
if (head == NULL)
    {
    cout<<"NULL";
}

Node* temp = head;
while (temp->next != tail){
    temp = temp->next;
}
temp->next=NULL;
delete tail;
tail = temp;

}

int search(int val)
{
    int index = 0;
    Node* temp = head;
    while (temp != NULL){
        if (temp->data == val){
            return index;
        }
        temp= temp-> next;
        index++;
    }
}
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp ->data<<"  ";
            temp = temp->next;
        }

    }



};

int main(){
    List l;

    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    l.insert(4,2);
    cout<<l.search(3)<<endl;
    l.push_back(-1);
    l.push_back(-2);

    l.display();
    cout<<endl;
    l.pop_front();

    l.display();
   cout<<endl;
    l.pop_back();

    l.display();
    cout<<endl;
       return 0;
}
