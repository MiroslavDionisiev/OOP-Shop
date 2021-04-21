#pragma once
#include "User.h"
#include "Cart.h"
#include <string>
using namespace std;

class Client : public User
{
private:
	userStatus status;
	Cart cart;

public:
	Client(string username, string password);
	Client(const Client& other);
	Client& operator=(const Client& other);

	bool operator== (const Client& other);

	userStatus getStatus() const override;
	string getName() const override;
	virtual Cart getCart() const;

	virtual void setCart(Cart cart);
};

