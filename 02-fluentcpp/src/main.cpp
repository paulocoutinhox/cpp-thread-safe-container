#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

#include "safe/lockable.h"

safe::Lockable<std::map<std::string, int>> myMap;
std::vector<std::thread> threadList;

std::thread createThread(const std::string &key)
{
    return std::thread([&]() {
        safe::WriteAccess<safe::Lockable<std::map<std::string, int>>> myMapAccess(myMap);

        auto const findIter = (*myMapAccess).find(key);

        if (findIter != (*myMapAccess).end())
        {
            int count = findIter->second;
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
            (*myMapAccess)[key] = count + 1;
        }
        else
        {
            (*myMapAccess).emplace(key, 1);
        }
    });
}

int main(int argc, char *argv[])
{
    int maxThreads = 1000;
    int maxThreadsHalf = (maxThreads / 2);

    for (int x = 0; x < maxThreadsHalf; x++)
    {
        threadList.push_back(createThread("potato"));
        threadList.push_back(createThread("apple"));
    }

    for (int x = 0; x < maxThreads; x++)
    {
        threadList[x].join();
    }

    safe::WriteAccess<safe::Lockable<std::map<std::string, int>>> myMapAccess(myMap);
    std::cout << "> Result: apple = " << (*myMapAccess)["apple"] << ", potato = " << (*myMapAccess)["potato"] << std::endl;

    return EXIT_SUCCESS;
}