#include <iostream>
using namespace std;

#define ll long long
#define MAXN 100005
int n, m;

int a[MAXN];

struct TreeNode{
    ll val;
    ll lazy;
} tr[4*MAXN];

void build(int l, int r, int idx){
    if (l == r){
        tr[idx].val = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    tr[idx].val = tr[2*idx].val + tr[2*idx+1].val;
}

void update(int pos, int val, int cl, int cr, int idx){
    if (cl == cr){
        tr[idx].val += val;
        return;
    }

    int mid = (cl + cr) / 2;

    if (pos <= mid) update(pos, val, cl, mid, idx*2);
    else update(pos, val, mid+1, cr, idx*2 + 1);

    tr[idx].val = tr[idx*2].val + tr[idx*2+1].val;
}

void pushdown(int cl, int cr, int idx){
    if (tr[idx].lazy != 0){
        tr[idx*2].lazy += tr[idx].lazy;
        tr[idx*2+1].lazy += tr[idx].lazy;

        int mid = (cl + cr) / 2;

        tr[idx*2].val += tr[idx].lazy * (mid - cl + 1);
        tr[idx*2+1].val += tr[idx].lazy * (cr - mid);

        tr[idx].lazy = 0;
    }
}

void update(int l, int r, ll val, int cl, int cr, int idx){
    if (l <= cl && r >= cr) {
        tr[idx].lazy += val;
        tr[idx].val += val * (cr - cl + 1);
        return;
    }

    pushdown(cl, cr, idx);

    int mid = (cl + cr) / 2;

    if (l <= mid) update(l, r, val, cl, mid, idx*2);
    if (r > mid) update(l, r, val, mid+1, cr, idx*2 + 1);

    tr[idx].val = tr[idx*2].val + tr[idx*2+1].val;
}

ll query(int l, int r, int cl, int cr, int idx){
    if (l <= cl && r >= cr) return tr[idx].val;

    pushdown(cl, cr, idx);

    int mid = (cl + cr) / 2;

    ll ans = 0;
    if (l <= mid) ans += query(l, r, cl, mid, idx*2);
    if (r > mid) ans += query(l, r, mid+1, cr, idx*2 + 1);

    return ans;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    build(1, n, 1);

    for (int i = 0; i < m; ++i){
        int t, l, r, v;
        cin >> t;
        if (t == 1){
            cin >> l >> r >> v;
            update(l, r, v, 1, n, 1);
        } else {
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << '\n';
        }
    }
}
