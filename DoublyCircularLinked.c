#include <stdio.h>
#include <stdlib.h>

typedef struct CircularDoublyLinkedList {
    int data;
    struct CircularDoublyLinkedList *next;
    struct CircularDoublyLinkedList *previous;
} cdll;

cdll *head;

int getLength() {
    cdll *temp = head;
    int len = 0;
    if (head->next == head) return 0;
    else {
        while (temp->next != head) {
        len++;
        }
        return (len + 1);
    }
    
}

void Insert_At_First (){
    cdll *temp = (cdll*)malloc(sizeof(cdll));
    printf("Enter Data To Be Added At First :\t");
    scanf("%d", &temp->data);
    if (head == NULL) {
        head = temp;
        temp->next = head;
        temp->previous = head;
    }
    else {
        temp->previous = head->previous;
        temp->next = head;
        head->previous->next = temp;
        head->previous = temp;
        head = temp;
    }
}

void Insert_At_End() {
    cdll *temp = (cdll*)malloc(sizeof(cdll));
    printf("Enter Data To Be Added At End :\t");
    scanf("%d", &temp->data);
    if (head == NULL) {
        head = temp;
        temp->next = head;
        temp->previous = head;
    }
    else {
        temp->previous = head->previous;
        temp->next = head;
        head->previous->next = temp;
        head->previous = temp;
    }
}

void Enter_After_a_Position() {
    printf("Enter Position After Which Data Will Be Addede :\t");
    int pos;
    scanf("%d", &pos);
    int counter = 1;
    if (pos == 0){
        Insert_At_First();
    }
    else if (pos == getLength()) {
        Insert_At_End();
    }
    else {
        cdll *temp = (cdll*)malloc(sizeof(cdll));
        printf("Enter Data To Be Added After Position %d", pos);
        scanf("%d", &temp->data);
        cdll *ttm = head;
        for (int counter = 1; counter < pos; counter++){
        
            ttm = ttm->next;
        }
        temp->previous = ttm;
        temp->next = ttm->next;
        ttm->next = temp;
        ttm->next->previous = temp;
        
    }
}

void Enter_At_a_Position() {
    printf("Enter Position After Which Data Will Be Addede :\t");
    int pos;
    scanf("%d", &pos);
    int counter = 1;
    if (pos == 0){
        Insert_At_First();
    }
    else if (pos == getLength()) {
        Insert_At_End();
    }
    else {
        cdll *temp = (cdll*)malloc(sizeof(cdll));
        printf("Enter Data To Be Added At a Position %d", pos);
        scanf("%d", &temp->data);
        cdll *ttm = head;
        for (int counter = 1; counter < pos; counter++){
        
            ttm = ttm->next;
        }
        temp->previous = ttm;
        temp->next = ttm->next;
        ttm->next = temp;
        ttm->next->previous = temp;
        
    }
}

void Delete_First_Node(){
    cdll *tail = head->previous;
    cdll *ttm = head;
    
    if (getLength() == 1){
        head = NULL;
    }
}