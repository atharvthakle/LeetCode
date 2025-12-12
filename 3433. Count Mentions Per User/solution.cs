public class Solution {
    public int[] CountMentions(int numberOfUsers, IList<IList<string>> events) {
        // Parse events into (time, type, payload, originalIndex) to stable-sort if needed
        var evList = new List<(int time, string type, string payload, int idx)>();
        for (int i = 0; i < events.Count; i++) {
            var e = events[i];
            string type = e[0];
            int time = int.Parse(e[1]);
            string payload = e[2];
            evList.Add((time, type, payload, i));
        }

        // Sort by time asc; if same time, OFFLINE before MESSAGE
        evList.Sort((a, b) => {
            if (a.time != b.time) return a.time.CompareTo(b.time);
            if (a.type == b.type) return a.idx.CompareTo(b.idx); // stable tie-break
            // OFFLINE first
            if (a.type == "OFFLINE") return -1;
            if (b.type == "OFFLINE") return 1;
            return a.idx.CompareTo(b.idx);
        });

        int[] mentions = new int[numberOfUsers];
        // offlineUntil[u] = time when user becomes online again; initially 0 => online at t>=0
        int[] offlineUntil = new int[numberOfUsers];

        foreach (var ev in evList) {
            int time = ev.time;
            string type = ev.type;
            string payload = ev.payload;

            if (type == "OFFLINE") {
                // payload is the id string (like "0")
                int id = int.Parse(payload);
                // They go offline at time and come back at time + 60
                offlineUntil[id] = time + 60;
            } else { // MESSAGE
                // payload can contain space-separated tokens: "id0 id1", "HERE", "ALL", etc.
                var tokens = payload.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                foreach (var tok in tokens) {
                    if (tok == "ALL") {
                        for (int u = 0; u < numberOfUsers; u++) mentions[u]++;
                    } else if (tok == "HERE") {
                        for (int u = 0; u < numberOfUsers; u++) {
                            if (offlineUntil[u] <= time) mentions[u]++;
                        }
                    } else if (tok.StartsWith("id")) {
                        // id<number>
                        // parse after "id"
                        int id = int.Parse(tok.Substring(2));
                        mentions[id]++;
                    } else {
                        // Defensive: if strange token (shouldn't happen per constraints), ignore
                    }
                }
            }
        }

        return mentions;
    }
}
