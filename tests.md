# empty inputs

""
""""
''
" "
"	"
# builtin commands
echo
echo ""
echo " "
echo Hello World
echo -n Hello World
echo -n
cd
cd ""
cd " "
cd Hello
cd ..
cd /home
pwd
export
export ""
export TEST
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
echo Hello World |
echo Hello World >
> | echo Hello World
# non-builtin command
ls
ls -l
# redirections
cat minishell.c > out.txt
< minishell.c awk '{print "42"}' >> out.txt
cat > out.txt minishell.c
# pipes
echo Hello World | cat
cat minishell.c | wc -l > out.txt
cat < minishell.c | awk '{print "42"}' | wc -l
# errors (exit code 1)

# command not found (exit code 127)
# command found but not executable (exit code 126)
