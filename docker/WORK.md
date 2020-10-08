
---
# Gdb

When playing with gdb, there is a disturbing warning, to be understood :

```
warning: Error disabling address space randomization: Operation not permitted
warning: File "/usr/local/lib64/libstdc++.so.6.0.28-gdb.py" auto-loading has been declined by your `auto-load safe-path' set to "$debugdir:$datadir/auto-load".
To enable execution of this file add
        add-auto-load-safe-path /usr/local/lib64/libstdc++.so.6.0.28-gdb.py
line to your configuration file "/root/.gdbinit".
To completely disable this security protection add
        set auto-load safe-path /
line to your configuration file "/root/.gdbinit".
For more information about this security protection see the
"Auto-loading safe path" section in the GDB manual.  E.g., run from the shell:
        info "(gdb)Auto-loading safe path"
```


---
# Marrying C++ and Python

Should we install something for the C++/Python connection ?

Also, the python example mandel.py (and perhaps others) needs an X11 display... and:
* pylab
* ...

Grosse galère avec "functools_lru_cache"...