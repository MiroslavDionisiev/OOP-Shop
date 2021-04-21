#pragma once
#include "Cart.h"
#include <string>
using namespace std;

enum class userStatus
{
	admin,
	client
};

class User
{
private:
	string username;
	string password;

protected:
	string getUsername() const;
	string getPassword() const;

public:
	User();
	User(string username, string pasword);
	User(const User& other);
	User& operator= (const User& other);

	virtual userStatus getStatus() const = 0;
	virtual string getName() const = 0;
	virtual Cart getCart() const;

	virtual void setCart(Cart cart);
};

