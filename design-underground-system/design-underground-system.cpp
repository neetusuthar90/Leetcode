class UndergroundSystem {
public:
    // id -> {stationName, t}
    unordered_map<int, pair<string,int>> checkInStation;

    // route -> {totalTime, count}
    unordered_map<string, pair<int,int>> checkOutStation;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkInfo = checkInStation[id];
        checkInStation.erase(id);

        string route = checkInfo.first + "-" + stationName;
        int totaltime = t - checkInfo.second;
        
        checkOutStation[route].first += totaltime;
        checkOutStation[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;
        double time = checkOutStation[route].first;
        double count = checkOutStation[route].second;

        double avgTime = time/count;
        return avgTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */