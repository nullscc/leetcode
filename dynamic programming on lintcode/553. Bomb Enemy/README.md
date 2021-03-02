<div class="problem-modal-description problem-description-markdown light"><div class="problem-modal-description-main"><div class="rendered-markdown markdown-body sample-markdown "><p>Given a 2D grid, each cell is either a wall <code>'W'</code>, an enemy <code>'E'</code> or empty <code>'0'</code> (the number zero), return the maximum enemies you can kill using one bomb.<br>
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.</p>
</div></div><div class="problem-modal-description-example"><h3><span>样例</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p><strong>Example1</strong></p>
<pre><code>Input:
grid =[
     "0E00",
     "E0WE",
     "0E00"
]
Output: 3
Explanation:
Placing a bomb at (1,1) kills 3 enemies
</code></pre>
<p><strong>Example2</strong></p>
<pre><code>Input:
grid =[
     "0E00",
     "EEWE",
     "0E00"
]
Output: 2
Explanation:
Placing a bomb at (0,0) or (0,3) or (2,0) or (2,3) kills 2 enemies
</code></pre>
</div></div><div class="problem-modal-description-notice"><h3><span>注意事项</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p>You can only put the bomb at an empty cell.</p>
</div></div></div>