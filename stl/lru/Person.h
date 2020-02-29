#include <iostream>

/* Person class 
   It can read and write itself from/to file (cache db).
*/

class Person
{
  public:
    Person();
    ~Person();

  public:
    bool serialize(fstream &fInOut, string &outPersonRecord); // @TODO check how cpp stl apis are desinged.
    bool deSerialize(fstream &fInOut, string &inPersonRecord); //From cache to App.

  private:
    string firstName;
    string lastName;
    unsigned short age;
};
