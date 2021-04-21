#include "Product.h"
#include <cstring>

Product::Product()
{
	this->category = CategoryName::none;
	this->nameOfProduct = "empty";
	setPrice(0);
}

Product::Product(CategoryName category, string nameOfProduct, double price)
{
	this->category = category;
	this->nameOfProduct = nameOfProduct;
	setPrice(price);
}

Product::Product(const Product& other)
{
	*this = other;
 }

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		this->category = other.category;
		this->nameOfProduct = other.nameOfProduct;
		setPrice(other.price);
	}
	return *this;
}

bool Product::operator< (const Product& rhs) const
{
	if (this->nameOfProduct < rhs.getNameOfProduct())
	{
		return true;
	}
	return false;
}

void Product::setPrice(double price)
{
	this->price = price;
}

CategoryName Product::getCategory() const
{
	return this->category;
}

string Product::getNameOfProduct() const
{
	return this->nameOfProduct;
}

double Product::getPrice() const
{
	return this->price;
}