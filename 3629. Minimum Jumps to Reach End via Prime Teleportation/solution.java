import java.util.*;

class Solution {

    public int minJumps(int[] nums) {
        int n = nums.length;

        if (n == 1) return 0;

        // value -> indices divisible by this prime
        Map<Integer, List<Integer>> primeToIndices = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int p : getPrimeFactors(nums[i])) {
                primeToIndices
                    .computeIfAbsent(p, k -> new ArrayList<>())
                    .add(i);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];

        q.offer(0);
        visited[0] = true;

        int steps = 0;

        while (!q.isEmpty()) {
            int size = q.size();

            while (size-- > 0) {
                int i = q.poll();

                if (i == n - 1) {
                    return steps;
                }

                // adjacent left
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.offer(i - 1);
                }

                // adjacent right
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.offer(i + 1);
                }

                // teleportation only if nums[i] is prime
                int val = nums[i];

                if (isPrime(val) && primeToIndices.containsKey(val)) {

                    for (int next : primeToIndices.get(val)) {
                        if (!visited[next]) {
                            visited[next] = true;
                            q.offer(next);
                        }
                    }

                    // prevent repeated processing
                    primeToIndices.remove(val);
                }
            }

            steps++;
        }

        return -1;
    }

    private boolean isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    private List<Integer> getPrimeFactors(int x) {
        List<Integer> factors = new ArrayList<>();

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.add(p);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        if (x > 1) {
            factors.add(x);
        }

        return factors;
    }
}
