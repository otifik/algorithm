//Brute-force
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s;
    int maxlen = 0;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        for(int j = 1; j <= s.size() - i; j++){
            string s1 = s.substr(i,j), s2 = s1;
            reverse(s2.begin(), s2.end());
            if(s2 == s1 && maxlen < s1.size()) maxlen = s1.size();
        }
    }
    printf("%d",maxlen);
    return 0;
}

//柳神动态规划
#include <iostream>
using namespace std;
int dp[1010][1010];
int main() {
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    for(int L = 3; L <= len; L++) {
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}

/*

递推方程：s[i]==s[j] ? dp[i][j] = dp[i+1][j-1] : dp[i][j]=0

递推边界：dp[i][i] = 1，dp[i][i+1] = (s[i]==s[i+1]) ? 1 : 0

*/