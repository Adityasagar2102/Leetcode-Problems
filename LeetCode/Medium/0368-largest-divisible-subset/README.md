# [368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset)

![Source](https://img.shields.io/badge/Source-LeetCode-blue)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange)

## Tags
`Array` `Math` `Dynamic Programming` `Sorting`

## Stats (Latest Submission)
| Metric | Value |
|--------|-------|
| Runtime | 11 ms |
| Runtime Beats | 63.302700000000016% |
| Memory | 12.6 MB |
| Memory Beats | 51.257700000000014% |
| Timestamp | Tue, 14 Jul 2026 09:28:07 GMT |

## Problem Description
<p>Given a set of <strong>distinct</strong> positive integers <code>nums</code>, return the largest subset <code>answer</code> such that every pair <code>(answer[i], answer[j])</code> of elements in this subset satisfies:</p>

<ul>
	<li><code>answer[i] % answer[j] == 0</code>, or</li>
	<li><code>answer[j] % answer[i] == 0</code></li>
</ul>

<p>If there are multiple solutions, return any of them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> [1,3] is also accepted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,4,8]
<strong>Output:</strong> [1,2,4,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2 * 10<sup>9</sup></code></li>
	<li>All the integers in <code>nums</code> are <strong>unique</strong>.</li>
</ul>


## Solutions
- [C++](solution.cpp)

