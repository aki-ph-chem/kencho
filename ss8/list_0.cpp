#include<iostream>
#include<string>
#include<vector>

// 単方向連結リスト 
struct Node {
    Node* next;
    std::string name;
    Node(std::string name_ = ""): next(NULL), name(name_){}
};
Node* nil = nullptr;
void init(void) {
    nil = new Node() ;
    nil->next = nil  ;
}

void print_list(void) {
    Node* cur = nil-> next;
    for(; cur != nil; cur = cur->next){
        std::cout << cur->name << "-> ";
    }
    std::cout << std::endl;
}

void insert(Node* v, Node* p= nil){
    v->next = p->next ;
    p->next = v;
}

int main(void){
    init();
    std::vector<std::string> names = { "yamamoto","watanebe","ito","takahashi","suzuki","sato"};
    for(int i=0; i < (int) names.size(); i++){
	Node* node = new Node(names[i]) ;
	insert(node) ;
	std::cout << "step "<<i<< ": ";
	print_list();
    }
}
