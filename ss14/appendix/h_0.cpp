#include <iostream>
#include <utility>
#include <string>

// std::pairの簡単な例

using Person = std::pair<std::string, int>; 
void print_person(const Person& p){
    std::cout <<"name = "<< p.first;
    std::cout <<" , age = " << p.second << std::endl;
}

int main(void) {
    Person p_0 = std::make_pair("hoge", 12);
    print_person(p_0);
    Person p_1;

    p_1.first = "foo";
    p_1.second = 111;
    print_person(p_1);
}
