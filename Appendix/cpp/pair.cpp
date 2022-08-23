#include<iostream>
#include<utility>

int main(void){

    std::pair<int,int> hoge{1,3};
    std::pair<int,double> foo;

    foo.first  = 10;
    foo.second = 111.111;

    auto piyo = std::make_pair("yosida",50);

    std::cout << "hoge.first = " << hoge.first << " ," << "hoge.second = " << hoge.second << std::endl;
    std::cout << "foo.first = "  << foo.first  << " ," << "foo.second = "  << foo.second << std::endl;
    std::cout << "piyo.first = " << piyo.first << " ," << "piyo.second = " << piyo.second << std::endl;

    return 0;
}

