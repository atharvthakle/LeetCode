public class Twitter
{
    private int time;
    private Dictionary<int, HashSet<int>> followees;
    private Dictionary<int, List<(int time, int tweetId)>> tweets;

    public Twitter()
    {
        time = 0;
        followees = new Dictionary<int, HashSet<int>>();
        tweets = new Dictionary<int, List<(int, int)>>();
    }

    public void PostTweet(int userId, int tweetId)
    {
        if (!tweets.ContainsKey(userId))
            tweets[userId] = new List<(int, int)>();

        tweets[userId].Add((time++, tweetId));
    }

    public IList<int> GetNewsFeed(int userId)
    {
        var result = new List<int>();

        // Max heap: newer tweets first
        var pq = new PriorityQueue<(int time, int tweetId), int>();

        // Add user's own tweets
        if (tweets.ContainsKey(userId))
        {
            foreach (var t in tweets[userId])
                pq.Enqueue(t, -t.time);
        }

        // Add followees' tweets
        if (followees.ContainsKey(userId))
        {
            foreach (int f in followees[userId])
            {
                if (tweets.ContainsKey(f))
                {
                    foreach (var t in tweets[f])
                        pq.Enqueue(t, -t.time);
                }
            }
        }

        // Get top 10 tweets
        while (pq.Count > 0 && result.Count < 10)
        {
            result.Add(pq.Dequeue().tweetId);
        }

        return result;
    }

    public void Follow(int followerId, int followeeId)
    {
        if (followerId == followeeId) return;

        if (!followees.ContainsKey(followerId))
            followees[followerId] = new HashSet<int>();

        followees[followerId].Add(followeeId);
    }

    public void Unfollow(int followerId, int followeeId)
    {
        if (followees.ContainsKey(followerId))
            followees[followerId].Remove(followeeId);
    }
}
