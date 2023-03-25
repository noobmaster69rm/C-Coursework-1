#ifndef VEHICLES_H_
#define VEHICLES_H_

#include <string>
#include <iostream>

class Vehicles
{
protected:
        std::string type;
        std::string make;
        std::string model;
        std::string reg_num;
        std::string color;
        std::string price;
        std::string availability;
        std::string return_date;

public:
        Vehicles()
        {

        }
virtual ~Vehicles() {}

    Vehicles(std::string type, std::string make, std::string model, std::string reg_num, std::string color, 
    std::string price, std::string availability, std::string return_date)
    {
            this->type = type;
            this->make = make;
            this->model = model;
            this->reg_num = reg_num;
            this->color = color;
            this->price = price;
            this->availability = availability;
            this->return_date = return_date;
    }

    std::string getType()
    {
        return this->type;
    }

    void setType(std::string type)
    {
        this->type = type;
    }

    std::string getMake()
    {
        return this->make;
    }

    void setMake(std::string make)
    {
        this->make = make;
    }

    std::string getModel()
    {
        return this->model;
    }

    void setModel(std::string model)
    {
        this->model = model;
    }

    std::string getRegNum()
    {
        return this->reg_num;
    }

     void setRegNum(std::string reg_num)
    {
        this->reg_num = reg_num;
    }

    std::string getColor()
    {
        return this->color;
    }

    void setColor(std::string color)
    {
        this->color = color;
    }

    std::string getPrice()
    {
        return this->price;
    }

    void setPrice(std::string price)
    {
        this->price = price;
    }

    std::string getAvailability()
    {
        return this->availability;
    }

    void setAvailability(std::string availability)
    {
        this->availability = availability;
    }

    std::string getReturnDate()
    {
        return this->return_date;
    }

    void setReturnDate(std::string return_date)
    {
        this->return_date = return_date;
    }

    virtual void convertString()
    {
        if (getRegNum() != "")
        {
            std::cout << std::endl
                      << "TYPE:                  " << this->type << std::endl
                      << "MAKE:                  " << this->make << std::endl
                      << "MODEL:                 " << this->model << std::endl
                      << "REGISTRATION NUM:      " << this->reg_num << std::endl
                      << "COLOR:                 " << this->color << std::endl
                      << "PRICE:                 " << this->price << std::endl
                      << "AVAILABILITY:          " << this->availability << std::endl
                      << "RETURN DATE:           " << this->return_date << std::endl;
        }
    }

    virtual void convertStringFull()
    {
        if (getRegNum() != "")
        {
            std::cout << std::endl
                      << "TYPE:                  " << this->type << std::endl
                      << "MAKE:                  " << this->make << std::endl
                      << "MODEL:                 " << this->model << std::endl
                      << "REGISTRATION NUM:      " << this->reg_num << std::endl
                      << "COLOR:                 " << this->color << std::endl
                      << "PRICE:                 " << this->price << std::endl
                      << "AVAILABILITY:          " << this->availability << std::endl
                      << "RETURN DATE:           " << this->return_date << std::endl;
        }
    }



    virtual std::string fileString()
    {
        return this->type + ":"
                +this->make + ":"
                + this->model + ":"
                + this->reg_num + ":"
                + this->color + ":"
                + this->price + ":"
                + this->availability + ":"
                + this->return_date + ":";
    }
};
#endif