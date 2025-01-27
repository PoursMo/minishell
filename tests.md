# empty inputs

""										okay, return value is 127
""""									okay, return value is 127
''										okay, return value is 127
" "										okay, return value is 127
"	"									okay, return value is 127
# builtin commands
echo									okay, return value is 0
echo ""									okay, return value is 0
echo Hello World						okay, return value is 0
echo "Hello World"						okay, return value is 0
echo -n Hello World						okay, return value is 0
echo -n -n Hello World					okay, return value is 0
echo -nnnnnnnnnnnnn Hello World			okay, return value is 0
echo Hello -n World						okay, return value is 0
cd										okay, return value is 0
cd ""									okay, return value is 0
cd " "									okay, return value is different 0 for minishell, 1 for bash
cd Hello								okay, return value is different 0 for minishell, 1 for bash
cd ..									okay, return value is 0
cd /home								okay, return value is 0
pwd										okay, return value is 0
pwd Hello World							okay, return value is 0
export									okay, return value is 0
export ""								not okay, should'nt be able to export empty or only numeric global values
export TEST								okay, return value is differrent 0 for minishell, 1 for bash
export TEST=Hello						okay, return value is 0
export TEST+=World
export TEST++=World
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
