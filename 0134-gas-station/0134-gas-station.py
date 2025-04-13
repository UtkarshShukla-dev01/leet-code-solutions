class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_tank = 0       # Tracks total net gas over the whole trip
        current_tank = 0     # Tracks gas from current starting station
        start_index = 0      # Potential starting index

        for i in range(len(gas)):
            net_gas = gas[i] - cost[i]
            total_tank += net_gas
            current_tank += net_gas

            # If we run out of gas at this point, we can't start from 'start_index'
            if current_tank < 0:
                start_index = i + 1  # Try next station as new start
                current_tank = 0     # Reset the tank

        # If total gas is sufficient to cover total cost, return starting index
        return start_index if total_tank >= 0 else -1
