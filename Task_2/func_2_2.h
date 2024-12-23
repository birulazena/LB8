#pragma once
#include "struct.h"

void delete_zero_cell(trains*& massiw, int couter);

void up_size_massiw(trains*& massiw, int& first_size);

void write_massiw(trains* massiw_BD, int number_of_trains, int start);

void delete_field(trains*& massiw_BD, int& number_of_trains);

void view_content(trains* massiw_BD, int number_of_buses);

void changing_values(trains* massiw_BD, int number_of_trains);

void write_in_file(trains* massiw_BD, int number_of_trains);
