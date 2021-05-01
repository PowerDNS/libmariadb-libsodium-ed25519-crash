#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  MYSQL db;
  char *host, *user, *password, *database;

  if (argc != 5) {
    printf("usage: %s HOST USER PASSWORD DATABASE\n", argv[0]);
    exit(1);
  }
  host = argv[1];
  user = argv[2];
  password = argv[3];
  database = argv[4];

  if (!mysql_init(&db)) {
    puts("mysql_init failed");
    exit(1);
  }

  if (!mysql_real_connect(&db, host, user, password, database, 3306, NULL, 0)) {
    puts("unable to connect");
    exit(1);
  }
  puts("connected");
  exit(0);
}