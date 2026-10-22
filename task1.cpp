#include <iostream>
int len_till_point(const char* str)
{
    int len = 0;
    for (int i; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            return len;
        }
        len++;
    }

    return len;
}

inline int sign(const char* str)
{
    return (str[0] != '-' || str[0] == '+') ? 1 : 0;
}

int main(int argc, char* argv[])
{
    int len_till_point1 = len_till_point(argv[1]);
    int len_till_point2 = len_till_point(argv[2]);

    int sign1 = sign(argv[1]);
    int sign2 = sign(argv[2]);

    if (argv[1][0] == '+')
    {
        argv[1]++;
    }
    if (argv[2][0] == '+')
    {
        argv[2]++;
    }
    if (len_till_point1 > len_till_point2)
    {
        if (sign1 == 1 && sign2 == 1)
        {
            std::cout << "greater" << std::endl;
            return 0;
        }
        else if (sign1 == 0 && sign2 == 1)
        {
        }
    }
}