//
// Created by szyns on 03.12.2023.
//

#include <map>
#include <algorithm>
#include "City.h"

City::City(const string &cityName) : city_name(cityName) {}

void City::addCitizen(Citizen c) {
    citizens.push_back(c);

}

void City::deleteCitizen(string surname, int age) {
    vector<Citizen>::iterator it;
    for(it=citizens.begin();it!=citizens.end();it++)
    {
        if(it->getSurname()==surname && it->getAge()==age)
        {
            citizens.erase(it);
        }
    }

}

void City::show_citizens() {
    vector<Citizen>::iterator it;
    for(it=citizens.begin();it!=citizens.end();it++)
    {
        it->show();
    }

}

void City::show_city() {
    cout<<"Nazwa miasta: "<<city_name<<endl;

}

int City::women() {
    int women = 0;
    vector<Citizen>::iterator it;
    for(it = citizens.begin();it!=citizens.end();it++)
    {
        if(it->getSex()=='W')
        {
            women++;
        }
    }
   // cout<<"There are "<<women<<" women in this city"<<endl;
    return women;
}

int City::city_citizens() {
    int cit  = 0 ;
    vector<Citizen>::iterator it;
    for(it = citizens.begin();it!=citizens.end();it++)
    {
        cit++;
    }
    //cout<<"There are "<<cit<<" citizens in this city"<<endl;
    return cit;
}

int City::adults() {
    int ad = 0;
    vector<Citizen>::iterator it;
    for(it=citizens.begin();it!=citizens.end();it++)
    {
        if(it->getAge()>=18)
        {
            ad++;
        }
    }
    //cout<<"There are "<<ad<<" adults in this city"<<endl;
    return ad;
}

int City::postal_codes() {
    cout<<"Nazwa miasta: "<<city_name<<endl;
    map<string,int>mapa_kodow;
    vector<Citizen>::iterator it;
    for(it=citizens.begin();it!=citizens.end();it++)
    {
        mapa_kodow.insert(make_pair(it->getPostalCode(),0));
    }
    for(it=citizens.begin();it!=citizens.end();it++)
    {
       if(mapa_kodow.count(it->getPostalCode()))
       {
           mapa_kodow.find(it->getPostalCode())->second++;
       }
    }
   map<string,int>::iterator it1;
    int unikatoweKody=0;
    for(it1=mapa_kodow.begin();it1!=mapa_kodow.end();it1++)
    {
        if(it1->second==1)
        {
          unikatoweKody++;
        }
    }
    for(it1=mapa_kodow.begin();it1!=mapa_kodow.end();it1++)
    {
        cout<<"Kod: "<<it1->first<<" Ile osob: "<<it1->second<<endl;
    }
    cout<<"W miescie jest "<<unikatoweKody<<" unikatowych kodow"<<endl;
    return unikatoweKody;

}

int City::differentCodes() {
    map<string,int>mapa_kodow;
    vector<Citizen>::iterator it;
    for(it=citizens.begin();it!=citizens.end();it++)
    {
        mapa_kodow.insert(make_pair(it->getPostalCode(),0));
    }
    int rozneKody = mapa_kodow.size();
    return rozneKody;
}

const string &City::getCityName() const {
    return city_name;
}

