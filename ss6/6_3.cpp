#include<iostream>
#include<string>

int main(){
    std::cout << "Game start!" << std::endl;
    int left = 20, right = 36;

    while(right - left > 1) {
	int mid = left + (right - left)/2 ;
	std::cout << "Is the age less than" << mid << " ?(yes / no)" << std::endl;

	std::string ans;
	std::cin >> ans;
	if(ans == "yes") right = mid;
	else             left  = mid;
    }
    std::cout << "The age is" << left << "!" << std::endl;
}
