//
//  competitorProductData.hpp
//  priceComparison
//
//  Created by Raeesa Dhoda on 03/12/2023.
//

#ifndef competitorProductData_hpp
#define competitorProductData_hpp

#include <stdio.h>
#include <string>
#include "productData.hpp"

using namespace std;

class competitorProductData : public productData {
    
public:
    competitorProductData();
    competitorProductData(const string productCode, const string productName, const string currency,
            int retailPrice, int unitsSold, double boughtInPrice, double shippingCost, double taxRate, const string competitor);
    virtual bool readFileData(ifstream& File) override;
    string competitor;
    
};

#endif /* competitorProductData_hpp */

