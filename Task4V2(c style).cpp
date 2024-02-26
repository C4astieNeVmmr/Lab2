#include <stdio.h>
typedef int listType;

struct node{
    listType key;
    node *next;
};

void addToBegin(node **head,listType key){
    node *newNode = new node{key,*head};
    *head = newNode;
}

bool empty(node *head){
    return head == nullptr;
}

listType pop(node **head){
    listType keyBuffer;
    if(empty(*head)){
        printf("error, linkedList is empty");
    }
    keyBuffer=(*head)->key;
    node *nodeBuffer = *head;
    *head = (*head)->next;
    delete nodeBuffer;
    return keyBuffer;
}

void clear(node **head){
    while(!empty(*head)){
        pop(head);
    }
}

int main(){
    node *head=nullptr,*ptr=head;
    for(int i=9;i>=0;i--){
        addToBegin(&head,i);
    }
    for(node *ptr=head;ptr!=nullptr;ptr=ptr->next){
        printf("%d\t",ptr->key);
    }
    printf("\n");
    while(!empty(head)){
        printf("%d\t",pop(&head));
    }
    clear(&head);
    return 0;
}