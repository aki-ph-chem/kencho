#include <stdio.h>
#include <stdlib.h>

// 単方向連結リスト
struct Node{
    struct Node* next;
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
        struct Node* prev = cur;
        cur = cur->next;
        free(prev);
    }
}

void insert(struct Node* v, struct Node* p){
    v->next = p->next;  
    p->next = v;
}

void print_list(void){
    struct Node* cur = nil->next; 
    for(; cur != nil; cur = cur->next){
        printf("%s ->",cur->name);
    }
    printf("\n");
}

int main(void){
    // ------------ 初期化 -------------
    struct Node node;
    nil = &node;
    nil->next = nil;
    // char*の配列
    char* name_list[] = {"Hanjou", "Oniya", "Mokou", "Kamonohashi", "Yuyuuta", "Jun", "Futon"};
    // ------------ 初期化 -------------
    
    struct Node* node_a = NULL; 
    for(size_t i = 0; i < 7; ++i){
        node_a = gen_node(name_list[i]);
        insert(node_a,nil);
        print_list();
    }
    delete_nodes();
}
