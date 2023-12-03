//
// Created by szyns on 03.12.2023.
//

#ifndef CICZENIA4_CITIZEN_H
#define CICZENIA4_CITIZEN_H
#include <iostream>
using namespace std;

class Citizen {
private:
    string name;
    string surname;
    int age;
    char sex;
    string postal_code;
public:
    Citizen();
    Citizen(const string &name, const string &surname, int age, char sex, const string &postalCode);
    void show();

    const string &getName() const;

    const string &getSurname() const;

    int getAge() const;

    char getSex() const;

    const string &getPostalCode() const;



};


#endif //CICZENIA4_CITIZEN_H
