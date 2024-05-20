#include<bits/stdc++.h>
#include "mutex"
using namespace std;

static int nextTripId = 1;

enum class RATING {
	UNASSIGNED,
	ONE_STAR,
	TWO_STARS,
	THREE_STARS,
	FOUR_STARS,
	FIVE_STARS,
};

enum class TRIP_STATUS {
	UNASSIGNED,
	DRIVER_ON_THE_WAY,
	DRIVER_ARRIVED,
	STARTED,
	PAUSED,
	CANCELLED,
	ENDED,
};

class Util {
public:
	static string ratingToString(RATING pRating) {
		if (pRating == RATING::ONE_STAR)
			return "one star";
		if (pRating == RATING::TWO_STARS)
			return "two stars";
		if (pRating == RATING::THREE_STARS)
			return "three stars";
		if (pRating == RATING::FOUR_STARS)
			return "four stars";
		if (pRating == RATING::FIVE_STARS)
			return "five stars";
		return "invalid rating";
	}

	static bool isHighRating(RATING pRating) {
		return pRating == RATING::FOUR_STARS || pRating == RATING::FIVE_STARS;
	}
};

class Location {
public:
	double latitude;
	double longitude;
	Location(double pLatitude, double pLongitude) : latitude(pLatitude), longitude(pLongitude) {}
};

class TripMetaData {
	Location* srcLoc;
	Location* dstLoc;
	RATING riderRating;
	RATING driverRating;
public:
	TripMetaData(Location* pSrcLoc, Location* pDstLoc, RATING pRiderRating){
		srcLoc=pSrcLoc;
		dstLoc=pDstLoc;
		riderRating=pRiderRating;
		driverRating = RATING::UNASSIGNED;
	}
	//getters and setters should be in cpp guys, I am just lazy to that
	RATING getRiderRating() {
		return riderRating;
	}
	RATING getDriverRating() {
		return driverRating;
	}
	void setDriverRating(RATING pDriverRating) {
		driverRating = pDriverRating;
	}
};

class Rider {
	string name;
	RATING rating;
public:
	Rider(string pName, RATING pRating) : name(pName), rating(pRating) {}
	string getRiderName() {
		return name;
	}
	RATING getRating() {
		return rating;
	}
}; 

class PricingStrategy {
public:
	virtual double calculatePrice(TripMetaData* pTripMetaData) = 0;
};

class RiderMgr {
	RiderMgr(){}
	static RiderMgr* riderMgrInstance;
	static mutex mtx;
	unordered_map<string, Rider*> ridersMap;
public:
	static RiderMgr* getRiderMgr(){
	    if (riderMgrInstance == nullptr) {
		mtx.lock();
		if (riderMgrInstance == nullptr) {
			riderMgrInstance = new RiderMgr();
		}
		mtx.unlock();
	}
	return riderMgrInstance;
	}
	void addRider(string pRiderName, Rider* pRider){
	    ridersMap[pRiderName] = pRider; 
	}
	Rider* getRider(string pRiderName){
	    return ridersMap[pRiderName];
	}
};
RiderMgr* RiderMgr::riderMgrInstance = nullptr;
mutex RiderMgr::mtx;

class DefaultPricingStrategy : public PricingStrategy {
public:
	double calculatePrice(TripMetaData* pTripMetaData) {
		cout << "Based on default strategy, price is 100" << endl;
		return 100.0;
	}
};

class RatingBasedPricingStrategy :public PricingStrategy {
public:
	double calculatePrice(TripMetaData* pTripMetaData) {
		double price = Util::isHighRating(pTripMetaData->getRiderRating()) ? 55.0 : 65.0;
		cout << "Based on " << Util::ratingToString(pTripMetaData->getRiderRating()) << 
			" rider rating, price of the trip is " << price << endl;
		return price;
	}
};

class Driver {
	string name;
	bool avail;
	RATING rating;
public:
	Driver(string pName, RATING pRating) : name(pName), rating(pRating) {
		avail = false;
	}
	void updateAvail(bool pAvail) {
		avail = pAvail;
	}
	string getDriverName() {
		return name;
	}
	RATING getRating() {
		return rating;
	}
};

class DriverMatchingStrategy {
public:
	virtual Driver* matchDriver(TripMetaData* pTripMetaData) = 0;
};

class DriverMgr {
	DriverMgr(){}
	static DriverMgr* driverMgrInstance;
	static mutex mtx;	
	unordered_map<string, Driver*> driversMap;
public:
	static DriverMgr* getDriverMgr(){
	    if (driverMgrInstance == nullptr) {
		mtx.lock();
		if (driverMgrInstance == nullptr) {
			driverMgrInstance = new DriverMgr();
		}
		mtx.unlock();
	}
	return driverMgrInstance;
	}
	void addDriver(string pDriverName, Driver* pDriver){
	    driversMap[pDriverName] = pDriver;
	}
	Driver* getDriver(string pDriverName){
	    return driversMap[pDriverName];
	}
	unordered_map<string, Driver*> getDriversMap(){
	    return driversMap;
	}
};
DriverMgr* DriverMgr::driverMgrInstance = nullptr;
mutex DriverMgr::mtx;

class LeastTimeBasedMatchingStrategy : public DriverMatchingStrategy {
public:
	Driver* matchDriver(TripMetaData* pMetaData) {
		DriverMgr* driverMgr = DriverMgr::getDriverMgr();

		if ((driverMgr->getDriversMap()).size() == 0) {
			cout << "No drivers! What service is this huh?" << endl;
		}
		cout << "Using quadtree to see nearest cabs, using driver manager to get details of drivers and send notifications" << endl;
		Driver* driver = ((driverMgr->getDriversMap()).begin())->second; //here we can call quadtree algo to get nearest cabs
		cout << "Setting " << driver->getDriverName() << " as driver" << endl;
		pMetaData->setDriverRating(driver->getRating());
		return driver;
	}
};

class StrategyMgr {
	StrategyMgr() {}
	static StrategyMgr* strategyMgrInstance;
	static mutex mtx;

public:
	static StrategyMgr* getStrategyMgr(){
	    if (strategyMgrInstance == nullptr) {
		mtx.lock();
		if (strategyMgrInstance == nullptr) {
			strategyMgrInstance = new StrategyMgr();
		}
		mtx.unlock();
	}
	return strategyMgrInstance;
	}
	PricingStrategy* determinePricingStrategy(TripMetaData* metaData){
	    cout << "Based on location and other factors, setting pricing strategy" << endl;
	    return new DefaultPricingStrategy();
	}
	DriverMatchingStrategy* determineMatchingStrategy(TripMetaData* metaData){
	    cout << "Based on location and other factors, setting matching strategy" << endl;
	    return new LeastTimeBasedMatchingStrategy();
	}
};
StrategyMgr* StrategyMgr::strategyMgrInstance = nullptr;
mutex StrategyMgr::mtx;

class Trip {
	Rider* rider;
	Driver* driver;
	Location* srcloc;
	Location* dstLoc;
	TRIP_STATUS status;
	int tripId;
	double price;
	PricingStrategy* pricingStrategy;
	DriverMatchingStrategy* driverMatchingStrategy;
public:
	Trip(Rider* pRider, Driver* pDriver, Location* pSrcLoc, Location* pDstLoc, double pPrice,
		PricingStrategy* pPricingStrategy, DriverMatchingStrategy* pDriverMatchingStrategy) : 
		rider(pRider), driver(pDriver), srcloc(pSrcLoc), dstLoc(pDstLoc), price(pPrice),
		pricingStrategy(pPricingStrategy), driverMatchingStrategy(pDriverMatchingStrategy) {
		status = TRIP_STATUS::DRIVER_ON_THE_WAY;
		//This is not threadsafe and is just for demo purposes
		tripId = nextTripId;
		nextTripId++;
	}
	int getTripId() {
		return tripId;
	}
	void displayTripDetails() {
		cout << endl;
		cout << "Trip id - " << tripId << endl;
		cout << "Rider - " << rider->getRiderName() << endl;
		cout << "Driver - " << driver->getDriverName() << endl;
		cout << "Price - " << price << endl;
		cout << "Locations - " <<srcloc->latitude<<","<<srcloc->longitude<<" and "<<dstLoc->latitude<<","<<dstLoc->longitude << endl;
	}
};

class TripMgr {
	static TripMgr* tripMgrInstance;
	static mutex mtx;
	TripMgr(){
		riderMgr = RiderMgr::getRiderMgr();
		driverMgr = DriverMgr::getDriverMgr();
	}
	RiderMgr* riderMgr;
	DriverMgr* driverMgr;
	unordered_map<int, TripMetaData*> tripsMetaDataInfo; 
	unordered_map<int, Trip*> tripsInfo;
public:
	static TripMgr* getTripMgr(){
	    if (tripMgrInstance == nullptr) {
		mtx.lock();
		if (tripMgrInstance == nullptr) {
			tripMgrInstance = new TripMgr();
		}
		mtx.unlock();
	}
	return tripMgrInstance;
	}
	void CreateTrip(Rider* pRider, Location* pSrcLoc, Location* pDstLoc){
	    TripMetaData* metaData = new TripMetaData(pSrcLoc, pDstLoc, pRider->getRating());
	    StrategyMgr* strategyMgr = StrategyMgr::getStrategyMgr();
	    PricingStrategy* pricingStrategy = strategyMgr->determinePricingStrategy(metaData);
	    DriverMatchingStrategy* driverMatchingStrategy = strategyMgr->determineMatchingStrategy(metaData);
	
	    Driver* driver = driverMatchingStrategy->matchDriver(metaData);
	    double tripPrice = pricingStrategy->calculatePrice(metaData);

	    Trip* trip = new Trip(pRider, driver, pSrcLoc, pDstLoc, tripPrice, pricingStrategy, driverMatchingStrategy);
	    int tripId = trip->getTripId();
	    tripsInfo[tripId] = trip;
	    tripsMetaDataInfo[tripId] = metaData;
	}
	unordered_map<int, Trip*> getTripsMap(){
	    return tripsInfo;
    }
};
TripMgr* TripMgr::tripMgrInstance = nullptr;
mutex TripMgr::mtx;


int main() {

	//---------------Creating Riders and Drivers--------------------------------
	Rider* keertiRider = new Rider("Keerti", RATING::FIVE_STARS);
	Rider* gauravRider = new Rider("Gaurav", RATING::FIVE_STARS);
	
	RiderMgr* riderMgr = RiderMgr::getRiderMgr();
	riderMgr->addRider("keerti", keertiRider);
	riderMgr->addRider("gaurav", gauravRider);
    
    Driver* yogitaDriver = new Driver("Yogita", RATING::THREE_STARS);
	Driver* riddhiDriver = new Driver("Riddhi", RATING::FOUR_STARS);
	DriverMgr* driverMgr = DriverMgr::getDriverMgr();
	driverMgr->addDriver("yogita", yogitaDriver);
	driverMgr->addDriver("riddhi", riddhiDriver);

	//These details in turn will be stored in database
	//-------------------------------------------------------------------------

	TripMgr* tripMgr = TripMgr::getTripMgr();


	cout << endl << "Creating Trip for Keerti from location (10,10) to (30,30)" << endl;
	tripMgr->CreateTrip(keertiRider, new Location(10, 10), new Location(30, 30));

	cout << endl << "Creating Trip for Gaurav from location (200,200) to (500,500)" << endl;
	tripMgr->CreateTrip(gauravRider, new Location(200, 200), new Location(500, 500));


	//-------------------Display all the trips created--------------------------
	unordered_map<int, Trip*> tripsMap = tripMgr->getTripsMap();
	for (auto mapVal : tripsMap) {
		(mapVal.second)->displayTripDetails();
	}



	return 0;
}

