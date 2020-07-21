#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

// Sets the product's name
void ItemToPurchase ::SetName(string productName) {
   itemName = productName;
}

// Sets the product's name
void ItemToPurchase::SetDescription(string productDescription) {
   itemDescription = productDescription;
}

// Sets the price 
void ItemToPurchase ::SetPrice(int productPrice) {
   itemPrice = productPrice;
}

// Sets the Quantity
void ItemToPurchase ::SetQuantity(int productQuantity) {
   itemQuantity = productQuantity;
}

string ItemToPurchase::GetName() const {
   return itemName;
}

string ItemToPurchase::GetDescription() const {
   return itemDescription;
}

int ItemToPurchase::GetPrice() const {
   return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
   return itemQuantity;
}

//default constructor 
ItemToPurchase::ItemToPurchase(){
    itemName = "0";
    itemDescription = "0";
     itemPrice = 0;
   itemQuantity = 0;
}

//set construction
ItemToPurchase::ItemToPurchase(string itemNameI, string itemDescriptionI, double itemPriceI, int itemQuantityI){
    itemName = itemNameI;
    itemDescription = itemDescriptionI;
     itemPrice = itemPriceI;
   itemQuantity = itemQuantityI;
}
