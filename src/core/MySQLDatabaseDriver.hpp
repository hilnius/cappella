#ifndef MYSQL_DATABASE_DRIVER_H_INCLUDED
#define MYSQL_DATABASE_DRIVER_H_INCLUDED

#include <string>
#include "common/Singleton.hpp"
#include "core/DatabaseDriver.hpp"
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class MySQLQueryBuilder;

class MySQLDatabaseDriver: public DatabaseDriver, public Singleton<MySQLDatabaseDriver>
{
  friend class Singleton<MySQLDatabaseDriver>;

  protected:
    MySQLDatabaseDriver();
    virtual ~MySQLDatabaseDriver();

  public:

    void connect(std::string host, std::string username, std::string password);
    void execute(std::string query);
    void use(std::string database);
    sql::ResultSet* executeQuery(std::string query);
    MySQLQueryBuilder* getQueryBuilder();

  private:
    sql::mysql::MySQL_Driver *p_driver;
    sql::Connection *p_connection;
    sql::Statement *p_statement;
};

class MySQLQueryBuilder
{
  public:
    MySQLQueryBuilder() { p_query = ""; }
    virtual ~MySQLQueryBuilder() {}

    MySQLQueryBuilder* select(std::string what, std::string from) {
      p_query += "SELECT " + what + " FROM " + from;
      return this;
    }
    MySQLQueryBuilder* where(std::string what, std::string operand, std::string value) {
      p_query += " WHERE" + what + " " + operand + " " + value;
      return this;
    }
    sql::ResultSet* get() {
      return MySQLDatabaseDriver::getInstance()->executeQuery(p_query);
    }
  private:
    std::string p_query;
};

#endif // MYSQL_DATABASE_DRIVER_H_INCLUDED
