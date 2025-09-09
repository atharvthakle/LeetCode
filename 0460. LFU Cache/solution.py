from collections import defaultdict, OrderedDict

class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.min_freq = 0
        self.key_to_val_freq = {}  # key -> (val, freq)
        self.freq_to_keys = defaultdict(OrderedDict)  # freq -> {key: None} (OrderedDict for LRU)

    def _update_freq(self, key: int):
        val, freq = self.key_to_val_freq[key]
        # Remove from old freq bucket
        del self.freq_to_keys[freq][key]
        if not self.freq_to_keys[freq]:  # If empty, remove it
            del self.freq_to_keys[freq]
            if self.min_freq == freq:
                self.min_freq += 1

        # Add to new freq bucket
        self.key_to_val_freq[key] = (val, freq + 1)
        self.freq_to_keys[freq + 1][key] = None

    def get(self, key: int) -> int:
        if key not in self.key_to_val_freq:
            return -1
        self._update_freq(key)
        return self.key_to_val_freq[key][0]

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key in self.key_to_val_freq:
            # Update value
            self.key_to_val_freq[key] = (value, self.key_to_val_freq[key][1])
            self._update_freq(key)
            return

        if self.size >= self.capacity:
            # Evict LFU key (and LRU among them)
            k, _ = self.freq_to_keys[self.min_freq].popitem(last=False)
            del self.key_to_val_freq[k]
            if not self.freq_to_keys[self.min_freq]:
                del self.freq_to_keys[self.min_freq]
            self.size -= 1

        # Insert new key
        self.key_to_val_freq[key] = (value, 1)
        self.freq_to_keys[1][key] = None
        self.min_freq = 1
        self.size += 1
