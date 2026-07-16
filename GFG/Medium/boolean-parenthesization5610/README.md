# [Boolean ParenthesizationSolved](https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1)

![Source](https://img.shields.io/badge/Source-GFG-blue)
![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange)

## Tags
`Amazon` `Microsoft` `Intuit` `Linkedin` `Dynamic Programming` `Algorithms`

## Stats (Latest Submission)
| Metric | Value |
|--------|-------|
| Runtime | N/A |
| Runtime Beats | N/A% |
| Memory | N/A |
| Memory Beats | N/A% |
| Timestamp | Thu, 16 Jul 2026 10:50:14 GMT |

## Problem Description
<p><span style="font-size: 18px;">You are given a boolean expression <strong>s&nbsp;</strong>containing<br>&nbsp;&nbsp;&nbsp; 'T' ---&gt; true<br>&nbsp;&nbsp;&nbsp; 'F' ---&gt; false&nbsp;<br>and following operators between symbols<br>&nbsp; &nbsp;&amp;&nbsp;&nbsp; ---&gt; boolean AND<br>&nbsp;&nbsp;&nbsp; |&nbsp;&nbsp; ---&gt; boolean OR<br>&nbsp; &nbsp;^&nbsp;&nbsp; ---&gt; boolean XOR<br>Count the number of ways we can <strong>parenthesize </strong>the expression so that the value of expression evaluates to <strong>true</strong>.</span></p>
<p><span style="font-size: 18px;">Note: The answer is guaranteed to fit within a <strong>32-bit</strong> integer.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> s = "T|T&amp;F^T"
<strong>Output:</strong> 4
<strong>Explaination:</strong> The expression evaluates to true in 4 ways: ((T|T)&amp;(F^T)), (T|(T&amp;(F^T))), (((T|T)&amp;F)^T) and (T|((T&amp;F)^T)).</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> s = "T^F|F"
<strong>Output:</strong> 2
<strong>Explaination:</strong> The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |s| ≤ 100&nbsp;</span></p>

## Solutions
- [C++](solution.cpp)

