#include <string>


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
        default:
            if(num_index == index)
            {
                result += input[i];
            }
            break;
        }
    }

    if(result == "")
        throw "Out of bounds";

    return atoi(result.c_str());
}


int calculate(std::string input)
{
    return get_number(input, 2);
}