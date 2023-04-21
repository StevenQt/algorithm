#pragma once

#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

double new21Game(int N, int K, int W) 
{
    random_device e;
    minstd_rand linear(e()); 
    uniform_int_distribution<int> u(1, W);

    int count = 0;
    for (int i = 0; i < 100; ++i) 
    {        
        count = u(linear);
        cout << count << " ";  
    }

    cout << endl;
    return 0;
}