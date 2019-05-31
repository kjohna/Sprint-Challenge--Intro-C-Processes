**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

running - process is being executed by the cpu
sleeping - process is on "hold" until another process finishes

**2. What is a zombie process?**

a child process which has been abandoned by its parent process.

**3. How does a zombie process get created? How does one get destroyed?**

when a program forks itself the child process gets allocated resources which are the responsibility of the parent process to clean up afte the child is finished.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

compiled programs have been converted into machine code and optimized by the compiler before even running so they are typically more performant than interpreted languages.
