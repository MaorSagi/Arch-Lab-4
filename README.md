# Arch-Lab-4
System Calls

Task 1

program:
patch FILE_NAME X_NAME

Changes the file FILE_NAME, so that it would print X_NAME instead of Shira's name.

Task 2a: restricted search

 list the relative path from the current directory of all the files in the working directory.

#>./search
.
./DIR2
./DIR2/D2_DIR3
./DIR2/D2_DIR3/Dolphine
./DIR2/D2_DIR3/Ostritch
./DIR2/D2_DIR3/Pigeon
./DIR2/D2_DIR3/Cat
./DIR2/Dolphine
./DIR2/Pigeon
./DIR2/Cat
./DIR2/D2_DIR1
./DIR2/D2_DIR1/Dolphine
./DIR2/D2_DIR1/Tiger
./DIR2/D2_DIR1/Lizard
./DIR2/Dog
./DIR2/D2_DIR2
./DIR2/D2_DIR2/Monkey
./DIR2/D2_DIR2/D2_D2_DIR1
./DIR2/D2_DIR2/D2_D2_DIR1/D2_D2_D1_DIR1
./DIR2/D2_DIR2/D2_D2_DIR1/D2_D2_D1_DIR1/Tiger
.......................................

Task 2b: search specific files

find . -name "filename"

#>./search -n Lion
./DIR2/D2_DIR2/D2_D2_DIR1/D2_D2_D1_DIR2/D2_D2_D1_D2_DIR1/Lion
./DIR4/D4_DIR1/Lion
./DIR4/D4_DIR2/Lion
./DIR4/D4_DIR3/Lion
./DIR3/Lion
./DIR1/D1_DIR2/D1_D2_DIR1/Lion
    
Task 2c: Extending Search: Execute commands on files

Add the option -e <name> <command>

user@ubuntu:~/Desktop/WorkingDirectory$ ./search -e TxtFile cat
Hello everyone!
It's me.
I would like to see you. 
user@ubuntu:~/Desktop/WorkingDirectory$ ./search -e NotExistingFile cat
The file 'NotExistingFile' Does not exist. 
    

    
