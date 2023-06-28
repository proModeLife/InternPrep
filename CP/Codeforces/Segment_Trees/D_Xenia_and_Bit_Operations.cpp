#include <climits>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTrees
{
public:
   vector<int> seg;
   SegmentTrees(int n)
   {
      seg.resize(4 * n);
   }
   void build(int ind, int low, int high, vector<int>& arr, int orr)
   {
      if (low == high)
      {
         seg[ind] = arr[low];
         return;
      }
      int mid = (low + high) / 2;
      build(2 * ind + 1, low, mid, arr, !orr);
      build(2 * ind + 2, mid + 1, high, arr, !orr);
      if (orr)
         seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
      else
         seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
   }
   void update(int ind, int low, int high, int val, int i, int orr)
   {
      if (low == high)
      {
         seg[ind] = val;
        //  arr[i] = val; // update the value in the original array
         return;
      }
      int mid = (low + high) / 2;
      if (i <= mid)
         update(2 * ind + 1, low, mid, val, i, !orr);
      else
         update(2 * ind + 2, mid + 1, high, val, i, !orr);
      if (orr)
         seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
      else
         seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
   }
};

void solve()
{
   int n;
   cin >> n;
   int q;
   cin >> q;
   int elems = pow(2, n);
   vector<int> arr(elems);
   for (int i = 0; i < elems; i++)
   {
      cin >> arr[i];
   }
   SegmentTrees sg(elems);
   sg.build(0, 0, elems - 1, arr, n%2==1);
   while (q--)
   {
      int p, b;
      cin >> p >> b;
      sg.update(0, 0, elems - 1, b, p-1, n%2==1);
      cout << sg.seg[0] << endl;
   }
}
int main()
{
   solve();
   return 0;
}