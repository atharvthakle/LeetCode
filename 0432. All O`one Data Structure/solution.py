class Node:
    def __init__(self, count):
        self.count = count
        self.keys = set()
        self.prev = None
        self.next = None


class AllOne:

    def __init__(self):
        self.head = Node(0)  # dummy head (min side)
        self.tail = Node(0)  # dummy tail (max side)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.key_map = {}  # key -> node

    # Helper: insert new_node after prev_node
    def _insert_after(self, prev_node, new_node):
        new_node.prev = prev_node
        new_node.next = prev_node.next
        prev_node.next.prev = new_node
        prev_node.next = new_node

    # Helper: remove node
    def _remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def inc(self, key: str) -> None:
        if key in self.key_map:
            curr = self.key_map[key]
            next_count = curr.count + 1

            # remove key from current bucket
            curr.keys.remove(key)

            # check if next bucket exists
            if curr.next != self.tail and curr.next.count == next_count:
                next_node = curr.next
            else:
                next_node = Node(next_count)
                self._insert_after(curr, next_node)

            next_node.keys.add(key)
            self.key_map[key] = next_node

            # remove bucket if empty
            if not curr.keys:
                self._remove(curr)

        else:
            # new key, count = 1
            if self.head.next != self.tail and self.head.next.count == 1:
                node = self.head.next
            else:
                node = Node(1)
                self._insert_after(self.head, node)

            node.keys.add(key)
            self.key_map[key] = node

    def dec(self, key: str) -> None:
        curr = self.key_map[key]
        curr.keys.remove(key)

        if curr.count == 1:
            # remove key entirely
            del self.key_map[key]
        else:
            prev_count = curr.count - 1

            if curr.prev != self.head and curr.prev.count == prev_count:
                prev_node = curr.prev
            else:
                prev_node = Node(prev_count)
                self._insert_after(curr.prev, prev_node)

            prev_node.keys.add(key)
            self.key_map[key] = prev_node

        # remove bucket if empty
        if not curr.keys:
            self._remove(curr)

    def getMaxKey(self) -> str:
        if self.tail.prev == self.head:
            return ""
        return next(iter(self.tail.prev.keys))

    def getMinKey(self) -> str:
        if self.head.next == self.tail:
            return ""
        return next(iter(self.head.next.keys))
