#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

int get_digits(unsigned int n, 
              vector<unsigned int> &v){
    v.clear();
    //vector<unsigned int>::iterator iter = v.begin();
    do {
        //iter = v.insert(iter, n % 10);
        v.insert(v.begin(), n % 10);
        n /= 10;
    } while (n);

    return 0;
}

unsigned int vector_to_number(const vector<unsigned int> &v){
    unsigned int n = 0;
    for(int i=0; i<v.size(); i++) {
        n *= 10;
        n += v[i];
    }
    return n;
}

void swap(vector<unsigned int> &v, int i, int j){
    int sz = v.size();
    if (i != j && sz > i && sz > j){
        unsigned int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
}

bool find_next(vector<unsigned int> &v, bool pos)
{
    // if pos == true, finds next higher number
    // if pos == false, finds next lower number
    // returns true if it is able to find the next number
    
    int ndigits = v.size();
    if (ndigits == 0)
        return false;

    bool found = false;
    //unsigned int last_num = v[ndigits-1];
    int behind = ndigits-1;
    for (int front=behind-1; front>=0 && !found; front--, behind--){
        if (pos && (v[front] < v[behind])){
            swap(v, front, behind);
            // sort the rest of the elements in ascending order
            // use 'less' function for ascending order
            sort(v.begin()+behind, v.end(), less<unsigned int>());
            found = true;
            break;
        }
        if (!pos && (v[front] > v[behind])){
            swap(v, front, behind);
            // sort the rest of the elements in descending order
            // use 'greater' function for descending order
            sort(v.begin()+behind, v.end(), greater<unsigned int>());
            found = true;
            break;
        }
    }
    return found;

}
int next_higher_num(int n) {
    bool positive_num = (n >= 0);

    // make it positive, we'll use this info later
    if (!positive_num) 
        n = n * (-1);

    vector<unsigned int> v;
    get_digits(static_cast<unsigned int>(n), v);
    if (!find_next(v, positive_num)) {
        cout << "could not find next higher number" << endl;
        return -1;
    }

    int result = static_cast<int> (vector_to_number(v));
    if (!positive_num)
        result = result *(-1);

    return result;
}

// utility functions
void print_vector(vector<unsigned int> &v){
    cout << "vector content: " ;
    for (int i=0; i<v.size(); i++){
        cout << v[i] << '\t';
    }
    cout << endl;
}

void show_get_digits(unsigned int n, 
        vector<unsigned int> &v){
    cout << "number: " << n;
    get_digits(n, v);
    cout << endl;
    print_vector(v);
}

// test it
int main(){
    vector<unsigned int> v;
    show_get_digits(0, v);
    unsigned int n;
    n = vector_to_number(v);
    assert(n == 0);
    show_get_digits(100, v);
    n = vector_to_number(v);
    assert(n == 100);
    show_get_digits(123, v);
    n = vector_to_number(v);
    assert(n == 123);
    int num = 21897;
    cout << "next_higher_num(" << num << ") = " << next_higher_num(num) << endl;
}
