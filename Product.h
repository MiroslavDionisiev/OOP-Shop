#pragma once
#include <string>
using namespace std;

enum class CategoryName
{
	Electric_appliances,
	Computers_and_Laptops,
	TV_and_Audio,
	Telephones,
	none
};

class Product
{
private:
	CategoryName category;
	string nameOfProduct;
	double price;

	void setPrice(double price);

public:
	Product();
	Product(CategoryName category, string nameOfProduct, double price);
	Product(const Product& other);
	Product& operator=(const Product& other);
	bool operator< (const Product& rhs) const;

	CategoryName getCategory() const;
	string getNameOfProduct() const;
	double getPrice() const;
};

