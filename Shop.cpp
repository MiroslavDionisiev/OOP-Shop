#include "Shop.h"
#include <cstring>
#include <iostream>
using namespace std;

Shop::Shop()
{
	this->storage = ProductContainer();
}

Shop::Shop(const Shop& other)
{
	*this = other;
}

Shop& Shop::operator=(const Shop& other)
{
	if (this != &other)
	{
		this->storage = other.storage;
		this->loggedUser = other.loggedUser;
		this->logOfUsers = other.logOfUsers;
	}
	return *this;
}

Shop::~Shop()
{
	this->logOfUsers.clear();
}

bool Shop::isPurchaseValdi() const
{
	map<Product, int> tempContainer = this->loggedUser->getCart().getCart().getContainer();
	for (map<Product, int>::const_iterator it = tempContainer.begin(); it != tempContainer.end(); ++it)
	{
		if (it->second > this->storage.getQuantity(it->first.getNameOfProduct()))
		{
			return false;
		}
	}
	return true;
}

int Shop::getIndexOfUser(User& user) const
{
	for (int i = 0; i < this->logOfUsers.size(); i++)
	{
		if ((&user == this->logOfUsers[i]) == true)
		{
			return i;
		}
	}
	return -1;
}

void Shop::addUser(User& user)
{
	for (int  i = 0; i < this->logOfUsers.size(); i++)
	{
		if (this->logOfUsers[i] == &user)
		{
			cout << "Such user exists" << endl;
			return;
		}
	}
	this->logOfUsers.push_back(&user);
}

void Shop::removeUser(User& user)
{
	for (int i = 0; i < this->logOfUsers.size(); i++)
	{
		if ((&user == this->logOfUsers[i]) == true)
		{
			this->logOfUsers.erase(this->logOfUsers.begin() + i - 1);
			return;
		}
	}
}

void Shop::logInShop(User& user)
{
	if (this->loggedUser == &user)
	{
		return;
	}
	if (this->loggedUser != nullptr)
	{
		cout << "User already logged" << endl;
		return;
	}
	int indexOfUser = this->getIndexOfUser(user);
	if (indexOfUser >= 0)
	{
		this->loggedUser = this->logOfUsers[indexOfUser];
		return;
	}
	cout << "No such user found" << endl;
}

void Shop::logOffShop()
{
	int indexOfUser = this->getIndexOfUser(*this->loggedUser);
	if (indexOfUser >= 0)
	{
		this->logOfUsers[indexOfUser] = this->loggedUser;
		this->loggedUser = nullptr;
		return;
	}
	cout << "No such user found" << endl;
}

void Shop::addProductPiecesToStorage(Product product, int pieces)
{
	if (this->loggedUser->getStatus() == userStatus::admin)
	{
		this->storage.addProductPieces(product, pieces);
	}
	else
	{
		cout << "Not autorize" << endl;
	}
}

void Shop::removeProductPiecesFromStorage(Product product, int pieces)
{
	if (this->loggedUser->getStatus() == userStatus::admin)
	{
		if (this->storage.areThereEnoughPieces(product.getNameOfProduct(), pieces) == true)
		{
			this->storage.removeProductPieces(product, pieces);
		}
		else
		{
			cout << "Not enough pieces to remove" << endl;
		}
	}
	else
	{
		cout << "Not autorize" << endl;
	}
}

void Shop::addPiecesOfAProductInCart(string nameOfProduct, int pieces)
{
	if (this->loggedUser->getStatus() == userStatus::client)
	{
		if ((this->storage.getQuantity(nameOfProduct) >= pieces) && (this->storage.getQuantity(nameOfProduct) > 0) && (pieces > 0))
		{
			Cart tempCart = this->loggedUser->getCart();
			tempCart.addProductPieces(this->storage.getProduct(nameOfProduct), pieces);
			this->loggedUser->setCart(tempCart);
		}
		else
		{
			cout << "Not enough products to add" << endl;
		}
	}
	else
	{
		cout << "Not autorize" << endl;
	}
}

void Shop::removePiecesOfAProductInCart(string nameOfProduct, int pieces)
{
	if (this->loggedUser->getStatus() == userStatus::client)
	{
		if (this->loggedUser->getCart().getCart().getQuantity(nameOfProduct) >= pieces)
		{
			Cart tempCart = this->loggedUser->getCart();
			tempCart.removeProductPieces(this->storage.getProduct(nameOfProduct), pieces);
			this->loggedUser->setCart(tempCart);
		}
		else
		{
			cout << "Not enough products to remove" << endl;
		}
	}
	else
	{
		cout << "Not autorize" << endl;
	}
}

void Shop::removeAllProductsInCart()
{
	Cart emptyCart = Cart();
	this->loggedUser->setCart(emptyCart);
}

void Shop::purchase()
{
	if ((this->loggedUser->getStatus() == userStatus::client) && (this->isPurchaseValdi() == true))
	{
		int indexOFCartSlots = 0;
		indexOFCartSlots = this->loggedUser->getCart().getNumberOfDifferentProducts();
		map<Product, int> tempContainer = this->loggedUser->getCart().getCart().getContainer();
		for (map<Product, int>::const_iterator it = tempContainer.begin(); it != tempContainer.end(); ++it)
		{
			this->storage.removeProductPieces(it->first, it->second);
		}
		Cart newEmptyCart;
		this->loggedUser->setCart(newEmptyCart);
		cout << "Purchase completed" << endl;
	}
	else
	{
		cout << "Too many products in cart" << endl;
	}
}

void Shop::printStorage() const
{
	this->storage.print();
}

void Shop::printStorageByCategory(CategoryName category) const
{
	this->storage.printByCategory(category);
}

void Shop::printCartOfUser() const
{
	if (this->loggedUser->getStatus() == userStatus::client)
	{
		this->loggedUser->getCart().print();
	}
}