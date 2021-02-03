#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif


  
int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }

 auto start = std::chrono::system_clock::now();
  int functionid = atoi(argv[1]);
  float a= strtof(argv[2],NULL);
  float b=strtof(argv[3],NULL); 
  int n= atoi(argv[4]);
  int intensity=atoi(argv[5]);
  float temp= (b-a)/n;
  float sum=0;float f=0;
  for(int i=0;i<n;i++)
    {
      float x=(a+(i+.5)*temp);
      if(functionid==1)
	f=f1(x,intensity);
      else if(functionid == 2)
	f=f2(x,intensity);
      else if(functionid ==3)
	f=f3(x,intensity);
      else if(functionid ==4)
	f=f4(x,intensity);

      sum=sum+f;
    }
  sum=sum*temp;
  std::cout<<sum<<std::endl;
 auto end=std::chrono::system_clock::now();
 auto  elapsed=duration_cast<seconds>(end-start);
 std::cerr<<elapsed.count()<<std::endl;	  
  return 0;
}
