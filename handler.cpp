#include <string>
#include <iostream>

int get_length(std::string input)
{
    int result = 1;

    for(int i = 0; i < input.length(); i++)
    {
        switch(input[i])
        {
        case '+':
            result++;
            break;

        case '-':
            result++;
            break;

        case '*':
            result++;
            break;
        
        case '/':
            result++;
            break;
        
        default:
            break;
        }
    }

    return result;
}


std::string get_actions(std::string input)
{
    std::string result;

    for(int i = 0; i < input.length(); i++)
    {
        switch(input[i])
        {
        case '+':
            result += '+';
            break;

        case '-':
            result += '-';
            break;

        case '*':
            result += '*';
            break;
        
        case '/':
            result += '/';
            break;
        
        default:
            break;
        }
    }

    return result;
}


int get_number(std::string input, int index)
{
    std::string result;
    int num_index = 0;

    for(int i = 0; i < input.length(); i++)
    {
        switch(input[i])
        {
        case '+':
            num_index++;
            break;

        case '-':
            num_index++;
            break;

        case '*':
            num_index++;
            break;

        case '/':
            num_index++;
            break;

        case '(':
            break;

        case ')':
            break;

        default:
            if(num_index == index)
            {
                result += input[i];
            }
            break;
        }
    }

    if(result == "") throw "Out of bounds";

    return atoi(result.c_str());
}


int calculate(std::string input)
{
    std::cout << get_actions(input) << std::endl;
    return get_length(input);
}