/*

     Patrick Saperstein
     March 26, 2013
     CS253
     HW4

*/

#ifndef Interval_h_included
#define Interval_h_included
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>
#include <iostream>


class Interval{
  public:
    // Constructors/Destructor
    Interval(const int &);
    Interval(const int &, const int &);
    Interval(const Interval &);
    ~Interval();

    // Assignment Operators
    Interval &operator=(const Interval &);
    Interval &operator=(const int &);

    // Modifiers
    void assign(const int &, const int &);
    int min() const;
    int max() const;

    // Operators with Intervals
    Interval operator+(const Interval &) const;
    Interval operator-(const Interval &) const;
    Interval operator*(const Interval &) const;
    Interval operator/(const Interval &) const;
    //Operators with ints
    Interval operator+(const int) const;
    Interval operator-(const int) const;
    Interval operator*(const int) const;
    Interval operator/(const int) const;

    //Modifying Operators w/ Intervals
    Interval& operator+=(const Interval &);
    Interval& operator-=(const Interval &);
    Interval& operator*=(const Interval &);
    Interval& operator/=(const Interval &);
    //Modifying Operators w/ ints
    Interval& operator+=(const int);
    Interval& operator-=(const int);
    Interval& operator*=(const int);
    Interval& operator/=(const int);

    // Pre and post increment (in that order)
    const Interval &operator++();
    Interval operator++(int);

    // Comparison Operators
    bool operator<(const Interval &)const;
    bool operator>(const Interval &)const;
    bool operator<=(const Interval &)const;
    bool operator>=(const Interval &)const;
    bool operator==(const Interval &)const;
    bool operator!=(const Interval &)const;
    // Comparison Operators with integers
    bool operator<(const int)const;
    bool operator>(const int)const;
    bool operator<=(const int)const;
    bool operator>=(const int)const;
    bool operator==(const int)const;
    bool operator!=(const int)const;

  private:
    int minimum;
    int maximum;
};

// Operators called by an int
Interval operator+(const int, const Interval &);
Interval operator-(const int, const Interval &);
Interval operator*(const int, const Interval &);
Interval operator/(const int, const Interval &);
bool operator<(const int, const Interval &);
bool operator>(const int, const Interval &);
bool operator<=(const int, const Interval &);
bool operator>=(const int, const Interval &);
bool operator==(const int, const Interval &);
bool operator!=(const int, const Interval &);

//Insertion and Extraction Operators
std::ostream &operator<<(std::ostream &stream, const Interval &);
std::istream &operator>>(std::istream &in, Interval &);
#endif /* Words_h_included */