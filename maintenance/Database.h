#pragma once
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

namespace myDB {
	class myDatabase
	{
	private:
		const char* dir;
		sqlite3* DB;
	public:
		myDatabase(const char* dir);
		int create_DB();
		int create_tables();
	};
}