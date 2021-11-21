#pragma once
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <array>
#include <locale.h>


	class myDatabase
	{
	private:
		const char* db_directory;
		sqlite3* db;
		static const int table_numbers = 15;
		static const int table_field_numbers = 15;
		std::string table_names[table_numbers];
		std::string field_names[table_numbers][table_field_numbers];
		std::string field_types[table_numbers][table_field_numbers];

	public:
		
		//Create database/ tables/ fields
		myDatabase(const char* dir);
		bool name_tables();
		bool name_fields();
		bool define_fields();
		bool create_open_db();
		bool create_table();

		//Insert data into database
		bool add_data_to_table(int, const char*);

		//Extract data from database
		bool extract_column_from_table(const char*, int ,const unsigned char*[]);
		bool extract_from_column(const char*, int, const char*, const char*);

		//Edit database
		bool update_data_in_table(int, int, const char*,int, const char*);

		//Close database
		bool close_db();
		~myDatabase();
	};