## Not much is commited, a little bit is on another VCS
# The Stage0 Compiler

We are using Xmake for this. Why? Because I love xmake.
How to run it? Use `xmake` to generate it and then run `xmake run` to run it.
You need to install [xmake](https://xmake.io)

### Runtime speed is useless right now

Prototyping speed is the only important thing. The stage0 compiler will never be used after I finish it. This is why I do not intend to spend much time on this process. Do not worry. I just want to get something up and running.

### Where is the stage0 compiler?
/stage0

### What is a stage0 compiler?

The bootstrapping process has the following stages:
- Stage 0: preparing an environment for the bootstrap compiler to work with. **<- We are here**
- Stage 1: the bootstrap compiler is produced.
- Stage 2: a full compiler is produced by the bootstrap compiler.
- Stage 3: a full compiler is produced by the stage 2 full compiler.

