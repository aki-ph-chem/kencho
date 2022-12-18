#include<iostream>

// キューの

const int MAX = 100000;
int que[MAX];
int tail = 0, head = 0;

void init(void){
    head = tail = 0;
}

bool isEmpty(void){
    return( head == tail);
}

bool isFull(void) {
    return( head == (tail + 1)%MAX) ;
}

void enqueue(int x){
    if(isFull()){
	std::cout << "error: queue is full." << std::endl;
	return;
    }
    que[tail] = x;
    ++tail;
    if (tail == MAX) tail = 0;
}

int dequeue(void){
    if(isEmpty()){
        std::cout << "error: queue is empty." << std::endl;
        return -1;\
    }
    int res = que[head];
    ++head;
    if(head == MAX) head = 0;
    return res;
}

int main(){

    init();

    enqueue(3);
    enqueue(5);
    enqueue(7);

    std::cout << dequeue() << std::endl;
    std::cout << dequeue() << std::endl;
    std::cout << dequeue() << std::endl;
    std::cout << dequeue() << std::endl;

    enqueue(9);

    return 0;
}

