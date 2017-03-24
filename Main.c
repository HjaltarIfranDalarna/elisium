#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "sqlite3.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int callback(void *data, int argc, char **argv, char **azColName){
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char sql[255];
	int max_id = 6;

	rc = sqlite3_open("DATABASE.db", &db);
	const char* data = "Callback function called";

	if (rc)
	{
		fprintf(stderr, "Can't open database : %s\n", sqlite3_errmsg(db));
		return 0;
	}
	else
	{
		fprintf(stderr, "Opened databse successfully\n");
	}
	char veryGoodLanguageForDevelopment;
	int per = 0;
	while (true)
	{
		printf("Input your operation 1 - SELECT all fields 2 - INSERT 3 - Parameterized queries 4 - DELETE 5 - Photo\n");
		scanf("%d", &per);
		
		switch (per){
		case 1:
			strcpy(sql,"SELECT * from EMPLOYEES");
			break;
		case 2:
		{
				  char name[256], Surname[256], FathersName[256],
					  birth_date[256], birth_city[256], birth_country[256],
					  address[256], department[256], position[256], acceptance_date[256];
				  char c;
				  do {
					  c = getchar();
				  } while (c != EOF && c != '\n');
				  printf("name: ");
				  fgets(name,255,stdin);
				  name[255] = strtok(name, "\n");
				  printf("FathersName: ");
				  fgets(FathersName, 255, stdin);
				  FathersName[255] = strtok(FathersName, "\n");
				  printf("Surname: ");
				  fgets(Surname, 255, stdin);
				  Surname[255] = strtok(Surname, "\n");
				  printf("Birth date: ");
				  fgets(birth_date, 255, stdin);
				  birth_date[255] = strtok(birth_date, "\n");
				  printf("Birth city: ");
				  fgets(birth_city, 255, stdin);
				  birth_city[255] = strtok(birth_city, "\n");
				  printf("Birth country: ");
				  fgets(birth_country, 255, stdin);
				  birth_country[255] = strtok(birth_country, "\n");
				  printf("Address: ");
				  fgets(address, 255, stdin);
				  address[255] = strtok(address, "\n");
				  printf("Department: ");
				  fgets(department, 255, stdin);
				  department[255] = strtok(department, "\n");
				  printf("Post: ");
				  fgets(position, 255, stdin);
				  position[255] = strtok(position, "\n");
				  printf("Acceptance date: ");
				  fgets(acceptance_date, 255, stdin);
				  acceptance_date[255] = strtok(acceptance_date, "\n");
				  strcpy(sql, "INSERT INTO EMPLOYEES VALUES ('");

				  char buf[50];
				  sprintf(buf, "%d", ++max_id);

				  strcat(sql, name);
				  strcat(sql, "', '");
				  strcat(sql, Surname);
				  strcat(sql, "', '");
				  strcat(sql, FathersName);
				  strcat(sql, "', '");
				  strcat(sql, birth_date);
				  strcat(sql, "', NULL, '");
				  strcat(sql, birth_city);
				  strcat(sql, "', '");
				  strcat(sql, birth_country);
				  strcat(sql, "', '");
				  strcat(sql, address);
				  strcat(sql, "', '");
				  strcat(sql, department);
				  strcat(sql, "', '");
				  strcat(sql, position);
				  strcat(sql, "', '");
				  strcat(sql, acceptance_date);
				  strcat(sql, "',");
				  strcat(sql, buf);
				  strcat(sql, ");");
				  break;
		}
		case 3:
			//veryGoodLanguageForDevelopment = getch();
			printf("Parameters:\n");
			printf("1) all\n");
			printf("2) by id\n");
			printf("3) by surname\n");
			printf("4) by post\n");
			strcpy(sql, "SELECT * from employees ");
			char a = getch();
			switch (a)
			{
			case '1':
			{
						break;
			}
			case '2':
			{
						printf("id = ");
						int d;
						scanf("%d", &d);
						printf("\n");
						strcat(sql, "where Id = ");
						char buf[256];
						sprintf(buf, "%d", d);
						strcat(sql, buf);

						char s[50] = "Photography";
						strcat(s, buf);
						strcat(s, ".jpg");

						rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
						if (rc != SQLITE_OK) {
							fprintf(stderr, "SQL error: %s\n", zErrMsg);
							sqlite3_free(zErrMsg);
						}
						else {
							fprintf(stdout, "Operation done successfully\n");
						}

						strcpy(sql, "SELECT Photography from employees where Id = ");
						strcat(sql, buf);

						sqlite3_stmt *pStmt;
						rc = sqlite3_prepare_v2(db, sql, -1, &pStmt, 0);

						if (rc != SQLITE_OK) {
							fprintf(stderr, "Failed to prepare statement\n");
							fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
							sqlite3_close(db);
							return 1;
						}

						rc = sqlite3_step(pStmt);

						int bytes = 0;

						if (rc == SQLITE_ROW) {
							bytes = sqlite3_column_bytes(pStmt, 0);
						}

						FILE* file = fopen(s, "wb");

						fwrite(sqlite3_column_blob(pStmt, 0), bytes, 1, file);

						fclose(file);
						continue;
			}
			case '3':
			{
						printf("Surname = ");
						char s[256];
						scanf("%255s", s);
						printf("\n");
						strcat(sql, "where Surname = '");
						strcat(sql, s);
						strcat(sql, "'");
						break;
			}
			case '4':
			{
						printf("Post = ");
						char s[256];
						scanf("%255s", s);
						printf("\n");
						strcat(sql, "where Post = '");
						strcat(sql, s);
						strcat(sql, "'");
						break;
			}
			default:
				printf("Nothing was chosen\n");
				return 1;
				break;
			}
			break;
		case 4:
		{
				  char s[50];
				  printf("id = ");
				  scanf("%49s", s);
				  strcpy(sql, "delete from employees where id = ");
				  strcat(sql, s);
				  break;
		}
		case 5:
			printf("File name = ");
			char filename[256];
			scanf("%s", filename);
			printf("Employee id = ");
			char id[20];
			scanf("%19s", id);
			FILE *fp = fopen(filename, "rb");
			if (fp == NULL)
			{
				fprintf(stderr, "Cannot open Photography file\n");
				return 1;
			}
			fseek(fp, 0, SEEK_END);
			if (ferror(fp)) {
				fprintf(stderr, "fseek() failed\n");
				int r = fclose(fp);
				if (r == EOF) {
					fprintf(stderr, "Cannot close file handler\n");
				}

				return 1;
			}
			int flen = ftell(fp);
			if (flen == -1) {

				perror("error occurred");
				int r = fclose(fp);

				if (r == EOF) {
					fprintf(stderr, "Cannot close file handler\n");
				}

				return 1;
			}

			fseek(fp, 0, SEEK_SET);

			if (ferror(fp)) {

				fprintf(stderr, "fseek() failed\n");
				int r = fclose(fp);

				if (r == EOF) {
					fprintf(stderr, "Cannot close file handler\n");
				}

				return 1;
			}

			char* data = malloc(sizeof(char)*(flen + 1));

			int size = fread(data, 1, flen, fp);

			if (ferror(fp)) {

				fprintf(stderr, "fread() failed\n");
				int r = fclose(fp);

				if (r == EOF) {
					fprintf(stderr, "Cannot close file handler\n");
				}

				return 1;
			}

			int r = fclose(fp);

			if (r == EOF) {
				fprintf(stderr, "Cannot close file handler\n");
			}

			char *err_msg = 0;

			sqlite3_stmt *pStmt;

			char rsql[512];
			strcpy(rsql, "update employees set Photography = ? where id = ");
			strcat(rsql, id);

			rc = sqlite3_prepare(db, rsql, -1, &pStmt, 0);

			if (rc != SQLITE_OK) {

				fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));

				return 1;
			}

			sqlite3_bind_blob(pStmt, 1, data, size, SQLITE_STATIC);

			rc = sqlite3_step(pStmt);

			if (rc != SQLITE_DONE) {

				printf("execution failed: %s", sqlite3_errmsg(db));
			}

			sqlite3_finalize(pStmt);

			break;
		}

		rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
		}
		
	}
	sqlite3_close(db);
	return 0;
}