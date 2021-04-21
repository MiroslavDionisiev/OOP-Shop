#pragma once
#include "Product.h"
#include <string>
#include <map>
using namespace std;

class ProductContainer
{
private:
	map<Product, int> container;

public:
	ProductContainer();
	ProductContainer(const ProductContainer& other);
	ProductContainer& operator=(const ProductContainer& other);
	~ProductContainer();

	int getSize() const;
	int getQuantity(string nameOfProduct) const;
	Product getProduct(string nameOfProduct) const;
	const map<Product, int>& getContainer() const;

	bool areThereEnoughPieces(string nameOfProduct, int pieces) const;

	void addProductPieces(Product product, int pieces);
	void removeProductPieces(Product product, int pieces);

	void print() const;
	void printByCategory(CategoryName category) const;
};

