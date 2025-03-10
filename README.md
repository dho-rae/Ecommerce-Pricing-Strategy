# Competitive Pricing Analysis

## Overview
This project implements a **competitive pricing analysis system** for an online retailer to dynamically adjust product prices based on competitor pricing and internal profitability metrics. The program analyses various factors, including:

- **Quantity sold** over a given period
- **Shipping costs**
- **Profit margin (GCBM - Gross Contribution Before Marketing)**
- **Competitor prices**

Using these parameters, the system evaluates whether adjusting the price to match competitors would be beneficial, assuming sales volume remains constant. The program then **proposes a price change** (or none, if not required).

## Features
- Parses competitor price data and internal sales records
- Computes profit margins under current and competitor pricing
- Evaluates pricing adjustments without impacting sales volume
- Suggests price changes based on profitability assessment

## Class Structure
### **1. ProductData** (`productData.hpp`, `productData.cpp`)
Handles the internal pricing and sales data for each product, including:
- Storing product details (ID, name, price, quantity sold)
- Calculating the **Gross Contribution Before Marketing (GCBM)**

### **2. CompetitorProductData** (`competitorProductData.hpp`, `competitorProductData.cpp`)
Manages external pricing data, including:
- Competitor prices for the same product
- Evaluation of pricing adjustments

### **3. Main Application** (`main.cpp`)
- Reads input data
- Computes profitability under different pricing strategies
- Displays **recommended price adjustments**

## Installation & Usage
### **1. Compile the Program**
```bash
g++ -o pricing_analysis main.cpp productData.cpp competitorProductData.cpp
```
### **2. Run the Program**
```bash
./pricing_analysis
```
### **3. Sample Output**
```
Product: Designer Handbag
Current Price: $1200
Competitor Price: $1100
Suggested Price Adjustment: Reduce to $1150 to stay competitive
```
