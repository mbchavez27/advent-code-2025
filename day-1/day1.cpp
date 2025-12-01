#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("input.txt");
    int dial_pos = 50;
    string input;
    int password = 0;

    if (!file.is_open())
    {
        cout << "[ERROR] NO FILE\n";
        return 1;
    }

    while (getline(file, input))
    {
        char direction = input[0];
        int distance = stoi(input.substr(1));

        if (direction == 'L')
        {
            dial_pos = (dial_pos - distance + 100) % 100;
        }
        else if (direction == 'R')
        {
            dial_pos = (dial_pos + distance) % 100;
        }

        if (dial_pos == 0)
            password++;
    }

    cout << "Password is: " << password << endl;

    return 0;
}