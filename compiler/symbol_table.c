#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct table
{
    int size;
    struct symbol symbols[500];
};

struct table symbol_table = {0};

int push_symbol(const char *id, int depth, int constant, int func_id)
{
    struct symbol *new = &(symbol_table.symbols[symbol_table.size]);
    strcpy(new->id, id);
    new->initialized = 0;
    new->depth = depth;
    new->constant = constant;
    new->function_id = func_id;
    symbol_table.size++;
    return symbol_table.size - 1;
}

void pop_symbol()
{
    symbol_table.size--;
}

int find_symbol(const char *id, int depth, int func_id)
{
    for (int i = 0; i < symbol_table.size; i++)
    {
        struct symbol *current = &(symbol_table.symbols[i]);
        if (current->depth <= depth && current->function_id == func_id)
            if (!strcmp(current->id, id))
                return i;
    }
    return -1;
}

int get_last_symbol()
{
    return symbol_table.size - 1;
}

void set_initialized(const char *id, int depth, int func_id)
{
    int adr = find_symbol(id, depth, func_id);
    symbol_table.symbols[adr].initialized = 1;
}

int get_initialized(const char *id, int depth, int func_id)
{
    int adr = find_symbol(id, depth, func_id);
    return symbol_table.symbols[adr].initialized;
}

int get_const(const char *id, int depth, int func_id)
{
    int adr = find_symbol(id, depth, func_id);
    return symbol_table.symbols[adr].constant;
}

void display_table()
{
    printf("Symbol table :\n");
    for (int i = 0; i < symbol_table.size; i++)
    {
        struct symbol *current = &(symbol_table.symbols[i]);
        int depth = current->depth;
        printf("index=%d\t", i);
        printf("id=%s\tconst=%d\tinit=%d\tdepth=%d\tfunc_id=%d\n",
          current->id, current->constant,
          current->initialized, current->depth,
          current->function_id);
    }
    printf("\n");
}
