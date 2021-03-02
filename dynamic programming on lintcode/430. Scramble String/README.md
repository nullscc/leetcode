<div class="rendered-markdown markdown-body sample-markdown "><p>Given a string <code>s1</code>, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.</p>
<p>Below is one possible representation of <code>s1 = "great"</code>:</p>
<pre><code>    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
</code></pre>
<p>To scramble the string, we may choose any non-leaf node and swap its two children.</p>
<p>For example, if we choose the node <code>"gr"</code> and swap its two children, it produces a scrambled string <code>"rgeat"</code>.</p>
<pre><code>    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
</code></pre>
<p>We say that <code>"rgeat"</code> is a scrambled string of <code>"great"</code>.</p>
<p>Similarly, if we continue to swap the children of nodes <code>"eat"</code> and <code>"at"</code>, it produces a scrambled string <code>"rgtae"</code>.</p>
<pre><code>    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
</code></pre>
<p>We say that <code>"rgtae"</code> is a scrambled string of <code>"great"</code>.</p>
<p>Given two strings <code>s1</code> and <code>s2</code> of the same length, determine if <code>s2</code> is a scrambled string of <code>s1</code>.</p>
</div>