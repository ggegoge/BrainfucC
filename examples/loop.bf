# simple nested loop example
# save 2*5*7 @2 and print the ascii there

++                       # set @0 := 2
[                        # a loop until @_ = 0
    -                    # @0 -= 1
    >                    # move to @1
    +++++                # @1 := 5
    [                    # a new loop until @_ = 0
        >                # move to @2
        +++++++          # @2 := 7
        <                # back @1
        -                # @1 -= 1
    ]                    # after the inner loop: @2 = 35
    <
]                        # after the outer loop @2 = 70
>>        
.                        # print chr(@2^) = chr(70) = 'F'
