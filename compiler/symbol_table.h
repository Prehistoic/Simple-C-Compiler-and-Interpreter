#ifndef SYMBOL_TABLES_H
#define SYMBOL_TABLES_H

struct symbol
{
  char id[256];
  int depth;
  int constant;
  int initialized;
  int function_id;
};

int push_symbol(const char *id, int depth, int constant, int func_id);

void pop_symbol();

int find_symbol(const char *id, int depth, int func_id);

int get_last_symbol();

void set_initialized(const char *id, int depth, int func_id);

int get_initialized(const char *id, int depth, int func_id);

int get_const(const char *id, int depth, int func_id);

int get_func_id(const char *id);

void display_table();

#endif
