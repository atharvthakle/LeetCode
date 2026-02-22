using System;
using System.Collections.Generic;

public class Solution {
    public int MinMutation(string startGene, string endGene, string[] bank) {
        HashSet<string> geneBank = new HashSet<string>(bank);

        if (!geneBank.Contains(endGene))
            return -1;

        Queue<string> queue = new Queue<string>();
        queue.Enqueue(startGene);

        int steps = 0;
        char[] genes = new char[] { 'A', 'C', 'G', 'T' };

        while (queue.Count > 0) {
            int size = queue.Count;

            for (int i = 0; i < size; i++) {
                string current = queue.Dequeue();

                if (current == endGene)
                    return steps;

                char[] arr = current.ToCharArray();

                for (int j = 0; j < 8; j++) {
                    char original = arr[j];

                    foreach (char c in genes) {
                        if (c == original) continue;

                        arr[j] = c;
                        string mutated = new string(arr);

                        if (geneBank.Contains(mutated)) {
                            queue.Enqueue(mutated);
                            geneBank.Remove(mutated); // avoid revisiting
                        }
                    }

                    arr[j] = original; // restore
                }
            }

            steps++;
        }

        return -1;
    }
}
