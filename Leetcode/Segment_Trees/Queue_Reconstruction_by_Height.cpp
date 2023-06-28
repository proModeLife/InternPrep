
class Solution {
    static const int M = 2001;
    int seg[M * 4];

    void buildSegTree(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = 1;
            return;
        }
        int mid = (l + r) / 2;
        buildSegTree(idx * 2, l, mid);
        buildSegTree(idx * 2 + 1, mid + 1, r);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    int query(int idx, int l, int r, int val) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (val <= seg[idx * 2])
            return query(idx * 2, l, mid, val);
        else
            return query(idx * 2 + 1, mid + 1, r, val - seg[idx * 2]);
    }

    void update(int idx, int l, int r, int pos) 
    {
        if (l == r) {
            seg[idx] = 0;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2, l, mid, pos);
        else
            update(idx * 2 + 1, mid + 1, r, pos);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    static bool compare(vector<int>& a, vector<int>& b) 
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] > b[1];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        buildSegTree(1, 0, people.size() - 1);
        sort(people.begin(), people.end(), compare);
        vector<int> ans;
        for (vector<int>& p : people) 
        {
            int q = query(1, 0, people.size() - 1, p[1] + 1);
            ans.push_back(q);
            update(1, 0, people.size() - 1, q);
        }
        vector<vector<int>> finalResult(people.size(), vector<int>(2, 0));
        int j = 0;
        for (int i : ans) 
        {
            finalResult[i] = people[j];
            j++;
        }
        return finalResult;
    }
};
