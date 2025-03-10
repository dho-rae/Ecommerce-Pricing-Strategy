//
//  competitorProductData.cpp
//  priceComparison
//
//  Created by Raeesa Dhoda on 03/12/2023.
//

#include "competitorProductData.hpp"
#include <fstream>
#include <string>

using namespace std;

competitorProductData::competitorProductData(){
}

competitorProductData::competitorProductData(const string productCode, const string productName,
                                             const string currency, int retailPrice, int unitsSold, double boughtInPrice, double shippingCost, double taxRate, const string competitor)
    : productData(productCode, productName, currency, retailPrice, unitsSold, boughtInPrice, shippingCost, taxRate),
      competitor(competitor) {}

bool competitorProductData::readFileData(ifstream& File) {

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
            competitor = lineOfData.substr(start, (end - start));
            start = end + 1; // pass the ","
        }

        end = lineOfData.find(',', start);
        if (end != string::npos) {
            currency = lineOfData.substr(start, (end - start));
            start = end + 1; // pass the ","
        }
        
        retailPrice = stoi(lineOfData.substr(start));
        
        return true;

    } else {
        return false;
    }
}



