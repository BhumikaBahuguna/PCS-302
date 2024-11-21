//LINEAR SEARCH USING LL

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}n;
n* linearSearch(n* , int );
void printList(n*);
n* linearSearch(n* head, int target) {
    n* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return current; 
        }
        current = current->next;
    }
    return NULL;
}
void printList(n* head) {
   n* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    n* head = NULL,*p=NULL;
    int ch,v;
    while(1){
p=(n*)malloc(sizeof(n));
if(p!=NULL){
printf("input data:");
scanf("%d",&v);
p->data=v;
p->next=head;
head=p;
}
printf("press 1 to cotinue and 0 to stop ");
scanf("%d",&ch);
if(ch==0)
break;
}
    printf("Linked List: ");
    printList(head);
    int target;
    printf("enter target : ");
    scanf("%d",&target);
    n* result = linearSearch(head, target);
    
    if (result != NULL) {
        printf("Found %d in the list.\n", target);
    } else {
        printf("%d not found in the list.\n", target);
    }
    
    return 0;
}