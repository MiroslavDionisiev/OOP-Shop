#include "Cart.h"
#include <cstring>
#include <iostream>
using namespace std;

Cart::Cart()
{
	this->cart = ProductContainer();;
	this->bill = 0;
}

Cart::Cart(const Cart& other)
{
	*this = other;
}

Cart& Cart::operator=(const Cart& other)
{
	if (this != &other)
	{
		this->cart = other.cart;
		this->bill = other.bill;
	}
	return *this;
}

double Cart::getBill() const
{
	return this->bill;
}

ProductContainer Cart::getCart() const
{
	return this->cart;
}

int Cart::getNumberOfDifferentProducts() const
{
	return this->cart.getSize();
}

bool Cart::areThereEnoughPieces(string nameOfProduct, int pieces) const
{
	return this->cart.areThereEnoughPieces(nameOfProduct, pieces);
}

void Cart::addProductPieces(Product product, int pieces)
{
	this->cart.addProductPieces(product, pieces);
	this->bill += product.getPrice() * pieces;
}

void Cart::removeProductPieces(Product product, int pieces)
{
	if (areThereEnoughPieces(product.getNameOfProduct(), pieces) == true)
	{
		this->cart.removeProductPieces(product, pieces);
		this->bill -= product.getPrice() * pieces;
	}
	else
	{
		cout << "Not enough pieces to remove" << endl;
	}
}

void Cart::print() const
{
	if (this->cart.getSize() > 0)
	{
		this->cart.print();
		cout << "The bill is: " << this->bill << endl;
	}
	else
	{
		cout << "The cart is empty" << endl;
	}
}