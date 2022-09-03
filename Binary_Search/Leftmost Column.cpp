#include<bits/stdc++.h>

using namespace std;

/*
You are given a row-sorted binary matrix, i.e., all the matrix rows are sorted in
non-decreasing order, and the matrix contains only 0 or 1. Your task is to return
the leftmost index of the column such that it contains at least one 1. If such a
column doesn’t exist in the matrix, then return -1.
*/

class Solution
{
    private:
        int matrix[102][102];
        int r, c;

    int BinarySearch(int row)
    {
        int lo, hi, mid;
        lo = 0; hi = c-1;

        while(hi - lo >= 2) {
            mid = lo + (hi-lo)/2;
            if(matrix[row][mid] == 1) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        for(int i = lo; i <= hi; i++) {
            if(matrix[row][i]) return i;
        }
        return 1000;
    }

    public:
        int leftmostColumn()
        {
            r = 4; c = 4;
            matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 1;
            matrix[1][0] = 0; matrix[1][1] = 0; matrix[1][2] = 1; matrix[0][3] = 1;
            matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0; matrix[2][3] = 0;
            matrix[3][0] = 0; matrix[3][1] = 1; matrix[3][2] = 1; matrix[3][3] = 1;
            int mn = 10000;
            for(int i = 0; i < r; i++) {
                int temp = BinarySearch(i);
                mn = min(mn, temp);
            }
            return mn;
        }
};

int main()
{
    Solution ss;
    cout << ss.leftmostColumn() << endl;
    return 0;
}
