#include "Admin.h"

Admin::Admin(string username, string password) : User(username, password)
{
	this->status = userStatus::admin;
}

bool Admin::operator==(const Admin& other)
{
	if ((userStatus::admin == other.getStatus()) && (this->getName() == other.getName()) && (this->getPassword() == other.getPassword()))
	{
		return true;
	}
	return false;
}

userStatus Admin::getStatus() const
{
	return userStatus::admin;
}

string Admin::getName() const
{
	return this->getUsername();
}