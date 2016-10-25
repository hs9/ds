#include <iostream>

using namespace std;


unsigned int get_bit(unsigned int n, int i)
{
    return (n >> i) & 1;
}

unsigned int set_bit(unsigned int n, int i)
{
    return n | (1 << i);
}

unsigned int clear_bit(unsigned int n, int i)
{
    return n & ~(1 << i);
}

unsigned int get_mask(int i, int j)
{
    // returns an integer with all 1s between i and j
    
    // make sure i > j
    if (i < j){
        int tmp = i;
        i = j;
        j = tmp;
    }

    return ((1 << (i+1)) - 1) & ~((1 << j) - 1);
}

unsigned int set_bits(unsigned int n, int i, int j)
{
    cout << "setting bits from " << i << " to " << j << endl;
    return n | get_mask(i, j);
}

unsigned int clear_bits(unsigned int n, int i, int j)
{
    cout << "clearing bits from " << i << " to " << j << endl;
    return n & ~get_mask(i,j);
}
void tobin(unsigned int n)
{
    if (n == 0){
        cout << n;
        return;
    }
    tobin(n/2);
    cout << n % 2;
}

void print_binary(unsigned int n)
{
    tobin(n);
    cout << endl;
}

int main()
{
    unsigned int n = 23;
    print_binary(n);
#if 0
    for (int i=0; i<=16; i++)
    {
        cout << i << '\t';
        print_binary(i);
    }
    for (int i=0; i<8; i++){
        //cout << get_bit(n, i) << endl;
        //print_binary(set_bit(n, i));
        print_binary(clear_bit(n, i));
    }
#endif
    //print_binary(set_bits(0, 4, 6));
    print_binary(clear_bits(0xffff, 4, 6));
}



