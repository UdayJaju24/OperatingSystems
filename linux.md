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


7. Move the file mydate into the new subdirectory.
  ```
mv mydate /Users/student/mydir
  ```

8. Go to the subdirectory mydir and copy the file mydate to a new file called
ourdate.
 ```
cd /Users/student/mydir
 ```
  ```
cp mydate ourdate
  ```

9. List the contents of mydir
  ```
ls mydir
  ```

10. Do a long listing on the file ourdate and note the permissions.
  ```
ls -l ourdate
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

17. Redirect the output of the long listing of files to a file named list.
 ```
ls -l > list
 ```

18. Select any 5 capitals of states in India and enter them in a file named capitals1. Choose 5 more capitals and enter them in a file named capitals2. Choose 5 more capitals and enter them in a file named capitals3. Concatenate all 3 files and redirect the output to a file named capitals.
    
 ```
echo "Jammu, Lucknow, Kolkatta, Shimla, Dehradun" > capitals1.txt
 ```

 ```
echo "Dispur, Aizwal, Shillong, Imphal, Bhubaneshwar" > capitals2.txt
 ```

 ```
echo "Kohima,  Ranchi, GandhiNagar, Bhopal, Raipur" > capitals3.txt
 ```

 ```
cat capitals1.txt capitals2.txt capitals3.txt > capitals.txt
 ```

19. Concatenate the file capitals2 at the end of file capitals
 ```
 cat capitals2.txt > capitals.txt
 ```

20. Give read and write permissions to all users for the file capitals.
 ```
chmod 755 capitals.txt
 ```

21. Give read permissions only to the owner of the file capitals. Open the file, make some changes and try to save it.
 ```
chmod u+r capitals.txt
 ```

```
ls -l capitals
 ```

```
cat > capitals
hello world
 ```

```
cat  capitals 
 ```

22. Create an alias to concatenate the 3 files capitals1, capitals2, capitals3 and redirect the output to a file named capitals. Activate the alias and make it run.
 ```
alias concat='cat capitals1.txt capitals2.txt capitals3.txt > capitals.txt'
 ```

 ```
concat
 ```

 ```
cat capitals.txt
 ```

23. Find out the number of times the string “the” appears in the file mydate.
 ```
grep -o "the" mydate | wc -l
 ```

24. Find out the line numbers on which the string “date” exists in mydate.
 ```
grep -n "date" mydate 
 ```

25. Print all lines of mydate except those that have the letter “i” in them.
 ```
grep -v i mydate 
 ```

26. List the words of 4 letters from the file mydate.
 ```
grep -o -w "\w\{4\}" mydate 
 ```

27. List 5 states in north east India in a file mystates. List their corresponding capitals in a file mycapitals. Use the paste command to join the 2 files.
 ```
touch mystates
 ```

 ```
cat > mystates
Maharashtra
Karnatka
Goa
Telangana
Tamil Nadu
 ```

 ```
touch mycapitals
 ```

 ```
cat > mycapitals
Mumbai
Bengaluru
Panaji
Hyderabad
Chennai
 ```

  ```
paste mystates mycapitals
 ```

28. Use the cut command to print the 1 st and 3 rd columns of the /etc/passwd file for all students in this class.
 ```
cut -f 1,3 /etc/passwd
 ```

29. Count the number of people logged in and also trap the users in a file using the tee command.
 ```
users | wc - w
 ```

```
w | tee users
```

30. Convert the contents of mystates into uppercase.
 ```
tr a-z A-Z < ./mystates
 ```

31. Create any two files & display the common values between them.
 ```
cat>file1
1
2
3
4
5
 ```

```
cat>file2
2
4
6
8
10
 ```

```
comm -1 < (sort file1) < (sort file2)
 ```
