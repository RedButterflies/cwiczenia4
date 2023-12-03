//
// Created by szyns on 03.12.2023.
//

#ifndef CICZENIA4_CITY_H
#define CICZENIA4_CITY_H


#include <vector>
#include "Citizen.h"

class City {
private:
    vector<Citizen>citizens;
    string city_name;
public:
    explicit City(const string &cityName);
    void addCitizen(Citizen c);
    void deleteCitizen(string surname, int age);
    void show_citizens();
    void show_city();
    int women();
    int city_citizens();
    int adults();
   int postal_codes();
   int differentCodes();

    const string &getCityName() const;

};


#endif //CICZENIA4_CITY_H
