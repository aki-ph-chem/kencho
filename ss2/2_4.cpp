#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

double dist(double x_1, double y_1, double x_2, double y_2) {
    return sqrt(std::pow(x_1 - x_2, 2) + std::pow(y_1 - y_2, 2));
}

int main(void) {
    std::size_t N;
    std::cin >> N;
    std::vector<double> x_array(N,0);
    std::vector<double> y_array(N,0);
    for(std::size_t i =0; i < N; ++i) {
        std::cin >> x_array[i] >> y_array[i];
    }

    double result = std::pow(10,4);
    for(std::size_t i = 0; i < N; ++i) {
        for(std::size_t j = i + 1; j < N; ++j) {
            double min_tmp =  dist(x_array[i], y_array[i], x_array[j], y_array[j]);
            if(result > min_tmp ) {
                result = min_tmp;
            }
        }
    }
    std::cout << result << std::endl;
}
