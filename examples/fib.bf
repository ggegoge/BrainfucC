# fib get n fib numbers
# @0 := n - input by user via the nonstandard `^` operator
# @1, @2 := f1, f2   assign two first
# copy @2 to @3 
# @2 := @1; @1 := 0
# @1 := @3; @2 := @2 + @3
# and i'll store @4 := 32 = ' ' for printin'
>>>++++++++[->++++<]<<<
^                  # get n
>+>+<<             # f1 = 1, f2 = 1
>>!>>.<<<<         # print with a space
[
    >>!>>.<<<<     # print with a space
    ->>
    [->+<]         # @3 := @2 = f2
    <[->+<]        # @2 := @1
    >>[-<+<+>>]    # @1 := @3; @2 := @2 + @3
    <<<
]

>>!>>.<<<<         # print with a space
