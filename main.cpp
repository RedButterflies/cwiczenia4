#include <iostream>
#include<list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "cmake-build-debug/City.h"

using namespace std;

void losowanie()
{
    srand(time(0));
    list<int> lista;
    int n = rand()%20;
    cout<<"Wylosowane n: "<<n<<endl;
    int number;
    for(int i=0;i<n;i++)
    {
        number = rand()%201-100;
        if(number>=0)
        {
            lista.push_front(number);
        }
        else
        {
            lista.push_back(number);
        }


    }
    cout<<"Elementy listy: "<<endl;
    list<int>::iterator it;
    for(it = lista.begin();it!=lista.end();it++)
    {
        cout<<*it<<",";
    }



}

void showCities(vector<City>c)
{
    cout<<"Informacje o wszystkich miastach: "<<endl;
    vector<City>::iterator it;
    for(it=c.begin();it!=c.end();it++)
    {
        it->show_city();
    }
}

void mostPostalCodes(vector<City>c)
{
    int most = 0;
    string cityname;
    vector<City>::iterator it;
    for (it=c.begin();it!=c.end();it++)
    {

        if(  it->differentCodes()>most)
        {
            most = it->differentCodes();
            cityname = it->getCityName();

        }
    }
    cout<<"W miescie: "<<cityname<< " jest najwiecej roznych kodow pocztowych, jest ich "<< most <<endl;

}

void leastCitizens(vector<City>c)
{
    int least = c[0].city_citizens();
    string city_name;
    vector<City>::iterator it;
    for(it=c.begin();it!=c.end();it++)
    {
        if(it->city_citizens()<least)
        {
            least = it->city_citizens();
            city_name = it->getCityName();
        }
    }
    cout<<"W miescie: "<<city_name<<" jest najmniej mieszkancow, jest ich "<<least<<endl;
}
void the_most(vector<City>c, int mode)
{
    if(mode==1) {
        mostPostalCodes(c);
    }
     else if(mode==2) {
        leastCitizens(c);
    }
     else{
            cout<<endl;
    }
}
void statistic(vector<City>c)
{
    vector <City>::iterator it;
    for(it=c.begin();it!=c.end();it++)
    {
        it->show_city();
        cout<<"There are "<<it->adults()<< " adults in this city"<<endl;
        cout<<"There are "<<it->women()<< " women in this city"<<endl;
        int men = it->adults()-it->women();
        cout<<"There are "<<men<<" men in this city"<<endl;
        int kids = it->city_citizens() - it->adults();
        cout<<"There are "<<kids <<" kids in this city"<<endl;


    }
}
static bool comp (City a, City &b)
{
    return a.city_citizens() < b.city_citizens();
}

void sort_cities(vector<City>&c)
{
    sort(c.begin(),c.end(),comp);
}
 bool sumaLiczb( int &a, int &b)
{
    int x=a;
    int y=b;
    int sumaA = 0;
    int sumaB = 0;
    while(x>0)
    {
        sumaA+=x%10;
        x/=10;
    }
    while(y>0)
    {
        sumaB+=y%10;
        y/=10;
    }

        return sumaA < sumaB;



}
static bool liczbaCyfr(const int &a, const int &b)
{

    int x = a;
    int y = b ;
    int liczbaA = 0;
    int liczbaB = 0;
    while(x>0)
    {
        liczbaA+=1;
        x/=10;
    }
    while(y>0)
    {
        liczbaB+=1;
        y/=10;
    }
   return a>b;

}
void sortowanieRosnacoWGSumyCyfr(vector<int>&s)
{
    sort(s.begin(),s.end(), sumaLiczb);

}
void sortowaniemalejacoWGLiczbyCyfr(vector<int>&s)
{
    sort(s.begin(),s.end(), liczbaCyfr);
}
void print( int &s)
{

        cout << s << ",";
}

int main() {
    //losowanie();

    Citizen a = Citizen("Ola","Szpak",21,'W',"40-890");
    Citizen b = Citizen("Pola","Lipowiec",41,'W',"40-990");
    Citizen c = Citizen("Kuba","osnowiec",1,'M',"40-890");
    Citizen d = Citizen("Pawel","Koczka",5,'M',"40-890");
    Citizen e = Citizen("Janul","Smik",55,'M',"20-515");
    Citizen f = Citizen("Vanessa","Kasmek",64,'K',"20-515");


    City Lublin = City ("Lublin");
    City Warszawa = City("Warszawa");
    City Sydney = City("Sydney");

    Lublin.addCitizen(a);
    Lublin.addCitizen(b);
    Lublin.addCitizen(c);

    Warszawa.addCitizen(d);

    Sydney.addCitizen(e);
    Sydney.addCitizen(f);

    Lublin.show_city();
    Warszawa.show_city();
    Sydney.show_city();

    Lublin.postal_codes();
    Warszawa.postal_codes();
    Sydney.postal_codes();


    vector<City>cities;
    cities.push_back(Lublin);
    cities.push_back(Sydney);
    cities.push_back(Warszawa);
    cout<<endl;
    showCities(cities);
    cout<<endl;
     the_most(cities,1);
    the_most(cities,2);
   statistic(cities);


   cout<<endl;
    Sydney.deleteCitizen("Smik",55);
    cout<<"Sydney citizens after deleting Janul Smik: "<<endl;
    Sydney.show_citizens();

    sort_cities(cities);

    cout<<"Sorted cities: "<<endl;
    showCities(cities);

    vector<int> liczby={10,12,45,21,34,56,78,98,76,103};
    vector<int> liczbyB={1000,124,425,2213,33334,562222,7338,9,76,103};
    sortowanieRosnacoWGSumyCyfr(liczby);
    sortowaniemalejacoWGLiczbyCyfr(liczbyB);

    cout<<"Liczby posortowane rosnaco wg sumy cyfr: "<<endl;
    for_each(liczby.begin(),liczby.end(),print);
    cout<<endl;
    cout<<"Liczby posortowane malejaco wg liczby cyfr: "<<endl;
    for_each(liczbyB.begin(),liczbyB.end(),print);
    cout<<endl;



    return 0;
}
