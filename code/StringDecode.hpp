#pragma once

#include <string>

using std::string;

string stringDecode(const string& src) 
{
    string result = string("");
    int count = 0;
    int i = 0, s = 0, l = 0;

    while(i < src.size()) 
    {
        if (isdigit(src[i])) 
        {
            count += 10 * count + (src[i] - '0');
        }
        else if (src[i] == '[') 
        {
            s = i + 1;
        }
        else if (src[i] == ']') 
        {
            l = i - s;  
            string tmp = src.substr(s, l);
            while (count--)
                result += tmp;

            count = 0;
        }
        i++;
    }

    return result;
}
