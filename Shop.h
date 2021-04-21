#pragma once
#include "ProductContainer.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include <string>
#include <vector>
using namespace std;

class Shop
{
private:
	ProductContainer storage;
	vector<User*> logOfUsers; // all the users the shop recognises
	User* loggedUser = nullptr;  // the logged user navigates around the shop, filles its cart and can make a purchase. If he logs off the products in the cart of the user are
	                  // remembered for the nexr time he logs in

	bool isPurchaseValdi() const;

	int getIndexOfUser(User& user) const;

public:
	Shop();
	Shop(const Shop& other);
	Shop& operator=(const Shop& other);
	~Shop();

	void addUser(User& user);
	void removeUser(User& user);

	void logInShop(User& user);
	void logOffShop();

	void addProductPiecesToStorage(Product product, int pieces);
	void removeProductPiecesFromStorage(Product product, int pieces);

	void addPiecesOfAProductInCart(string nameOfProduct, int pieces);
	void removePiecesOfAProductInCart(string nameOfProduct, int pieces);
	void removeAllProductsInCart();

	void purchase();

	void printStorage() const;
	void printStorageByCategory(CategoryName category) const;
	void printCartOfUser() const;
};