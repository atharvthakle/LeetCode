import java.util.*;

class Solution {
    static final int MOD = 1_000_000_007;

    static class Node {
        long val;
        int len;
        int sum;
        Node() {}
        Node(long v, int l, int s) {
            val = v;
            len = l;
            sum = s;
        }
    }

    Node[] seg;
    long[] pow10;
    int[] pos;

    public int[] sumAndMultiply(String s, int[][] queries) {
        int m = s.length();

        ArrayList<Integer> pList = new ArrayList<>();
        ArrayList<Integer> dList = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int d = s.charAt(i) - '0';
            if (d != 0) {
                pList.add(i);
                dList.add(d);
            }
        }

        int n = pList.size();
        int[] ans = new int[queries.length];

        if (n == 0) return ans;

        pos = new int[n];
        int[] digits = new int[n];
        for (int i = 0; i < n; i++) {
            pos[i] = pList.get(i);
            digits[i] = dList.get(i);
        }

        pow10 = new long[n + 1];
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        seg = new Node[4 * n];
        build(1, 0, n - 1, digits);

        for (int i = 0; i < queries.length; i++) {
            int l = lowerBound(pos, queries[i][0]);
            int r = upperBound(pos, queries[i][1]) - 1;

            if (l > r) {
                ans[i] = 0;
                continue;
            }

            Node res = query(1, 0, n - 1, l, r);
            ans[i] = (int) (res.val * res.sum % MOD);
        }

        return ans;
    }

    private void build(int idx, int l, int r, int[] digits) {
        if (l == r) {
            seg[idx] = new Node(digits[l], 1, digits[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(idx << 1, l, mid, digits);
        build(idx << 1 | 1, mid + 1, r, digits);
        seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
    }

    private Node query(int idx, int l, int r, int ql, int qr) {
        if (ql == l && qr == r) return seg[idx];
        int mid = (l + r) >> 1;
        if (qr <= mid) return query(idx << 1, l, mid, ql, qr);
        if (ql > mid) return query(idx << 1 | 1, mid + 1, r, ql, qr);
        return merge(
                query(idx << 1, l, mid, ql, mid),
                query(idx << 1 | 1, mid + 1, r, mid + 1, qr)
        );
    }

    private Node merge(Node a, Node b) {
        return new Node(
                (a.val * pow10[b.len] + b.val) % MOD,
                a.len + b.len,
                a.sum + b.sum
        );
    }

    private int lowerBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }

    private int upperBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] <= target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
}
