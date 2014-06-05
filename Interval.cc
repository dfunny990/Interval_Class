/*

     Patrick Saperstein
     March 26, 2013
     CS253
     HW4

*/
#include "Interval.h"

Interval::Interval(const int &newint){
  minimum=newint;
  maximum=newint;
}

Interval::Interval(const int &low, const int &high){
  if(low>high){
    throw "out of order";
  }
  minimum=low;
  maximum=high;
}

Interval::Interval(const Interval &newint){
  maximum=newint.maximum;
  minimum=newint.minimum;
}

Interval::~Interval(){    //default constructor for all member variables is fine
}

void Interval::assign(const int &min, const int &max){
  if (max<min){
    throw "out of order";
  }
  minimum=min;
  maximum=max;
}

int Interval::min() const{
  return minimum;
}

int Interval::max() const{
  return maximum;
}

Interval &Interval::operator=(const Interval &rhs){
  maximum=rhs.maximum;
  minimum=rhs.minimum;
}

Interval &Interval::operator=(const int &rhs){
  maximum=rhs;
  minimum=rhs;
}

Interval Interval::operator+(const Interval &rhs)const{
  int tempmax=maximum+rhs.maximum;
  int tempmin=minimum+rhs.minimum;
  return Interval(tempmin,tempmax);
}

Interval Interval::operator-(const Interval &rhs)const{
  int tempmax=maximum-rhs.minimum;
  int tempmin=minimum-rhs.maximum;
  return Interval(tempmin,tempmax);
}

Interval Interval::operator*(const Interval &rhs)const{
  int tempmax=minimum*rhs.minimum;
  int tempmin=minimum*rhs.minimum;
  if(minimum*rhs.maximum>tempmax){
    tempmax=minimum*rhs.maximum;
  }
  if(minimum*rhs.maximum<tempmin){
    tempmin=minimum*rhs.maximum;
  }
  if(maximum*rhs.minimum>tempmax){
    tempmax=maximum*rhs.minimum;
  }
  if(maximum*rhs.minimum<tempmin){
    tempmin=maximum*rhs.minimum;
  }
  if(maximum*rhs.maximum>tempmax){
    tempmax=maximum*rhs.maximum;
  }
  if(maximum*rhs.maximum<tempmin){
    tempmin=maximum*rhs.maximum;
  }
  return Interval(tempmin,tempmax);
}

Interval Interval::operator/(const Interval &rhs)const{
  if(rhs.minimum<=0&&rhs.maximum>=0){
    throw "divide by zero";
  }
  int tempmax=minimum/rhs.minimum;
  int tempmin=minimum/rhs.minimum;
  if(minimum/rhs.maximum>tempmax){
    tempmax=minimum/rhs.maximum;
  }
  if(minimum/rhs.maximum<tempmin){
    tempmin=minimum/rhs.maximum;
  }
  if(maximum/rhs.minimum>tempmax){
    tempmax=maximum/rhs.minimum;
  }
  if(maximum/rhs.minimum<tempmin){
    tempmin=maximum/rhs.minimum;
  }
  if(maximum/rhs.maximum>tempmax){
    tempmax=maximum/rhs.maximum;
  }
  if(maximum/rhs.maximum<tempmin){
    tempmin=maximum/rhs.maximum;
  }
  return Interval(tempmin,tempmax);
}

Interval Interval::operator+(const int rhs)const{
  int tempmax=maximum+rhs;
  int tempmin=minimum+rhs;
  return Interval(tempmin,tempmax);
}

Interval Interval::operator-(const int rhs)const{
  int tempmax=maximum-rhs;
  int tempmin=minimum-rhs;
  return Interval(tempmin,tempmax);
}

Interval Interval::operator*(const int rhs)const{
  int tempmax=maximum*rhs;
  int tempmin=minimum*rhs;
  if(tempmax>tempmin){
    return Interval(tempmin,tempmax);
  }
  else{
    return Interval(tempmax,tempmin);
  }
}

Interval Interval::operator/(const int rhs)const{
  if(rhs==0){
    throw "divide by zero";
  }
  int tempmax=maximum/rhs;
  int tempmin=minimum/rhs;
  if(tempmax>tempmin){
    return Interval(tempmin,tempmax);
  }
  else{
    return Interval(tempmax,tempmin);
  }
}

Interval& Interval::operator+=(const Interval &rhs){
  minimum+=rhs.minimum;
  maximum+=rhs.maximum;
}

Interval& Interval::operator-=(const Interval &rhs){
  minimum-=rhs.maximum;
  maximum-=rhs.minimum;
}

Interval& Interval::operator/=(const Interval &rhs){
  if(rhs.minimum<=0&&rhs.maximum>=0){
    throw "divide by zero";
  }
  Interval temp(minimum,maximum);
  Interval temp2=temp/rhs;
  minimum=temp2.min();
  maximum=temp2.max();
}

Interval& Interval::operator*=(const Interval &rhs){
  Interval temp(minimum,maximum);
  Interval temp2=temp*rhs;
  minimum=temp2.min();
  maximum=temp2.max();
}

Interval& Interval::operator+=(const int rhs){
  minimum+=rhs;
  maximum+=rhs;
}

Interval& Interval::operator-=(const int rhs){
  minimum-=rhs;
  maximum-=rhs;
}

Interval& Interval::operator/=(const int rhs){
  if(rhs==0){
    throw "divide by zero";
  }
  Interval temp(minimum,maximum);
  Interval temp2=temp/rhs;
  minimum=temp2.min();
  maximum=temp2.max();
}

Interval& Interval::operator*=(const int rhs){
  Interval temp(minimum,maximum);
  Interval temp2=temp*rhs;
  minimum=temp2.min();
  maximum=temp2.max();
}

const Interval &Interval::operator++(){
  *this +=1;
  return *this;
}

Interval Interval::operator++(int){
  const Interval temp = *this;
  ++*this;
  return temp;
}

bool Interval::operator<(const Interval &rhs)const{
  return (maximum<rhs.minimum);
}

bool Interval::operator>(const Interval &rhs)const{
  return (minimum>rhs.maximum);
}

bool Interval::operator<=(const Interval &rhs)const{
  return (maximum<=rhs.minimum);
}

bool Interval::operator>=(const Interval &rhs)const{
  return (minimum>=rhs.maximum);
}

bool Interval::operator==(const Interval &rhs)const{
  return (minimum==rhs.minimum && maximum==rhs.maximum);
}

bool Interval::operator!=(const Interval &rhs)const{
  return (minimum!=rhs.minimum||maximum!=rhs.maximum);
}

bool Interval::operator<(const int rhs)const{
  return (maximum<rhs);
}

bool Interval::operator>(const int rhs)const{
  return (minimum>rhs);
}

bool Interval::operator<=(const int rhs)const{
  return (maximum<=rhs);
}

bool Interval::operator>=(const int rhs)const{
  return (minimum>=rhs);
}

bool Interval::operator==(const int rhs)const{
  return (minimum==rhs && maximum==rhs);
}

bool Interval::operator!=(const int rhs)const{
  return (maximum<rhs||minimum>rhs);
}

//////// NON MEMBER FUNCTIONS ///////////////////////

Interval operator+(const int lhs, const Interval &rhs){
  Interval temp=rhs+lhs;
  return temp;
}

Interval operator-(const int lhs, const Interval &rhs){
  Interval temp(lhs);
  return temp-rhs;
}

Interval operator*(const int lhs, const Interval &rhs){
  Interval temp(lhs);
  return temp*rhs;
}

Interval operator/(const int lhs, const Interval &rhs){
  if(rhs.min()<=0&&rhs.max()>=0){
    throw "divide by zero";
  }
  Interval temp(lhs);
  return temp/rhs;
}

bool operator<(const int lhs, const Interval &rhs){
  return (lhs<rhs.min());
}

bool operator>(const int lhs, const Interval &rhs){
  return (lhs>rhs.max());
}

bool operator<=(const int lhs, const Interval &rhs){
  return (lhs<=rhs.min());
}

bool operator>=(const int lhs, const Interval &rhs){
  return (lhs>=rhs.max());
}

bool operator==(const int lhs, const Interval &rhs){
  return (lhs==rhs.min() && lhs==rhs.max());
}

bool operator!=(const int lhs, const Interval &rhs){
  return (lhs<rhs.min()||lhs>rhs.max());
}

std::ostream &operator<<(std::ostream &stream, const Interval &inter){
  return stream <<"["<<inter.min()<<","<<inter.max()<<"]";
}

std::istream &operator>>(std::istream &in, Interval &inter){
  int min, max;
  char ch1,ch2,ch3;
  if(in >> ch1 && ch1=='['
   && in >> min //&& typeid(min)=="int"
   && in >> ch2 && ch2==','
   && in >> max //&& typeid(min)=="int"
   && in >> ch3 && ch3==']'){
    inter=Interval(min,max);
  }
  else{
    in.setstate(std::ios::failbit);
  }
  return in;
}