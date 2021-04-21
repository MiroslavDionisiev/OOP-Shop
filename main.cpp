#include <iostream>
#include "Shop.h"
#include "Product.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"
#include "List.h"
using namespace std;

int main()
{
	Shop shop;
	Admin admin("hs", "s");
	Client a("hh", "s");
	Client b("aa", "v");
	shop.addUser(admin);
	shop.addUser(a);
	shop.addUser(a);
	shop.logInShop(b);
	shop.logInShop(admin);
	shop.addProductPiecesToStorage(Product(CategoryName::Telephones, "Nokia", 400), 3);
	shop.addProductPiecesToStorage(Product(CategoryName::Computers_and_Laptops, "HP", 400), 3);
	shop.addProductPiecesToStorage(Product(CategoryName::Telephones, "Samsung", 400), 3);
	shop.printStorage();
	cout << "//////////////////////" << endl;
	shop.addPiecesOfAProductInCart("HP", 2);
	cout << "//////////////////////" << endl;
	shop.logOffShop();
	shop.logInShop(a);
	shop.addPiecesOfAProductInCart("HP", 3);
	shop.printCartOfUser();
	cout << "//////////////////////" << endl;
	shop.removePiecesOfAProductInCart("HP", 4);
	cout << "//////////////////////" << endl;
	shop.logOffShop();
	shop.logInShop(a);
	shop.printCartOfUser();
	cout << "//////////////////////" << endl;
	cout << "//////////////////////" << endl;
	shop.purchase();
	shop.addPiecesOfAProductInCart("HP", 3);
	shop.removePiecesOfAProductInCart("HP", 3);
	cout << "//////////////////////" << endl;
	shop.printStorage();
	cout << "//////////////////////" << endl;
	shop.printCartOfUser();
	cout << "//////////////////////" << endl;
	shop.removeProductPiecesFromStorage(Product(CategoryName::Telephones, "Samsung", 400), 2);
	cout << "//////////////////////" << endl;
	shop.logOffShop();
	shop.logInShop(admin);
	shop.removeProductPiecesFromStorage(Product(CategoryName::Telephones, "Samsung", 400), 2);
	shop.printStorageByCategory(CategoryName::Telephones);
	cout << "//////////////////////" << endl;
	shop.printStorageByCategory(CategoryName::Computers_and_Laptops);
	cout << "//////////////////////" << endl;
	shop.logOffShop();
	shop.logInShop(a);
	shop.removePiecesOfAProductInCart("HP", 2);

	Client v("aass", "v");
	User* aa = &v;

	Admin bb = admin;
	cout << bb.getName() << endl;
	if (bb.getStatus() == userStatus::admin)
	{
		cout << "admin" << endl;
	}

	/*List<int> arr;

	arr.pushBack(2);
	arr.pushBack(423);
	arr.pushBack(23);
	arr.pushBack(54);
	arr.pushBack(53);

	arr.print();

	arr.popBack();
	arr.print();

	arr.popFront();
	arr.print();

	arr.remove(-1);
	arr.print();

	arr.remove(1);
	arr.print();

	arr.insert(3, 67);
	arr.print();

	arr.insert(-1, 4);
	arr.print();*/

	return 0;
}