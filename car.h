#ifndef CAR_H_
#define CAR_H_
#include "vehicles.h"

class Car : public Vehicles
{
    private:
        std::string engine_size_litres;
        std::string seats_num;
        std::string door_num;

    public:
        Car(std::string type, std::string make, std::string model, std::string reg_num, std::string color, 
    std::string price, std::string availability, std::string return_date, std::string engine_size_litres, 
    std::string seats_num, std::string door_num)
    {
        this->setType(type);
        this->setMake(make);
        this->setModel(model);
        this->setRegNum(reg_num);
        this->setColor(color);
        this->setPrice(price);
        this->setAvailability(availability);
        this->setReturnDate(return_date);
        this->engine_size_litres = engine_size_litres;
        this->seats_num = seats_num;
        this->door_num = door_num;
    }

    std::string getEngineSizeLitresCar()
    {
        return this->engine_size_litres;
    }

    void setEngineSizeLitresCar(std::string engine_size_litres)
    {
        this->engine_size_litres = engine_size_litres;
    }

    std::string getSeatsNumCar()
    {
        return this->seats_num;
    }

    void setSeatsNumCar(std::string seats_num)
    {
        this->seats_num = seats_num;
    }

    std::string getDoorCar()
    {
        return this->door_num;
    }

    void setDoorCar(std::string door_num)
    {
        this->door_num = door_num;
    }

    void convertString()
    {
        std::cout << std::endl
                  << "MAKE:                    " << this->getMake() << std::endl
                  << "MODEL:                   " << this->getModel() << std::endl
                  << "REGISTRATION NUMBER:     " << this->getReturnDate() << std::endl
                  << "AVAILABLE:               " << this->seats_num << std::endl;
    }

    void convertStringFull()
    {
        std::cout << std::endl
                  << "TYPE:                    " << this->getType() <<std::endl
                  << "MAKE:                    " << this->getMake() << std::endl
                  << "MODEL:                   " << this->getModel() << std::endl
                  << "PRICE:                   " << this->getRegNum() << std::endl
                  << "COLOR:                   " << this->engine_size_litres << std::endl
                  << "ENGINE SIZE:             " << this->getColor() << std::endl
                  << "PASSENGER SEATS:         " << this->getPrice() << std::endl
                  << "DOOR NUMBER:             " << this->getAvailability() << std::endl
                  << "AVAILABLE:               " << this->seats_num << std::endl
                  << "RETURN DATE:             " << this->door_num << std::endl
                  << "REGISTRATION NUMBER:     " << this->getReturnDate() << std::endl;
        }

    std::string fileString()
    {
        return this->type + ":" 
                +this->make + ":"
                + this->model + ":"
                + this->price + ":"
                + this->engine_size_litres + ":"
                + this->seats_num + ":"
                + this->door_num + ":"
                + this->reg_num + ":"
                + this->color + ":"
                + this->availability + ":"
                + this->return_date;
    }
};
#endif