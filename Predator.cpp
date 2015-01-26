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
    digestion = 0;
    preyEaten = 0;

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
    digestion = 0;
    preyPos = -1;
    preyEaten = 0;

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
    digestion = 0;
    preyPos = -1;
    preyEaten = 0;

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

int Predator::getpreyPos()
{
    return preyPos;
}

int Predator::getpreyEaten()
{
    return preyEaten;

}

//----------------------------------------------------------------------------
//                                       newPosition
//----------------------------------------------------------------------------

/*
void Predator::newPosition()
{

    x = nextX;
    y = nextY;
    
    if(attack == false)
    {
        double nx = x + DT * vx;
        double ny = y + DT * vy;

        //we look at the x position
        if((40<nx) && (nx<600))
        {
            nextX = nx;
        }

        else if(nx<40)
        {
            //vx= vx + 10;
            nextVx=vx + 5;
            nextX = x + DT * vx;
        }
        else if(nx>600)
        {
            //vx= vx - 10;
            nextVx=vx - 5;
                win.draw_fsquare(ag[pr[i].getpreyPos()].getx(),
            nextX = x + DT * vx;
        }


        //we look at the y position
        if((40<ny) && (ny<440))
        {
            nextY = ny;
        }

        else if(ny<40)
        {
            //vy= vy + 10;
            nextVy=vy + 5;
            nextY = y + DT * vy;
        }

        else if(ny>440)
        {
            //vy= vy - 10;
            nextVy=vy - 5;
            nextY = y + DT * vy;
        }



    }
    else if(attack == true)
    {
        nextX = x + DT*vx;
        nextY = y + DT*vy;
    }
}
    
*/
//----------------------------------------------------------------------------
//                                    move
//----------------------------------------------------------------------------

void Predator::move(Agent* ag, int nbPop, double vmax)
{

    //if the Predator is not digesting after he ate a prey
    if(digestion == 0)
    {
        printf("Rentre dans boucle digestion == 0\n");
        double* v = new double[2];
        double closest = 810; //it's the max distance possible between the predator and the Agent
        int position = 0; // position of the closest 
        int K = 0;

         //we look if there is an Agent in his radius of perception
        for(int i=0; i<nbPop; i++)
        {

            if(ag[i].getisObstacle() == false && ag[i].getalive() == true) // we check it's not an obstacle and that he is alive
            {
                if(this->isClosedTo(ag[i],Rp) == true && this->norm(ag[i]) < closest)  //if it is in Rp and the closest Agent we actualize
                {
                    closest = this->norm(ag[i]);
                    position = i;
                    K = K + 1;
                }
            }  
        } 

        printf("K=%d\n",K );

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

        else // if there is at least an Agent in his radius of perception 
        {
            printf("commence attaque alors que cherchait proie\n");
            attack = true;
            preyPos = position;

            hunting(ag);
            //nextVx = vx;
            //nextVy = vy;
        }


    }
    else 
    {
        hunting(ag);
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

    //}


}





void Predator::hunting(Agent* ag)
{
    if(attack == true)
    {   

        // if the Predator is not close enough to eat the prey
        if(this->norm(ag[preyPos]) > Re)
        {
            nextVx = -((x - ag[preyPos].getx()))*10/(this->norm(ag[preyPos]));
            nextVy = -((y - ag[preyPos].gety()))*10/(this->norm(ag[preyPos]));


        }

        // if the Predator can eat the prey
        else
        {
            //time_t* clock = new time_t();
            //time(clock);
            
            attack = false;
            digestion = digestion + 1;
            preyEaten = preyEaten + 1;

            nextVx = 0;
            nextVy = 0;

            ag[preyPos].setNextvx(0);
            ag[preyPos].setNextvy(0);
            ag[preyPos].setAlive(false);
        }

    }
    else
    {
        this->digest();
    }
}


void Predator::digest()
{
    if(attack == false)
    {
        if(digestion <400)
        {
            digestion = digestion +1;
            nextVx = 0;
            nextVy = 0;
            printf("DISGESTION GOING ON\n");
            printf("vx = %lf vy=%lf\n",vx,vy );
        }

        else if(digestion == 400)
        {
            digestion = 0;
            printf("End of digestion -------------------\n");

            vx = 1;
            vy = 1;
            printf("nextvx = %lf nextVy=%lf\n",vx,vy );

        }
    }

}

// ===========================================================================
//                                Protected Methods
// ===========================================================================



// ===========================================================================
//                               Non inline accessors
// ===========================================================================
