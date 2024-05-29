// Author: Sadab Hafiz
// Date: 05-28-2024
// Implements the Date class

// Include the header file
#include "date.hpp"

Date::Date(int day, int month, int year){
    this -> day = day;
    this -> month = month;
    this -> year = year;
}

int Date::getMonth() const{
    return month;
}

int Date::getDay() const{
    return day;
}

int Date::getYear() const{
    return year;
}

bool Date::setMonth(int month){
    if(month <= 0 || month > 12){
        return false;
    }
    this -> month = month;
    return true;
}

bool Date::setDay(int day){
    if(day <= 0 || day > 31){
        return false;
    }
    this -> day = day;
    return true;
}

bool Date::setYear(int year){
    if(year <= 0){
        return false;
    }
    this -> year = year;
    return true;
}

const std::string* Date::dateToString() const{
    std::string* date = new std::string;
    *date = *date + std::to_string(month) + " - " + std::to_string(day) + " - " + std::to_string(year);
    return date;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << *date.dateToString();
    return os;
}

int main() {
    Date class_start(5,28,2024);
    std::cout << class_start << std::endl;
    return 0;
}

