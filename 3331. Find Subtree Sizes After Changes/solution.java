class Solution {
    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;

        int[] head = new int[n];
        int[] next = new int[n];
        int[] children = new int[n];
        java.util.Arrays.fill(head, -1);

        for (int i = 1; i < n; i++) {
            next[i] = head[parent[i]];
            children[i] = i;
            head[parent[i]] = i;
        }

        int[] last = new int[26];
        java.util.Arrays.fill(last, -1);

        int[] prevSame = new int[n];
        int[] newParent = new int[n];

        int[] stack = new int[2 * n];
        int top = 0;
        stack[top++] = 0;

        while (top > 0) {
            int node = stack[--top];

            if (node < 0) {
                node = ~node;
                last[s.charAt(node) - 'a'] = prevSame[node];
                continue;
            }

            int c = s.charAt(node) - 'a';
            prevSame[node] = last[c];

            newParent[node] = (prevSame[node] != -1)
                    ? prevSame[node]
                    : parent[node];

            last[c] = node;

            stack[top++] = ~node;

            for (int child = head[node]; child != -1; child = next[child]) {
                stack[top++] = child;
            }
        }

        int[] finalHead = new int[n];
        int[] finalNext = new int[n];
        java.util.Arrays.fill(finalHead, -1);

        for (int i = 1; i < n; i++) {
            int p = newParent[i];
            finalNext[i] = finalHead[p];
            finalHead[p] = i;
        }

        int[] order = new int[n];
        top = 0;
        int size = 0;

        stack[top++] = 0;

        while (top > 0) {
            int node = stack[--top];
            order[size++] = node;

            for (int child = finalHead[node]; child != -1; child = finalNext[child]) {
                stack[top++] = child;
            }
        }

        int[] ans = new int[n];
        java.util.Arrays.fill(ans, 1);

        for (int i = size - 1; i > 0; i--) {
            int node = order[i];
            ans[newParent[node]] += ans[node];
        }

        return ans;
    }
}  
