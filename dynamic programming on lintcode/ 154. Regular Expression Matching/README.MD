<div class="problem-modal-description problem-description-markdown light"><div class="problem-modal-description-main"><div class="rendered-markdown markdown-body sample-markdown "><p><span style="line-height: 30px;">Implement regular expression matching with support for&nbsp;</span><code style="font-size: 13px; line-height: 30px; white-space: normal;">'.'</code><span style="line-height: 30px;">&nbsp;and&nbsp;</span><code style="font-size: 13px; line-height: 30px; white-space: normal;">'*'</code><span style="line-height: 30px;">.</span></p><pre>'.' Matches any single character.
'*' Matches zero or more of the preceding element.
<p>The matching should cover the <span style="font-weight: 700;">entire</span> input string (not partial).</p>
<p>The function prototype should be:<br>
bool isMatch(string s, string p)</p></pre><p></p>
<p>isMatch("aa","a") → false</p><p>isMatch("aa","aa") → true</p><p>isMatch("aaa","aa") → false</p><p>isMatch("aa", "a*") → true</p><p>isMatch("aa", ".*") → true</p><p>isMatch("ab", ".*") → true</p><p>isMatch("aab", "c*a*b") →  true</p></div></div><div class="problem-modal-description-example"><h3><span>样例</span></h3><div class="rendered-markdown markdown-body sample-markdown "><p><strong>Example 1:</strong></p>
<pre><code>Input："aa"，"a"
Output：false
Explanation：
unable to match
</code></pre>
<p><strong>Example 2:</strong></p>
<pre><code>Input："aa"，"a*"
Output：true
Explanation：
'*' can repeat a
</code></pre>
</div></div></div>