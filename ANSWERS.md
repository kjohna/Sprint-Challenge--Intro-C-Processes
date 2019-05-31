**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Running - process is being executed by the cpu
Waiting - process is on "hold" ready to execute but waiting on other processes to finish to get time on the CPU
Blocked - process is on "hold" until a change in input or state

**2. What is a zombie process?**

A child process which has been abandoned by its parent process, likely because the parent process completed before the child then exited.

**3. How does a zombie process get created? How does one get destroyed?**

When a program forks itself the child process gets allocated resources and assigned an entry in the process table. It is the responsibility of the parent process to clean up after the child is finished. The parent process must wait for any child processes to complete then free resources and clear their processes from the process table before quitting.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled programs have been converted into machine code and optimized by the compiler before running so they typically perform better than interpreted languages.
