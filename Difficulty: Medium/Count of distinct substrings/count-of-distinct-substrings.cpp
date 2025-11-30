class Solution {
public:
    struct State {
        int link;                   
        int len;                     
        map<char, int> next;         
        State() : link(-1), len(0) {}
    };

    vector<State> sa;   
    int last;           

    void sa_init() {
        sa.clear();
        sa.push_back(State());
        last = 0;
    }

    void sa_extend(char c) {
        int cur = sa.size();
        sa.push_back(State());
        sa[cur].len = sa[last].len + 1;

        int p = last;
        while (p != -1 && !sa[p].next.count(c)) {
            sa[p].next[c] = cur;
            p = sa[p].link;
        }

        if (p == -1) {
            sa[cur].link = 0;
        } else {
            int q = sa[p].next[c];
            if (sa[p].len + 1 == sa[q].len) {
                sa[cur].link = q;
            } else {
                int clone = sa.size();
                sa.push_back(sa[q]);
                sa[clone].len = sa[p].len + 1;

                while (p != -1 && sa[p].next[c] == q) {
                    sa[p].next[c] = clone;
                    p = sa[p].link;
                }
                sa[q].link = sa[cur].link = clone;
            }
        }
        last = cur;
    }

    int countSubs(string& s) {
        sa_init();
        for (char c : s) sa_extend(c);

        long long ans = 0;
        for (int i = 1; i < sa.size(); i++) {
            ans += sa[i].len - sa[sa[i].link].len;
        }
        return ans;
    }
};
