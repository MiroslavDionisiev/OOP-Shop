#include "User.h"
#include <cstring>
#include <iostream>
using namespace std;

User::User()
{
	this->username = "empty";
	this->password = "empty";
}

User::User(string username, string password)
{
	this->username = username;
	this->password = password;
}

User::User(const User& other)
{
	*this = other;
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		this->username = other.username;
		this->password = other.password;
	}
	return *this;
}

//bool User::operator==(const User& other)
//{
//	if ((this->status == other.status) && (this->username == other.username) && (this->password == other.password))
//	{
//		return true;
//	}
//	return false;
//}

//userStatus User::getStatus() const
//{
//	return this->status;
//}
//
//string User::getName() const	
//{
//	return this->username;
//}

string User::getUsername() const
{
	return this->username;
}

string User::getPassword() const
{
	return this->password;
}

Cart User::getCart() const
{
	return Cart();
}

void User::setCart(Cart cart)
{
	return;
}