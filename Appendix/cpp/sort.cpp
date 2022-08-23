#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

std::vector<int> hoge = {4,2,10,8,1,5};

struct piyo{

    int x;
    int y;
};

bool cmp(const piyo& a, const piyo& b){

    return a.x < b.x;
}

std::vector<piyo> hogehoge(4); 
int main(void){

    std::sort(hoge.begin(),hoge.end());
    for(std::size_t i = 0; i < 6; ++i){

	std::cout << hoge[i] << std::endl;
    }

    hogehoge[0].x = 10;
    hogehoge[1].x = 2;
    hogehoge[2].x = 1;
    hogehoge[3].x = 5;

    hogehoge[0].y = 10;
    hogehoge[1].y = 2;
    hogehoge[2].y = 1;
    hogehoge[3].y = 5;

    std::sort(hogehoge.begin(),hogehoge.end(),cmp);
    for(std::size_t i = 0; i < 4; ++i){

	std::cout << hogehoge[i].x << std::endl;
    }


}
