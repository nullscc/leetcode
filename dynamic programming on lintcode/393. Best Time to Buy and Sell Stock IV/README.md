<div role="tabpanel" aria-hidden="false" class="ant-tabs-tabpane ant-tabs-tabpane-active"><div tabindex="0" role="presentation" style="width: 0px; height: 0px; overflow: hidden; position: absolute;"></div><div class="problem-modal-description problem-description-markdown light"><div class="problem-modal-description-main"><div class="rendered-markdown markdown-body sample-markdown "><p>Given an array <code>prices</code> and the <code>i-th</code> element of it represents the price of a stock on the <code>i-th</code> day.</p>
<p><strong>You may complete at most <code>k</code> transactions.</strong> What's the maximum profit?</p>
</div></div><div class="problem-modal-description-example"><h3><span>样例</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p><strong>Example 1:</strong></p>
<pre><code>Input: k = 2, prices = [4, 4, 6, 1, 1, 4, 2 ,5]
Output: 6
Explanation: Buy at 4 and sell at 6. Then buy at 1 and sell at 5. Your profit is 2 + 4 = 6.
</code></pre>
<p><strong>Example 2:</strong></p>
<pre><code>Input: k = 1, prices = [3, 2, 1]
Output: 0
Explanation: No transaction.
</code></pre>
</div></div><div class="problem-modal-description-challenge"><h3><span>挑战</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p>O(nk) time. <code>n</code> is the size of <code>prices</code>.</p>
</div></div><div class="problem-modal-description-notice"><h3><span>注意事项</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p>You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).</p>
</div></div></div><div tabindex="0" role="presentation" style="width: 0px; height: 0px; overflow: hidden; position: absolute;"></div></div>