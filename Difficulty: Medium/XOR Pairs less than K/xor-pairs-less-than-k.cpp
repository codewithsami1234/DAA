struct TrieNode {
    TrieNode* children[2];
    int count;
    TrieNode() {
        children[0] = children[1] = nullptr;
        count = 0;
    }
};

class Solution {
public:
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 15; i >= 0; i--) { // 16-bit numbers, max 5*10^4
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
            node->count++;
        }
    }

    int countLessThan(TrieNode* root, int num, int k) {
        TrieNode* node = root;
        int cnt = 0;
        for (int i = 15; i >= 0; i--) {
            if (!node) break;
            int bitNum = (num >> i) & 1;
            int bitK = (k >> i) & 1;

            if (bitK == 1) {
                if (node->children[bitNum])
                    cnt += node->children[bitNum]->count;
                node = node->children[1 - bitNum];
            } else {
                node = node->children[bitNum];
            }
        }
        return cnt;
    }

    int cntPairs(vector<int>& arr, int k) {
        TrieNode* root = new TrieNode();
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans += countLessThan(root, arr[i], k);
            insert(root, arr[i]);
        }
        return ans;
    }
};
