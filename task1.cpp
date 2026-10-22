#include <iostream>

int len(const char* str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    return len;
}
int len_till_point(const char* str)
{
    int len = 0;
    int i = 0;
    while (str[i] != '.' && str[i] != '\0')
    {
        len++;
        i++;
    }

    return len;
}

int len_after_point(const char* str)
{
    int len = 0;
    bool flag = false;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (flag)
        {
            len++;
        }
        if (str[i] == '.')
        {
            flag = true;
        }
    }

    return len;
}

inline int sign(const char* str)
{
    return (str[0] != '-' || str[0] == '+') ? 1 : 0;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    int sign1 = sign(argv[1]);
    int sign2 = sign(argv[2]);

    if (argv[1][0] == '+' || argv[1][0] == '-')
    {
        argv[1]++;
    }
    if (argv[2][0] == '+' || argv[2][0] == '-')
    {
        argv[2]++;
    }
    int len_till_point1 = len_till_point(argv[1]);
    int len_till_point2 = len_till_point(argv[2]);

    // compare if different signs
    if (sign1 == 1 && sign2 == 0)
    {
        std::cout << "greater" << std::endl;
        return 0;
    }
    else if (sign1 == 0 && sign2 == 1)
    {
        std::cout << "less" << std::endl;
        return 0;
    }

    // compare if different whole part
    if (len_till_point1 > len_till_point2)
    {
        if (sign1 == 1 && sign2 == 1)
        {
            std::cout << "greater" << std::endl;
            return 0;
        }
        else if (sign1 == 0 && sign2 == 0)
        {
            std::cout << "less" << std::endl;
            return 0;
        }
    }
    else if (len_till_point1 < len_till_point2)
    {
        if (sign1 == 1 && sign2 == 1)
        {
            std::cout << "less" << std::endl;
            return 0;
        }
        else if (sign1 == 0 && sign2 == 0)
        {
            std::cout << "greater" << std::endl;
            return 0;
        }
    }

    // if nums have same size
    if (sign1 == 1)
    {
        for (int i = 0; i < len_till_point1; i++)
        {
            if (argv[1][i] > argv[2][i])
            {
                std::cout << "greater" << std::endl;
                return 0;
            }
            else if (argv[1][i] < argv[2][i])
            {
                std::cout << "less" << std::endl;
                return 0;
            }
        }
    }

    if (sign1 == 0)
    {
        for (int i = 0; i < len_till_point1; i++)
        {
            if (argv[1][i] > argv[2][i])
            {
                std::cout << "less" << std::endl;
                return 0;
            }
            else if (argv[1][i] < argv[2][i])
            {
                std::cout << "greater" << std::endl;
                return 0;
            }
        }
    }

    bool reached_end1 = false;
    bool reached_end2 = false;

    argv[1] += len_till_point1;
    argv[2] += len_till_point2;

    if (*argv[1] == '.')
    {
        argv[1]++;
    }
    if (*argv[2] == '.')
    {
        argv[2]++;
    }
    if (sign1 == 1)
    {
        while (!(reached_end1 && reached_end2))
        {
            if (argv[1][0] == '\0')
            {
                reached_end1 = true;
            }
            if (argv[2][0] == '\0')
            {
                reached_end2 = true;
            }

            if (reached_end1 && !reached_end2) // virtual zeros for 1st
            {
                if (argv[2][0] > '0')
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
            }

            if (reached_end2 && !reached_end1) // virtual zeros for 2nd
            {
                if (argv[1][0] > '0')
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
            }

            if (!reached_end1 && !reached_end2)
            {
                if (argv[1][0] > argv[2][0])
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
                else if (argv[1][0] < argv[2][0])
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
            }
            if (!reached_end1)
            {
                argv[1]++;
            }
            if (!reached_end2)
            {
                argv[2]++;
            }
        }
    }
    else
    {
        while (!(reached_end1 && reached_end2))
        {
            if (argv[1][0] == '\0')
            {
                reached_end1 = true;
            }
            if (argv[2][0] == '\0')
            {
                reached_end2 = true;
            }

            if (reached_end1 && !reached_end2) // virtual zeros for 1st
            {
                if (argv[2][0] > '0')
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
            }

            if (reached_end2 && !reached_end1) // virtual zeros for 2nd
            {
                if (argv[1][0] > '0')
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
            }

            if (!reached_end1 && !reached_end2)
            {
                if (argv[1][0] > argv[2][0])
                {
                    std::cout << "less" << std::endl;
                    return 0;
                }
                else if (argv[1][0] < argv[2][0])
                {
                    std::cout << "greater" << std::endl;
                    return 0;
                }
            }

            if (!reached_end1)
            {
                argv[1]++;
            }
            if (!reached_end2)
            {
                argv[2]++;
            }
        }
    }
    std::cout << "equal" << std::endl;
}