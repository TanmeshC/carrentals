#include <iostream>
#include <string.h>
#include<fstream>
#include <vector>


using namespace std;

// Base class for vehicles
class Vehicle {
protected:
    string model;
    string color;
    int year;
    double rentalCostPerDay;

public:
    Vehicle(string model, string color, int year, double rentalCostPerDay)
        : model(model), color(color), year(year), rentalCostPerDay(rentalCostPerDay) {}

    virtual void displayDetails() {
    cout<<(" --------------------------------------------------------");
    cout<<"\n| \t\t !!! RENTAL SERVICES !!!\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n|COLOR:- "<<color<<"\t\t\t\t\t\t |";
    cout<<"\n|YEAR:- "<<year<<"\t\t\t\t\t\t |";
    cout<<"\n|RENTAL COST PER DAY:- ₹"<<rentalCostPerDay<<"\t\t\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    }
};

// Derived class for bikes
class Bike : public Vehicle {
public:
    int engineCapacity;

public:
    Bike(string model, string color, int year, double rentalCostPerDay, int engineCapacity)
        : Vehicle(model, color, year, rentalCostPerDay), engineCapacity(engineCapacity) {}

    void displayDetails() override {
        Vehicle::displayDetails();
        cout<<"\n|MODEL:- "<<model<<"\t\t\t\t\t\t |";
        cout<<"\n|Engine Capacity:- "<<engineCapacity<< " cc"<<"\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";

    }
};

// Derived class for super bikes
class SuperBike : public Bike {
private:
    string brand;

public:
    SuperBike(string model, string color, int year, double rentalCostPerDay, int engineCapacity, string brand)
        : Bike(model, color, year, rentalCostPerDay, engineCapacity), brand(brand) {}

    void displayDetails() override {
        Vehicle::displayDetails();
        cout<<"\n|MODEL:- "<<model<<"\t\t\t\t\t |";
        cout<<"\n|Engine Capacity:- "<<engineCapacity<< " cc"<<"\t\t\t\t |";
        cout<<"\n|Brand:- "<<brand<<"\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
    }
};

// Derived class for cars
class Car : public Vehicle {
public:
    int seatingCapacity;
    bool allWheelDrive;

public:
    Car(string model, string color, int year, double rentalCostPerDay, int seatingCapacity)
        : Vehicle(model, color, year, rentalCostPerDay), seatingCapacity(seatingCapacity) {}

    void displayDetails() override {
        Vehicle::displayDetails();
        cout<<"\n|MODEL:- "<<model<<"\t\t\t\t\t\t |";
        cout<<"\n|Seating Capacity:- "<<seatingCapacity<< " persons"<<"\t\t\t\t |";
        cout<<"\n|All Wheel Drive:- "<<"NO"<<"\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
    }
};

// Derived class for SUVs
class SUV : public Car {
private:
    bool allWheelDrive;

public:
    SUV(string model, string color, int year, double rentalCostPerDay, int seatingCapacity, bool allWheelDrive)
        : Car(model, color, year, rentalCostPerDay, seatingCapacity), allWheelDrive(allWheelDrive) {}

    void displayDetails() override {
        Vehicle::displayDetails();
        cout<<"\n|MODEL:- "<<model<<"\t\t\t\t\t |";
        cout<<"\n|All Wheel Drive:- "<< (allWheelDrive ? "YES" : "NO")<<"\t\t\t\t\t |";
        cout<<"\n|Seating Capacity:- "<<seatingCapacity<< " persons"<<"\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
        cout<<"\n| \t\t\t\t\t\t\t |";
    }
};

int tot_amt(int x,int rental_per_day)
{
    return  x*rental_per_day;


}
int main() {
    ofstream outfile;

    outfile.open("sample.csv");
    outfile << "NAME,,AGE,,PHONE NO.,,EMAIL,,ADDRESS,,START DATE,,END DATE,,VEHICLE TYPE,,NO. OF DAYS,,DATE,,TIME" << endl;

    struct people
    {
        string name[20];
        string age[2];
        string num[10];
        string email[15];
        string address[25];
        string sd[10];
        string ed[10];
        string veh_type[10];
        string date[10];
        string time[10];
        int days;
    };
    struct people s1;
    char choice;
    int i=0;
    Vehicle *vehicle = nullptr;

    int bike_amt=1;
    int superbike_amt=1;
    int car_amt=1;
    int suv_amt=1;
    do
    {

    vector<string> coupons = {"FIRST", "SUPER30", "FLAT60", "GO100"};

    cout<<"ENTER YOUR NAME :- "<<endl;
    cin>> s1.name[i];
    cout<< "ENTER YOUR AGE :- "<<endl;
    cin>> s1.age[i];
    cout<< "ENTER YOUR PHONE NUMBER :- "<<endl;
    cin>> s1.num[i];
    cout<< "ENTER YOUR EMAIL ID :- "<<endl;
    cin>> s1.email[i];
    cout<< "ENTER YOUR ADDRESS :- "<<endl;
    cin>> s1.address[i];
    cout<< "ENTER START DATE (DD/MM/YYYY) :- "<<endl;
    cin>> s1.sd[i];
    cout<< "ENTER END DATE (DD/MM/YYYY) :- "<<endl;
    cin>> s1.ed[i];
    s1.date[i]=__DATE__;
    s1.time[i]=__TIME__;
    int daays;
    string vehicleType;
    cout<<"ENTER THE NO. OF DAYS YOU WANT :- "<<endl;
    cin>>daays;
    s1.days=daays;
    cout << "Enter the type of vehicle you want to rent (Bike/SuperBike/Car/SUV): ";
    cin >> vehicleType;
    s1.veh_type[i]=vehicleType;
    outfile << s1.name[i]<<","<<","<<s1.age[i]<<","<<","<<s1.num[i]<<","<<","<<s1.email[i]<<","<<","<<s1.address[i]<<","<<","<<s1.sd[i]<<","<<","<<s1.ed[i]<<","<<","<<s1.veh_type[i]<<","<<","<<s1.days<<","<<","<<s1.date[i]<<","<<","<<s1.time[i]<<endl;


    int discount;
    int insurance;
    char insured;
    int gst=100;
    int sgst=85;
    int a;
    if (vehicleType == "Bike") {
        if (bike_amt>0)
        {
        cout<<"DO YOU WANT INSURANCE(CAR=750,SUPERBIKE=1000,SUV=1350,BIKE=250):-(Y/N) ";
        cin>>insured;
        if(insured=='Y'||'y')
            {
            insurance=250;
            }
        else
            {
            insurance=0;
            }
        cout << "Enter your coupon code:(Capital letters only) ";
        string userCoupon;
        cin >> userCoupon;
        bool isValidCoupon = false;
    for (const string& coupon : coupons) {
        if (coupon == userCoupon) {
            isValidCoupon = true;
            if (coupon=="FIRST")
                {
                    discount=50;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="SUPER30")
                {
                    discount=30;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="FLAT60")
                {
                    discount=60;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="GO100")
                {
                    discount=100;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
        }
    }

    // If the coupon is not valid, inform the user
    if (!isValidCoupon) {
        discount=0;
        cout << "Sorry, your coupon is invalid." << endl;
    }

        bike_amt=-bike_amt;
        vehicle = new Bike("PULSAR", "RED", 2020, 125.0, 150);
        a=tot_amt(daays,125);
          cout << "\nVehicle Details:\n";
    vehicle->displayDetails();
    cout<<"\n|NAME:- "<<s1.name[i]<<"\t\t\t\t\t\t |";
    cout<<"\n|EMAIL ID:- "<<s1.email[i]<<"\t\t\t\t |";
    cout<<"\n|CONTACT NO.:- "<<s1.num[i]<<"\t\t\t\t |";
    cout<<"\n|DATE:- "<<__DATE__<<"\t\t\t\t\t |";
    cout<<"\n|TIME:- "<<__TIME__<<"\t\t\t\t\t |";
    cout<<"\n|AMT:- ₹"<<"\t\t"<<a<<"\t\t\t\t |";
    cout<<"\n|GST:- ₹"<<"\t\t"<<gst<<"\t\t\t\t |";
    cout<<"\n|SGST:- ₹"<<"\t\t"<<sgst<<"\t\t\t\t |";
    cout<<"\n|INSURANCE:- ₹"<<"\t\t"<<insurance<<"\t\t\t\t |";
    cout<<"\n|DISCOUNT:- ₹"<<"\t\t"<<discount<<"\t\t\t\t |";
    cout<<"\n|_________________________________\t\t\t |";
    cout<<"\n|TOTAL AMT:- ₹"<<"\t\t"<<(a+gst+sgst+insurance-discount)<<"\t\t\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n|\t!! THANKYOU FOR USING OUR SERVICES !!\t\t |";
    cout<<"\n|\t    !! WISH YOU A HAPPY JOURNEY !!\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n --------------------------------------------------------";
        }
        else if (bike_amt<=0)
        {cout<<"OUT OF STOCK";}
    }
    else if (vehicleType == "SuperBike") {
        if (superbike_amt>0)
        {
        cout<<"DO YOU WANT INSURANCE(CAR=750,SUPERBIKE=1000,SUV=1350,BIKE=250):-(Y/N) ";
        cin>>insured;
        if(insured=='Y'||'y')
            {
            insurance=1000;
            }
        else
            {
            insurance=0;
            }
        cout << "Enter your coupon code:(Capital letters only) ";
        string userCoupon;
        cin >> userCoupon;
        bool isValidCoupon = false;
    for (const string& coupon : coupons) {
        if (coupon == userCoupon) {
            isValidCoupon = true;
            if (coupon=="FIRST")
                {
                    discount=50;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="SUPER30")
                {
                    discount=30;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="FLAT60")
                {
                    discount=60;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="GO100")
                {
                    discount=100;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
        }
    }

    // If the coupon is not valid, inform the user
    if (!isValidCoupon) {
        discount=0;
        cout << "Sorry, your coupon is invalid." << endl;
    }
        superbike_amt=-superbike_amt;
        vehicle = new SuperBike("Ninja ZX-10R", "GREEN", 2021, 1000.0, 1000, "Kawasaki");
        a=tot_amt(daays,1000);
          cout << "\nVehicle Details:\n";
    vehicle->displayDetails();
    cout<<"\n|NAME:- "<<s1.name[i]<<"\t\t\t\t\t\t |";
    cout<<"\n|EMAIL ID:- "<<s1.email[i]<<"\t\t\t\t |";
    cout<<"\n|CONTACT NO.:- "<<s1.num[i]<<"\t\t\t\t |";
    cout<<"\n|DATE:- "<<__DATE__<<"\t\t\t\t\t |";
    cout<<"\n|TIME:- "<<__TIME__<<"\t\t\t\t\t |";
    cout<<"\n|AMT:- ₹"<<"\t\t"<<a<<"\t\t\t\t |";
    cout<<"\n|GST:- ₹"<<"\t\t"<<gst<<"\t\t\t\t |";
    cout<<"\n|SGST:- ₹"<<"\t\t"<<sgst<<"\t\t\t\t |";
    cout<<"\n|INSURANCE:- ₹"<<"\t\t"<<insurance<<"\t\t\t\t |";
    cout<<"\n|DISCOUNT:- ₹"<<"\t\t"<<discount<<"\t\t\t\t |";
    cout<<"\n|_________________________________\t\t\t |";
    cout<<"\n|TOTAL AMT:- ₹"<<"\t\t"<<(a+gst+sgst+insurance-discount)<<"\t\t\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n|\t!! THANKYOU FOR USING OUR SERVICES !!\t\t |";
    cout<<"\n|\t    !! WISH YOU A HAPPY JOURNEY !!\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n --------------------------------------------------------";
        }
        else if (superbike_amt<=0)
        {cout<<"OUT OF STOCK";}
    }
    else if (vehicleType == "Car") {
         if (car_amt>0)
        {
        cout<<"DO YOU WANT INSURANCE(CAR=750,SUPERBIKE=1000,SUV=1350,BIKE=250):-(Y/N) ";
        cin>>insured;
        if(insured=='Y'||insured=='y')
            {
            insurance=750;
            }
        else
            {
            insurance=0;
            }
        cout << "Enter your coupon code:(Capital letters only) ";
        string userCoupon;
        cin >> userCoupon;
        bool isValidCoupon = false;
    for (const string& coupon : coupons) {
        if (coupon == userCoupon) {
            isValidCoupon = true;
            if (coupon=="FIRST")
                {
                    discount=50;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="SUPER30")
                {
                    discount=30;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="FLAT60")
                {
                    discount=60;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="GO100")
                {
                    discount=100;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
        }
    }

    // If the coupon is not valid, inform the user
    if (!isValidCoupon) {
        discount=0;
        cout << "Sorry, your coupon is invalid." << endl;
    }

        car_amt=-car_amt;
        vehicle = new Car("VERNA", "BLACK", 2019, 1500.0, 5);
        a=tot_amt(daays,1500);
          cout << "\nVehicle Details:\n";
    vehicle->displayDetails();
    cout<<"\n|NAME:- "<<s1.name[i]<<"\t\t\t\t\t\t |";
    cout<<"\n|EMAIL ID:- "<<s1.email[i]<<"\t\t\t\t |";
    cout<<"\n|CONTACT NO.:- "<<s1.num[i]<<"\t\t\t\t |";
    cout<<"\n|DATE:- "<<__DATE__<<"\t\t\t\t\t |";
    cout<<"\n|TIME:- "<<__TIME__<<"\t\t\t\t\t |";
    cout<<"\n|AMT:- ₹"<<"\t\t"<<a<<"\t\t\t\t |";
    cout<<"\n|GST:- ₹"<<"\t\t"<<gst<<"\t\t\t\t |";
    cout<<"\n|SGST:- ₹"<<"\t\t"<<sgst<<"\t\t\t\t |";
    cout<<"\n|INSURANCE:- ₹"<<"\t\t"<<insurance<<"\t\t\t\t |";
    cout<<"\n|DISCOUNT:- ₹"<<"\t\t"<<discount<<"\t\t\t\t |";
    cout<<"\n|_________________________________\t\t\t |";
    cout<<"\n|TOTAL AMT:- ₹"<<"\t\t"<<(a+gst+sgst+insurance-discount)<<"\t\t\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n|\t!! THANKYOU FOR USING OUR SERVICES !!\t\t |";
    cout<<"\n|\t    !! WISH YOU A HAPPY JOURNEY !!\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n --------------------------------------------------------";
        }
        else if (car_amt<=0)
        {cout<<"OUT OF STOCK";}
    }
    else if (vehicleType == "SUV") {
        if (suv_amt>0)
        {
        cout<<"DO YOU WANT INSURANCE(CAR=750,SUPERBIKE=1000,SUV=1350,BIKE=250):-(Y/N) ";
        cin>>insured;
        if(insured=='Y'||'y')
            {
            insurance=1350;
            }
        else
            {
            insurance=0;
            }
        cout << "Enter your coupon code:(Capital letters only) ";
        string userCoupon;
        cin >> userCoupon;
        bool isValidCoupon = false;
    for (const string& coupon : coupons) {
        if (coupon == userCoupon) {
            isValidCoupon = true;
            if (coupon=="FIRST")
                {
                    discount=50;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="SUPER30")
                {
                    discount=30;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="FLAT60")
                {
                    discount=60;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
            else if (coupon=="GO100")
                {
                    discount=100;
                cout << "Congratulations! Your coupon '" << coupon << "' is valid." << endl;
                break;
                }
        }
    }

    // If the coupon is not valid, inform the user
    if (!isValidCoupon) {
        discount=0;
        cout << "Sorry, your coupon is invalid." << endl;
    }
        suv_amt=-suv_amt;
        vehicle = new SUV("FORTUNER", "SILVER", 2022, 2755.0, 7, true);
        a=tot_amt(daays,2755);
          cout << "\nVehicle Details:\n";
    vehicle->displayDetails();
    cout<<"\n|NAME:- "<<s1.name[i]<<"\t\t\t\t\t\t |";
    cout<<"\n|EMAIL ID:- "<<s1.email[i]<<"\t\t\t\t |";
    cout<<"\n|CONTACT NO.:- "<<s1.num[i]<<"\t\t\t\t |";
    cout<<"\n|DATE:- "<<__DATE__<<"\t\t\t\t\t |";
    cout<<"\n|TIME:- "<<__TIME__<<"\t\t\t\t\t |";
    cout<<"\n|AMT:- ₹"<<"\t\t"<<a<<"\t\t\t\t |";
    cout<<"\n|GST:- ₹"<<"\t\t"<<gst<<"\t\t\t\t |";
    cout<<"\n|SGST:- ₹"<<"\t\t"<<sgst<<"\t\t\t\t |";
    cout<<"\n|INSURANCE:- ₹"<<"\t\t"<<insurance<<"\t\t\t\t |";
    cout<<"\n|DISCOUNT:- ₹"<<"\t\t"<<discount<<"\t\t\t\t |";
    cout<<"\n|_________________________________\t\t\t |";
    cout<<"\n|TOTAL AMT:- ₹"<<"\t\t"<<(a+gst+sgst+insurance-discount)<<"\t\t\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n|\t!! THANKYOU FOR USING OUR SERVICES !!\t\t |";
    cout<<"\n|\t    !! WISH YOU A HAPPY JOURNEY !!\t\t |";
    cout<<"\n| \t\t\t\t\t\t\t |";
    cout<<"\n --------------------------------------------------------";
        }
        else if (suv_amt<=0)
        {cout<<"OUT OF STOCK";}
    } else {
        cout << "Invalid vehicle type!" << endl;
        return 1;
    }
    ofstream txt_out;

        txt_out.open("sample22.txt");
        txt_out<< "NAME:- "<<s1.name[i]<<endl;
        txt_out<< "AGE:- "<<s1.age[i]<<endl;
        txt_out<< "CONTACT NO.:- "<<s1.num[i]<<endl;
        txt_out<< "EMAIL ID:- "<<s1.email[i]<<endl;
        txt_out<< "ADDRESS:- "<<s1.address[i]<<endl;
        txt_out<< "START DATE:- "<<s1.sd[i]<<endl;
        txt_out<< "END DATE:- "<<s1.ed[i]<<endl;
        txt_out<< "VEHICLE TYPE:- "<<s1.veh_type[i]<<endl;
        txt_out<< "TAKEN ON RENT FOR DAYS:- "<<s1.days<<endl;
        txt_out<< "CURRENT TIME:- "<<s1.time[i]<<endl;
        txt_out.close();

    cout<<"\n\nDO YOU WANT TO CONTINUE :- (Y/N)"<<endl;
    cin>>choice;

    if(choice=='Y'||choice=='y')

    {i++;}

    }while (choice=='Y'||choice=='y');
    delete vehicle;
    outfile.close();
    return 0;
}
