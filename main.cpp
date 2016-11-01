//
//  main.cpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    clock_t tStart = clock();
    int sum = 0, dec;
    unsigned long int bin = 0;
    
    for (int i = 1; n > sum; i++) {
        dec = i;
        bin = 0;
        for (int j = 0; dec > 0; j++) {
            bin += (dec % 2) * powl(10, j);
            dec /= 2;
        }
        
        int binCount = 0;
        unsigned long int bin2 = bin;
        for (; bin2 > 0; binCount++) {
            bin2 /= 10;
        }
        
        if ((bin % (int)powl(2, binCount)) == i) {
            sum++;
        }
    }
    cout << bin << "\nExecutional time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s" << endl;
    
    return 0;
}
