# Linux Admin 1 - Task 3
## Requirements
Write a Bash script that checks IF the .bashrc file exists in the user's home directory. If it does, append new environment variables to the file: one called `HELLO` with the value of HOSTNAME, and another local variable called `LOCAL` with the value of the whoami command. 
Additionally, the script should include a command to open another terminal at the end. Describe what happens when the terminal is opened.

---
## Results

![Running the script](https://github.com/AalaaIbrahim/Embedded-Linux/assets/118854389/d323d67b-afff-462f-9575-7b7fec981182)

*After running the script (`./script.sh`), since the .bashrc file does exist, two lines were appeneded to the file to define the given global and local environment variables. Additionally, a new terminal was opened.*

![image](https://github.com/AalaaIbrahim/Embedded-Linux/assets/118854389/df16756a-ab48-4ff7-9af1-e9207d98de8f)

*When the new terminal is opened, the modified .bashrc script is executed and we can view the new variables. However, we still cannot view them in the original terminal because the original terminal was initialized by the old .bashrc script before modification.*

