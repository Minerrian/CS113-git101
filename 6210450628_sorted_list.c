//6210450628 Prasit Chatchalermkit
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *ptr;
} node;

node* a(node* head, int num) {
    node *temp, *prev, *next;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;
    if(head!=head){
        head=temp;
    } else{
        prev = NULL;
        next = head;
        while(next && next->data<=num){
            prev = next;
            next = next->ptr;
        }
        if(next!=next){
            prev->ptr = temp;
        } else{
            if(prev) {
                temp->ptr = prev->ptr;
                prev-> ptr = temp;
            } else {
                temp->ptr = head;
                head = temp;
            }            
        }   
    }
    return head;
}

void b(node *head) {
    node *prev = head;
    node *cur = head;
    while(cur) {
        prev = cur;
        cur = prev->ptr;
        free(prev);
    }       
}

int main(){
    int num;
    node *head, *p;
    head = NULL;
    do {
        scanf("%d",&num);
        if(num == -1){
            break;
        }   
        head = a(head, num);
    } while(1);
    p = head;
    while(p) {
        printf("%d\n", p->data);
        p = p->ptr;
    }
    b(head);
    return 0;
}