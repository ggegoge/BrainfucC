# BrainfucC
a simple brainfuck interpreter written in C that can be used in an interactive way

## compile
`gcc -o bf *.c`

## usage
you can either

* pass commands via the terminal eg. `./bf "++++[>++++[>+++<-]<-]>>++.-.++.++++."`
* execute brainfuck code from a source file `./bf -f examples/hello.bf`. it is possible to add `-s` after the file's path to tell the interpreter to show the source file before executing it
* use an interactive interpreter/console `./bf -i`

