#include<iostream>
#include<unistd.h>

using namespace std;


char *getname(void)
{
  static char name[256];
  gethostname(name,255);
  return name;
}
  int main()
{ 
  system("clear");
  char *hostname;
   hostname= getname();
   std::cout<<"\n"<<hostname<<"\n";
 return 0;
}

