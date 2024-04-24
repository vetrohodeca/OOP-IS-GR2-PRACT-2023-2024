#include "Shop.h"


Shop::Shop() : name(""), productList(nullptr), size(0), capacity(4)
{
	this->productList = new Product * [capacity] {nullptr};;
}

Shop::Shop(const Shop& other)
{
	copyFrom(other);
}

Shop::Shop(const MyString& shopName) :name(shopName), size(0), capacity(4)
{
	this->productList = new Product * [capacity] {nullptr};
}


Shop& Shop::operator=(const Shop& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Shop::~Shop()
{
	free();
}
void Shop::copyFrom(const Shop& other)
{
	size = other.size;
	capacity = other.capacity;

	productList = new Product * [capacity];
	for (int i = 0; i < size; i++)
	{
		if (other.productList[i] == nullptr)
		{
			productList[i] = nullptr;
		}
		else
		{
			productList[i] = new Product(*other.productList[i]);
		}
	}
}

void Shop::free()
{
	for (int i = 0; i < size; i++)
		delete productList[i];
	delete[] productList;
}

void Shop::resize(unsigned capacity)
{
	Product** newDataPtr = new Product * [capacity] {nullptr};

	for (int i = 0; i < size; i++)
		newDataPtr[i] = productList[i];

	delete[] productList;
	productList = newDataPtr;

	this->capacity = capacity;
}
void Shop::setName(const MyString& newName)
{
	name = newName;
}

MyString Shop::getName() const
{
	return name;
}

unsigned Shop::getSize() const
{
	return size;
}

Product** Shop::getProductList() const
{
	return productList;
}

void Shop::addProducts(Product** productList)
{
	for (int i = 0; productList[i] != nullptr; ++i)
	{
		Product* newProduct = productList[i];
		bool found = false;
		for (int j = 0; j < size; ++j)
		{
			if (*productList[j] == *newProduct)
			{
				productList[j]->setCount(productList[j]->getCount() + newProduct->getCount());
				Product::allProductsCount += newProduct->getCount();
				found = true;
				break;
			}
		}
		if (!found)
		{
			if (size >= capacity)
			{
				resize(capacity * 2);
			}

			this->productList[size++] = newProduct;

			Product::differentProductsCount++;
			Product::allProductsCount += newProduct->getCount();
		}
	}
}
void Shop::removeProduct(Product& product)
{
	int indexToRemove = -1;

	for (int i = 0; i < this->size; ++i)
	{
		if (*productList[i] == product)
		{
			indexToRemove = i;
			break;
		}
	}

	if (indexToRemove != -1)
	{
		if (product.getCount() == productList[indexToRemove]->getCount())
		{
			Product::differentProductsCount--;
			delete productList[indexToRemove];

			for (int i = indexToRemove; i < size - 1; ++i)
			{
				productList[i] = productList[i + 1];
			}

			--size;

			if (size < capacity / 4)
			{
				resize(capacity / 2);
			}
		}
		else 
		{
			productList[indexToRemove]->setCount(productList[indexToRemove]->getCount() - product.getCount());
		}
	}
	Product::allProductsCount -= productList[indexToRemove]->getCount();
}