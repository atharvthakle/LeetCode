class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        if valueDiff < 0 or indexDiff <= 0:
            return False

        bucket = {}
        bucket_size = valueDiff + 1  # bucket width

        for i, num in enumerate(nums):
            bucket_id = num // bucket_size  # Python's // already floors (works for negatives)

            # Check current bucket
            if bucket_id in bucket:
                return True

            # Check neighbor buckets
            if (bucket_id - 1 in bucket and abs(num - bucket[bucket_id - 1]) <= valueDiff) or \
               (bucket_id + 1 in bucket and abs(num - bucket[bucket_id + 1]) <= valueDiff):
                return True

            # Insert current number into its bucket
            bucket[bucket_id] = num

            # Remove the number that's out of the sliding window
            if i >= indexDiff:
                old = nums[i - indexDiff]
                old_bucket_id = old // bucket_size  # same formula
                # safe removal: the key must exist if window maintenance is correct
                if old_bucket_id in bucket:
                    del bucket[old_bucket_id]

        return False
