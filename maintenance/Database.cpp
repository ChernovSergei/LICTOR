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

	names_tables[0] = "COMPANY_NAMES";
	names_tables[1] = "FIELD_SITES_NAMES";
	names_tables[2] = "FIELD_SITES";
	names_tables[3] = "FSR";
	names_tables[4] = "FSR_SALARY";
	names_tables[5] = "EQIOPMENT";
	names_tables[6] = "PARTS";
	names_tables[7] = "TASKS";
	names_tables[8] = "HOLYDAYS";
	names_tables[9] = "WOs";

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
	//
	names_fields[0][0] = "id";
	names_fields[0][1] = "company_name_eng";
	names_fields[0][2] = "company_name_loc";

	names_fields[1][0] = "id";
	names_fields[1][1] = "field_site_name_eng";
	names_fields[1][2] = "field_site_name_loc";

	names_fields[2][0] = "id";
	names_fields[2][1] = "id_field_site_name";
	names_fields[2][2] = "id_company_name";
	names_fields[2][3] = "hard_ship";
	names_fields[2][4] = "archive";
	names_fields[2][5] = "modification_date";

	names_fields[3][0] = "id";
	names_fields[3][1] = "fsr_name_eng";
	names_fields[3][2] = "fsr_name_loc";
	names_fields[3][3] = "fsr_credentials";

	names_fields[4][0] = "id";
	names_fields[4][1] = "id_fsr_name";
	names_fields[4][2] = "fsr_base_salary";
	names_fields[4][3] = "modification_date";

	names_fields[5][0] = "id";

	names_fields[6][0] = "id";

	names_fields[7][0] = "id";

	names_fields[8][0] = "id";

	names_fields[9][0] = "id";

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
	field_types[3][3] = " TEXT NOT NULL";

	field_types[4][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	field_types[4][1] = " INT NOT NULL";
	field_types[4][2] = " REAL NOT NULL";
	field_types[4][3] = " TEXT NOT NULL";

	field_types[5][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[6][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[7][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[8][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	field_types[9][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	//
	types_fields[0][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	types_fields[0][1] = " TEXT NOT NULL";
	types_fields[0][2] = " TEXT";

	types_fields[1][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	types_fields[1][1] = " TEXT NOT NULL";
	types_fields[1][2] = " TEXT NOT NULL";

	types_fields[2][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	types_fields[2][1] = " INT NOT NULL";
	types_fields[2][2] = " INT NOT NULL";
	types_fields[2][3] = " INT NOT NULL";
	types_fields[2][4] = " INT";
	types_fields[2][5] = " TEXT NOT NULL";

	types_fields[3][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	types_fields[3][1] = " TEXT NOT NULL";
	types_fields[3][2] = " TEXT NOT NULL";
	types_fields[3][3] = " TEXT NOT NULL";

	types_fields[4][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	types_fields[4][1] = " INT NOT NULL";
	types_fields[4][2] = " REAL NOT NULL";
	types_fields[4][3] = " TEXT NOT NULL";

	types_fields[5][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	types_fields[6][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	types_fields[7][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	types_fields[8][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";

	types_fields[9][0] = " INTEGER PRIMARY KEY AUTOINCREMENT";
	
	return true;
}

bool myDatabase::create_open_db()
{
	(sqlite3_open(db_directory, &db)) ? (true) : (false);
	return true;
}

bool myDatabase::create_table()
{
	char statement[999]{};
	
	for (int i = 0; i < table_numbers; i++)
	{
		memset(statement, 0, sizeof(statement));
		statement[sizeof(statement) - 1] = '\n';
		
		if (names_tables[i] !=NULL)
		{
			snprintf(
				statement,
				sizeof(statement) - 1,
				"CREATE TABLE %s (",
				names_tables[i]
			);

			for (int j = 0; j < table_field_numbers; j++)
			{
				
				if (names_fields[i][j]!=NULL)
				{
					if (j > 0)
					{
						strcat_s(statement, ",");
					}
					strcat_s(statement, names_fields[i][j]);
					strcat_s(statement, types_fields[i][j]);
					
				}
			}
			
			strcat_s(statement, ")");
			strcat_s(statement, ";");
			
			if (sqlite3_exec(db, statement, NULL, NULL, NULL) != SQLITE_OK)
			{
				std::cout << "ERROR - class myDatabase// create tables in database function failure";
			}
			
		}
	}
	
	return true;
}

//Insert data into database
bool myDatabase::add_data_to_table(int i, const char* values)
{
	char statement[999];
	char* sql_statement_char;

	if (!table_names[i].empty())
	{
		snprintf(
			statement,
			sizeof(statement)-1,
			"INSERT INTO %s (",
			table_names[i].c_str()
		);

		for (int j = 1; j < table_field_numbers; j++)
		{
			if (!field_names[i][j].empty())
			{
				//there is no popup method for chars and I am lazy to create it on my own.
				//if else statement had been written to avoid comma at the end of the statement
				if (j == 1)
				{
					snprintf
					(
						statement,
						sizeof(statement) - 1,
						"%s %s",
						statement,
						field_names[i][j].c_str()
					);
				}
				else
				{
					snprintf
					(
						statement,
						sizeof(statement) - 1,
						"%s ,%s",
						statement,
						field_names[i][j].c_str()
					);
				}
			}
		}

		snprintf
		(
			statement,
			sizeof(statement)-1,
			"%s) VALUES (%s);",
			statement,
			values
		);

		if (sqlite3_exec(db, statement, NULL, NULL, NULL) != SQLITE_OK)
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
	char statement[999];// = "UPDATE COMPANY_NAMES SET company_name_eng = 'LookOil' WHERE id = 2";
	statement[sizeof(statement) - 1] = '\n';
	

	snprintf(
		statement,
		sizeof(statement) - 1,
		"UPDATE %s SET %s = '%s' WHERE %s = %s",
		table_names[table_name].c_str(),
		field_names[table_name][table_column].c_str(),
		value,
		field_names[table_name][table_column_condition].c_str(),
		condition
	);
	sqlite3_exec(db, statement, NULL, NULL, NULL);
	
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

	/*delete db;
	delete[] db_directory;
	delete[] field_names;
	delete[] field_types;
	delete[] table_names;*/
	
	db = NULL;
	db_directory = NULL;

}