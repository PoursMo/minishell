# empty inputs

""
""""
''
" "
"	"
# builtin commands
echo
echo ""
echo Hello World
echo "Hello World"
echo -n Hello World
echo -n -n Hello World
echo -nnnnnnnnnnnnn Hello World
echo Hello -n World
cd
cd ""
cd " "
cd Hello
cd ..
cd /home
pwd
pwd Hello World
export
export ""
export TEST
export TEST=Hello
export TEST+=World
export TEST=Hello World
export TEST="Hello World"
unset
unset ""
unset TEST
env
exit
exit ""
exit Hello World
exit 42
# environment variables
echo $HOME
echo $ABCDEF
echo $42
echo $%+
echo $?
echo '$HOME'
echo "$HOME"
# syntax errors (exit code 2)
| echo Hello World
echo Hello World |									# bash diff
echo Hello World >
echo ||| Hello World
> | echo Hello World
# non-builtin command
ls
ls -l
# redirections
cat minishell.c > out.txt
< minishell.c awk '{print "42"}' >> out.txt
cat > out.txt minishell.c
cat > nopermout.txt
cat > out.txt > out2.txt minishell.c
# pipes
echo Hello World | cat
cat minishell.c | wc -l > out.txt
cat < minishell.c | awk '{print "42"}' | wc -l
< minishell.c cat | >> out.txt wc -l
cat /dev/random | cat
cat > out minishell.c | wc -l
cat minishell.c | << end cat
cat nonexistant | ls
# errors (exit code 1)
ls "-l -a"
cat nonexistant
ls | cat nonexistant
# no path || no env

# command not found (exit code 127)
# command found but not executable (exit code 126)
