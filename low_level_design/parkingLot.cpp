// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#include<mutex>
#include <cstdlib> 


class Address {
    public:
    string city;
    string country;
    Address(string city, string c){
        city=city;
        country=c;
    }
};

enum class VehicleCategory {
    TwoWheeler,
    Hatchback,
    Sedan,
    SUV,
    Bus,
};

enum class ParkingSlotType {
    TwoWheeler,
    COMPACT,
};

class Price{
    virtual double getPriceForParking(long duration)=0;
};

class TwoWheeler:public Price{
    double getPriceForParking(long duration){
            return duration*0.05;
        }
};

class Compact:public Price{
    double getPriceForParking(long duration){
            return duration*0.75;
        }
};

class Vehicle{
    public:
    string vehicleNumber;
    VehicleCategory vehicleCategory;
    Vehicle( VehicleCategory b,string a){
        vehicleNumber=a;
        vehicleCategory=b;
    }
};

class ParkingSlot{
    string name;
    bool isAvailable;
    Vehicle* vehicle;
    ParkingSlotType* parkingSlotType;
    public:
    ParkingSlot(string name, ParkingSlotType parkingSlotType) {
        name = name;
        isAvailable= true;
        parkingSlotType = parkingSlotType;
    }
    void addVehicle(Vehicle vehicle){
        vehicle = vehicle;
        isAvailable=false;
    }
    void removeVehicle(){
        isAvailable=true;
    }
};

class Ticket{
    string ticketNumber;
    long startTime;
    long endTime;
    Vehicle* vehicle;
    ParkingSlot* parkingSlot;
    public:
    Ticket(Vehicle* vehicle,ParkingSlot* parkingSlot){
        ticketNumber = rand();
        startTime = 700;
        endTime = 1000;
        vehicle = vehicle;
        parkingSlot = parkingSlot; 
    }
    void getTicketDetails(){
        cout<<ticketNumber<< " "<< startTime<< " "<<" " <<endl;
    }
};

class parkingFloor{
    string name;
    unordered_map<ParkingSlotType*, unordered_map<string, ParkingSlot*>> parkingSlots;
    public:
    parkingFloor(string name , unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot*>> parkingSlots) {
        name=name;
        parkingSlots = parkingSlots;
    }
};

class parkingMain {
    parkingMain(){}
    static parkingMain* parkingLotIns;
    static mutex mtx;
    string name;
    Address* address;
    unordered_map<string, parkingFloor*> floors;
    public:
    static parkingMain* getInstance(){
        if(parkingLotIns == nullptr){
            mtx.lock();
            if(parkingLotIns == nullptr){
                parkingLotIns = new parkingMain();
            }
            mtx.unlock();
        }
        return parkingLotIns;
    }
    void setData(string nameOfParkingLot, Address* address, unordered_map<string, parkingFloor*> parkingFloors){
        nameOfParkingLot = nameOfParkingLot;
        address = address;
        floors = parkingFloors;
    }
    void addFloor(string name, parkingFloor* f){
        floors[name]=f;
    }
    void removefloor(string name){
        floors.erase(name);
    }
};
parkingMain* parkingMain::parkingLotIns = nullptr;
mutex parkingMain::mtx;


int main() {
    // Write C++ code here
     string nameOfParkingLot ="Practice Parking Lot";
     Address* address = new Address("HYD","IND");
     unordered_map<ParkingSlotType, unordered_map<string, ParkingSlot*>> ps;
     unordered_map<string, ParkingSlot*> cs;
     cs["C1"]= new ParkingSlot("C1", ParkingSlotType::COMPACT);
     cs["C2"]= new ParkingSlot("C2!!", ParkingSlotType::COMPACT);
     cs["C3"]= new ParkingSlot("C3!!", ParkingSlotType::COMPACT);
     unordered_map<string, ParkingSlot*> tw;
     tw["W1"]= new ParkingSlot("W1!!", ParkingSlotType::TwoWheeler);
     tw["W2"]= new ParkingSlot("W2!!", ParkingSlotType::TwoWheeler);
     tw["W3"]= new ParkingSlot("W3!!", ParkingSlotType::TwoWheeler);
     ps[ParkingSlotType::COMPACT] = cs;
     ps[ParkingSlotType::TwoWheeler] = tw;
     parkingFloor* ParkingFloor = new parkingFloor("1",ps);
     unordered_map<string, parkingFloor*> fs;
     fs["floor1"] = ParkingFloor;
     parkingMain* parkingLot1 = parkingMain::getInstance();
     parkingLot1->setData("nameOfParkingLot",address,fs);
     Vehicle* vehicle = new Vehicle(VehicleCategory::Hatchback,"KA-01-MA-9999");
     Ticket* ticket = new Ticket(vehicle, cs["C1"]);
     cout<<" << ticket number >> "<<endl;
     ticket->getTicketDetails();
     return 0;
}
