# [Longest Subarray with Sum K](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)

![Source](https://img.shields.io/badge/Source-GFG-blue)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange)

## Tags
`Amazon` `Arrays` `Hash` `Map` `prefix-sum` `Longest Sub Array Sum K`

## Stats (Latest Submission)
| Metric | Value |
|--------|-------|
| Runtime | N/A |
| Runtime Beats | N/A% |
| Memory | N/A |
| Memory Beats | N/A% |
| Timestamp | Mon, 20 Jul 2026 10:01:19 GMT |

## Problem Description
<p><span style="font-size: 14pt;">Given an array <strong><code>arr[]</code></strong> containing integers and an integer <strong><code>k</code></strong>, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value&nbsp;<strong style="font-size: 18.6667px;"><code>k</code></strong>. If there is no subarray with sum equal to&nbsp;<strong style="font-size: 18.6667px;"><code>k</code></strong>, return <strong style="font-size: 18.6667px;"><code>0</code></strong>.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [10, 5, 2, 7, 1, -10], k = 15
<strong>Output:</strong> 6
<strong>Explanation: </strong></span><span style="font-size: 18.6667px;">Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [-5, 8, -14, 2, 4, 12], k = -5
<strong>Output:</strong> 5
<strong>Explanation: </strong>S</span><span style="font-size: 18.6667px;">ubarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [10, -10, 20, 30], k = 5
<strong>Output:</strong> 0
<strong>Explanation: </strong></span><span style="font-size: 18.6667px;">No subarray with sum = 5 is present in arr[].</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong></span><br><span style="font-size: 14pt;">1 ≤ arr.size() ≤ 10<sup>5<br></sup><span style="font-size: 18.6667px;">-10</span><sup>4&nbsp;</sup><span style="font-size: 18.6667px;">≤ arr[i] ≤ 10</span><sup>4</sup><sup><br></sup></span><span style="font-size: 14pt;">-10<sup>9 </sup>≤ k ≤ 10<sup>9</sup></span></p>

## Solutions
- [C++](solution.cpp)

