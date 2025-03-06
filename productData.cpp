//
//  productData.cpp
//  priceComparison
//
//  Created by Raeesa Dhoda on 03/12/2023.
//

#include "productData.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

productData::productData(){
}

productData::productData(const string productCode, const string productName, const string currency,
                 int retailPrice, int unitsSold, double boughtInPrice, double shippingCost, double taxRate)
    : productCode(productCode), productName(productName), currency(currency), retailPrice(retailPrice),
      unitsSold(unitsSold), boughtInPrice(boughtInPrice), shippingCost(shippingCost), taxRate(taxRate) {}

productData::~productData() {}

bool productData::readFileData(ifstream& File) {
    string lineOfData;

    if (getline(File, lineOfData) && !lineOfData.empty()) {
        string::size_type start = 0;
        string::size_type end;

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            productCode = lineOfData.substr(start, (end - start));
            start = end + 1; // pass the ","
        }

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            productName = lineOfData.substr(start, (end - start));
            start = end + 1; // pass the ","
        }

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            currency = lineOfData.substr(start, (end - start));
            start = end + 1; // pass the ","
        }

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            retailPrice = stoi(lineOfData.substr(start, (end - start)));
            start = end + 1; // pass the ","
        }

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            unitsSold = stoi(lineOfData.substr(start, (end - start)));
            start = end + 1; // pass the ","
        }

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            boughtInPrice = stod(lineOfData.substr(start, (end - start)));
            start = end + 1; // pass the ","
        }

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            shippingCost = stod(lineOfData.substr(start, (end - start)));
            start = end + 1; // pass the ","
        }

        taxRate = stod(lineOfData.substr(start));

        return true;

    } else {
        return false;
    }
}

double productData::computeGCBM() const {
    return unitsSold * (retailPrice * (1 - taxRate) - boughtInPrice - shippingCost);
}
