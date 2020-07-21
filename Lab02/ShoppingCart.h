#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart  {                              // Info about a product
   public:  
      void SetName(string name);      // Sets the product's name     
      void SetDate(string date);
      string GetCustomerName() const;                // gets name
      string GetDate() const;                // gets date
      ShoppingCart();
      ShoppingCart(string cName, string Date);
      
      //new stuff
      void AddItem(ItemToPurchase item);
      
      
      void RemoveItem(string itemName);
      void ModifyItem(ItemToPurchase item);
      int GetNumItemsInCart();
      int GetCostOfCart();
      void PrintTotal();
      void PrintDescriptions();
      
   private:
      string customerName = "none";
      string currentDate = "none";
      vector<ItemToPurchase> cartItems;
};

#endif