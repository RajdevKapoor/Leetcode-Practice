class RecentCounter {
private:
    vector<int> vec; // Vector to store timestamps
public:
    RecentCounter() {
        vec = {}; // Initialize the vector as empty in the constructor
    }
    
    int ping(int t) {
        int count = 0; // Variable to store the count of timestamps within the specified time range
        int beg = t - 3000, end = t; // Define the time range [t - 3000, t]
        vec.push_back(t); // Add the current timestamp to the vector

        // Iterate through the vector from the end to the beginning
        for (int i = vec.size() - 1; i >= 0; i--) {
            // Check if the timestamp falls within the specified time range
            if (vec[i] >= beg && vec[i] <= end) {
                count++; // Increment the count if within the time range
            } else {
                break; // Break out of the loop if the timestamp is outside the time range
            }
        }

        return count; // Return the count of timestamps within the time range
    }
};
