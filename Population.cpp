//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Population.h"




//############################################################################
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const size_t Population::MAX_POP = 1000;

// ===========================================================================
//                                  Constructors
// ===========================================================================
Population::Population(void)
{
	ag = new Agent[MAX_POP];
	nbPop = 0;
	W = 640;
	H = 480;
	G1 = 0.05;
	G2 = 0.02;
	G3 = 0.1;
}

Population::Population(double w, double h, double g1, double g2, double g3)
{

    ag = new Agent[MAX_POP];
    nbPop = 0; 

    W = w;  
    H = h;
    G1 = g1;
    G2 = g2;
    G3 = g3;
}


// ===========================================================================
//                                  Destructor
// ===========================================================================
Population::~Population(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================


//----------------------------------------------------------------------------
//                                   Getters
//----------------------------------------------------------------------------

int Population::getNbPop() 
{
	return nbPop;
}


Agent* Population::getAg()
{
	return ag;
}


//-----------------------------------------------------------------------------
//                                   add
//-----------------------------------------------------------------------------


void Population::add(Agent a)
{
	ag[nbPop]= a;
	nbPop += 1;
}

//-----------------------------------------------------------------------------
//                                   speed
//-----------------------------------------------------------------------------


void Population::speed()
{

	double DT = ag[0].getDT();

	for(int i = 0; i< nbPop; i++)
	{

		printf("SPEED : i= %d\n",i);
		ag[i].setVx(ag[i].getNextvx());
		ag[i].setVy(ag[i].getNextvy());

		ag[i].setNextvx(ag[i].getx() + DT * (G1*ag[i].v1(ag, nbPop)[0] + G2*ag[i].v2(ag, nbPop)[0] + G3*ag[i].v3(ag, nbPop)[0]));

		printf("vx = %lf vy = %lf nextvx = %lf nextvy = %lf\n", ag[i].getVx(), ag[i].getVy(), ag[i].getNextvx(), ag[i].getNextvy());
	}


}

//-----------------------------------------------------------------------------
//                                   run
//-----------------------------------------------------------------------------

void Population::run()
{

// creation of the bwindow

	bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();

    double DT = ag[0].getDT();

    for(;;)  // infinite loop for(;;)
    {
		int ev = win.parse_event();
		usleep(100000); 
		switch(ev)
		{
	  	  case BKPRESS :
			printf("keypressed\n"); 
			printf("key : %s\n",win.get_lastkey());
			break;
	    	case BBPRESS:
			printf("buttonpressed\n"); break;
	    	case BEXPOSE:
			printf("expose\n"); break;
	    	case BCONFIGURE:
			printf("configure\n"); break;
		}

		//win.draw_point(100,100,0xFF00);
		//win.draw_line(100,100,200,200,0xFF0000);
		//win.draw_text(10,10,0x0,"Yo men",strlen("Yo men"));     //text

		for(int i=0; i<nbPop; i++)
		{
			win.draw_fsquare(ag[i].getx(),ag[i].gety(),ag[i].getx() + 10 ,ag[i].gety() + 10,0xFF0000); //full square
			ag[i].newPosition();
			this->speed();

		}
		//win.draw_square(200,200,220,220,0xFF00);   //square
	   

		//sleep() tps en s
		//usleep() tps en ms
 	}
    
		
}


//-----------------------------------------------------------------------------
//                                   print
//-----------------------------------------------------------------------------

void Population::print()
{
	printf("\n\nDébut du pop.print()\n");

	printf("\n\nnbPop = %d\nMAX_POP= %d\n", nbPop,MAX_POP);

	for(int i=0; i<nbPop; i++)
	{
		printf("i⁼%d \n", i);
		ag[i].print();
	}

	printf("Fin du pop.print()\n\n");
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
