int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    
    for (int i = 0; i < intervalsSize - 1; i++) {
        for (int j = i + 1; j < intervalsSize; j++) {
            if (intervals[i][0] > intervals[j][0] ||
               (intervals[i][0] == intervals[j][0] && intervals[i][1] < intervals[j][1])) {
                int tempL = intervals[i][0];
                int tempR = intervals[i][1];
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
                intervals[j][0] = tempL;
                intervals[j][1] = tempR;
            }
        }
    }

    int count = 0;
    int prevRight = 0;
    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][1] > prevRight) {
            count++;
            prevRight = intervals[i][1];
        }
    }
    return count;
}
