# BrainfucC

a simple brainfuck interpreter written in C that can be used in an interactive way


## compile

`gcc -o bf *.c`


#### execute

you can either use the plain executable file so do stuff like `./bf` or make yourself an **alias** in your shell. Something along the lines of: `alias bf="[absolute path]/bf/bf"` so that you can write `bf` in your terminal anywhere you are and it will result in executing the compiled file provided under the absolute path. In the following paragraphs I shall use the aliased version but I guess you know the difference.

Though there is one issue - it's *plain terminal* so there's no using your arrows for navigating in the bf commandline. Fortunately you can use special packages by people who have already had that problem before. Just use the `rlwrap` that many people may have already installed or the ocaml based tool called [**ledit**](https://opam.ocaml.org/packages/ledit/) that basicaly serves the same exact purpose. Then your alias might look something like

```bash
alias bf="ledit /[path]/bf/bf"
```

and now you can use arrows etc for navigation.


## usage

you can either

-   pass commands via the terminal eg. `bf "++++[>++++[>+++<-]<-]>>++.-.++.++++."`
-   execute brainfuck code from a source file `bf -f examples/hello.bf`. it is possible to add `-s` after the file's path to tell the interpreter to show the source file before executing it
-   use an interactive interpreter/console `bf` or `bf -i`

**the interactive console mode:**

![console](https://github.com/test0wanie/BrainfucC/blob/master/examples/bf_ex_nums.png?raw=true)

as you can see it shows both what values are currently saved under each cell and where is the pointer pointing at the moment.

which is pretty neat

---


###### DISCLAIMER - my terminal turned red??

well if you are really stubborn and really try to cause an error then it may not be caught in time. In general the interpreter tries to find errors beforehand eg. it checks whether the number of `[` matches the number of `]` etc **but** if you somehow try to acces cells under indexes lesser then 0 or bigger then the maximum size (specified in `main.h`) then you can cause a serious error and get a `segmentation fault` all in red because the program couldn't finish changing the colours before the seg fault. Fortunately you can easily fix that by writing:

`printf "\033[0m"`

in your terminal
