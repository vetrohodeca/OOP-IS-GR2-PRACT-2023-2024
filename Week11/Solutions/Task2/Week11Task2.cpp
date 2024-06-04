#include <iostream>
#include "HouseClub.h"
#include "PopFolkClub.h"
#include "RockClub.h"

int main() {
    Customer customer1("Alex", 25, 100.0, 2, 3, false, 0, "", "House");
    Customer customer2("Stoyan", 30, 50.0, 1, 1, true, 0, "", "Rock");
    Customer customer3("Ivan", 22, 30.0, 0, 2, false, 0, "John Doe", "PopFolk");


    HouseClub houseClub("Yalta", 0, 50, 3);
    PopFolkClub popFolkClub("Illusion", 0, 40, "Aliisia");
    RockClub rockClub("Barabar", 0, 60, true);

    std::cout << "Testing HouseClub:" << std::endl;
    std::cout << "Can Alex enter? " << (houseClub.canEnter(customer1) ? "Yes" : "No") << std::endl;
    std::cout << "Can Stoyan enter? " << (houseClub.canEnter(customer2) ? "Yes" : "No") << std::endl;
    std::cout << "Can Ivan enter? " << (houseClub.canEnter(customer3) ? "Yes" : "No") << std::endl;

    std::cout << "\nTesting PopFolkClub:" << std::endl;
    std::cout << "Can Alex enter? " << (popFolkClub.canEnter(customer1) ? "Yes" : "No") << std::endl;
    std::cout << "Can Stoyan enter? " << (popFolkClub.canEnter(customer2) ? "Yes" : "No") << std::endl;
    std::cout << "Can Ivan enter? " << (popFolkClub.canEnter(customer3) ? "Yes" : "No") << std::endl;

    std::cout << "\nTesting RockClub:" << std::endl;
    std::cout << "Can Alex enter? " << (rockClub.canEnter(customer1) ? "Yes" : "No") << std::endl;
    std::cout << "Can Stoyan enter? " << (rockClub.canEnter(customer2) ? "Yes" : "No") << std::endl;
    std::cout << "Can Ivan enter? " << (rockClub.canEnter(customer3) ? "Yes" : "No") << std::endl;

    return 0;
}