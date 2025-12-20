Trailing Zeros in n! (Short & Clear)

A trailing zero comes from 10, and 10 = 2 × 5.
In factorials, 2s are always more than 5s, so 5 decides everything.

Some numbers give more than one 5:

25 gives two 5s

125 gives three 5s

So we keep dividing by 5 and add:

zeros = n/5 + n/25 + n/125 + ...


Stop when division becomes 0.
That final number is the answer.

That’s it. ✅