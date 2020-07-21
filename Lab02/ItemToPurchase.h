#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase  {                              // Info about a product
   public:                                          
      void SetName(string productName);      // Sets the product's name     
      void SetDescription(string productDescription);
      void SetPrice(int productPrice);       // Sets the price
      void SetQuantity(int productQuantity);   // Sets the Quantity

      string GetName() const;                // gets name
      string GetDescription() const;                // gets desc
      int GetPrice() const;                 // gets price
      int GetQuantity() const;              // gets Quantity

      void Print() const;                  //print
      ItemToPurchase();
      ItemToPurchase(string itemNameI, string itemDescriptionI, double itemPriceI, int itemQuantityI);
   private:
      string itemName = "none";
      string itemDescription = "none";
      int itemPrice;
      int itemQuantity;
};

#endif