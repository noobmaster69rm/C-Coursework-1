#ifndef APP_HPP_
#define APP_HPP_
#include "vehicles.h"
#include "bike.h"
#include "car.h"
#include "van.h"
#include <fstream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>

std::vector<Vehicles*> vehicles;

bool intInput(std::string price)
{
	if (price.empty())
		return false;

	for (char &c: price)
	{
		if (std::isdigit(c) == 0 || price.empty())
		{
			return false;
		}
	}
	return true;
}

std::vector<std::string > splitBySpecialChar(std::string str, std::vector<std::string > &result, std::string specialChar)
{
	if (str.find(specialChar) == std::string::npos)
	{
		result.push_back(str.substr(0, str.find(specialChar)));
		return result;
	}
	result.push_back(str.substr(0, str.find(specialChar)));
	str = str.substr(str.find(specialChar) + 1);
	return splitBySpecialChar(str, result, specialChar);
}

void loadData(char *filename)
{
	vehicles.clear();
	std::ifstream file(filename);
	std::string newLine;

	if (file.is_open())
	{
		std::cout << "File successfully loaded";

		while (std::getline(file, newLine))
		{
			std::vector<std::string > results;
			splitBySpecialChar(newLine, results, ":");

			if (results.at(0) == "bike")
			{
				vehicles.emplace_back(new Motorbike(results.at(0), results.at(1), results.at(2), results.at(3), results.at(4),
					results.at(5), results.at(6), results.at(7), results.at(8), results.at(9), results.at(10)));
			}
			else if (results.at(0) == "van")
			{
				vehicles.emplace_back(new Van(results.at(0), results.at(1), results.at(2), results.at(3), results.at(4),
					results.at(5), results.at(6), results.at(7), results.at(8), results.at(9), results.at(10)));
			}
			else if (results.at(0) == "car")
			{
				vehicles.emplace_back(new Car(results.at(0), results.at(1), results.at(2), results.at(3), results.at(4),
					results.at(5), results.at(6), results.at(7), results.at(8), results.at(9), results.at(10)));
			}
		}
	}
	file.close();
}

void saveData(char *filename)
{
	std::ofstream fileToSaveTo;

	fileToSaveTo.open(filename);
	std::cin.ignore(256, '\n');
	if (!fileToSaveTo)
	{
		std::cerr << "Error: file could not be opened" << std::endl;
		exit(1);
	}

	for (std::string::size_type i = 0; i < vehicles.size(); i++)
		fileToSaveTo << vehicles[i]->fileString() << "\n";
	fileToSaveTo.close();
	
	std::cout << "File successfully saved";
}

void addVehicle()
{
	std::string type;
	std::string make;
	std::string model;
	std::string reg_num;
	std::string color;
	std::string price;
	std::string availability;
	std::string return_date;

	std::cin.ignore(256, '\n');

	std::cout << "Enter make: ";
	std::cin >> make;

	std::cout << "Enter model: ";
	std::cin >> model;

	std::cout << "Enter registration number: ";
	std::cin >> reg_num;

	std::cout << "Enter color: ";
	std::cin >> color;

	std::cout << "Enter price per day (£): ";
	std::cin >> price;

	while (!intInput(price))
    {
        std::cout << "\nPrice entered must be an integer!\n";
        std::cout << "\nEnter price in pounds: ";
        std::getline(std::cin, price);
    }

	std::cin.ignore(256, '\n');
	std::cout << "\nIs vehicle available?\n1 => Yes\n2 => No\n";
	std::getline(std::cin, availability);

	int vehicleAvailable = atoi(availability.c_str());

	switch (vehicleAvailable)
	{
		case 1:
			{
				availability = "Yes";
				return_date = "N/A";
				break;
			}

		case 2:
			{
				availability = "No";
				std::cout << "Enter return date: ";
				std::cin >> return_date;
				break;
			}
		default:
        {
            std::cerr << "\n***Please enter one of the options ( 1 or 2 )***\n";
			break;
		}
	}

	std::cin.ignore(256, '\n');
	std::cout << "\nEnter Vehicle Type\n1 => bike\n2 => van\n3 => car\n ";
	std::getline(std::cin, type);

	int userChoice = atoi(type.c_str());

	switch (userChoice)
	{
		case 1:
			{
				type = "bike";
				std::string engineCC;
				std::cout << "Enter engine size of motobike (CC): ";
				std::cin >> engineCC;

				std::string hasSeat;
				std::cout << "\nDoes motobike has passenger seat?\n1 => Yes\n2 => No\n ";

				std::cin >> hasSeat;
				int seat = atoi(hasSeat.c_str());

				switch (seat)
				{
					case 1:
						{
							hasSeat = "Passenger seat";
							break;
						}

					case 2:
						{
							hasSeat = "No passenger seat";
							break;
						}
					default:
        				{
            				std::cerr << "\n***Please enter one of the options ( 1 or 2 )***\n";
							break;
						}
				}

				std::string hasLugg;
				std::cout << "\nDoes motobike has luggage space?\n1 => Yes\n2 => No\n";
				std::cin >> hasLugg;
				int luggage = atoi(hasLugg.c_str());

				switch (luggage)
				{
					case 1:
						{
							hasLugg = "Has luggage";
							break;
						}

					case 2:
						{
							hasLugg = "No luggage";
							break;
						}

					default:
        				{
            				std::cerr << "\n***Please enter one of the options ( 1 or 2 )***\n";
							break;
						}
				}

				vehicles.emplace_back(new Motorbike(type, make, model, "£" + price, engineCC + "cc", hasSeat,
					hasLugg, reg_num, color, availability, return_date));
				break;
			}

		case 2:
			{
				type = "van";
				std::string VanEngineLitre;
				std::cout << "Enter engine size of van (L): ";
				std::cin >> VanEngineLitre;

				std::string VanSeats;
				std::cout << "Enter number of seats available: ";
				std::cin >> VanSeats;

				std::string VanDoors;
				std::cout << "Enter number of doors: ";
				std::cin >> VanDoors;

				vehicles.emplace_back(new Van(type, make, model, "£" + price, VanEngineLitre + "L",
					VanSeats + " seats", VanDoors + " door", reg_num, color, availability, return_date));
				break;
			}

		case 3:
			{
				type = "car";
				std::string CarEngineLitre;
				std::cout << "Enter engine size of van (L): ";
				std::cin >> CarEngineLitre;

				std::string CarSeats;
				std::cout << "Enter number of seats available: ";
				std::cin >> CarSeats;

				std::string CarDoors;
				std::cout << "Enter number of doors: ";
				std::cin >> CarDoors;

				vehicles.emplace_back(new Van(type, make, model, "£" + price, CarEngineLitre + "L",
					CarSeats + " seats", CarDoors + " door", reg_num, color, availability, return_date));
				break;
			}

		default:
        	{
            	std::cerr << "\n***Please enter one of the options ( 1 - 3 )***\n";
				break;
			}
	}
}

void printItems()
{
	for (std::string::size_type i = 0; i < vehicles.size(); i++)
	{
		std::cout << "\n-\nID: " << i + 1;
		vehicles[i]->convertString();
		std::cout << "\n";
	}
}

void printAllItems()
{
	for (std::string::size_type i = 0; i < vehicles.size(); i++)
	{
		std::cout << "\n-\nID: " << i + 1;
		vehicles[i]->convertStringFull();
		std::cout << "\n";
	}
}

void menu()
{
	std::string userInput;

	std::cout <<
		"\n-------------------------\n" <<
		"Vehicle Rental Management" <<
		"\n-------------------------";

	std::cout << "\nEnter one of the following options:" <<
		"\n1 to Load" <<
		"\n2 to Save" <<
		"\n3 to Add new Vehicle" <<
		"\n4 to Remove a Vehicle" <<
		"\n5 to View all Vehicles" <<
		"\n6 to Display Details of a Vehicle" <<
		"\n7 to Exit" <<
		"\n>_ ";
	std::cin >> userInput;
	int userInputToInt = atoi(userInput.c_str());
	switch (userInputToInt)
	{
		case 1:
			{
				std::cin.ignore(256, '\n');
				char filename[100];
				std::cout << "Enter file name to load: ";
				std::cin >> filename;
				loadData(filename);
				menu();
				break;
			}

		case 2:
			{
				std::cin.ignore(256, '\n');
				char filename[100];
				std::cout << "Enter file name to save as: ";
				std::cin >> filename;
				saveData(filename);
				menu();
				break;
			}

		case 3:
			{
				addVehicle();
				menu();
				break;
			}

		case 5:
			{
				std::cin.ignore(256, '\n');
				printItems();
				menu();
				break;
			}

		case 6:
			{
				std::cin.ignore(256, '\n');
				printAllItems();
				menu();
				break;
			}

		case 7:
			{
				vehicles.clear();
				exit(0);
				break;
			}
	}
}
#endif