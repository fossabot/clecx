## Not much is commited, a little bit is on another VCS
# The Stage0 Compiler

### Why Python, the slowest language, a language that should never be used for interpreters?

Prototyping speed. The stage0 compiler will never be used after I finish it. This is why I do not intend to spend much time on this process. Do not worry. I just want to get something up and running.

### Where is the stage0 compiler?
/stage0

### What is a stage0 compiler?

The bootstrapping process has the following stages:
- Stage 0: preparing an environment for the bootstrap compiler to work with. **<- We are here**
- Stage 1: the bootstrap compiler is produced.
- Stage 2: a full compiler is produced by the bootstrap compiler.
- Stage 3: a full compiler is produced by the stage 2 full compiler.

