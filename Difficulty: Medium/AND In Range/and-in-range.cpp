class Solution {
  public:
    int andInRange(int l, int r) {
        int shift = 0;

        // Keep shifting until both numbers become equal
        while (l < r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }

        // Left-shift back to restore common prefix
        return l << shift;
    }
};
