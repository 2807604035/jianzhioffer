#include<iostream>
#include<vector>
using namespace std;
struct Dict {
	int key;
	int value;
};
int countFrequency(vector<int> numbers, int number) {
	int count = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == number) count++;
	}
	return count;
}
int MoreThanHalfNum_Solution(vector<int> number) {
	vector<Dict> number_fre;
	for (int i = 0; i < number.size(); i++) {
		Dict dict;
		dict.key = number[i];
		dict.value = countFrequency(number, number[i]);
		number_fre.push_back(dict);	
	}
	int max = 0;
	Dict answer;
	for (int i = 0; i < number_fre.size(); i++) {
		if (number_fre[i].value > max) {
			max = number_fre[i].value;
			answer = number_fre[i];
		}
	}
	if (max > number.size() / 2) return answer.key;
	else return 0;
}
int main() {
	vector<int> input;
	int number;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		input.push_back(number);
	}
	int output = MoreThanHalfNum_Solution(input);
	cout << output << endl;
	system("PAUSE");
	return 0;



}