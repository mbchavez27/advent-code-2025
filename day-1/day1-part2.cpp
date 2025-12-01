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
        for (int i = 0; i < distance; i++)
        {
            if (direction == 'L')
                dial_pos = (dial_pos - 1 + 100) % 100;
            else
                dial_pos = (dial_pos + 1) % 100;

            if (dial_pos == 0)
                password++;
        }
    }

    cout << "Password is: " << password << endl;

    return 0;
}
