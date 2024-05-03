#include <iostream>
#include <random>
#include <chrono>



#define ARRAY_SIZE 1000

void generateRandomArray(int array[ARRAY_SIZE][ARRAY_SIZE]) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for(int i = 0; i < ARRAY_SIZE; ++i) {
        for(int j = 0; j < ARRAY_SIZE; ++j) {
            array[i][j] = dis(gen);
        }
    }
}

void cache_efficient(int array[ARRAY_SIZE][ARRAY_SIZE])
{
    int num = 0;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        for(int j = 0; j < ARRAY_SIZE; j++)
        {
            num += array[i][j];
        }
    }
}

void cache_inefficient(int array[ARRAY_SIZE][ARRAY_SIZE])
{
    int num = 0;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        for(int j = 0; j < ARRAY_SIZE; j++)
        {
            num += array[j][i];
        }
    }
}

int main() {
    int array[ARRAY_SIZE][ARRAY_SIZE];

    generateRandomArray(array);

    //auto t_start1 = std::chrono::high_resolution_clock::now();
    //cache_efficient(array);
    //auto t_end1 = std::chrono::high_resolution_clock::now();
    //std::cout << "The first implementataion requires: " << std::chrono::duration<double, std::milli>(t_end1 - t_start1).count() << " ms" << std::endl;

    //auto t_start2 = std::chrono::high_resolution_clock::now();
    cache_inefficient(array);
    //auto t_end2 = std::chrono::high_resolution_clock::now();
    //std::cout << "The second implementataion requires: " << std::chrono::duration<double, std::milli>(t_end2 - t_start2).count() << " ms" << std::endl;
    //std::cout << "The first implementation is better by " << std::chrono::duration<double, std::milli>(t_end2 - t_start2).count() - std::chrono::duration<double, std::milli>(t_end1 - t_start1).count() << " ms" << std::endl;
    
    return 0;
}
