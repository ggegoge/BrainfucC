# raising to a power bf program

# getting the input via the additional `^` operator
# print "base: "
--[----->+<]>----.-.--[--->+<]>--.++++[->+++<]>.+++[->+++<]>++.[-->+<]>+++.
[-]<<<<<
# @5 := base
^[->>>>>+<<<<<]

# print "exponent: "
--[----->+<]>-.[--->+<]>+.--------.-.-.---------.+++++++++.++++++.[-->+<]>.[-->+<]>+++.
[-]<<<<
# @3 := exp
^[->>>+<<<]

# @1 & @2 := @5 = base
>>>>>[-<<<+<+>>>>]
<+
<
# memory rn:
# @ 00@00 b@01 b@02 ex@03 01@04 00@05 00@06
#                   ^

[                         # @3
    -
    >                     # @4   base0
    [
        -
        >                 # @5 += (base = @2)
        <<<[->>>+<<<]     # @2 = 0 so let's restore it @2 := @1 = base
        <[-<+>]<          # @0 := @1; @1 := 0        
        [->+>+<<]>>       # @1 := base & @2 := base; @0 := 0
        >>                # @4 := base 
    ]
    >                     # go to @5 and move it to @
    [-<+>]
    <<                    # bacc to the exp
]

<<< #?
>>>>!