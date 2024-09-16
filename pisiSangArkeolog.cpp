#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

char temukan_huruf_terdekat(const string &s, int i){
	map<char,vector<int>> pos_map;
	
	for(int j = 0; j< s.size(); j++){
		if(s[j] !='_'){
			pos_map[s[j]].push_back(j);
		}
	}
	
	char closest_char = '\0';
	double min_diff = 1e9;
	
	for(const auto&pair : pos_map){
		char letter = pair.first;
		const vector<int> &posisi = pair.second;
		
		double rata_rata_pos = 0;
		
		for(int pos : posisi){
			rata_rata_pos += pos;
		}
		
		rata_rata_pos /= posisi.size();
		
		double diff = abs(rata_rata_pos - i);
		if (diff < min_diff){
			min_diff = diff;
			closest_char = letter;
		}
	}
	
	return closest_char;
}

int main (){
	string s;
	int i;
	
	cin >> s >> i;
	
	char result = temukan_huruf_terdekat(s,i);
	
	cout<< result << endl;
	
	return 0;
	
}