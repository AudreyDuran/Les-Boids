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
#include "Agent.h"





//############################################################################
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================



const double Agent::R = 70;
const double Agent::c = 30;

// ===========================================================================
//                                  Constructors
// ===========================================================================

/* create an Agent at the position (0,0) and a null velocity */
Agent::Agent(void)
{
	
	x = 0;
	y = 0;

	vx = 0;
	vy = 0;

	nextX = 0;
	nextY = 0;

	nextVx = 0;
	nextVy = 0;

	DT = 0.1;

	isObstacle = false;   // we create prey by default 

}

/* create an Agent with a random positon and a null velocity */
Agent::Agent(double W, double H, bool obstacle)
{
	isObstacle = obstacle;

	x = (double)(rand()/(double)RAND_MAX)*W;
	y = (double)(rand()/(double)RAND_MAX)*H;

	nextX = x;
	nextY = y;

	if(obstacle == false)
	{
		vx = 1;
		vy = 1;

		nextVx = 1;
		nextVy = 1;

	}
	else
	{	
		vx = 0;
		vy = 0;

		nextVx = 0;
		nextVy = 0;
	}
	
	DT = 0.1;

}

/*create an Agent with a given position and a given velocity*/
Agent::Agent(double X, double Y, double Vx, double Vy,double W, double H, double dt, bool obstacle)
{

	isObstacle = obstacle;

	x = X;
	y = Y;

	nextX = X;
	nextY = Y;


	if(obstacle == false)
	{
		vx = Vx;
		vy = Vy;

		nextVx = Vx;
		nextVy = Vy;

	}
	else
	{	
		vx = 0;
		vy = 0;

		nextVx = 0;
		nextVy = 0;
	}

	DT = dt;
}




// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================


//-----------------------------------------------------------------------------
//                                  Getters
//-----------------------------------------------------------------------------


double Agent::getx() 
{
	return x;
}

double Agent::gety()
{
	return y;

}  


double Agent::getVx()
{
	return vx;
} 

double Agent::getVy() 
{
	return vy;
}

double Agent::getNextX()
{
	return nextX;
}

double Agent::getNextY()
{
	return nextY;
}


// get the next velocity on the x line of the Agent
 double Agent::getNextvx()
 {
 	return nextVx;
 }

// get the next velocity on the y line of the Agent
double Agent::getNextvy()
{
	return nextVy;
}

double Agent::getDT()
{
	return DT;
}

bool Agent::getisObstacle()
{
	return isObstacle;
}

//-----------------------------------------------------------------------------
//                                  Setters
//-----------------------------------------------------------------------------

void Agent::setX(double px)
{
	x = px;
}

void Agent::setVx(double v)
{
	vx = v;
}



void Agent::setVy(double v)
{
	vy = v;

}

void Agent::setNextvx(double v)
{
	nextVx = v;
}

void Agent::setNextvy(double v)
{
	nextVy = v;
}

//----------------------------------------------------------------------------
//                                newPosition
//----------------------------------------------------------------------------




void Agent::newPosition()
{

	x = nextX;
	y = nextY;
	
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
/*

	if((10<nx) && (nx<630))
	{
		nextX = nx;
	}

	else
	{
		vx=-vx;
		nextVx=vx;
		nextX = x + DT * vx;
	}

    if((10<ny)&&(ny<470))
	{
		nextY = ny;
	}

	else
	{
		vy=-vy;
		nextVy=vy;
		nextY = y + DT * vy;
	}
*/
}

//---------------------------------------------------------------------------
//                                 random
//---------------------------------------------------------------------------

double Agent::random(int min, int max)
{
	double r = 0;
	r = (double)(rand()/(double)RAND_MAX)*(max-min) + min;

	return r;

}

//---------------------------------------------------------------------------
//                                  norm
//---------------------------------------------------------------------------

double Agent::norm(Agent ag)
{
	double norm = 0;
	norm = sqrt((x-ag.getx())* (x-ag.getx()) +(y-ag.gety())*(y-ag.gety()));

	return norm;

}

//---------------------------------------------------------------------------
//                                diffPos
//---------------------------------------------------------------------------

double* Agent::diffPos(Agent ag)
{
	double* diffPos = new double[2];

	diffPos[0] = (ag.getx()-x);
	diffPos[1] = (ag.gety()-y);

	return diffPos;
}
//---------------------------------------------------------------------------
//                                diffSpeed
//---------------------------------------------------------------------------


double* Agent::diffSpeed(Agent ag)
{
	double* diffSpeed= 0;
	diffSpeed[0] = (ag.getVx()-vx);
	diffSpeed[1] = (ag.getVy()-vy);

	return diffSpeed;
}

//---------------------------------------------------------------------------
//                              isCloserThan
//---------------------------------------------------------------------------


bool Agent::isClosedTo(Agent ag, double distance)
{
	bool close = false;
	double norm = 0; //distance between the two agents

	norm = this->norm(ag);

	//norm = sqrt((x-ag.getx())* (x-ag.getx()) +(y-ag.gety())*(y-ag.gety()) );
	
	if( norm < distance && norm !=0)   //we check it's not the same Agent
	{
		close = true;

	}
	
	return close;
}

//----------------------------------------------------------------------------
//                                   v1
//----------------------------------------------------------------------------

double* Agent::v1(Agent* ag, int nbPop)
{
	//printf("\nDébut du calcul de v1 pour cet Agent\n");
	
	double* v1 = new double[2];
	v1[0] = 0;
	v1[1] = 0;
	
	int K = 0; //number of Agents into the Agent's radius of perception

	for(int i=0; i<nbPop; i++)
	{
		if(ag[i].getisObstacle() == false)
		{
			if(this->isClosedTo(ag[i],R) == true)
			{
			K = K + 1;

			v1 [0] = v1[0] + ag[i].getVx() - this->getVx();
			v1 [1] = v1[1] + ag[i].getVy() - this->getVy();

			}
		}		
	}
	
	if(K!=0)
	{
		v1[0] = (double)1/K* (double)v1[0];
	    v1[1] = (double)1/K * (double)v1[1];

	}
	
	return v1;
}

//----------------------------------------------------------------------------
//                                   v2
//----------------------------------------------------------------------------

double* Agent::v2(Agent* ag, int nbPop)
{
	
	double* v2 = new double[2];

	v2[0] = 0;
	v2[1] = 0;
	
	int K = 0;  //number of Agents into the Agent's radius of perception

	for(int i=0; i<nbPop; i++)
	{
		if(ag[i].getisObstacle() == false)
		{
			if(this->isClosedTo(ag[i],R) == true)
			{
				K = K + 1;
				

				v2 [0] = v2[0] + ag[i].getx() - this->getx();
				v2 [1] = v2[1] + ag[i].gety() - this->gety();

			}

		}
		
	}
	
	if(K!=0)
	{
		v2[0] = (double)1/K * (double)v2[0];
	    v2[1] = (double)1/K * (double)v2[1];
	}
	

	//printf("fin : v2[0]= %lf v2[1]=%lf\n",v2[0],v2[1]);

	//printf("Fin du calcul de v2 pour cet Agent\n\n");
	

	return v2;
	
}

//----------------------------------------------------------------------------
//                                   v3
//----------------------------------------------------------------------------

double* Agent::v3(Agent* ag, int nbPop)
{
	//printf("\nDébut du calcul de v3 pour cet Agent\n");

	double* v3 = new double[2];
	double* v3inter = new double[2];   // on créé une vitesse intermediaire pour la partie droite de l'expression de la vitesse

	int K2 = 0;  //number of Agents closed to the considerated Agent
	int O = 0;  //number of obstacles closed to the considerated Agent

	//first we calculate the first part of the expression of v3

	if (isObstacle == false)   // we check the Agent of the function is not an obstacle
	{
		for(int i=0; i<nbPop; i++)
		{
			
			if(ag[i].getisObstacle() == false)     //we check that the Agent is not an obstacle
			{
				if(this->isClosedTo(ag[i],c) == true)
				{
				K2 = K2 + 1;

				v3 [0] = v3[0] + ag[i].getx() - this->getx();
				v3 [1] = v3[1] + ag[i].gety() - this->gety();

				}

			}

			else // if it is an obstacle
			{
				if(this->isClosedTo(ag[i],c) == true)  
				{
				O = O + 1;

				v3inter[0] = v3inter[0] + ag[i].getx() - this->getx();
				v3inter[1] = v3inter[1] + ag[i].gety() - this->gety();
				}
			}
	
		}
	}
	

	if(K2!=0)
	{
		v3[0] = (double)1/K2 * (double)v3[0] * (-1);
	    v3[1] = (double)1/K2 * (double)v3[1]*(-1);

	}
	
	if(O!=0)
	{
	    v3[0] = v3[0]+(double)1/O * (double)v3inter[0] * (-1);
	    v3[1] = v3[1]+(double)1/O * (double)v3inter[1] * (-1);	
	}

	//printf("Fin du calcul de v3 pour cet Agent\n\n");

	return v3;

}
	
//the Agent is positionning himself in fonction of the Predators
//-----------------------------------------------------------------------------
//                                      v4
//-----------------------------------------------------------------------------

// prey.v4() : pop=predator 
double* Agent::v4(Agent* pop, int nbPop, double rp)
{

	double* v4 = new double[2];
	int K=0;

	if(isObstacle == false)  // we check that we don't call this fonction with an obstacle
	{
		for(int i=0; i<nbPop; i++)
		{
		
			if(this->isClosedTo(pop[i], rp) == true && pop[i].getisObstacle() == false) 
			{
			v4[0]= v4[0] + (pop[i].getx()-x)/this->norm(pop[i]);
			v4[1]= v4[1] + (pop[i].gety()-y)/this->norm(pop[i]);

			K = K+1;
			}
		}
		
	}

	if(K!=0)
	{
		v4[0] = -1 * v4[0];
		v4[1] = -1 * v4[1];
	}

	//printf("K %d\n",K );

	return v4;
}

//----------------------------------------------------------------------------
//                                  print
//----------------------------------------------------------------------------

void Agent::print()
{
	printf("x=%lf y=%lf\nvx=%lf vy=%lf\nnextX=%lf nextY=%lf\nnextVx=%lf nextVy=%lf\n\n", x,y,vx,vy,nextX,nextY,nextVx,nextVy);
}


// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
