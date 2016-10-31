//
//  main.cpp
//  Dop*Task1
//
//  Created by Глеб Линник on 27.10.16.
//  Copyright © 2016 Linkin Industris. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "LongBin.h"

using namespace std;

int main()
{
    LongBin Ak[1000], Bk[1000], Ck[1000],c=1111101000;
    int ABki = 0, Cki = 8, k = 4, answer = 7, m = 0;
    
    Ck[0] = 0;
    Ck[1] = 1;
    Ck[2] = 1010;
    Ck[3] = 1011;
    Ck[4] = 1100100;
    Ck[5] = 1100101;
    Ck[6] = 1101110;
    Ck[7] = 1101111;
    
    //Формиируем Ak из Ck - 1
    int number;
    
    cout << "Введите n:";
    cin >> number;
    
    for (k = 4; answer < number; k++)
    {
        for (int i = 0; i < Cki; i++)
        {
            if (Ck[i].getBin().size() >= k)
            {
                if (Ck[i].getKBit(k) == 0)
                {
                    Ak[ABki] = Ck[i];
                    ABki++;
                }
            }
            else
            {
                Ak[ABki] = Ck[i];
                ABki++;
            }
        }
        //Формируем Bk из Ak
        for (int i = 0; i < ABki; i++)
        {
            Bk[i] = Ak[i] + c;
            answer++;
        }
        //Формируем Ck
        for (int i = 0; i < ABki; i++)
        {
            Ck[i] = Ak[i];
        }
        for (int i = ABki; i < 2 * ABki; i++)
        {
            Ck[i] = Bk[i - ABki];
        }
        m = ABki;
        ABki = 0;
        c = (c << 3) + (c << 1);
    }
    cout << Bk[m - 1 - (answer - number)].getBin() << " " << Bk[m - 1 - (answer - number)].getDec() <<endl;
    return 0;
}
