//
//  productData.hpp
//  priceComparison
//
//  Created by Raeesa Dhoda on 03/12/2023.
//

#ifndef productData_hpp
#define productData_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class productData {

public:
    productData();
    productData(const string productCode, const string productName, const string currency,
            int retailPrice, int unitsSold, double boughtInPrice, double shippingCost, double taxRate);
    ~productData();
    virtual bool readFileData(ifstream& File);
    virtual double computeGCBM() const;
    string productCode;
    string productName;
    string currency;
    int retailPrice;
    int unitsSold;
    double boughtInPrice;
    double shippingCost;
    double taxRate;
    
};

#endif /* productData_hpp */
