#include <stdio.h>
#include <iostream>
#include <bitset>
#define HASH_SIZE 128

using namespace std;

typedef char data_t;

void Print2DArray(char A[], int nr, int nc)
{
    int size = nr * nc;
    for (int i = 0; i < size; i++)
        printf("%4c", *(A + i));

    printf("\n");
}

void MatrixTransposeInplaceArrangement(data_t A[], int r, int c)
{
    int size = r * c - 1;
    data_t t;            // holds element to be replaced, eventually becomes next element to move
    int next;            // location of 't' to be moved
    int cycleBegin;      // holds start of cycle
    int i;               // iterator
    bitset<HASH_SIZE> b; // hash to mark moved elements

    b.reset();
    b[0] = b[size] = 1;
    i = 1; // Note that A[0] and A[size-1] won't move
    while (i < size)
    {
        cycleBegin = i;
        t = A[i];
        do
        {
            // Input matrix [r x c]
            // Output matrix
            // i_new = (i*r)%size
            next = (i * r) % size;
            swap(A[next], t);
            b[i] = 1;
            i = next;
        } while (i != cycleBegin);

        // Get Next Move (what about querying random location?)
        for (i = 1; i < size && b[i]; i++)
            ;
        cout << endl;
    }
}

void Fill(data_t buf[], int size)
{
    // Fill abcd ...
    for (int i = 0; i < size; i++)
        buf[i] = 'a' + i;

    // Fill 0123 ...
    buf += size;
    for (int i = 0; i < size; i++)
        buf[i] = '0' + i;
}

void TestCase_01(void)
{
    int r = 2, c = 10;
    int size = r * c;
    data_t *A = new data_t[size];

    Fill(A, c);

    Print2DArray(A, r, c), cout << endl;
    MatrixTransposeInplaceArrangement(A, r, c);
    Print2DArray(A, c, r), cout << endl;

    delete[] A;
}

int main()
{
    TestCase_01();

    cout << endl;
    system("pause");
    return 0;
}
