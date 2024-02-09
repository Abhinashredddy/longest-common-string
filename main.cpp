#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string get_common_string(const string &s1, const string &s2) {
    const int len1 = s1.size();
    const int len2 = s2.size();

    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));

    auto max_pos = make_pair(0, 0);

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                max_pos = (dp[i][j] > dp[max_pos.first][max_pos.second]) ? make_pair(i, j) : max_pos;
            }
        }
    }

    vector<char> result_vec;

    while (dp[max_pos.first][max_pos.second] != 0) {
        result_vec.push_back(s1[max_pos.first - 1]);
        --max_pos.first;
        --max_pos.second;
    }

    return string(result_vec.rbegin(), result_vec.rend());
}

int main() {
    string input1, input2;

    cout << "Input 1: ";
    getline(cin, input1);

    cout << "Input 2: ";
    getline(cin, input2);

    string result = get_common_string(input1, input2);

    cout << "The longest common substring is: " << result << endl;
    cout << "The length of the longest common substring is: " << result.size() << endl;

    return 0;
}
