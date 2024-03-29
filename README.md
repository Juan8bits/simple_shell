![ ](https://content.instructables.com/ORIG/FAF/EHV8/J2AWLJOC/FAFEHV8J2AWLJOC.jpg?frame=1)

-------------------------------------------------

# **SIMPLE SHELL**

## **Description:memo:**

In this project we investigated, understood, and developed a basic clone of a UNIX shell that performs shell (sh) functionalities. This program was written in C language.

Simple Shell is an end-of-term collaborative project conducted by Juan Manuel Ramirez Saa and Carolina Hernandez Viveros for Holberton School Cali.

## **Respository / Simple shell files and description:bookmark_tabs:**

> - header.h\. Header file that contains all the functions and standard C libraries.
>
> - main.c\. Contains the int main(void) function and a function that become a string in pointers array separated by limit variable: get pointer array.
>
> - exec.c\. Contains the functions that handle the environment, path/file verification, and child process functions: getevn, status exec, new process.
>
> - strings.c\. Contains all helper functions to manipulate strings or characters: _strlen, strcmp, strcat, strncpy,_pathcat
	  
	  
## **How to Install:computer:**

Clone the repo below

`https://github.com/Juan8bits/simple_shell.git` 

## **How to Compile:desktop_computer:**

`gcc -Wall -Werror -Wextra -pedantic *.c header.h -o hsh`

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

### **Interactive Mode**

In interactive mode, simply run the program and wait for the prompt to appear. From there, type commands freely, exiting with either the "exit" command or ctrl-D.

### **Non-Interactive Mode**

In non-interactive mode, echo desired command and pipe it into the program as following:
echo "ls" | ./hsh
In non-interactive mode, the program will exit after finishing desired command(s).

## **Example Output Interactive Mode**
```Git Bash
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ gcc *.c header.h -o hsh
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ ./hsh
#cisfun$ pwd
/home/vagrant/Holberton/simple_shell
#cisfun$ /bin/pwd
/home/vagrant/Holberton/simple_shell
#cisfun$ ls -la
total 52
drwxrwxr-x  3 vagrant vagrant  4096 Nov 24 00:31 .
drwxrwxr-x 12 vagrant vagrant  4096 Nov 23 15:45 ..
-rw-rw-r--  1 vagrant vagrant   181 Nov 23 15:45 AUTHORS
-rw-rw-r--  1 vagrant vagrant  1832 Nov 23 20:22 exec.c
drwxrwxr-x  8 vagrant vagrant  4096 Nov 23 20:22 .git
-rw-rw-r--  1 vagrant vagrant   685 Nov 23 15:45 header.h
-rwxrwxr-x  1 vagrant vagrant 13800 Nov 24 00:31 hsh
-rw-rw-r--  1 vagrant vagrant  1476 Nov 23 20:47 main.c
-rw-rw-r--  1 vagrant vagrant   136 Nov 23 23:54 README.md
-rw-rw-r--  1 vagrant vagrant  1809 Nov 23 15:45 strings.c
#cisfun$ /bin/ls -l -a
total 52
drwxrwxr-x  3 vagrant vagrant  4096 Nov 24 00:31 .
drwxrwxr-x 12 vagrant vagrant  4096 Nov 23 15:45 ..
-rw-rw-r--  1 vagrant vagrant   181 Nov 23 15:45 AUTHORS
-rw-rw-r--  1 vagrant vagrant  1832 Nov 23 20:22 exec.c
drwxrwxr-x  8 vagrant vagrant  4096 Nov 23 20:22 .git
-rw-rw-r--  1 vagrant vagrant   685 Nov 23 15:45 header.h
-rwxrwxr-x  1 vagrant vagrant 13800 Nov 24 00:31 hsh
-rw-rw-r--  1 vagrant vagrant  1476 Nov 23 20:47 main.c
-rw-rw-r--  1 vagrant vagrant   136 Nov 23 23:54 README.md
-rw-rw-r--  1 vagrant vagrant  1809 Nov 23 15:45 strings.c
```

## **Example Output Non-Interactive Mode**
```
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ gcc *.c header.h -o hsh
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ echo pwd | ./hsh
/home/vagrant/Holberton/simple_shell
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ echo ls -la | ./hsh
total 52
drwxrwxr-x  3 vagrant vagrant  4096 Nov 24 00:36 .
drwxrwxr-x 12 vagrant vagrant  4096 Nov 23 15:45 ..
-rw-rw-r--  1 vagrant vagrant   181 Nov 23 15:45 AUTHORS
-rw-rw-r--  1 vagrant vagrant  1832 Nov 23 20:22 exec.c
drwxrwxr-x  8 vagrant vagrant  4096 Nov 23 20:22 .git
-rw-rw-r--  1 vagrant vagrant   685 Nov 23 15:45 header.h
-rwxrwxr-x  1 vagrant vagrant 13800 Nov 24 00:36 hsh
-rw-rw-r--  1 vagrant vagrant  1476 Nov 23 20:47 main.c
-rw-rw-r--  1 vagrant vagrant   136 Nov 23 23:54 README.md
-rw-rw-r--  1 vagrant vagrant  1809 Nov 23 15:45 strings.c
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ echo /bin/pwd | ./hsh
/home/vagrant/Holberton/simple_shell
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ echo /bin/ls | ./hsh
AUTHORS  exec.c  header.h  hsh  main.c  README.md  strings.c
vagrant@vagrant-ubuntu-trusty-64:~/Holberton/simple_shell$ echo cat AUTHORS | ./hsh
# This file lists all individuals having contributed content to the repository.

Carolina Hernandez Viveros <carolina.hv02@gmail.com>
Juan Manuel Ramírez Saa <Juan160820@gmail.com>
```
## Flow Chart Shell

![](https://i.ibb.co/4KnrWfq/Flowchart-Shell.jpg)


## **Resource:card_index:**

Simple Shell was built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

:open_book: [Blog about command ls -l](https://2418.medium.com/inside-shell-a-little-journey-through-the-ls-l-command-863370f06e21)

## **Authors:writing_hand:** 

**Juan Manuel Ramirez Saa:man_technologist:** - [*Juan8bits*](https://github.com/Juan8bits)\
**Carolina Hernandez Viveros:woman_technologist:** - [*CarolinaHV*](https://github.com/CarolinaHV)

[ ](https://img.shields.io/github/status/s/pulls/Juan8bits/simple_shell/1111)
