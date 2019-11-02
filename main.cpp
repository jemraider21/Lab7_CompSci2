#include <iostream>
#include <iomanip>
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
        void printPay() override { 
            cout << setprecision(2) << fixed;
            cout <<"The pay for the hourly emplyee with ID number " << getEmpID() <<" is $" << (hours * payRate) << endl;
        }
};

class SalariedEmployee: public Employee{
    private:
        double salary;
    public:
        SalariedEmployee(int empID, double salary): Employee(empID){ this->salary = salary; }
        double getSalary() const { return salary; }
        void printPay() override { 
            cout << setprecision(2) << fixed;
            cout << "The pay for the salaried employee with ID number " << getEmpID() <<" is $" << (salary / 52) << endl;
        }
};

// Function prototypes
void getInput(vector <Employee *> &Ve);
void printList(const vector<Employee *> &Ve);

int main(){
    vector <Employee *> VEmp;

    getInput(VEmp);
    printList(VEmp);
    cout << "Lab 7 completed by: " << "Jared Morris" << endl;

    return 0;
}

void getInput(vector <Employee *> &Ve){
    int choice, empID;
    double hours, payRate, salary;

    do{
        cout << "Enter 1 for Hourly Employee\n" << "Enter 2 for Salaried Emplyee\n" << "Enter 3 to stop: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Get user data
                cout << "\nEnter the ID: ";
                cin >> empID;

                cout << "Enter the numbers of hours worked: ";
                cin >> hours;

                cout << "Enter the pay rate: ";
                cin >> payRate;
                cout << endl;

                // Input data into object and store memory address
                Ve.push_back(new HourlyEmployee(empID, hours, payRate));

                break;
            case 2:
                cout << "\nEnter the ID: ";
                cin >> empID;

                cout << "Enter the salary: ";
                cin >> salary;
                cout << endl;

                // Input data into object and store memory address
                Ve.push_back(new SalariedEmployee(empID, salary));

                break;
        }
    } while(choice != 3);
}

void printList(const vector<Employee *> &Ve){
    cout << endl;

    for(int i = 0; i < Ve.size(); i++){
        Ve[i]->printPay();
    }
}