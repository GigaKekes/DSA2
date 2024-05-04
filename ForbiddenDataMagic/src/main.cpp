#include <iostream>
#include <chrono>
#include <thread>

const size_t MEMORY_SIZE = 2ULL * 1024ULL * 1024ULL * 1024ULL;
const size_t PAGE_SIZE = 4 * 1024; 

volatile char *memory = nullptr;


void read(size_t delayPages)
{
    for (size_t i = 0; i < MEMORY_SIZE / PAGE_SIZE; ++i)
    {
        volatile char value = memory[i * PAGE_SIZE];
        if (i % delayPages == 0)
        {
            std::cout << "memory[" << i * PAGE_SIZE << "] value: " << static_cast<int>(value) << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    }
}

void write(size_t delayPages)
{
    for (size_t i = 0; i < MEMORY_SIZE / PAGE_SIZE; ++i)
    {
        if (i % delayPages == 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        memory[i * PAGE_SIZE] = '\0';
    }
}

int main()
{

    memory = new (std::nothrow) volatile char[MEMORY_SIZE];

    read(2048);

    delete[] memory;

    return 0;
}