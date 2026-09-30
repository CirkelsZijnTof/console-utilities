#include "ConsoleUtil.hpp"

// YOURPATH\ucrt64\bin\g++.exe demo_ConsoleUtil.cpp -o demo_ConsoleUtil.exe

int main() {  

    ConsoleUtils CONSOLE;

    double difference = 0.0;
    double finish = 5.0;

    int bar_length = 10;

    auto start = std::chrono::steady_clock::now();
    while(difference < finish) 
    {

        CONSOLE.moveCursor(1);
        
        CONSOLE.printProgressBar(bar_length, difference, 100, false, true);

        CONSOLE.pause(0.05);

    auto current = std::chrono::steady_clock::now();
    difference = std::chrono::duration<double>(current - start).count();
    };

    CONSOLE.moveCursor(1);
    CONSOLE.printProgressBar(bar_length, 100, 100, false, true);

    std::cin.get();

};
