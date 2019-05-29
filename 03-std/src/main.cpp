#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

std::map<std::string, int> myMap;
std::vector<std::thread> threadList;
std::mutex myMapMutex;

std::thread createThread(const std::string &key)
{
    return std::thread([&]() {
        std::lock_guard<std::mutex> lock(myMapMutex);

        auto const findIter = myMap.find(key);

        if (findIter != myMap.end())
        {
            int count = myMap[key];
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
            myMap[key] = count + 1;
        }
        else
        {
            myMap.emplace(key, 1);
        }

        // std::cout << "> Result: apple = " << myMap["apple"] << ", potato = " << myMap["potato"] << " - " << key << std::endl;
    });
}

int main(int argc, char *argv[])
{
    int maxThreads = 500;

    for (int x = 0; x < maxThreads; x++)
    {
        threadList.push_back(createThread("potato"));
        threadList.push_back(createThread("apple"));
    }

    for (auto &thread : threadList)
    {
        thread.join();
    }

    std::cout << "> Result: apple = " << myMap["apple"] << ", potato = " << myMap["potato"] << std::endl;

    return EXIT_SUCCESS;
}