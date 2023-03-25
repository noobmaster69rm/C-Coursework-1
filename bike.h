#ifndef BIKE_H_
#define BIKE_H_
#include "vehicles.h"

class Motorbike : public Vehicles
{
    private:
        std::string engine_size_cc;
        std::string passenger_seat;
        std::string hasLuggage;
    
    public:
        Motorbike(std::string type, std::string make, std::string model, std::string reg_num, std::string color, 
    std::string price, std::string availability, std::string return_date, std::string engine_size_cc,
    std::string passenger_seat, std::string hasLuggage)
    {
        this->setType(type);
        this->setMake(make);
        this->setModel(model);
        this->setRegNum(reg_num);
        this->setColor(color);
        this->setPrice(price);
        this->setAvailability(availability);
        this->setReturnDate(return_date);
        this->engine_size_cc = engine_size_cc;
        this->passenger_seat = passenger_seat;
        this->hasLuggage = hasLuggage;
    }

    std::string getEngineSizeCC()
    {
        return this->engine_size_cc;
    }

    void setEngineSizeCC(std::string engine_size_cc)
    {
        this->engine_size_cc = engine_size_cc;
    }

    std::string getPassengerSeat()
    {
        return this->passenger_seat;
    }

    void setPassengerSeat(std::string passenger_seat)
    {
        this->passenger_seat = passenger_seat;
    }

    std::string getHasLuggage()
    {
        return this->hasLuggage;
    }

    void setHasLuggage(std::string hasLuggage)
    {
        this->hasLuggage = hasLuggage;
    }

     void convertString()
    {
        std::cout << std::endl
                  << "MAKE:                    " << this->getMake() << std::endl
                  << "MODEL:                   " << this->getModel() << std::endl
                  << "REGISTRATION NUMBER:     " << this->getReturnDate() << std::endl
                  << "AVAILABLE:               " << this->passenger_seat << std::endl;
        }
    
    void convertStringFull()
    {
        std::cout << std::endl
                  << "TYPE:                    " << this->getType() <<std::endl
                  << "MAKE:                    " << this->getMake() << std::endl
                  << "MODEL:                   " << this->getModel() << std::endl
                  << "PRICE:                   " << this->getRegNum() << std::endl
                  << "COLOR:                   " << this->engine_size_cc << std::endl
                  << "ENGINE SIZE:             " << this->getColor() << std::endl
                  << "PASSENGER SEATS:         " << this->getPrice() << std::endl
                  << "HAS LUGGAGE:             " << this->getAvailability() << std::endl
                  << "AVAILABLE:               " << this->passenger_seat << std::endl
                  << "RETURN DATE:             " << this->hasLuggage << std::endl
                  << "REGISTRATION NUMBER:     " << this->getReturnDate() << std::endl;
        }

    std::string fileString()
    {
        return  this->type + ":"
                +this->make + ":"
                + this->model + ":"
                + this->price + ":"
                + this->engine_size_cc + ":"
                + this->passenger_seat + ":"
                + this->hasLuggage + ":"
                + this->reg_num + ":"
                + this->color + ":"
                + this->availability + ":"
                + this->return_date;
    }
};
#endif