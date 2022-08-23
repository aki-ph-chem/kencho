# include<iostream>
# include<vector>

const std::vector<int> value = {500, 100, 50, 10, 5, 1};

int main(void){

    // 入力
    int x;
    std::vector<int> a(6);
    std::cin >> x;
    for(int i = 0; i < 6; ++i) std::cin >> a[i];

    // 貪欲法
    int result = 0;
    for(int i = 0; i < 6; ++i){

	// 枚数の制限がない場合
	int add = x / value[i];

	// 枚数制限を考慮する
	if( add > a[i]) add = a[i];

	x -= value[i] * add;
	result += add;
    }

    std::cout << result << std::endl;
}

