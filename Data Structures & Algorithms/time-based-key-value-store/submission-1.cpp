class TimeMap {
    map<string, vector<pair<int, string>>> data;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (data.find(key) == data.end()) return "";

        int low = 0;
        int high = data[key].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (data[key][mid].first <= timestamp) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }

        if (high == -1) return "";

        return data[key][high].second;
    }
};