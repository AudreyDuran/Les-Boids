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
	pr = new Predator[MAX_POP];
	nbPop = 0;
	nbPred = 0;

	W = 640;
	H = 480;
	G1 = 0.05;
	G2 = 0.02;
	G3 = 0.1;
	G4 = 0.1;
}

//create an empty population with a given size for the window and the gi to calculate the speed
Population::Population(double w, double h, double g1, double g2, double g3, double g4)
{

    ag = new Agent[MAX_POP];
    pr = new Predator[MAX_POP];
    nbPop = 0; 
    nbPred = 0;

    W = w;  
    H = h;
    G1 = g1;
    G2 = g2;
    G3 = g3;
    G4 = g4;
}

Population::Population(int nbPrey, int nbObs, int nbPredator, double radiusP, double re, double w, double h, double g1, double g2, double g3, double g4)
{
	ag = new Agent[MAX_POP];
    nbPop = nbPrey + nbObs; 

    pr = new Predator[MAX_POP];
    nbPred = nbPredator;

    for (int i = 0; i < nbPrey; ++i)
    {
    	ag[i]= Agent(w,h, false);
    }
    for (int i = nbPrey; i < nbPop; ++i)
    {
    	ag[i] = Agent(w,h,true);
    }

    for(int i=0; i<nbPred; i++)
    {
    	pr[i]= Predator(w,h,radiusP, re);
    }

    W = w;  
    H = h;
    G1 = g1;
    G2 = g2;
    G3 = g3;
    G4 = g4;
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

Agent* Population::getAg(int pos)
{
	return &ag[pos];
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
	double Rp = pr[0].getRp();

	// we actualize the speed of the Prey
	for(int i = 0; i< nbPop; i++)
	{
		if(ag[i].getisObstacle() == false)
		{
			//we actualize vx and vy with nextvx and nextvy already calculated
			ag[i].setVx(ag[i].getNextvx());
			ag[i].setVy(ag[i].getNextvy());

			//we actualize nextvx and nexvy (calculating it with the gamas)
			ag[i].setNextvx(ag[i].getVx() + DT * (G1*ag[i].v1(ag, nbPop)[0] + G2*ag[i].v2(ag, nbPop)[0] + G3*ag[i].v3(ag, nbPop)[0] + G4*ag[i].v4(pr, nbPred, Rp)[0]));
			ag[i].setNextvy(ag[i].getVy() + DT * (G1*ag[i].v1(ag, nbPop)[1] + G2*ag[i].v2(ag, nbPop)[1] + G3*ag[i].v3(ag, nbPop)[1] + G4*ag[i].v4(pr, nbPred, Rp)[1]));

			double norm = sqrt(ag[i].getVx()*ag[i].getVx()+ag[i].getVy()*ag[i].getVy());

 			if(norm>5)
 			{
 				double max = norm/5;
 				ag[i].setVx((ag[i].getVx())/max);
 				ag[i].setVy((ag[i].getVy())/max);

 			}
		}
	}

	// we actualize the speed of the Predator
	for(int i=0; i<nbPred; i++)
	{
		//printf("Predator dans speed : vx=%lf vy=%lf\n", pr[i].getVx(), pr[i].getVy());
		// vx and vy
		pr[i].setVx(pr[i].getNextvx());
		pr[i].setVy(pr[i].getNextvy());

		//pr[i].setNextvx(pr[i].getVx() + DT*(double)(rand()/(double)RAND_MAX)*(5)-5);
		//pr[i].setNextvx(pr[i].getVy() + DT*(double)(rand()/(double)RAND_MAX)*(5)-5);


		//nextvx and nextvy
		//pr[i].setNextvx(pr[i].getVx() + DT * (-1) *pr[i].v4(ag, nbPop, Rp)[0]);
		//pr[i].setNextvy(pr[i].getVy() + DT * -(1) *pr[i].v4(ag, nbPop, Rp)[1]);

		//we actualize nextvx and nextvy
		if(pr[i].getattack() == false)
		{
			pr[i].move(ag, nbPop,50);
			//pr[i].setNextvx(pr[i].getVx() + DT *pr[i].move(ag, nbPop, 20)[0]);
			//pr[i].setNextvy(pr[i].getVy() + DT *pr[i].move(ag, nbPop, 20)[1]);
		}
		/*else
		{
			pr[i].hunting(ag);
		}*/

		double norm = sqrt(pr[i].getVx()*pr[i].getVx()+pr[i].getVy()*pr[i].getVy());

		if(norm>5)
 			{
 				double max = norm/5;
 				pr[i].setVx((pr[i].getVx())/max);
 				pr[i].setVy((pr[i].getVy())/max);

 			}

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

    double DT = ag[0].getDT();  //we get DT from an Agent


    for(;;)  // infinite loop for(;;)
    {
		int ev = win.parse_event();
	
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

		//usleep(100);
		win.draw_fsquare(0, 0, 645, 485, 0xFEFEFE);  // we actualize the window puting a white square on it
		

		// we look over the table of Agent (which contains Prey and Obstacle)
		for(int i=0; i<nbPop; i++)
		{
			//we draw the obstacles (don't move)
			if(ag[i].getisObstacle() == true)
			{
				win.draw_fsquare(ag[i].getx(),ag[i].gety(),ag[i].getx() + 7, ag[i].gety() + 7, 0x960018);
			}
			else
			{
    			// we draw the Prey
				win.draw_fsquare(ag[i].getx(),ag[i].gety(),ag[i].getx() + 3 ,ag[i].gety() + 3,0xE73E01);
				// we update his position (with the wind)
				ag[i].newPosition();
			}
			
		}

		
	

		// we look over the table of Predator
		for(int i=0; i<nbPred; i++)
		{ 
			//we print the Predator
			win.draw_fsquare(pr[i].getx(),pr[i].gety(),pr[i].getx() + 10 ,pr[i].gety() + 10,0x26C4EC);	
			
			//we update his position (with the wind)
			pr[i].newPosition();
			printf("Predator\n");
			pr[i].print();
			//if(pr[i].isClosedTo())
		}
		//we update the speed of all the Population (Prey and Predator)
	   	this->speed();

		//sleep() tps en s
		//usleep() tps en ms
 	}
    
		
}


//-----------------------------------------------------------------------------
//                                   print
//-----------------------------------------------------------------------------

void Population::print()
{
	//printf("\n\nDébut du pop.print()\n");

	//printf("\n\nnbPop = %d\nMAX_POP= %d\n", nbPop,MAX_POP);

	for(int i=0; i<nbPop; i++)
	{
		printf("i⁼%d \n", i);
		ag[i].print();
	}

	printf("nb pred %d\n", nbPred);

	for(int i=0; i<nbPred; i++)
	{
		printf("Prédateurs :\n");
		pr[i].print();
	}

	//printf("Fin du pop.print()\n\n");
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
