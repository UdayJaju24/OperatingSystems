### Instructions
* Open Linux Kernel(Terminal) using Linux/Ubuntu OS
* Copy and paste the commands at obtain the output
* Ensure correct file names & if not create as per requirements
 #  

- Redirect the output of ls command to a file named outfile. Use this as an input file for remaining commands.
  ```
  ls > outfile
  ```
  
- To select the lines in a file which has digit as one of the character in that line and redirect the output to the file named list.
  ```
  grep '[0-9]' outfile > list
  ```
  
- Assign execute permission to owner and remove read permission from other for an ordinary file named test by relative way
  ```
  chmod u+x,go-r test
  ```
  
- Create an alias named rm that always deletes file interactively.
  ```
  alias rm='rm -i'
  ```
  
- Count the currently login users to the system.
 ```
who | wc -l
 ```

- Redirect the output of cat command to a file named outfile. Use this as an input file for remaining commands.
  ```
  cat inputfile > outfile
  ```
  
- List all hidden files under current directory and store in “hidden” file
  ```
  ls -a | grep "^\." > hidden
  ```
  
- Assign write permission to owner and remove execute permission from other for an ordinary file named test by absolute way.
  ```
  chmod u+w,go-x /path/to/test
  ```
  
  
- To extract 1st and 10th character of a given file
  ```
   cut -c 1,10 inputfile
  ```
  
- To display how many times lines are repeated in a given file
  ```
  sort inputfile | uniq -c
  ```

- To redirect the output of cp command to a file named outfile. Use this as an input file for remaining commands.
  ```
  cp source_file destination_file > outfile
  ```
  
- To select the lines in a file which has 4 letter words in that line and redirect the output to the file named list.
  ```
  grep -o '\b\w\{4\}\b' outfile > list
  ```
  
- Assign write permission to owner and remove read permission from group user for an ordinary file named test by relative way.
  ```
  chmod u+w,g-r test
  ```
  
- Create an alias named ls that always lists all the files including hidden files.
  ```
  alias ls='ls -a'
  ```
- Count the number of words in the list file
  ```
  wc -w list
  ```

- Redirect the output of mv command to a file named outfile. Use this as an input file for remaining commands.
  ```
  mv source_file destination_file > outfile
  ```
  
- List all hidden files under current directory and store in “hidden” file
  ```
  ls -a > hidden
  ```
  
- Assign write permission to group user and remove execute permission from owner for an ordinary file named test by absolute way
  ```
  chmod 260 test
  ```
  
- To create soft and hard link for given file
  ```
  ln -s source_file soft_link
  ```
  ```
  ln source_file hard_link
  ```
  
- To convert lowercase to upper case of a given file
  ```
  tr '[:lower:]' '[:upper:]' < input_file > output_file
  ```
  
- To extract 2nd and 3rd character of a given file
  ```
  cut -c 2-3 input_file > output_file
  ```
  
- To display how many times lines are repeated in a given file
  ```
  sort input_file | uniq -c > output_file
  ```
