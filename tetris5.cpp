#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "genMino.h" 
using namespace std; 
int main()
{ 
	Mino * mino_ptr1=new MinoS;
	mino_ptr1->paint();
        delete mino_ptr1;
	Mino * mino_ptr2=new MinoI;
        mino_ptr2->paint();
        delete mino_ptr2;
	Mino * mino_ptr3=new MinoL;
        mino_ptr3->paint();
        delete mino_ptr3;
	Mino * mino_ptr4=new MinoT;
        mino_ptr4->paint();
        delete mino_ptr4;
	Mino * mino_ptr5=new MinoJ;
        mino_ptr5->paint();
        delete mino_ptr5;
	return 0; 
}
