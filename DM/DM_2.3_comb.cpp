#include <iostream>
#include <string>
#include <regex>
#include <set>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main()
{
	string line;
	getline(cin, line);
	line = regex_replace(line, regex(" +"), ""); // убираем пробелы
	unsigned k; //положительное целое
	cin >> k;
	auto length = line.length();
	if (k >= length)
		cout << line;
	else {
		set <string> st;  //контейнер set
		auto comb = string(line.begin(), line.begin() + k);
		st.insert(comb);
		while (next_permutation(line.begin(), line.end())) {
			comb = string(line.begin(), line.begin() + k);
			if (is_sorted(comb.begin(), comb.end())) st.insert(comb);
		}
		auto width = k + 1;
		for (auto& token : st) cout << token << ' ';
		cout.put('\n');

	}

	system("pause");

}

