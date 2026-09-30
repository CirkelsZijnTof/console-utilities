#ifndef CUTIL_HPP
#define CUTIL_HPP

#include <iostream>
#include <array>
#include <cmath>
#include <chrono>

class ConsoleUtils
{
private:
    
    const double pi = 3.142; // more than accurate enough
    const int max_pixel_value = 255;

    // standard constants of trigonometric functions
    // a * std::func ( b * x + c * pi ) + d
    const double a = 0.5;
    const double b = pi * 2;
    const double c_offset_red = 0.45 * pi * 2;
    const double c_offset_grn = 1.8 * pi * 2;
    const double c_offset_blu = 0.9 * pi * 2;
    const double d = 1 - a;

    void 
    printColored(int color, const char& text)
    {
        std::cout << "\x1B[" << color << "m" // escape sequence for setting text color
                << text
                << "\x1B[0m"; // escape sequence for resetting text color
    };

    void 
    printColored(int color = 37, const std::string& text = "")
    {
        std::cout << "\x1B[" << color << "m" // escape sequence for setting text color
                << text
                << "\x1B[0m"; // escape sequence for resetting text color
    };

    void 
    printColored(std::string color, const std::string& text)
    {

        int c = 37; // default to white

        if (color == "black") {
            c = 30;
        } else if (color == "red") {
            c = 31;
        } else if (color == "green") {
            c = 32;
        } else if (color == "yellow") {
            c = 33;
        } else if (color == "blue") {
            c = 34;
        } else if (color == "magenta") {
            c = 35;
        } else if (color == "cyan") {
            c = 36;
        } else if (color == "bright_black") {
            c = 90;
        } else if (color == "white") {
            c = 37;
        } else {
            std::cout << "Warning: Invalid color specified. Defaulting to white.\n";
        }

        std::cout << "\x1B[" << c << "m" // escape sequence for setting text color
                << text
                << "\x1B[0m"; // escape sequence for resetting text color
    };

    void
    printRGBColored(std::array<int, 3> RGB, const char& text) 
    {
        std::cout << "\x1b[38;2;"
                << RGB[0] << ";"
                << RGB[1] << ";"
                << RGB[2] << "m"
                << text;

        std::cout << "\x1b[0m";
    };

    void
    printRGBColored(std::array<int, 3> RGB, const std::string& text) 
    {
        std::cout << "\x1b[" << RGB[0] << RGB[1] << RGB[2] << "m" 
                  << text;

        std::cout << "\x1b[0m";
    };

public:

    void pause(double duration) 
    {
        double difference = 0.0;

        auto start = std::chrono::steady_clock::now();
        while(difference < duration) 
        {
    
        auto current = std::chrono::steady_clock::now();
        difference = std::chrono::duration<double>(current - start).count();
        };
    };

    // function that takes a bottom, a top and a current value and outputs RGB value for that part of the rainbow
    // example syntax: printf("\x1B[38;2;R;G;Bm"); 
    std::array<int, 3> 
    green2redGradient(int bottom, int top, double progress) 
    {
        
        std::array<int, 3> RGB;
        double x = (progress - bottom) / double(top - bottom) * 2 * pi;

        // a * std::func ( b * x + c * pi ) + d
        int red = int((a * std::sin(b * (x - c_offset_red)) + d) * max_pixel_value);
        int grn = int((a * std::sin(b * (x - c_offset_grn)) + d) * max_pixel_value);
        int blu = 0; //int((a * std::sin(b * (x - c_offset_blu)) + d) * max_pixel_value);

        RGB = {red, grn, blu};
        //std::cout << red << "|" << grn << "|" << blu << "\n";
        return RGB;
    };

    void 
    clearLine()
    {
        std::cout << "\x1B[2K";
    }

    void 
    moveCursor(int row, int column=1, bool do_clear = true)
    {
        std::cout << "\x1B[" << row << ";" << column << "H";

        if (do_clear) 
        {
            clearLine();
        };
    };

    // use in conjunction with ConsoleUtils::moveCursor(n,1) to draw multiple
    void printProgressBar(int bar_len, double progress, double finish, bool is_complete = false, bool do_color = true, char sides = '<', char fill = '#', char empty = ' ', char half = ':') 
    {
        int bottom = 0;
        int top = 100; // hardcoded to be in terms of percentages

        double adj_progress = progress / finish * top;
        double bar_progress = (adj_progress - bottom) / double(top - bottom) * bar_len;
        double progress_in_rads = adj_progress / top * pi * 2;

        std::array<int, 3> RGB = {255,255,255};

        char left;
        char right;

        if(sides == '<' || sides == '>') {
            left = '<';
            right = '>';
        } else if(sides == '[' || sides == ']') {
            left = '[';
            right = ']';
        } else if(sides == '(' || sides == ')') {
            left = '(';
            right = ')';
        } else {
            left = sides;
            right = sides;
        }
        
        if(do_color) 
        {
            RGB = green2redGradient(bottom, top, progress_in_rads);
        };

        int full_chars = static_cast<int>(bar_progress);
        double fraction = bar_progress - full_chars;

        int empty_chars = bar_len - full_chars;

        printColored(37, left);

        if(!is_complete) 
        {
            // Full characters
            for (int i = 0; i < full_chars; i++)
            {
                printRGBColored(RGB, fill);
            };

            // Partial character
            if (fraction > 0.1 && empty_chars > 0)
            {
                printRGBColored(RGB, half);
                empty_chars--;
            };

            // Empty characters
            for (int i = 0; i < empty_chars; i++)
            {
                printRGBColored(RGB, empty);
            };

        } else {

            // Full characters
            for (int i = 0; i < bar_len; i++)
            {
                printRGBColored(RGB, fill);
            };

        };

        printColored(37, right);
        std::cout << " " << int(adj_progress) << "%\n";
    
    };

};

#endif
