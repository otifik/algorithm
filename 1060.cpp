/*
科学计数法计算逻辑：
1、找小数点位置。
2、找某数第一个不为0数字的位置。
3、将第一个不为0数字后的数字加入temp(有效数字)
4、第二点减第一点为指数值
5、判断指数和有效数字是否相等即可。
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
    //1
    int n, p = 0, q = 0;
    char a[10000], b[10000], A[10000], B[10000];
    scanf("%d%s%s", &n, a, b);
    int cnta = strlen(a), cntb = strlen(b);
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] == '.') {
            cnta = i;
            break;
        }
    }
    for(int i = 0; i < strlen(b); i++) {
        if(b[i] == '.') {
            cntb = i;
            break;
        }
    }
    //2,4
    int indexa = 0, indexb = 0;
    while(a[p] == '0' || a[p] == '.') p++;
    while(b[q] == '0' || b[q] == '.') q++;
    if(cnta >= p)
        cnta = cnta - p;
    else
        cnta = cnta - p + 1;
    if(cntb >= q)
        cntb = cntb - q;
    else
        cntb = cntb - q + 1;
    if(p == strlen(a))
        cnta = 0;
    if(q == strlen(b))
        cntb = 0;
    //3
    while(indexa < n) {
        if(a[p] != '.' && p < strlen(a))
            A[indexa++] = a[p];
        else if(p >= strlen(a))
            A[indexa++] = '0';
        p++;
    }
    while(indexb < n) {
        if(b[q] != '.' && q < strlen(b))
            B[indexb++] = b[q];
        else if(q >= strlen(b))
            B[indexb++] = '0';
        q++;
    }
    //5
    if(strcmp(A, B) == 0 && cnta == cntb)
        printf("YES 0.%s*10^%d", A, cnta);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d" , A, cnta, B, cntb);
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
 
// int f(const string&s, string&temp, int N) {
// 	int point = s.size(), index = -1;	//小数点位置、第一个非0数字位置
// 	for(int i = 0; i < s.size(); i++) {
// 		if(s[i] == '.') 	//找小数点 
// 			point = i;
// 		//若第一个不为0的位置找到，则将其后的数字加入temp 
// 		else if(index != -1 && temp.size() < N)	 
// 			temp += s[i];
// 		else if(index == -1 && s[i] != '0') { //找第一个不为0的位置 
// 			index = i;
// 			temp += s[i];
// 		}
// 	} 
// 	while(temp.size() < N)	//如果temp长度小于N，那么+0
// 		temp += "0";
// 	if(index == -1) //没有找到非零数字，说明字符串s表示的数是0
// 		return 0; 
// 	point -= index;		//小数点减去第一排非零数字位置得到指数 
// 	return point < 0 ? point+1 : point;	//如果为负数，返回point+1，否则返回point 
// }

// int main() {
// 	int N;
// 	string A, B, Atemp="", Btemp="";
// 	cin >> N >> A >> B;				 //读取数据
// 	int Aexp = f(A, Atemp, N), Bexp = f(B, Btemp, N); 
// 	if(Aexp == Bexp && Atemp == Btemp)	//若有效数字和指数皆相同
// 		cout << "YES 0." << Atemp << "*10^" << Aexp;
// 	else 
// 		cout << "NO 0." << Atemp << "*10^" << Aexp << " 0." << Btemp << "*10^" << Bexp; 
// 	return 0;
// } 
