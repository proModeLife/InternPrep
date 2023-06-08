#include <bits/stdc++.h>
using namespace std;

vector<int> allPalindrome;

// Function to check if a number is a palindrome
bool is_palindrome(int n) {
    int rev = 0, temp = n;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return n == rev;
}

// Function to generate all palindromes up to 2^15
void get_palindromes(){
    for (int i=1; i<=(1<<17); i++){
        if (is_palindrome(i)){
            allPalindrome.push_back(i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    get_palindromes(); // Call the function to generate the list of palindromes
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        long long int v[n];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            freq[v[i]]++;
        }
        long long int ans = 0;
        for (int i=0;i<allPalindrome.size();i++){
    		    long long int num=allPalindrome[i];
            for (int j=0;j<n;j++)
            {
    			ans+=freq[v[j]^num];	
    		}
    	}
        // Divide by 2 to avoid overcounting pairs of indices
        ans /= 2;
        // Add pairs of indices where A[i] = A[j]
        for (int i=0; i<(1<<17); i++){
            ans += (freq[i] * (freq[i]+1))/2;
        }
        cout << ans << endl;
    }
    return 0;
}


// Above implementation fails, below given passes 
#include<bits/stdc++.h>
using namespace std;
vector<int>allPalindrome;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
bool isPalindrome(int num){
	int rev=0;
	int temp=num;
	while (num>0){
		rev=rev*10 + (num%10);
		num/=10;
	}
	return (rev==temp);
}
void solve(){
	long long int n;
	cin>>n;
	long long int v[n];
	long long int freq[(1<<17)];
	memset(freq,0,sizeof(freq));
	for (int i=0;i<n;i++){
		cin>>v[i];
		freq[v[i]]++;
	}
    long long int ans=0;
	for (int i=0;i<allPalindrome.size();i++){
		long long int num=allPalindrome[i];
		for (int j=0;j<n;j++){
			ans+=freq[v[j]^num];	
		}
	}

	//Divide ans by 2 as each pair will be calculated twice
	ans/=2;
	//add all pairs such that A[i]^A[j] = 0 means A[i] and A[j] are same
    for (int i=0;i<(1<<17);i++){
        ans = ans + (freq[i] * (freq[i]+1))/2;

    }
	cout<<ans<<endl;
}

void generatePalindromes(){
	for (int i=1;i<=(1<<17);i++){
		if (isPalindrome(i)){
			allPalindrome.push_back(i);
		}
	}
}

int main(){
	int t;
	fast;
	cin>>t;
	generatePalindromes();
	while (t--){
		solve();
	}
}


// Difference is instead of using map they have used array 