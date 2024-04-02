#include "Stock.h"
#include "Car.h"
#include "Race.h"
#include "Festival.h"

int main() 
{
    //Task 1
    //Stock stock;

    //stock.setAbreviation("XYZ");
    //stock.setName("XYZ Corporation");
    //double prices[12] = { 100.0, 110.0, 120.0, 130.0, 140.0, 150.0, 160.0, 170.0, 180.0, 190.0, 200.0, 109.0 };
    //stock.setPrices(prices);

    //std::cout << "Abbreviation: " << stock.getAbbreviation() << std::endl;
    //std::cout << "Name: " << stock.getName() << std::endl;
    //std::cout << "Prices: ";
    //const double* retrievedPrices = stock.getPrices();
    //for (int i = 0; i < 12; i++) 
    //{
    //    std::cout << retrievedPrices[i] << " ";
    //}
    //std::cout << std::endl;

    //if (stock.isProfitable()) 
    //{
    //    std::cout << "The stock is profitable." << std::endl;
    //}
    //else 
    //{
    //    std::cout << "The stock is not profitable." << std::endl;
    //}

    //task 2

    Car car1, car2;

    car1.setRegNumber("ABC123");
    car1.setManufacturer("Toyota");
    car1.setModel("Corolla");
    double fuelCons1[3] = { 8.5, 9.0, 7.5 };
    car1.setFuelConsumption(fuelCons1);

    car2.setRegNumber("DEF456");
    car2.setManufacturer("Honda");
    car2.setModel("Civic");
    double fuelCons2[3] = { 7.0, 4.8, 5.8 };
    car2.setFuelConsumption(fuelCons2);

    std::cout << "Car 1 Registration Number: " << car1.getRegNumber() << std::endl;
    std::cout << "Car 1 Manufacturer: " << car1.getManufacturer() << std::endl;
    std::cout << "Car 1 Model: " << car1.getModel() << std::endl;
    std::cout << "Car 1 Fuel Consumption: ";
    const double* fuelConsCar1 = car1.getFuelConsumption();
    for (int i = 0; i < 3; ++i) 
    {
        std::cout << fuelConsCar1[i] << " ";
    }

    std::cout << "Car 1 Average Fuel Consumption: " << car1.getAverageFuelConsumption() << std::endl;
    std::cout << "Car 2 Average Fuel Consumption: " << car2.getAverageFuelConsumption() << std::endl;

    std::cout << "Car 1 is Fuel Efficient: " << (car1.isFuelEfficient() ? "Yes" : "No") << std::endl;
    std::cout << "Car 2 is Fuel Efficient: " << (car2.isFuelEfficient() ? "Yes" : "No") << std::endl;

    std::cout << "Car 1 is More Fuel Efficient than Car 2: " << (car1.isMoreFuelElficient(car2) ? "Yes" : "No") << std::endl;
    
    //task 3
    Engine engine;
    engine.setPower(200);
    engine.setDisplacement(2500);
    engine.setVIN("ABCD1234");
    car1.setEngine(engine);

    Wheel wheels[4];
    for (int i = 0; i < 4; ++i) 
    {
        wheels[i].setRadius(18);
        wheels[i].setAlloy(Alloy::Aluminium);
    }
    car1.setWheels(wheels);

    std::cout << "Engine Power: " << car1.getEngine().getPower() << " HP" << std::endl;
    std::cout << "Engine Displacement: " << car1.getEngine().getDisplacement() << " cc" << std::endl;
    std::cout << "Engine VIN: " << car1.getEngine().getVIN() << std::endl;

    for (int i = 0; i < 4; ++i) 
    {
        std::cout << "Wheel " << i + 1 << " Radius: " << car1.getWheel(i).getRadius() << " inches" << std::endl;
        std::cout << "Wheel " << i + 1 << " Alloy: " << car1.getWheel(i).getAlloy() << std::endl;
    }

    // task 4

    Car car3, car4, car5;
    car3.setManufacturer("Opel");
    car3.setModel("Corsa");
    car3.setAcceleration(20);
    car3.setHandling(5);
    car3.setTopSpeed(200);
    car3.setDrivetrain(Drivetrain::Front);

    car4.setManufacturer("Mercedes");
    car4.setModel("A class");
    car4.setAcceleration(35);
    car4.setHandling(7);
    car4.setTopSpeed(360);
    car4.setDrivetrain(Drivetrain::Rear);

    car5.setManufacturer("Toyota");
    car5.setModel("Yaris");
    car5.setAcceleration(12);
    car5.setHandling(60);
    car5.setTopSpeed(180);
    car5.setDrivetrain(Drivetrain::Rear);

    Track track;
    track.setSlowCorners(10);
    track.setFastCorners(5);
    track.setStraightLength(1000);

    Race race;
    race.setTrack(track);
    race.addCar(car3);
    race.addCar(car4);
    race.addCar(car5);

    race.classify();

    //task 5

    Movie movie1("The Godfather", "Francis Ford Coppola", 175);
    Projection projection1(movie1, "2024-04-05 18:00", "Hall 1");
    Festival festival("Movie Festival");
    festival.addProjection(projection1);
    std::cout << "Festival Name: " << festival.getFestivalName() << std::endl;

    std::cout << "Projections:" << std::endl;
    const Projection* projections = festival.getProjections();
    for (int i = 0; i < festival.getNumProjections(); ++i) 
    {
        std::cout << "Movie: " << projections[i].getMovie().getTitle() << std::endl;
        std::cout << "Director: " << projections[i].getMovie().getDirector() << std::endl;
        std::cout << "Length: " << projections[i].getMovie().getLength() << " minutes" << std::endl;
        std::cout << "Date and Time: " << projections[i].getDatetime() << std::endl;
        std::cout << "Hall: " << projections[i].getHallName() << std::endl << std::endl;
    }
    return 0;
}