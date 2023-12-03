//
// Created by szyns on 03.12.2023.
//

#include "Citizen.h"

Citizen::Citizen() {}

Citizen::Citizen(const string &name, const string &surname, int age, char sex, const string &postalCode) : name(name),
                                                                                                           surname(surname),
                                                                                                           age(age),
                                                                                                           sex(sex),
                                                                                                           postal_code(
                                                                                                                   postalCode) {}

void Citizen::show() {
    cout<<"Name: "<<name<<endl;
    cout<<"Surname: "<<surname<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Sex: "<<sex<<endl;
    cout<<"Postal code: "<<postal_code<<endl;

}

const string &Citizen::getName() const {
    return name;
}

const string &Citizen::getSurname() const {
    return surname;
}

int Citizen::getAge() const {
    return age;
}

char Citizen::getSex() const {
    return sex;
}

const string &Citizen::getPostalCode() const {
    return postal_code;
}
