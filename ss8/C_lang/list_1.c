#include <stdio.h>
#include <stdlib.h>

// 双方向連結リスト
struct Node{
    struct Node *next, *prev;
    char* name;
};

struct Node* nil = NULL;

struct Node* gen_node(char* name){
    struct Node* node = malloc(sizeof(struct Node));
    if(!node){
        fprintf(stderr,"Error: malloc\n");
        exit(1);
    }
    node->name = name;
    return node;
}

void delete_nodes(void){
    struct Node* cur = nil->next;
    while(!cur){
        struct Node* for_delete = cur;
        cur = cur->next;
        free(for_delete);
    }
}

void insert(struct Node* v, struct Node* p){
    v->next = p->next; 
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

void erase_node(struct Node* v){
    if(v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    free(v);
}

void print_nodes(void){
    struct Node* cur = nil->next;
    for(; cur != nil; cur = cur->next){
        printf("%s ->",cur->name);
    }
    printf("\n");
}

int main(void){
    // ----- 初期化 ----
    struct Node node;
    nil = &node; 
    nil->next = nil;
    char* name_list[] = {"Hanjou", "Oniya", "Mokou", "Kamonohashi", "Yuyuuta", "Jun", "Futon"};
    // ----- 初期化 ----
    
    struct Node* node_a = NULL;
    // Mokou Node
    struct Node* mokou = NULL;     
    for(size_t i = 0;i < 7; ++i){
        node_a = gen_node(name_list[i]);
        insert(node_a,nil);
        if(name_list[i] == "Mokou") mokou = node_a;
    }

    printf("Before: ");
    print_nodes();

    erase_node(mokou);

    printf("After: ");
    print_nodes();

    delete_nodes();
}
