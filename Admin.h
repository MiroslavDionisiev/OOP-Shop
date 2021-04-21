#pragma once
#include "User.h"
#include <string>
using namespace std;

class Admin : public User
{
private:
	userStatus status;

public:
	Admin(string username, string password);

	bool operator== (const Admin& other);

	userStatus getStatus() const override;
	string getName() const override;
};
