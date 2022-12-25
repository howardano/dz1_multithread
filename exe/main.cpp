#include "realisation.hpp"
#include <vector>
#include <algorithm>

std::vector<int> create_vector() {
    int N = 0; // количество элементов в контейнере

    std::vector<int> result; // вводить элементы нужно/можно не в сортированном порядке

    //std::cout << "Creating vector...\nInput N(num of elements): ";
    std::cin >> N;

    int num = 0;

    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        result.push_back(num);
    }

    return result;
}

int main() {

    int method = 0; // обязательно ввести правильно, иначе - программа закрывается

    //std::cout << "Firstly, input your vector (example: 1 2 3 4 5 5 6) -- in must be sorted:" << std::endl;

    std::vector<int> example = create_vector();

    /*std::cout << "Choose method to execute with your container(s): \
        \n1 lower_bound\n2 upper_bound\n3 binary_search \
        \n4 equal_range\n5 merge\nPress any key to quit..." << std::endl;*/

    std::cin >> method;

    if (method == 1) {
        int lb = 0;
        //std::cout << "Input your num: ";
        std::cin >> lb;
        auto result = lower_bound_(example.begin(), example.end(), lb);
        std::cout << *result << std::endl;
    }
    if (method == 2) {
        int ub = 0;
        //std::cout << "Input your num: ";
        std::cin >> ub;
        auto result = upper_bound_(example.begin(), example.end(), ub);
        std::cout << *result << std::endl;
    }
    if (method == 3) {
        int num_to_search = 0;
        //std::cout << "Input num to search: ";
        std::cin >> num_to_search;
        std::cout << binary_search_(example.begin(), example.end(), num_to_search) ? "true" : "false"; 
        std::cout << std::endl;
    }
    if (method == 4) {
        int num = 0;
        //std::cout << "Input num: ";
        std::cin >> num;
        auto p = equal_range_(example.begin(), example.end(), num);
        std::cout << *p.first << " " << *p.second << std::endl;
    }
    if (method == 5) {
        //std::cout << "Input another vector (you use method that require 2 vectors):\n" << std::endl;
        std::vector<int> example1 = create_vector();
        std::vector<int> dst;
        merge_(example.begin(), example.end(), example1.begin(), example1.end(), std::back_inserter(dst));
        //std::cout << "Your result: ";
        for (const auto &it : dst) {
            std::cout << it << " ";
        } 
        std::cout << std::endl;
    }
}
