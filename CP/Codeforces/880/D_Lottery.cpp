#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    long long m;
    cin >> n >> m >> k;

    set<int> places;
    multiset<int> lengths;

    // Add the start and end points to the set and multiset
    places.insert(0);
    places.insert(n);
    lengths.insert(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        // Find the segments that contain the new ticket
        auto it = places.upper_bound(t);
        int high = *it;
        it--;
        int low = *it;

        // Remove the length of the old segment
        lengths.erase(lengths.find(high - low));

        // Insert the new ticket into the set
        places.insert(t);

        // Insert the lengths of the two new segments
        lengths.insert(t - low);
        lengths.insert(high - t);

        // Output the largest segment length
        auto itr = lengths.end();
        itr--;
        cout << (*itr) << " ";
    }

    cout << endl;

    return 0;
}