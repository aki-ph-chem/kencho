#include<iostream>

// stack
const int MAX = 100000;
int st[MAX];
int top = 0;

void init(void){
    top = 0;
}

bool isEmpty(void){
    return (top == 0);
}

bool isFull(void){
    return (top == MAX);
}

void push(int x){
    if(isFull()) {
        std::cout << "error: stack is full." << std::endl;
	return;
    }
    st[top] = x;
    ++top;
}

int pop(void){
    if(isEmpty()){
        std::cout << "error: stack is empty." << std::endl;
	return -1;
    }
    --top;
    return st[top];
}

int main(){
    init();

    push(3);
    push(5);
    push(7);

    std::cout << pop() << std::endl;
    std::cout << pop() << std::endl;
    std::cout << pop() << std::endl;
    
    push(9);
    std::cout << pop() << std::endl;

    return 0;
}
