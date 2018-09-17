#include <iostream>
#include <vector>
#include<string>
using namespace std;
int candy(vector<int> &ratings) {
	int i, j, sum = 0, min = ratings[0], n = ratings.size();
	vector<int> dp(n);
	if (n<2)return 1;
	for (i = 0; i<n; i++)
		dp[i] = 1;

	for (i = 0; i<n; i++)
	{
		if (i<n - 1 && ratings[i + 1]>ratings[i])
			dp[i + 1] = dp[i] + 1;
	}
	for (i = n - 1; i >= 0; i--)
	{
		if (i>0 && ratings[i - 1]>ratings[i] && dp[i - 1]<dp[i] + 1)
			dp[i - 1] = dp[i] + 1;
		sum += dp[i];
	}
	return sum;
}

int main() {
	int n;
	int number;
	vector<int> numbers;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		numbers.push_back(number);
	}
	int sum = candy(numbers);
	cout << sum << endl;
	system("PAUSE");
	return 0;

}
