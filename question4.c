#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the maximum subarray sum in a circular array
int maxSubarraySumCircular(int* nums, int numsSize) {
    int maxSum = INT_MIN, minSum = INT_MAX;
    int totalSum = 0, currentMax = 0, currentMin = 0;

    for (int i = 0; i < numsSize; i++) {
        // Calculate the total sum of the array
        totalSum += nums[i];
        // Find maximum subarray sum using Kadane's algorithm
        currentMax = (currentMax > 0 ? currentMax : 0) + nums[i];
        maxSum = (currentMax > maxSum ? currentMax : maxSum);

        // Find minimum subarray sum using Kadane's algorithm
        currentMin = (currentMin < 0 ? currentMin : 0) + nums[i];
        minSum = (currentMin < minSum ? currentMin : minSum);
    }

    // If all numbers are negative, return the maximum element
    if (totalSum == minSum) {
        return maxSum;
    }
    // Maximum circular subarray sum is either the max subarray sum
    // or the total sum minus the min subarray sum
    return (maxSum > totalSum - minSum ? maxSum : totalSum - minSum);
}
