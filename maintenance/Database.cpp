#include "Database.h"

myDatabase::myDatabase(const char* dir)
{
	this->db_directory = dir;
	if (!myDatabase::name_tables())
	{
		std::cout << "ERROR - class myDatabase// consturctor// name tables function failure";
	}
	if (!myDatabase::name_fields())
	{
		std::cout << "ERROR - class myDatabase// consturctor// name table fields function failure";
	}
	if (!myDatabase::create_open_db())
	{
		std::cout << "ERROR - class myDatabase// consturctor// create open database function failure";
	}
	if (!myDatabase::create_table())
	{
		std::cout << "ERROR - class myDatabase// consturctor// create tables function failure";
	}
}

bool myDatabase::name_tables()
{
	table_names[0] = "COMPANY_NAMES";
	table_names[1] = "FIELD_SITES_NAMES";
	table_names[2] = "FIELD_SITES";
	table_names[3] = "FSR";
	table_names[4] = "FSR_SALARY";
	table_names[5] = "EQIOPMENT";
	table_names[6] = "PARTS";
	table_names[7] = "TASKS";
	table_names[8] = "HOLYDAYS";
	table_names[9] = "WOs";

	return true;
}

bool myDatabase::name_fields()
{
	field_names[0][0] = "ID INT PRIMARY KEY NOT NULL";
	field_names[0][1] = "COMPANY_NAME_ENG TEXT NOT NULL";
	field_names[0][2] = "COMPANY_NAME_LOC TEXT NOT NULL";

	field_names[1][0] = "ID INT PRIMARY KEY NOT NULL";
	field_names[1][1] = "FIELD_SITE_NAME_ENG TEXT NOT NULL";
	field_names[1][2] = "FIELD_SITE_NAME_LOC TEXT NOT NULL";

	field_names[2][0] = "ID INT PRIMARY KEY NOT NULL";
	field_names[2][1] = "ID_FIELD_SITE_NAME INT NOT NULL";
	field_names[2][2] = "ID_COMPANY_NAME INT NOT NULL";
	field_names[2][3] = "HARD_SHIP INT NOT NULL";
	field_names[2][4] = "ARHIVE INT";
	field_names[2][5] = "MODIFICATION_DATE TEXT NOT NULL";

	field_names[3][0] = "ID INT PRIMARY KEY NOT NULL";
	field_names[3][1] = "FSR_NAME TEXT NOT NULL";
	field_names[3][2] = "FSR_NUMBER TEXT NOT NULL";
	
	field_names[4][0] = "ID INT PRIMARY KEY NOT NULL";
	field_names[4][1] = "ID_FSR INT NOT NULL";
	field_names[4][2] = "FSR_BASE_SALARY REAL NOT NULL";
	field_names[4][3] = "MODIFICATION_DATE TEXT NOT NULL";

	field_names[5][0] = "ID INT PRIMARY KEY NOT NULL";

	field_names[6][0] = "ID INT PRIMARY KEY NOT NULL";

	field_names[7][0] = "ID INT PRIMARY KEY NOT NULL";

	field_names[8][0] = "ID INT PRIMARY KEY NOT NULL";

	field_names[9][0] = "ID INT PRIMARY KEY NOT NULL";

	return true;
}

bool myDatabase::create_open_db()
{
	(sqlite3_open(db_directory, &db)) ? (true) : (false);
	return true;
}

bool myDatabase::create_table()
{
	std::string sql_statement;
	char* sql_statement_char;

	for (int i = 0; i < table_numbers; i++)
	{
		
		if (!table_names[i].empty())
		{
			sql_statement = "CREATE TABLE " + table_names[i] + char(40);
			
			for (int j = 0; j < table_fields_number; j++)
			{
				if (!field_names[i][j].empty())
				{
					sql_statement = sql_statement + field_names[i][j] + char(44);
				}
			}
			sql_statement.pop_back();
			sql_statement = sql_statement + char(41) + char(59);
			sql_statement_char = &sql_statement[0];
			if (sqlite3_exec(db, sql_statement_char, NULL, NULL, NULL)!=SQLITE_OK)
			{
				std::cout << "ERROR - class myDatabase// create tables in database function failure";
			}
		}
		sql_statement="";
	}
	
	return true;
}

bool myDatabase::close_db()
{
	sqlite3_close(db);
	return true;
}

myDatabase::~myDatabase()
{
	myDatabase::close_db();
	delete[] db_directory;
	delete[] field_names;
	delete[] table_names;
}