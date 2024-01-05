## Task2 - Question 2
### Requirements
> Move the binary file outpur to the directory /usr/local/bin with sudo permissions.
Afterward, attempt to execute the binary from any working directory and explain the outcome. Provide a detailed explanation supported by evidence as to why the binary can be executed from any location.

### Results
![image](https://github.com/AalaaIbrahim/Embedded-Linux/assets/118854389/3eedf6a9-e234-4c04-b661-535261685915)


### Conclusion
Normally, a binary executable can only be executed inside its local directory. However, if the binary executable is inside a directory whose path is part of the PATH variable (like /usr/local/bin), then it can be executed anywhere in the system.
