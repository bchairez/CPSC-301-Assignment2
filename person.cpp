#include "person.h"

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

Person::Person()
{
  firstName = " ";
  lastName = " ";
  hoursWorked = 0.0;
  payRate = 0.0;
}

void Person::setLastName(string lname)
{
  lastName = lname;
}

string Person::getLastName()
{
  return lastName;
}

void Person::setFirstName(string fname)
{
  firstName = fname;
}

string Person::getFirstName()
{
  return firstName;
}

void Person::setPayRate(float rate)
{
  if(rate < 0.0)
  {
    cout << "Error. Pay rate must be greater than zero." << endl
         << "Terminating program.";
    exit(1);
  }
  payRate = rate;
}

float Person::getPayRate()
{
  return payRate;
}

void Person::setHoursWorked(float hours)
{
  if(hours < 0.0)
  {
    cout << "Error. Hours worked must be greater than zero." << endl
         << "Terminating program.";
    exit(1);
  }
  hoursWorked = hours;
}

float Person::getHoursWorked()
{
  return hoursWorked;
}

float Person::totalPay()
{
  return(hoursWorked * payRate);
}

string Person::fullName()
{
  return(firstName + " " + lastName);
}
