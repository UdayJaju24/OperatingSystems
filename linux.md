### Instructions
- Open Linux Kernel(Terminal) using Linux/Ubuntu OS
- Copy and paste the commands at obtain the output
- Ensure correct file names & if not create as per requirements
-  Note:- Home directory is /Users/Student if not, edit the command to modify it as per your home directory path

 ##
1. Change your password to a password you would like to use
  ```
passwd
  ```
Note-: Type old password, enter,  New password,enter, Retype new password and **no** cursor or **NO** star symbol will appear as you type but it will get changed. Ensure to note it down, as once changed and forgotten the machine would be locked.

2. Display the system’s date.
  ```
date
  ```

3.Count the number of lines in the /etc/passwd file.
  ```
wc -l/etc/passwd
  ```

4. Find out who else is on the system.
  ```
who
  ```

5. Direct the output of the man pages for the date command to a file named
mydate.
  ```
man date > mydate
  ```

6. Create a subdirectory called mydir.
  ```
mkdir mydir
  ```
 ```
cd mydir
 ```

7. Move the file mydate into the new subdirectory.
  ```
mv mydate /Users/student/mydir
  ```

8. Go to the subdirectory mydir and copy the file mydate to a new file called
ourdate.
  ```
mydir % cp mydate ourdate
  ```

9. List the contents of mydir
  ```
ls mydir
  ```

10. Do a long listing on the file ourdate and note the permissions.
  ```
ls ourdate
  ```

11. Display the name of the current directory starting from the root.
  ```
pwd 
  ```

12. Move the files in the directory mydir back to the HOME directory.
  ```
mv mydir /Users/student
  ```

13. List all the files in your HOME directory.
  ```
ls /Users/student
  ```

14. Display the first 5 lines of mydate.
  ```
head -5 mydate
  ```

15. Display the last 8 lines of mydate.
  ```
tail -8 mydate
  ```

16. Remove the directory mydir.
  ```
rmdir mydir
  ```
