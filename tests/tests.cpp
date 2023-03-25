#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../app.hpp"

TEST_CASE("test isDigit", "[intInput]")
{
    REQUIRE(!intInput("-1"));
    REQUIRE(intInput("123456789101112"));
    REQUIRE(!intInput("111.1"));
    REQUIRE(!intInput("≥≈“«≥"));
    REQUIRE(intInput("25"));
}

TEST_CASE("test data written to file when saving or loading")
{
    SECTION( "Test string for Bike" ) 
    {
        Motorbike bike("bike", "Honda", "Fireblade", "25", "199", "No", "No", "BCC123", "red", "Yes", "N/A");
        REQUIRE(bike.fileString() == "bike:Honda:Fireblade:No:red:Yes:N/A:25:199:No:BCC123");
    }
    
    SECTION( "Test string for Van" ) 
    {
        Van van("van", "Toyota", "Hilux", "75", "3.0", "5", "5", "AB123", "red", "Yes", "N/A");
        REQUIRE(van.fileString() == "van:Toyota:Hilux:5:red:Yes:N/A:75:3.0:5:AB123");
    }

    SECTION( "Test string for Car" ) 
    {
        Car car("car", "Toyota", "Aqua", "50", "1.5", "5", "5", "ABC123", "white", "No", "30/04/2023");
        REQUIRE(car.fileString() == "car:Toyota:Aqua:5:white:No:30/04/2023:50:1.5:5:ABC123");
    }
}
