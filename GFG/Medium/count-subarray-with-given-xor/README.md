# [Count Subarrays with given XORSolved](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1)

![Source](https://img.shields.io/badge/Source-GFG-blue)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange)

## Tags
`Arrays` `Map` `Bit Magic` `Count Number Subarrays Given Xor`

## Stats (Latest Submission)
| Metric | Value |
|--------|-------|
| Runtime | N/A |
| Runtime Beats | N/A% |
| Memory | N/A |
| Memory Beats | N/A% |
| Timestamp | Wed, 22 Jul 2026 16:06:32 GMT |

## Problem Description
<p><span style="font-size: 14pt;">Given an array of integers <strong>arr[]</strong> and a number <strong>k</strong>, count the number of subarrays having <strong>XOR</strong> of their elements as <strong>k</strong>.</span></p>
<p><strong><span style="font-size: 14pt;">Note:&nbsp;</span></strong><span style="font-size: 14pt;">It is guranteed that the total count will fit within a 32-bit integer.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:&nbsp;<br></strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [4, 2, 2, 6, 4], k = 6</span><br><span style="font-size: 14pt;"><strong>Output:</strong> 4</span><br><span style="font-size: 14pt;"><strong>Explanation:</strong> The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [5, 6, 7, 8, 9], k = 5</span><br><span style="font-size: 14pt;"><strong>Output:</strong> 2</span><br><span style="font-size: 14pt;"><strong>Explanation:</strong> The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [1, 1, 1, 1], k = 0</span><br><span style="font-size: 14pt;"><strong>Output:</strong> 4</span><br><span style="font-size: 14pt;"><strong>Explanation:</strong> The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:<br></strong></span><span style="font-size: 14pt;">1&nbsp;<span style="color: #1e2229; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span>&nbsp;arr.size()&nbsp;<span style="color: #1e2229; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span>&nbsp;10<sup>5<br></sup></span><span style="font-size: 14pt;">0&nbsp;<span style="color: #1e2229; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤ </span>arr[i] <span style="color: #1e2229; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤ </span>10<sup>5<br></sup></span><span style="font-size: 14pt;">0&nbsp;<span style="color: #1e2229; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span> k&nbsp;<span style="color: #1e2229; font-family: Nunito; font-size: 17px; background-color: #ffffff;">≤</span>&nbsp;10<sup>5</sup></span></p>

## Solutions
- [C++](solution.cpp)

