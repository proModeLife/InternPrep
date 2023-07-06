
class UndergroundSystem {
public:
    map<pair<string, string>, pair<int, int>> mp;
    map<int, pair<string, int>> chk;

    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        chk[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto it = chk[id];
        mp[{it.first, stationName}].first += t - it.second;
        mp[{it.first, stationName}].second++;
    }

    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = mp[{startStation, endStation}];
        return (double) p.first / p.second;
    }
};
