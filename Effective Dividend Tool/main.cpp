//
//  main.cpp
//  Effective Dividend Tool
//
//  Created by jason eastman on 1/12/21.
//

#include <iostream>
#include <iomanip>
using namespace std;
float calculateEffective(float annualDividend,float currentShares,int purchaseShares, int price){
    return (annualDividend/price)*(currentShares/purchaseShares)*100;
}

int main(int argc, const char * argv[]) {
    float annualDividend, currentShares, effectiveDividend, price;
    int years = 40,purchasedShares;
    purchasedShares = currentShares = 150;
    annualDividend = 0.235*12;
    price = 60.50;
    effectiveDividend = annualDividend/price;
    cout << "Year\t Effective Yield\t Annual Dividend\tCurrent Shares" << endl;
    for(int i = 0; i < years; i++){
        annualDividend += annualDividend * 0.0045;
        float tempDiv  = annualDividend * currentShares;
        currentShares = currentShares + (tempDiv/price);
        cout <<setprecision(4) <<  i+1 << "\t     " << calculateEffective(annualDividend, currentShares, purchasedShares, price) <<  "%\t\t\t\t $" << setprecision(7)<< tempDiv << "\t\t\t\t" << currentShares << endl;
    }
    cout << setprecision(6) << "Purchase Price: " << purchasedShares * price << "\t\t\t\ Current Price: " << currentShares * price << endl;
    return 0;
}
