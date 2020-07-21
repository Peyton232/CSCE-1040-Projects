#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"



void PrintMenu(ShoppingCart cart){
   //choice
   char choice = 'm';
   ItemToPurchase item;
 
    //menuloop
    while (choice != 'q'){
      cout << "MENU" << endl;
      cout << "a - Add item to cart" << endl;
      cout << "d - Remove item from cart" << endl;
      cout << "c - Change item quantity" << endl;
      cout << "i - Output items' descriptions" << endl;
      cout << "o - Output shopping cart" << endl;
      cout << "q - Quit" << endl << endl;
      cout << "Choose an option:\n";
      cin >> choice;
      
      if (choice == 'a'){
         //add item to the cart
       cart.AddItem(item);  
      } else if (choice == 'd'){
         
      } else if (choice == 'c'){
         
      } else if (choice == 'i'){
         
      } else if (choice == 'o'){
         
      } else if (choice == 'q'){
         cout << "quitting";
      } else {
       cout <<  "wrong";  
      }

   }
}

int main() {
   
   //variables
   string name;
   
   //objects
   ShoppingCart cart;
   
   
   /*
   Enter customer's name:
   John Doe
   Enter today's date:
   */
   
   //prompt and get info
   cout << "Enter customer's name:\n";
   getline(cin, name);
   cart.SetName(name);
   
   cout << "Enter today's date:\n\n";
   getline(cin, name);
   cart.SetDate(name);
   
   //output info
   cout << "Customer name: " << cart.GetCustomerName() << endl;
   cout << "Today's date: " << cart.GetDate() << endl;
   
   
   
   
   
   //menu
   PrintMenu(cart);
   
   
   
   
   
   return 0;
}