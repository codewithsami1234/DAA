class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0) return 0;
        int x = 0;
        while ((1 << (x + 1)) <= n) {
            x++;
        }

        // Bits till 2^x - 1
        int bits_up_to_2x = x * (1 << (x - 1));

        // MSB bits from 2^x to n
        int msb_bits = (n - (1 << x) + 1);

        // Remaining bits
        int rest = n - (1 << x);

        return bits_up_to_2x + msb_bits + countSetBits(rest);
    }
};
