
class MyHashSet {
public:
    vector<vector<int>> cell;
    int size;

    MyHashSet() {
        size = 10000;
        cell.resize(size);
    }

    void add(int key) {
        int cellNo = key % size;
        for (int i = 0; i < cell[cellNo].size(); i++) {
            if (cell[cellNo][i] == key) {
                return;
            }
        }
        cell[cellNo].push_back(key);
    }

    void remove(int key) {
        int cellNo = key % size;
        for (int i = 0; i < cell[cellNo].size(); i++) {
            if (cell[cellNo][i] == key) {
                swap(cell[cellNo][i], cell[cellNo].back());
                cell[cellNo].pop_back();
                return;
            }
        }
    }

    bool contains(int key) {
        int cellNo = key % size;
        for (int i = 0; i < cell[cellNo].size(); i++) {
            if (cell[cellNo][i] == key) {
                return true;
            }
        }
        return false;
    }
};
