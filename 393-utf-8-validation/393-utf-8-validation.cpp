class Solution {
public:
	string tobinary(int n) {
		string s = "";
		for(int i = 7; i >= 0; i--) {
			int k = n >> i;
			if(k & 1) {
				s.push_back('1');
			}
			else {
				s.push_back('0');
			}
		}
		return s;
	}

	int byte(string s) {
		if(s[0] == '0') {
			return 0;
		}
		else if(s[0] == '1' && s[1] == '1' && s[2] == '0') {
			return 1;
		}
		else if(s[0] == '1' && s[1] == '1' && s[2] == '1' && s[3] == '0') {
			return 2;
		}
		else if(s[0] == '1' && s[1] == '1' && s[2] == '1' && s[3] == '1' && s[4] == '0') {
			return 3;
		}
		return -1;
	}

	bool validUtf8(vector<int>& data) {
		int i = 0;
		while(i < data.size()) {
			string s = tobinary(data[i]);
			int cnt = byte(s);

			if(cnt == -1) {
				cout << "1";
				return false;
			}

			while(cnt) {
				i++;
				if(i >= data.size()) {
					cout << "2";
					return false;
				}
				string s = tobinary(data[i]);
				if(s[0] != '1' || s[1] != '0') {
					cout << "3";
					return false;
				}
				cnt--;
			}

			i++;
		}
		return true;
	}
};