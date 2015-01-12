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


/*const double Agent::XMAX = 640;
const double Agent::YMAX = 480;*/

const double Agent::R = 2;
const double Agent::c = 0.5;

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

}

/* create an Agent with a random positon and a null velocity */
Agent::Agent(double W, double H)
{
	x = (double)(rand()/(double)RAND_MAX)*W;
	y = (double)(rand()/(double)RAND_MAX)*H;

	vx = 0;
	vy = 0;

	nextX = 0;
	nextY = 0;

	nextVx = 0;
	nextVy = 0;

}

/*create an Agent with a given position and a given velocity*/
Agent::Agent(double X, double Y, double Vx, double Vy,double W, double H)
{
	x = X;
	y = Y;

	vx = Vx;
	vy = Vy;

	nextX = 0;
	nextY = 0;

	nextVx = 0;
	nextVy = 0;

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

//-----------------------------------------------------------------------------
//                                  Setters
//-----------------------------------------------------------------------------


void Agent::setVx(double v)
{
	vx = v;
}



void Agent::setVy(double v)
{
	vy = v;

}

//----------------------------------------------------------------------------
//                                nextPosition
//----------------------------------------------------------------------------




void Agent::nextPosition()
{

}


//---------------------------------------------------------------------------
//                              isCloserThan
//---------------------------------------------------------------------------


bool Agent::isClosedTo(Agent ag, double distance)
{
	bool close = false;
	double norm = 0; //distance between the two agents

	norm = sqrt((x-ag.getx())* (x-ag.getx()) +(y-ag.gety())*(y-ag.gety()) );
	
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
	double* v1 = new double[2];
	v1[0] = 0;
	v1[1] = 0;
	
	int K = 0; //number of Agents into the Agent's radius of perception

	for(int i=0; i<nbPop; i++)
	{
		if(this->isClosedTo(ag[i],R) == true)
		{
			K = K + 1;
			printf("K=%d i=%d\n",K,i);

			v1 [0] = v1[0] + ag[i].getVx() - this->getVx();
			v1 [1] = v1[1] + ag[i].getVy() - this->getVy();

		}
	}
	

	v1[0] = (double)1/K* (double)v1[0];
	v1[1] = (double)1/K * (double)v1[1];

	printf("fin : v1[0]= %lf v1[1]=%lf\n",v1[0],v1[1]);
	
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
		if(this->isClosedTo(ag[i],R) == true)
		{
			K = K + 1;
				printf("K=%d i=%d\n",K,i);

			v2 [0] = v2[0] + ag[i].getx() - this->getx();
			v2 [1] = v2[1] + ag[i].gety() - this->gety();

		}
	}
	

	v2[0] = (double)1/K* (double)v2[0];
	v2[1] = (double)1/K * (double)v2[1];

	printf("fin : v2[0]= %lf v2[1]=%lf\n",v2[0],v2[1]);
	

	return v2;
	
}

//----------------------------------------------------------------------------
//                                   v3
//----------------------------------------------------------------------------

double* Agent::v3(Agent* ag, int nbPop)
{
	double* v3 = new double[2];

	int K2 = 0;  //number of Agents closed to the considerated Agent
	int O = 0;  //number of obstacles closed to the considerated Agent

	//first we calculate the first part of the expression of v3
	for(int i=0; i<nbPop; i++)
	{
		if(this->isClosedTo(ag[i],c) == true)
		{
			K2 = K2 + 1;
				printf("K2=%d i=%d\n",K2,i);

			v3 [0] = v3[0] + ag[i].getx() - this->getx();
			v3 [1] = v3[1] + ag[i].gety() - this->gety();

		}
	}

	v3[0] = (double)-1/K2* (double)v3[0];
	v3[1] = (double)-1/K2* (double)v3[1];

   //now we can focus on the second part of the expression of v3

	return v3;

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
