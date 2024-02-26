#include <iostream>
using namespace std;

template <typename listType>
class linkedList;

template <typename nodeType>
class node{
    friend class linkedList<nodeType>;
    nodeType key;
    node *next;
    node(nodeType k,node* n){
        key=k;
        next = n;
    }
    node(){}
};

template <typename listType>
class linkedList{
    node<listType> *head;
    int size;
    public:
    linkedList(){
        head=0;
        size=0;
    }
    ~linkedList(){
        clear();
    }
    void addToBegin(listType k){
        node<listType> *n = new node<listType>(k,head);
        head=n;
        size+=1;
    }
    listType pop(){
        listType res=head->key;
        node<listType> *tmp=head;
        head = head->next;
        size-=1;
        delete tmp;
        return res;
    }
    listType operator[](int k){
        node<listType> *ptr = head;
        if(k<0 || k>=size){
            throw "Out of bounds";
        }
        for(;k>0;k--){
            ptr = ptr->next;
        }
        return ptr->key;
    }

    listType top(){
        return head->key;
    }
    bool empty(){
        return head==0;
    }
    int getSize(){
        return size;
    }
    void clear(){
        while (head!=0){
            pop();
        }
    }
};

int main(){
    linkedList<int> l;
    for(int i=9;i>=0;i--){
        l.addToBegin(i);
    }
    for(int i=0;i<l.getSize();i++){
        cout << l[i] << "\t";
    }
    cout << endl;
    while(!l.empty()){
        cout << l.pop() << "\t";
    }
    return 0;
}