#include"Product.h"
#include"Shop.h"
#include <iostream>

int main()
{
    //task 1

    Product product1("Apple", Food, 100, 10, 1.50);
    Product product2("Water", Drink, 500, 20, 0.0f);

    std::cout << "Product 1:" << std::endl;
    product1.printProduct();
    std::cout << std::endl;

    std::cout << "Product 2:" << std::endl;
    product2.printProduct();
    std::cout << std::endl;

    std::cout << "Different Products Count Initially: " << Product::differentProductsCount << std::endl;
    std::cout << "All Products Count Initially: " << Product::allProductsCount << std::endl;

    Product::addProduct(product1);
    Product::addProduct(product2);

    std::cout << "Different Products Count After Adding The Products: " << Product::differentProductsCount << std::endl;
    std::cout << "All Products Count After Adding The Products: " << Product::allProductsCount << std::endl;

    Product::sellProduct(product1, 5);
    Product::sellProduct(product2, 10);

    std::cout << "Different Products Count After Deleting The Products: " << Product::differentProductsCount << std::endl;
    std::cout << "All Products Count After Deleting The Products: " << Product::allProductsCount << std::endl;

    //task 2
    std::cout << "==========================================TASK 2<<==========================================" << std:: endl;
    Shop shop("MyShop");

    Product* product3 = new Product("Apple", Food, 100, 10, 1.50);
    Product* product4 = new Product("Water", Drink, 500, 20, 0.5);
    Product* product5 = new Product("Banana", Food, 80, 15, 1.2);

    Product* productsToAdd[] = { product3, product4, product5, nullptr };

    shop.addProducts(productsToAdd);

    std::cout << "Shop Name: " << shop.getName() << std::endl;

    std::cout << "Products in the shop:" << std::endl;
    for (int i = 0; i < shop.getSize(); ++i) {
        std::cout << "Name: " << shop.getProductList()[i]->getName() << ", Count: " << shop.getProductList()[i]->getCount() << std::endl;
    }

    shop.removeProduct(*product3);
    Product* product6 = new Product("Banana", Food, 80, 2, 1.2);
    shop.removeProduct(*product6);


    std::cout << "\nProducts in the shop after removal:" << std::endl;
    for (int i = 0; i < shop.getSize(); ++i) {
        std::cout << "Name: " << shop.getProductList()[i]->getName() << ", Count: " << shop.getProductList()[i]->getCount() << std::endl;
    }

}