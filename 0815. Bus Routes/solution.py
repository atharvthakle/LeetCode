from collections import defaultdict, deque
from typing import List

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0

        # Map from stop to list of buses that go through it
        stop_to_buses = defaultdict(set)
        for i, route in enumerate(routes):
            for stop in route:
                stop_to_buses[stop].add(i)

        visited_stops = set()
        visited_buses = set()
        queue = deque([(source, 0)])  # (current stop, buses taken)

        while queue:
            stop, buses_taken = queue.popleft()
            if stop == target:
                return buses_taken

            for bus in stop_to_buses[stop]:
                if bus in visited_buses:
                    continue
                visited_buses.add(bus)
                for next_stop in routes[bus]:
                    if next_stop not in visited_stops:
                        visited_stops.add(next_stop)
                        queue.append((next_stop, buses_taken + 1))

        return -1
