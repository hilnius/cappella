#include "core/MySQLDatabaseDriver.hpp"

MySQLDatabaseDriver::MySQLDatabaseDriver()
{
  p_driver = sql::mysql::get_mysql_driver_instance();
  p_statement = nullptr;
  p_connection = nullptr;
}

MySQLDatabaseDriver::~MySQLDatabaseDriver()
{
  if (p_statement)
  {
    delete p_statement;
  }
  if (p_connection)
  {
    delete p_connection;
  }
}

void MySQLDatabaseDriver::connect(std::string host, std::string username, std::string password)
{
  p_connection = p_driver->connect("tcp://" + host, username, password);
  p_statement = p_connection->createStatement();
}

void MySQLDatabaseDriver::execute(std::string query)
{
  p_statement->execute(query);
}

sql::ResultSet* MySQLDatabaseDriver::executeQuery(std::string query)
{
  return p_statement->executeQuery(query);
}

void MySQLDatabaseDriver::use(std::string database)
{
  this->execute("USE " + database);
}

MySQLQueryBuilder* MySQLDatabaseDriver::getQueryBuilder()
{
  return new MySQLQueryBuilder();
}
