#pragma once
#include "struct.h"
// #include "func_2.cpp"

void up_size_massiw(reference*& massiw, int& first_size);

void view_content(reference* massiw_BD, int number_of_buses);

void delete_zero_cell(reference*& massiw, int couter);

void scan_tabl_element(reference* massiw_BD, int number_of_buses);

void changing_values(reference* massiw_BD, int number_of_buses);

void my_selection_sort(reference* massiw_BD, int number_of_buses);

void write_in_file(reference* massiw_BD, int number_of_buses);

void write_massiw(reference* massiw_BD, int number_of_buses, int start);
