class UndergroundSystem {
    map<pair<string, string>, int> sum;
    map<pair<string, string>, int> count;
    map<pair<int, string>, int> idStationTime;
    map<int, string> idStation;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) { 
        idStationTime[{id, stationName}] = t;
        idStation[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        int tIn = idStationTime[{id, idStation[id]}];
        sum[{idStation[id], stationName}] += t - tIn;
        count[{idStation[id], stationName}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return ((double) sum[{startStation, endStation}] / count[{startStation, endStation}]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */