// Author: Sadab Hafiz
// Date: 05-28-2024
// Include Guards
#ifndef DATE_H
#define DATE_H

// Libraries
#include <iostream>

// Simple Date Class
class Date{
    public:
        // Default Constructor
        Date(){};
        // Parameterized Constructor
        Date(int month, int day, int year);
        // Getter functions
        int getMonth() const;
        int getDay() const;
        int getYear() const; 
        // Setter functions
        bool setMonth(int month);
        bool setDay(int day);
        bool setYear(int year);
        // operator overload for << operator
        friend std::ostream& operator<<(std::ostream& os, const Date& date);
    private:
        // Date members
        int month;
        int day;
        int year;
        // Private member functions
        const std::string* dateToString() const;
};

#endif

