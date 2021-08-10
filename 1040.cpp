//Brute-force
 #include <iostream>
 #include <algorithm>
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
