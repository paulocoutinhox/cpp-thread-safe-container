#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

std::map<std::string, int> myMap;
std::vector<std::thread> threadList;

std::thread createThread(const std::string &key)
{
    return std::thread([&]() {
        auto const findIter = myMap.find(key);

        if (findIter != myMap.end())
        {
            int count = myMap[key];
            myMap[key] = count + 1;
        }
        else
        {
            myMap.emplace(key, 1);
        }
    });
}

int main(int argc, char *argv[])
{
    int threadMax = 10000;
    int threadMaxHalf = (threadMax / 2);

    for (int x = 0; x < threadMax; x++)
    {
        threadList.push_back(createThread("potato"));
    }

    for (int x = 0; x < threadMax; x++)
    {
        threadList.push_back(createThread("apple"));
    }

    for (int x = 0; x < threadMaxHalf; x++)
    {
        threadList[x].detach();
    }

    for (int x = threadMaxHalf; x < threadMax; x++)
    {
        threadList[x].detach();
    }

    /*
    for (auto &thread : threadList)
    {
        thread.detach();
    }
    */

    std::cout << "> Result: apple = " << myMap["apple"] << ", potato = " << myMap["potato"] << std::endl;

    return EXIT_SUCCESS;
}