#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <random>

std::mutex mtx;
long long num_threads;
long long num_points;
long long in_circle = 0;

void Simulate(long long thread_id, long long points_per_thread)
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    for (long long i = 0; i < points_per_thread; i++)
    {
        double x = distribution(generator);
        double y = distribution(generator);
        if (x * x + y * y <= 1.0)
        {
            mtx.lock();
            in_circle++;
            mtx.unlock();
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <number_of_threads> <number_of_points>" << std::endl;
        return 1;
    }

    num_threads = std::stoll(argv[1]);
    num_points = std::stoll(argv[2]);

    std::vector<std::thread> threads(num_threads);
    long long points_per_thread = num_points / num_threads;

    auto start = std::chrono::high_resolution_clock::now();

    for (long long i = 0; i < num_threads; i++)
    {
        threads[i] = std::thread(Simulate, i, points_per_thread);
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    double pi = 4.0 * in_circle / num_points;
    std::cout << "Pi: " << pi << std::endl;
    std::cout << "Time: " << duration << " ms" << std::endl;
}