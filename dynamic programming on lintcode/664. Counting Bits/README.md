<div class="problem-modal-description problem-description-markdown light"><div class="problem-modal-description-main"><div class="rendered-markdown markdown-body sample-markdown "><p>Given a <strong>non negative</strong> integer number num. For every numbers i in the range <code>0 ≤ i ≤ num</code> calculate the number of 1's in their binary representation and return them as an array.</p>
</div></div><div class="problem-modal-description-example"><h3><span>样例</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p><strong>Example1</strong></p>
<pre><code>Input: 5
Output: [0,1,1,2,1,2]
Explanation:
The binary representation of 0~5 is:
000
001
010
011
100
101
the count of "1" in each number is: 0,1,1,2,1,2
</code></pre>
<p><strong>Example2</strong></p>
<pre><code>Input: 3
Output: [0,1,1,2]
</code></pre>
</div></div><div class="problem-modal-description-challenge"><h3><span>挑战</span></h3><div class="rendered-markdown markdown-body sample-markdown "><ol>
<li>It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?</li>
<li>Space complexity should be O(n).</li>
<li>Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.</li>
</ol>
</div></div></div>