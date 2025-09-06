import heapq

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        # Max-heap to store available fuel at stations we have passed
        maxHeap = []
        stations.append([target, 0])  # Treat destination as a station
        fuel = startFuel
        prev = 0
        refuels = 0
        
        for pos, cap in stations:
            fuel -= (pos - prev)  # Fuel spent to reach current station
            while fuel < 0 and maxHeap:
                # Refuel at the station with max fuel we've passed
                fuel += -heapq.heappop(maxHeap)
                refuels += 1
            if fuel < 0:
                # Cannot reach this station
                return -1
            heapq.heappush(maxHeap, -cap)  # Push current station fuel
            prev = pos
            
        return refuels
