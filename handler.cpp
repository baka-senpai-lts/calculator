#include <stdio.h>
#include <string>

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
        
        case '(':
            result += '(';
            break;

        case ')':
            result += ')';
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
            if(i > 0) num_index++;
            else if(input[i-1] != '(') num_index++;
            else if (num_index == index) result += input[i];
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


int get_index(std::string input, char ch)
{
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == ch) return i;
    }

    throw "Not found";
}


void set_index(std::string input, char ch, int& var)
{
    try
    {
        var = get_index(input, ch);
    }
    catch(...)
    {
        var = -1;
    }
}


int next_action(std::string input)
{
    int mul, div, sum, sub;

    set_index(input, '*', mul);
    set_index(input, '/', div);
    set_index(input, '+', sum);
    set_index(input, '-', sub);

    if(mul != -1 && div != -1) return mul > div ? mul : div;
    if(mul != -1) return mul;
    if(div != -1) return div;
    if(sum != -1 && sub != -1) return sum > sub ? sum : sub;
    if(sum != -1) return sum;
    if(sub != -1) return sub;

    return 0;
}


int calculate(std::string input)
{
    if(get_length(input) == 1) return get_number(input, 0);

    return next_action(get_actions(input));
}