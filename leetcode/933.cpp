class RecentCounter {
public:
    std::queue<int> requests;

    RecentCounter() {
        // q empty by default
    }

    int ping(int t) {
        requests.push(t);

        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        return requests.size();
    }
};
