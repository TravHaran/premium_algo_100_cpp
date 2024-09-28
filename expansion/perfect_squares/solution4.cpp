class Solution {
    // Mathematical optimization: Lagrange's Four Square Theorem
    // every positive integer can be represented as the sum of four or fewer perfect squares.
    // if n is a perfect square return 1 directly
    // if n is of the form (4^a)(8b+7) then it requires exactly 4 squares (number theory)
    // if n can be expressed as the sum of two perfect squares, return 2
    // else return 3 
public:
    bool isPerfectSquare(int x) {
        int s = (int)sqrt(x);
        return s * s == x;
    }
    
    // Check if the number can be written as a^2 + b^2
    bool isSumOfTwoSquares(int n) {
        for (int i = 1; i * i <= n; ++i) {
            if (isPerfectSquare(n - i * i)) {
                return true;
            }
        }
        return false;
    }

    int numSquares(int n) {
        // 1. Check if it's a perfect square
        if (isPerfectSquare(n)) {
            return 1;
        }
        
        // 2. Apply the form of 4^a(8b + 7)
        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }

        // 3. Check if the number can be written as the sum of two squares
        if (isSumOfTwoSquares(n)) {
            return 2;
        }

        // 4. Otherwise, return 3
        return 3;
    }
};