#pragma once
#include "ProductContainer.h"
#include <string>
#include <map>
using namespace std;

class Cart
{
private:
	ProductContainer cart;
	double bill;

public:
	Cart();
	Cart(const Cart& other);
	Cart& operator=(const Cart& other);

	double getBill() const;
	ProductContainer getCart() const;
	int getNumberOfDifferentProducts() const;

	bool areThereEnoughPieces(string, int pieces) const;

	void addProductPieces(Product product, int pieces);
	void removeProductPieces(Product product, int pieces);
	void print() const;
};

