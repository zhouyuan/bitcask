#include "bitcask.h"

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()  // Random string generator function.
{

    return alphanum[rand() % stringLength];
}

string getString()
{
  string str;
  for(unsigned int i = 0; i < 4096; ++i)
  {
      str += genRandom();
  }

  return str;
}

int main()
{
  bitcask bc;
  bitcask_data bc_data;
  bc.init();

  bc.insert_data("testkey2", getString());
  bc.insert_data("testkey1", getString());
  bc.insert_data("testkey3", getString());
  bc.update_data("testkey1", "testvalue");
  int i = 0;
  for (; i<=1000 ; i++ ) {
    string testkey = "mykey" + to_string(i);
    bc.insert_data(testkey, getString());
  }


/*
  bc.insert_data("testkey6", "testvaluesssss");
  bc.insert_data("testkey8", "testvaluesssss");
  bc.insert_data("testkey5", "testvaluesssss");


  bc_data = bc.read_data("testkey2");
*/
  bc_data = bc.read_data("testkey2");
  bc_data = bc.read_data("testkey1");
  //cout << bc_data.value << endl;

}
