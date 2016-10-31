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

LongBin powIntToBin (int);

int main() {
    LongBin Ak[1000], Bk[1000], Ck[1000];
    int ABki = 0, Cki = 8, k = 4, answer = 7;
    
    Ck[0] = 0;
    Ck[1] = 1;
    Ck[2] = 1010;
    Ck[3] = 1011;
    Ck[4] = 1100100;
    Ck[5] = 1100101;
    Ck[6] = 1101110;
    Ck[7] = 1101111;
    
    for (k = 4; answer < 20000; k++) {
        //Формиируем Ak из Ck - 1
        for (int i = 0; i < Cki; i++) {
            if (Ck[i].getBin().size() >= k) {
                if (Ck[i].getKBit(k) == 0) {
                    Ak[ABki] = Ck[i];
                    ABki++;
                }
            } else {
                Ak[ABki] = Ck[i];
                ABki++;
            }
        }
        //Формируем Bk из Ak
        for (int i = 0; i < ABki; i++) {
            Bk[i] = Ak[i] + powIntToBin(k - 1);
            answer++;
        }
        //Формируем Ck
        for (int i = 0; i < ABki; i++) {
            Ck[i] = Ak[i];
        }
        for (int i = ABki; i < 2 * ABki; i++) {
            Ck[i] = Bk[i - ABki];
        }
    }
    cout << answer << endl;
    cout << Bk[answer - 20000].getBin() << endl;
    return 0;
}

LongBin powIntToBin (int k) {
    LongBin c = 1010;
    for (int i = 1; i < k; i++) {
        c = (c << 3) + (c << 1);
    }
    return c;
}
