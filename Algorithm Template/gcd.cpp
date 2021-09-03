/*
辗转相除法是先用两个数中较大的数除以较小的数，
如果有余数，则用较小的那个数继续除以余数，
按照这样的方法一直除下去，除到余数为0为止，
那么最后的除数就是两个数的最大公因数。
*/
// int gcd(int m, int n) {
//     return n ? gcd(n, m % n) : m;
// }
int gcd(int a, int b){
    int t;
    while (b != 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}