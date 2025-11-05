class Solution {
public:
    bool isSquare(int x){
        int r = (int)floor(sqrt(x));
        return r * r == x;
    }

    int minSquares(int n) {
        // If n is already a perfect square
        if(isSquare(n)) return 1;

        // Check if sum of 2 perfect squares
        for(int i = 1; i * i <= n; ++i){
            if(isSquare(n - i * i))
                return 2;
        }

        // Legendre's theorem check for 4-squares
        int m = n;
        while(m % 4 == 0) m /= 4;
        if(m % 8 == 7) return 4;

        // Otherwise answer is 3
        return 3;
    }
};
