/* Problem statement:
 *   Given an array of integers. 
 *   Write a function which returns the maximum
 *   subarray sum. */

int kadanesAlgo (vector<int> arr) { 
  int maxSum = (int) -1e9, curSum = 0;
  for (int i = 0; i < n; ++i) { 
    curSum += arr[i];
    maxSum = max(maxSum, curSum);
    if (curSum < 0) { 
      curSum = 0;
    }
  }
  return maxSum;
}
