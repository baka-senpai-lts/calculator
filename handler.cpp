#include <string>
#include <stdio.h>

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
            /*if(i != 0 && input[i - 1] != '(')*/ result += '-';
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

    std::string buf;

    for(int i = 0; i < result.length(); i++)
    {
        if(result[i] == '(' && result[i + 1] == ')')
        {
            i++;
        }
        else
        {
            buf += result[i];
        }
    }

    printf("%s\n", buf.c_str());

    result = buf;

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
    int result;
    char last;

    std::string actions = get_actions(input);

    for(int i = 0; i < actions.length(); i++)
    {
        if(input[i] == '(' && last != '*')
        {
            return i + 1;
        }
        
        if((input[i] == '*' || input[i] == '/') && last != '(' && last != '*')
        {
            result = i;
            last = '*';
        }

        if((input[i] == '+' || input[i] == '-') && last != '(' && last != '*' && last != '+')
        {
            result = i;
            last = '+';
        }
    }

    printf("%d\n", result);

    return result;
}


int calculate(std::string input)
{
    if(get_length(input) == 1) return get_number(input, 0);

    std::string result;

    std::string buf;

    int act = next_action(get_actions(input));

    int first = get_number(input, act);
    int second = get_number(input, act + 1);

    switch(get_actions(input)[act])
    {
    case '*':
        buf = std::to_string(first * second);
        break;

    case '/':
        buf = std::to_string(first / second);
        break;
    
    case '+':
        buf = std::to_string(first + second);
        break;
    
    case '-':
        buf = std::to_string(first - second);
        break;
    }

    for(int i = 0; i < get_length(input) - 1; i++)
    {
        if(i == act)
        {
            result += buf;
        }
        else
        {
            if(i + 1 == act)
            {
                result += std::to_string(get_number(input, i));
                result += get_actions(input)[i];
            }
            else if(i - 1 == act)
            {
                result += get_actions(input)[i];
                result += std::to_string(get_number(input, i + 1));
            }
            else
            {
                result += std::to_string(get_number(input, i));
                result += get_actions(input)[i];
                result += std::to_string(get_number(input, i + 1));
            }
        }
        printf("%s\n", result.c_str());
    }

    return calculate(result);
}