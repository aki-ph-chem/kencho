#include<iostream>
#include<vector>
#include<string>

// 双方向連結リスト
struct Node{
    Node *prev, *next;
    std::string name;
    Node(std::string name_ = ""): prev(NULL), next(NULL), name(name_) {}
};

Node* nil = nullptr;

void init(void) {
    nil = new Node() ;
    nil->prev = nil;
    nil->next = nil;
}

void print_list(void) {
    Node* cur = nil->next;
    for(; cur != nil; cur = cur->next){
        std::cout << cur->name << "->" ;
    }
    std::cout << std::endl;
}

void insert(Node* v, Node* p = nil) {
    v->next = p->next ;
    p->next->prev = v ;
    p->next = v;
    v->prev = p;
}

void erase(Node* v){
    if(v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;

    delete v;
}

int main(void){
    init();
    std::vector<std::string> names = { "yamamoto","watanebe","ito","takahashi","suzuki","sato" };
    Node* watanebe = nullptr;

    for(std::size_t i=0; i< names.size(); i++){
	Node* node = new Node(names[i]);
	insert(node);
	if(names[i] == "watanebe") watanebe = node;
    }

    std::cout << "before" ;
    print_list() ;
    erase(watanebe);

    std::cout << "after: ";
    print_list() ;
}
