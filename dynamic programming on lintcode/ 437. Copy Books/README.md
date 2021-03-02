<div class="problem-modal-description problem-description-markdown light"><div class="problem-modal-description-main"><div class="rendered-markdown markdown-body sample-markdown "><p>Given <code>n</code> books and the <code>i-th</code> book has <code>pages[i]</code> pages. There are <code>k</code> persons to copy these books.</p>
<p>These books list in a row and each person can claim a continous range of books. For example, one copier can copy the books from <code>i-th</code> to <code>j-th</code> continously, but he can not copy the 1st book, 2nd book and 4th book (without 3rd book).</p>
<p>They start copying books at the same time and they all cost 1 minute to copy 1 page of a book. What's the best strategy to assign books so that the slowest copier can finish at earliest time?</p>
<p>Return the shortest time that the slowest copier spends.</p>
</div></div><div class="problem-modal-description-example"><h3><span>样例</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p><strong>Example 1:</strong></p>
<pre><code>Input: pages = [3, 2, 4], k = 2
Output: 5
Explanation: 
    First person spends 5 minutes to copy book 1 and book 2.
    Second person spends 4 minutes to copy book 3.
</code></pre>
<p><strong>Example 2:</strong></p>
<pre><code>Input: pages = [3, 2, 4], k = 3
Output: 4
Explanation: Each person copies one of the books.
</code></pre>
</div></div><div class="problem-modal-description-challenge"><h3><span>挑战</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p>O(nk) time</p>
</div></div><div class="problem-modal-description-notice"><h3><span>注意事项</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p>The sum of book pages is less than or equal to 2147483647</p>
</div></div></div>