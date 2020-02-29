#include "Person.h"

Person :: Person()
{
}

Person :: ~Person()
{

}

/*
   Creates a string record from Person's data member and writes to given file.
*/
bool Person :: serialize(fstream &fInOut, string &outPersonRecord)
{

  return true;
}

/* 
   Gets the Person record as string, parse it and copy the values to Person's data members.
*/
bool Person :: deSerialize(fstream &fInOut, string &inPersonRecord)
{

  return true;
}
