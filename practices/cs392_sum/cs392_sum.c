/**
 * Constance Xu
 * I pledge my honor that I have abided by the Stevens Honor System
 * March 14, 2020
 **/

//This function adds the two arguments and returns the result
int cs392_sum(int op1, int op2) {
    return op1 + op2;
}
// gcc -fPIC -c cs392_sum.c
// gcc -shared -o libcs392_sum.so cs392_sum.o
// gcc -c cs392_practice.c
// gcc -o cs392_practice cs392_practice.o libcs392_sum.so
// sudo mv libcs392_sum.so /usr/lib/
// sudo ldconfig
// ./cs392_practice


