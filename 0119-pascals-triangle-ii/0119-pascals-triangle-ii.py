class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [1]  # Start with the first element

        for i in range(1, rowIndex + 1):
            # Update from right to left to avoid overwriting needed values
            row.append(1)  # Add a placeholder 1 for the new row end
            for j in range(i - 1, 0, -1):
                row[j] = row[j] + row[j - 1]

        return row
