#pragma once
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <array>


	class myDatabase
	{
	private:
		const char* db_directory;
		sqlite3* db;
		static const int table_numbers = 15;
		static const int table_fields_number = 10;
		std::string table_names[table_numbers];
		std::string field_names[table_numbers][table_fields_number];

	public:
		myDatabase(const char* dir);
		bool name_tables();
		bool name_fields();
		bool create_open_db();
		bool create_table();
		bool get_data_from_table();
		bool add_data_to_table();
		//char* sub_convert_str_to_char(std::string sentence);
		bool close_db();
		~myDatabase();
	};