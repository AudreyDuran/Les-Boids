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
#include "Predator.h"




//############################################################################
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Predator::Predator(void)
{
	x = 0;
	y = 0;

	nextX = 0;
	nextY = 0;

	vx = 1;
	vy=1;

	nextVx = vx;
	nextVy = vy;

	Rp = 10;
	Re = 1;

	DT=0.1;

	isObstacle = false;
    attack = false;

    preyPos = -1;
}

Predator::Predator(int W, int H, double rp, double re)
{
	x = (double)(rand()/(double)RAND_MAX)*W;
	y = (double)(rand()/(double)RAND_MAX)*H;

    nextX = x;
	nextY = y;

	vx = 10;
	vy = 10;

	nextVx = vx;
	nextVy = vy;

	DT = 0.1;


	isObstacle = false; 
    attack = false;
    preyPos = -1;

	Rp = rp;
	Re = re;
}

//Constructor of Predator with a given position
Predator::Predator(int X, int Y, int W, int H, double rp, double re)
{
    x = X;
    y = Y;

    nextX = x;
    nextY = y;

    vx = 10;
    vy = 10;

    nextVx = vx;
    nextVy = vy;

    DT = 0.1;


    isObstacle = false; 
    attack = false;
    preyPos = -1;

    Rp = rp;
    Re = re;
}
// ===========================================================================
//                                  Destructor
// ===========================================================================
Predator::~Predator(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

//----------------------------------------------------------------------------
//                                    Getters
//----------------------------------------------------------------------------

double Predator::getRp()
{
	return Rp;
}

bool Predator::getattack()
{
    return attack;
}

//----------------------------------------------------------------------------
//                                    move
//----------------------------------------------------------------------------

void Predator::move(Agent* ag, int nbPop, double vmax)
{
    double* v = new double[2];
    double closest = 810; //it's the max distance possible between the predator and the Agent
    int position = 0; // position of the closest 
    int K = 0;

    //if the Preadator is not already hunting
    if(attack == false)
    {
        //we look if there is an Agent in his radius of perception
        for(int i=0; i<nbPop; i++)
        {

            if(ag[i].getisObstacle() == false) // we check it's not an obstacle
            {
                if(this->isClosedTo(ag[i],Rp) == true && this->norm(ag[i]) < closest)  //if it is in Rp and the closest Agent we actualize
                {
                    closest = this->norm(ag[i]);
                    position = i;
                    K = K + 1;
                }
            }  
        //printf("K=%d\n",K );   
        }    


        if(K == 0)  // if there is no Agent is the radius of perception
        {
            //random speed
            v[0] = random(-1,1);
            v[1] = random(-1,1);

            printf("v[0]=%lf\n", v[0] );
            printf("v[1]=%lf\n", v[1] );
   

            nextVx = vx + v[0];
            nextVy = vy + v[1];
        }

        else
        {
            nextVx = vx;
            nextVy = vy;
        }

       /* else  //if there are agent in the radius of percepcion now
        {

            preyPos = position;
            attack = true;  //the predator is now in the mode attack

            if(this->norm(ag[preyPos]) > Re)
            {
                v[0] = (double)(-1)*(x - ag[preyPos].getx())/(double)sqrt(x*x+ag[preyPos].getx()*ag[preyPos].getx());
                v[1] = (double)(-1)*(y - ag[preyPos].gety())/(double)sqrt(y*y+ag[preyPos].gety()*ag[preyPos].gety());
            }

            nextVx = vx + v[0];
            nextVy = vy + v[1];


        }*/

    }


}





void Predator::hunting(Agent* ag)
{
    if(attack == true)
    {   
        if(this->norm(ag[preyPos]) > Re)
        {
            nextVx = (x - ag[preyPos].getx())/sqrt(x*x+ag[preyPos].getx()*ag[preyPos].getx());
            nextVy = (y - ag[preyPos].gety())/sqrt(y*y+ag[preyPos].gety()*ag[preyPos].gety());
        }

        else
        {
            nextVx = 0;
            nextVy = 0;

            ag[preyPos].setNextvx(0);
            ag[preyPos].setNextvy(0);
        }
        


    }


}

// ===========================================================================
//                                Protected Methods
// ===========================================================================



// ===========================================================================
//                               Non inline accessors
// ===========================================================================
