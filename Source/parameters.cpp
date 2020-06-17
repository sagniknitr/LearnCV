#include "parameters.h"
#define junk -1001

parameters::parameters()
{
    track1=track2=track3=track4=track5=track6=junk;
}

parameters::~parameters()
{

}

parameters::parameters(int x1)
{
    track1=x1;track2=junk; track3=junk;track4=junk; track5=junk;track6=junk;
}

parameters::parameters(int x1,int x2)
{
    track1=x1;track2=x2;track3=junk;track4=junk; track5=junk;track6=junk;
}

parameters::parameters(int x1,int x2,int x3)
{
     track1=x1;track2=x2;track3=x3;track4=junk; track5=junk;track6=junk;
}

parameters::parameters(int x1,int x2,int x3,int x4)
{
     track1=x1;track2=x2; track3=x3;track4=x4;track5=junk;track6=junk;
}

parameters::parameters(int x1,int x2,int x3,int x4,int x5)
{
     track1=x1;track2=x2; track3=x3;track4=x4;track5=x5;track6=junk;
}

parameters::parameters(int x1,int x2,int x3,int x4,int x5,int x6)
{
     track1=x1;track2=x2; track3=x3;track4=x4; track5=x5;track6=x6;
}



