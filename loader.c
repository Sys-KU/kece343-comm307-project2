/***************************************************************/
/*                                                             */
/*   RISC-V (RV32I) Instruction Level Simulator                */
/*                                                             */
/*   KECE343/COMM307 Korea University                          */
/*   loader.c                                                  */
/*                                                             */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "loader.h"
#include "mem.h"
#include "util.h"


void load_inst_to_mem(const char *buffer, const int index)
{
    int word;

    word = str_to_int(buffer);
    mem_write_32(MEM_TEXT_START + index, word);
}

void load_data_to_mem(const char *buffer, const int index)
{
    uint32_t word;
    word = str_to_int(buffer);
    mem_write_32(MEM_DATA_START + index, word);
}

/**************************************************************/
/*                                                            */
/* TODO: Load program and service routines into mem.          */
/*                                                            */
/**************************************************************/
void load_program(char *program_filename) {                   
    FILE *prog;
    int i = 0;
    char buffer[32 + 2];

    //to notifying data & text segment size
    int text_size = 0;
    int data_size = 0;

    /* Open program file. */
    prog = fopen(program_filename, "r");
    if (prog == NULL) {
        printf("Error: Can't open program file %s\n", program_filename);
        exit(EXIT_FAILURE);
    }

    /* Read in the program. */
    // 1st: read the size of text section
    if (fgets(buffer, 32 + 2, prog) != NULL) {
        //check text segment size
        text_size = str_to_int(buffer);
        g_processor.input_insts = text_size/4;

    } else {
        printf("Error occured while loading %s\n", program_filename);
        exit(EXIT_FAILURE);
    }

    // 2nd: read the size of data section
    // TODO

    // 3rd: load the text and data binary to memory
    // TODO
    
    fclose(prog);

    g_processor.pc = MEM_TEXT_START;
    g_processor.running = TRUE;
}
