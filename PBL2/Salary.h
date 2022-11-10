#ifndef SALARY_H
#define SALARY_H
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Salary
{
private:
    int salaryBase;
    int bonus;
    Time timeslr;
public:
    Salary();
    ~Salary();
    void setSalaryBase(int);
    int getSalaryBase();
    void setBonus(int);
    int getBonus();
    void setTimeslr(Time);
    Time getTimeslr();
    void readFile(fstream&);
    void writeFile(fstream&);
    void write();
    void add(Salary&);
};

#endif
