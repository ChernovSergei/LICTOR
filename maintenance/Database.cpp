#include "Database.h"

//Create database/ tables/ fields
myDatabase::myDatabase(const char* dir)
{
	this->db_directory = dir;
	
	if (!myDatabase::name_tables())
	{
		//Error message
	}
	if (!myDatabase::name_fields())
	{
		//Error message
	}
	if (!myDatabase::define_fields())
	{
		//Error message
	}

	if (!myDatabase::create_open_db())
	{
		//Error message
	}
	if (!myDatabase::create_table())
	{
		//Error message
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
	field_names[0][0] = "id";
	field_names[0][1] = "company_name_eng";
	field_names[0][2] = "company_name_loc";

	field_names[1][0] = "id";
	field_names[1][1] = "field_site_name_eng";
	field_names[1][2] = "field_site_name_loc";

	field_names[2][0] = "id";
	field_names[2][1] = "id_field_site_name";
	field_names[2][2] = "id_company_name";
	field_names[2][3] = "hard_ship";
	field_names[2][4] = "archive";
	field_names[2][5] = "modification_date";

	field_names[3][0] = "id";
	field_names[3][1] = "fsr_name_eng";
	field_names[3][2] = "fsr_name_loc";
	field_names[3][3] = "fsr_credentials";
	
	field_names[4][0] = "id";
	field_names[4][1] = "id_fsr_name";
	field_names[4][2] = "fsr_base_salary";
	field_names[4][3] = "modification_date";

	field_names[5][0] = "id";

	field_names[6][0] = "id";

	field_names[7][0] = "id";

	field_names[8][0] = "id";

	field_names[9][0] = "id";

	return true;
}

bool myDatabase::define_fields()
{
	field_types[0][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	field_types[0][1] = " TEXT NOT NULL";
	field_types[0][2] = " TEXT";

	field_types[1][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	field_types[1][1] = " TEXT NOT NULL";
	field_types[1][2] = " TEXT NOT NULL";

	field_types[2][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	field_types[2][1] = " INT NOT NULL";
	field_types[2][2] = " INT NOT NULL";
	field_types[2][3] = " INT NOT NULL";
	field_types[2][4] = " INT";
	field_types[2][5] = " TEXT NOT NULL";

	field_types[3][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	field_types[3][1] = " TEXT NOT NULL";
	field_types[3][2] = " TEXT NOT NULL";

	field_types[4][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	field_types[4][1] = " INT NOT NULL";
	field_types[4][2] = " REAL NOT NULL";
	field_types[4][3] = " TEXT NOT NULL";

	field_types[5][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[6][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[7][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[8][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[9][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	
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
			
			for (int j = 0; j < table_field_numbers; j++)
			{
				if (!field_names[i][j].empty())
				{
					sql_statement = sql_statement + field_names[i][j] + field_types[i][j] + char(44);
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

//Insert data into database
bool myDatabase::add_data_to_table(int i, const char* values)
{
	std::string sql_statement;
	char* sql_statement_char;

	if (!table_names[i].empty())
	{
		sql_statement = "INSERT INTO " + table_names[i] + char(40);

		for (int j = 1; j < table_field_numbers; j++)
		{
			if (!field_names[i][j].empty())
			{
				sql_statement = sql_statement + field_names[i][j] + char(44);
			}
		}
		sql_statement.pop_back();
		sql_statement = sql_statement + char(41) + " VALUES ";
		sql_statement = sql_statement + char(40) + values + char(41) + char(59);
		sql_statement_char = &sql_statement[0];
		if (sqlite3_exec(db, sql_statement_char, NULL, NULL, NULL) != SQLITE_OK)
		{
			std::cout << "ERROR - class myDatabase// create tables in database function failure";
		}
	}
	return true;
}

//Extract data from database
bool myDatabase::extract_column_from_table(const char* table_name, int table_column,const unsigned char* result[])
{
	sqlite3_stmt* stmt;
	int index = 1;
	char statement[999];
	bool done =false;

	statement[sizeof(statement) - 1] = '\n';

	snprintf(
		statement,
		sizeof(statement) - 1,
		"SELECT * FROM %s",
		table_name
		);
	sqlite3_prepare(db, statement, sizeof(statement), &stmt, NULL);

	while (!done)
	{
		switch (sqlite3_step(stmt))
		{
		case SQLITE_ROW:
			result[index] = sqlite3_column_text(stmt, table_column);
			index++;
			break;
		case SQLITE_DONE:
			done = true;
			break;
		default:
			return 1;
		}
	}

	sqlite3_finalize(stmt);
	stmt = NULL;

	return true;
}

bool myDatabase::extract_from_column(const char* table_name, int table_column, const char* condition, const char* result)
{
	sqlite3_stmt* stmt;
	int index = 1;
	char statement[999];
	bool done = false;

	statement[sizeof(statement) - 1] = '\n';

	snprintf(
		statement,
		sizeof(statement) - 1,
		"SELECT * FROM %s WHERE %s",
		table_name,
		condition
	);
	sqlite3_prepare(db, statement, sizeof(statement), &stmt, NULL);

	while (!done)
	{
		switch (sqlite3_step(stmt))
		{
		case SQLITE_ROW:
			result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, table_column));
			index++;
			break;
		case SQLITE_DONE:
			done = true;
			break;
		default:
			return 1;
		}
	}

	sqlite3_finalize(stmt);
	stmt = NULL;

	return true;
}
//Edit database
bool myDatabase::update_data_in_table(int table_name, int table_column_condition, const char* condition, int table_column, const char* value)
{
	char statement[999];

	snprintf(
		statement,
		sizeof(statement) - 1,
		"UPDATE %s set %s = %s where %s = %s",
		table_names[table_name],
		field_names[table_column],
		value,
		field_names[table_name][table_column],
		condition
	);
	return true;
}

//Close database

bool myDatabase::close_db()
{
	sqlite3_close(db);
	return true;
}

myDatabase::~myDatabase()
{
	myDatabase::close_db();

	delete db;
	delete[] db_directory;
	delete[] field_names;
	delete[] field_types;
	delete[] table_names;
	
	db = NULL;
	db_directory = NULL;

}