#include <iostream>
#include "handler.hpp"


int main()
{
    using namespace std;

    std::string input;

    cin >> input;

    cout << calculate(input) << endl;

    return 0;
}