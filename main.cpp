//
//  main.cpp
//  priceComparison
//
//  Created by Raeesa Dhoda on 03/12/2023.
//

// main.cpp

#include "productData.hpp"
#include "competitorProductData.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream myFile("/Users/raeesauser/Desktop/ProgramingWithC++/Assignments/Project/Company_Data.txt");
    vector<productData> myProducts;

    ifstream competitorFile("/Users/raeesauser/Desktop/ProgramingWithC++/Assignments/Project/Competitor_Pricing.txt");
    vector<competitorProductData> competitorProducts;

    while (true) {
        competitorProductData competitorProduct;

        if (competitorProduct.readFileData(competitorFile)) {
            competitorProducts.push_back(competitorProduct);
        } else {
            break; // End of file reached
        }
    }

    while (true) {
        productData myProduct;

        if (myProduct.readFileData(myFile)) {
            myProducts.push_back(myProduct);

            // Print company details
            cout << myProduct.productCode << ", Net a Porter, Retail Price: " << myProduct.currency << myProduct.retailPrice << ", GCBM: "<< myProduct.currency << myProduct.computeGCBM() << endl;
            cout << endl;

            // Print competitor details
            for (auto& competitorProduct : competitorProducts) {
                if (myProduct.productCode == competitorProduct.productCode) {
                    competitorProduct.taxRate = myProduct.taxRate;
                    competitorProduct.shippingCost = myProduct.shippingCost;
                    competitorProduct.boughtInPrice = myProduct.boughtInPrice;
                    competitorProduct.unitsSold = myProduct.unitsSold;
                    cout << competitorProduct.productCode << ", " << competitorProduct.competitor << ", Retail Price: " << competitorProduct.currency << competitorProduct.retailPrice << ", GCBM: " << competitorProduct.currency << competitorProduct.computeGCBM() << endl;
                }
            }

            // Recommend adjustments based on GCBM
            double recommendedRetailPrice = 0.0;

            if (myProduct.computeGCBM() < 0) {
                // Case: myProduct.computeGCBM() is negative
                double maxCompetitorGCBM = numeric_limits<double>::lowest();

                for (const auto& competitorProduct : competitorProducts) {
                    if (myProduct.productCode == competitorProduct.productCode && competitorProduct.computeGCBM() > maxCompetitorGCBM) {
                        maxCompetitorGCBM = competitorProduct.computeGCBM();
                        recommendedRetailPrice = competitorProduct.retailPrice;
                    }
                }
                cout << endl;
                if (recommendedRetailPrice > 0) {
                    double adjustmentDirection = recommendedRetailPrice - myProduct.retailPrice;
                    cout << "Consider adjusting the retail price from $" << myProduct.retailPrice
                         << " to $" << recommendedRetailPrice << " to make GCBM positive." << endl;
                } else {
                    cout << endl;
                    cout << "No adjustment recommended for product " << myProduct.productCode << "." << endl;
                }
            } else {
                // Case: myProduct.computeGCBM() is non-negative
                double minPositiveCompetitorGCBM = numeric_limits<double>::max();

                for (const auto& competitorProduct : competitorProducts) {
                    if (myProduct.productCode == competitorProduct.productCode && competitorProduct.computeGCBM() > 0 &&
                        competitorProduct.retailPrice < minPositiveCompetitorGCBM) {
                        minPositiveCompetitorGCBM = competitorProduct.retailPrice;
                        recommendedRetailPrice = competitorProduct.retailPrice;
                    }
                }

                if (recommendedRetailPrice > 0) {
                    double adjustmentDirection = recommendedRetailPrice - myProduct.retailPrice;
                    cout << endl;
                    cout << "Consider adjusting the retail price from $" << myProduct.retailPrice
                         << " to $" << recommendedRetailPrice << " to match the smallest competitor with positive GCBM." << endl;
                } else {
                    cout << endl;
                    cout << "No adjustment recommended for product " << myProduct.productCode << "." << endl;
                }
            }

            cout << endl;
        } else {
            break; // End of file reached
        }
    }

    return 0;
}




