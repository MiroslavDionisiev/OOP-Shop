#include "Client.h"

Client::Client(string username, string password) : User(username, password)
{
	this->status = userStatus::client;
	this->cart = Cart();
}

Client::Client(const Client& other)
{
	*this = other;
}

Client& Client::operator=(const Client& other)
{
	if (this != &other)
	{
		User::operator=(other);
		this->status = other.status;
		this->cart = other.cart;
	}
	return *this;
}

bool Client::operator==(const Client& other)
{
	if ((userStatus::admin == other.getStatus()) && (this->getName() == other.getName()) && (this->getPassword() == other.getPassword()))
	{
		return true;
	}
	return false;
}

userStatus Client::getStatus() const
{
	return userStatus::client;
}

string Client::getName() const
{
	return this->getUsername();
}

Cart Client::getCart() const
{
	return this->cart;
}

void Client::setCart(Cart cart)
{
	this->cart = cart;
}