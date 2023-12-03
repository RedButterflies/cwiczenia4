# cwiczenia4
Task translated to English ->
Task 4.2. Random Selection
Write a program that generates a positive integer n, then randomly selects n integers from the range [-100, 100] and inserts them into a list in such a way that positive or zero elements are at the beginning of the list and negative elements are at the end. The program should print the contents of the list.

Task 4.3. City
Create a class Citizen that represents a resident and contains the following fields and methods:
• private fields: name, surname of type string, age of type int, sex of type char, and postal_code of type string;
• constructors: parameterless and one allowing the initialization of class fields;
• a method show displaying information about the resident;
• appropriate getters for the fields.
Create a class City that contains the following fields and methods:
• private fields: citizens - a vector storing residents – objects of the Citizen class, city_name – the name of the city;
• a constructor initializing the city name;
• a method addCitizen that allows adding a resident to the city. The method should take an object of the Citizen class;
• a method deleteCitizen that removes a resident with a given surname and age. We assume that the combination of surname and age is unique. The surname and age should be passed as arguments to the method;
• a method show_citizens that displays all residents of the city;
• a method show_city that displays information about the city name;
• a method women() that returns the number of women in the city;
• a method city_citizens() that returns the number of residents in the city;
• a method adults() that returns the number of adult residents in the city;
• a method postal_codes() that displays statistics of postal codes of its residents, e.g., "20-389 -> 3 residents, 30-678 -> 10 residents" and returns the number of unique postal codes.
Hint: Since the number of unique postal codes is unknown, you can create a helper class storing the postal code and the number of residents and increment the number of residents accordingly. Objects of this class should be stored in a container. As an exercise, choose a container other than a vector.
Implement the following functions:
• void showCities(vector<City> c), the function displays information about the cities;
• void the_most(vector<City> c, int mode), the function searches for data specified by the parameter mode and displays information on the console. Each subpoint should be implemented in a separate function. Mode:
1. The city with the most different postal codes;
2. The city with the fewest residents;
• void statatistic(vector <City> c), the function displays statistics for each city: the city name, the number of residents of that city broken down by the number of women and men, minors and adults;
• void sort_cities(vector <City> &c), the function sorts cities in ascending order by the number of residents.
In the main function, demonstrate the operation of the implemented methods and functions.
STL algorithms can be used in this task.

Task 4.4. Sorting
Create a vector that will store integers. Using the sort function from the STL library, sort the data in the vector container:
• in ascending order by the sum of digits in the number;
• in descending order by the number of digits.
Use the for_each function to display the contents of the container.
