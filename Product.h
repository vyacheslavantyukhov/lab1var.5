#pragma once

#include <string>

class Product {
public:
	std::string name;
	float price;
	float weight;

	Product()
		: name("NONAME")
		, price(0.0f)
		, weight(0.0f)
	{}

	Product(const Product& other)
		: name(other.name)
		, price(other.price)
		, weight(other.weight)
	{}

	Product(const std::string& name, float price, float weight)
		: name(name)
		, price(price)
		, weight(weight)
	{}

	Product& operator= (const Product& other)
	{
		if (&other != this) {
			name = other.name;
			price = other.price;
			weight = other.weight;
		}
		return *this;
	}

	bool operator== (const Product& other)
	{
		return (name == other.name)
			&& (std::abs(price - other.price) < 1e-8)
			&& (std::abs(weight - other.weight) < 1e-8);
	}
};

std::ostream& operator<< (std::ostream& out, const Product& product)
{
	out << "[" << product.name << " -- $" << product.price << " -- " << product.weight << " kg]";
	return out;
}