#include "ProductContainer.h"
#include <iostream>
#include <cstring>
using namespace std;

ProductContainer::ProductContainer(){}

ProductContainer::ProductContainer(const ProductContainer& other)
{
	*this = other;
}

ProductContainer& ProductContainer::operator=(const ProductContainer& other)
{
	if (this != &other)
	{
		this->container = other.container;
	}
	return *this;
}

ProductContainer::~ProductContainer()
{
	this->container.clear();
}

int ProductContainer::getSize() const
{
	return this->container.size();
}

int ProductContainer::getQuantity(string nameOfProduct) const
{
	Product tempProduct = this->getProduct(nameOfProduct);
	if (tempProduct.getNameOfProduct() != "empty")
	{
		map<Product, int>::const_iterator it = this->container.find(tempProduct);
		return it->second;
	}
	else
	{
		return -1;
		cout << "No such item" << endl;
	}
}

Product ProductContainer::getProduct(string nameOfProduct) const
{
	Product tempProduct;
	for (map<Product, int>::const_iterator it = this->container.begin(); it != this->container.end(); ++it)
	{
		if (it->first.getNameOfProduct() == nameOfProduct)
		{
			tempProduct = it->first;
			return tempProduct;
		}
	}
	return tempProduct;
}

const map<Product, int>& ProductContainer::getContainer() const
{
	return this->container;
}

bool ProductContainer::areThereEnoughPieces(string nameOfProduct, int pieces) const
{
	int quantity = this->getQuantity(nameOfProduct);
	if ((pieces > 0) && (quantity >= 0))
	{
		if (quantity >= pieces)
		{
			return true;
		}
	}
	return false;
}

void ProductContainer::addProductPieces(Product product, int pieces)
{
	Product tempProduct = this->getProduct(product.getNameOfProduct());
	if (tempProduct.getNameOfProduct() != "empty")
	{
		this->container[product] += pieces;
	}
	this->container.insert(pair<Product, int>(product, pieces));
}

void ProductContainer::removeProductPieces(Product product, int pieces)
{
	if (this->areThereEnoughPieces(product.getNameOfProduct(), pieces) == true)
	{
		this->container[product] -= pieces;
	}
	else
	{
		cout << "No such product" << endl;
	}
}

void ProductContainer::print() const
{
	this->printByCategory(CategoryName::Computers_and_Laptops);
	this->printByCategory(CategoryName::Electric_appliances);
	this->printByCategory(CategoryName::Telephones);
	this->printByCategory(CategoryName::TV_and_Audio);
}

void ProductContainer::printByCategory(CategoryName category) const
{
	Product tempProduct;
	switch (category)
	{
	case CategoryName::Computers_and_Laptops:
	{
		cout << "Computers and Laptops:" << endl;
		break;
	}
	case CategoryName::Electric_appliances:
	{
		cout << "Electric appliances:" << endl;
		break;
	}
	case CategoryName::Telephones:
	{
		cout << "Telephones:" << endl;
		break;
	}
	case CategoryName::TV_and_Audio:
	{
		cout << "TV and Audio:" << endl;
		break;
	}
	default:
	{
		cout << "There are no items in stock." << endl;
		return;
	}
	}
	for (map<Product, int>::const_iterator it = this->container.begin(); it != this->container.end(); ++it)
	{
		if (it->first.getCategory() == category)
		{
			cout << "Name: " << it->first.getNameOfProduct() << " Count: " << it->second << " Price: " << it->first.getPrice() << endl;
		}
	}
}