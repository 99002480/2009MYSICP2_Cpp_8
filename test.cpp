#include<gtest/gtest.h>
#include <string.h>
#include"car.h"


namespace{
TEST(car,AllTest)
{
    car a;
    int c=0;
   ifstream infile("parking3.dat",ios::binary|ios::in);
           int dn=1;
           while (infile.read((char *)&a,sizeof (a)))
		   {
			system("clear");
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<dn;
           dn++;
           a.details();
           c=c+1;
           }



EXPECT_EQ(c,2);




}


}
