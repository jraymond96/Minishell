# Minishell

## DESCRIPTION

It's a interpretor of command, who handle environement variable.

## WHAT CAN YOU DO WITH ?

* all executable can be execut if he is in PATH variable or if you specify his path `/usr/.../exec`
* multiple executables separated by `,`

| BUILTIN | ACTION |
| --- | --- |
| cd | change directory |
| env | display variable environement, execute an executable in edit environment (`env -i ./a.out` exec with empty environment) |
| unsetenv | unset environment variable (`unsetenv PATH`) |
| setenv | set new environmemt varaiable (` setenv NEWVAR contents_ofnewvar`) |
| echo | print the argument(s) of exectuable |
| exit | exit programme |

## GOAL OF THIS PROJECT

* Basic lexical and syntactic analysis ("lexing" and "parsing")
* Running a command in a new process
* Environnment management
* PATH Management
