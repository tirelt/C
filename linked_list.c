#include <stdio.h>
#include <stdlib.h>

struct List{
    int head;
    struct List* tail;
};

void append( struct List* l, int value ){
    if(l->tail){
        append(l->tail, value);
    } else{
        l->tail = malloc(sizeof(struct List));
        if (!l->tail) {
            printf("Memory allocation failed!\n");
            return;
        }
        l->tail->head = value;
        l->tail->tail = NULL;
    }
}

void printList(struct List* l) {
    while(l){
        printf("%d -> ", l->head);
        l = l->tail;
    }
    printf("NULL\n");
}

void deallocateList(struct List* l){
    struct List* temp;
    if(l->tail){
        temp = l->tail;
        l->tail = l->tail->tail;
        free(temp);
    }
}
int main(){   
    struct List l = {1,NULL};
    append(&l,4);
    append(&l,2);
    printList(&l);
    deallocateList(&l);
    return 0;
}