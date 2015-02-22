#include <iostream>

#include "app/User.hpp"

using namespace std;

int main() {
  cout << "Monokroma started" << endl;
  User user;
  user.setId(42);
  cout << user.getTotalPageViews() << endl;
  return 0;
}
