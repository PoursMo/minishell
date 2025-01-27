# empty inputs

""										okay, return value is 127	Leaks because of env, normal
""""									okay, return value is 127	Leaks because of env, normal
''										okay, return value is 127	Leaks because of env, normal
" "										okay, return value is 127	Leaks because of env, normal
"	"									okay, return value is 127	Leaks because of env, normal
# builtin commands
echo									okay, return value is 0		No leaks
echo ""									okay, return value is 0		No leaks
echo Hello World						okay, return value is 0		No leaks
echo "Hello World"						okay, return value is 0		No leaks
echo -n Hello World						okay, return value is 0		No leaks
echo -n -n Hello World					okay, return value is 0		No leaks
echo -nnnnnnnnnnnnn Hello World			okay, return value is 0		No leaks
echo Hello -n World						okay, return value is 0		No leaks
cd										okay, return value is 0		No leaks
cd ""									okay, return value is 0		No leaks
cd " "									okay, return value is 1		No leaks
cd Hello								okay, return value is 1		No leaks
cd ..									okay, return value is 0		No leaks
cd /home								okay, return value is 0		No leaks
pwd										okay, return value is 0		No leaks
pwd Hello World							okay, return value is 0		No leaks
export									okay, return value is 0		No leaks
export ""								okay, return value is 1		No leaks
export TEST								okay, return value is 0		No leaks
export TEST=Hello						okay, return value is 0		No leaks
export TEST+=World						okay, return value is 0		No leaks
export TEST++=World						okay, return value is 1		No leaks
export TEST=Hello World					okay, return value is 0		No leaks
export TEST="Hello World"				okay, return value is 0		No leaks
unset									okay, return value is 0		No leaks
unset ""								okay, return value is 0		No leaks
unset TEST								okay, return value is 0		No leaks
env										okay, return value is 0		No leaks
exit									okay, exit value is 0		Leaks in tokens
exit ""									okay, exit value is 2
exit Hello World						okay, exit value is 2
exit 42									okay, exit value is 42
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
