 # Project #2: Building a Simple RISC-V Simulator

 ### Goal
 This programming assignment is designed for an educational purpose. As we learned in the lectures, the objective
 of this assignment is to help students how a modern processor executes the program binary.

 ### Background of the skeleton code

 This repository provides the skeleton codes to simulate the RISC-V instructions. First, we recommend you to be familar with the code structure.
 The `proc.h` file defines the `struct RISC_V32_porc_t` to model the RISC-V processor and you can find the `struct inst_t` type how we represent the
 RISC-V instructions. To simulate the main memory for the RISC-V processor, we have the `mem.h` and `mem.c` files that support loading data and
 instructions to the simulated memory.

 Second, you may need to understand how the simulated RISC-V processor and memory are configured. The `main.c` file includes the entry
 point (main function) and initalize the system with the `void initialize(char *program_filename)` function. It loads the given  RISC-V binary file
 to the simulated memory and then invokes the `void run(int num_cycles)` function to simulate the RISC-V instructions.

 Last, in the `proc.c` file, we have the `void cycle()` function to execute a cycle. As we discussed in the lecture, it consists of three
 steps: fetch, decode, and execute.

 ### Task #1
 To simulate the given RISC-V binary, you need to load the binary into the simulated memory. In the `loader.c` file, there is an incomplete code 
 for loading the binary file. It reads the first line of the binary file to extract the text section size, but the remaining steps are not implmented.
 You should complete the `load_program()` function as indicated by `TODO`. 
  
 
 ### Task #2
 Once you successfully load the binary into the simulated memory, you can fetch an instruction from the simulated memory. We provide the implementation of `fetch()` function. It just reads a 32B data from the text memory. Then, you are supposed to implement the following two functions in the `proc.c` file.

     struct inst_t decode(int word)
     void execute(struct inst_t inst)
     
 * The `cycle()` function invokes `fetch()`, `decode()`, and `execute()` functions and then adjust the program counter and ticks of the
 `g_processor` object.
 
 * In the 'decode' function, you need to interpret a given 32 bit instruction as an argument and then compose a `struct inst_t` data type.

 * Once you decode an instruction, you can simulate the execution for the instruction. You may need to read data from the simulated memory
 or write data to the simulated memory. For some types of instructions, you should update the register values in the simulated processor
 (the `g_processor` object). For the jump instruction (jal), the program counter register should be updated.

 ## Hints

 * Always use the `mem_read_32()`, `mem_write32()` functions when trying to read or write from the `simulated memory`.
 This includes your implementation of the load/store functions.
 * You may generate input files of very simple instructions to check the functionality of your simulator. For example, `add x1, x1, 5`.
 Then you can check if the R1 of your simulator has been incremented by 5, etc..
 * To compare your results to the reference simulator of the TAs that will be used to grade your simulator, execute `make test`.
 * Check carefully where the `TODO`s are located. One or more `TODO`s in the skeleton are not mentioned above nor in the handout document. Even though they are not memtioned, you should implement or modify the given `TODO` sections.