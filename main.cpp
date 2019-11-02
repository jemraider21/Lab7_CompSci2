#include <iostream>
#include <vector>
using namespace std;

class Employee {
    private:
        int empID;
    public:
        Employee(int empID){this->empID = empID;}
        int getEmpID() const { return empID; }
        virtual void printPay() = 0;
};

class HourlyEmployee: public Employee {
    private:
        double hours;
        double payRate;
    public:
        HourlyEmployee(int empID, double hours, double payRate): Employee(empID){
            this->hours = hours;
            this->payRate = payRate;
        }
        
        double getHours() const { return hours; }
        double getPayRate() const { return payRate; }
        void printPay() override { cout << (hours * payRate) << endl;}
};

class SalariedEmployee: public Employee{
    private:
        double salary;
    public:
        SalariedEmployee(int empID, double salary): Employee(empID){ this->salary = salary; }
        double getSalary() const { return salary; }
        void printPay() override { cout << (salary / 52) << endl;}
};

/* Completed main function
int main(){
    vector <Employee *> VEmp;

    getInput(VEmp);
    printList(VEmp);
    cout << "Lab 7 completed by: " << "Jared Morris" << endl;

    return 0;
}
*/