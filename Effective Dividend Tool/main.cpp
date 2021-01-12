//
//  main.cpp
//  Effective Dividend Tool
//
//  Created by jason eastman on 1/12/21.
//

#include <iostream>
#include <iomanip>
using namespace std;
float calculateEffective(float annualDividend,float currentShares,int purchasedShares,int price){
    return ((annualDividend *(purchasedShares+currentShares))/price);
}

int main(int argc, const char * argv[]) {
    float annualDividend, currentShares, effectiveDividend, price;
    int months = 120,purchasedShares = 50 ;
    currentShares = purchasedShares = 50;
    annualDividend = 0.235 * 12;
    price = 57.50;
    effectiveDividend = annualDividend/price;
    cout << "Month\t Effective Yield\t Monthly Dividend\tCurrent Shares" << endl;
    for(int i = 0; i < months; i++){
       if(i%12 ==  0){
            annualDividend += annualDividend * 0.0045;
        }
        float tempDiv  = annualDividend/12 * currentShares;
        currentShares = currentShares + (tempDiv/price);
        cout <<setprecision(4) <<  i+1 << "\t     " << calculateEffective(annualDividend, currentShares, currentShares, price) <<  "\t\t\t\t\t " << tempDiv << "\t\t\t" << currentShares << endl;
    }
    return 0;
}
