<div class="problem-modal-description problem-description-markdown light"><div class="problem-modal-description-main"><div class="rendered-markdown markdown-body sample-markdown "><p>There are a row of <code>n</code> houses, each house can be painted with one of the <code>k</code> colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.</p>
<p>The cost of painting each house with a certain color is represented by a <code>n</code> x <code>k</code> cost matrix. For example, <code>costs[0][0]</code> is the cost of painting house <code>0</code> with color <code>0</code>; <code>costs[1][2]</code> is the cost of painting house <code>1</code> with color <code>2</code>, and so on... Find the minimum cost to paint all houses.</p>
</div></div><div class="problem-modal-description-example"><h3><span>样例</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p><strong>Example 1</strong></p>
<pre><code class="language-plain">Input:
costs = [[14,2,11],[11,14,5],[14,3,10]]
Output: 10
Explanation:
The three house use color [1,2,1] for each house. The total cost is 10.
</code></pre>
<p><strong>Example 2</strong></p>
<pre><code class="language-plain">Input:
costs = [[5]]
Output: 5
Explanation:
There is only one color and one house.
</code></pre>
</div></div><div class="problem-modal-description-challenge"><h3><span>挑战</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p>Could you solve it in O(nk)</p>
</div></div><div class="problem-modal-description-notice"><h3><span>注意事项</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p>All costs are positive integers.</p>
</div></div></div>