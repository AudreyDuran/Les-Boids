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

// ===========================================================================
//                                  Constructors
// ===========================================================================
Population::Population(void)
{
	ag = NULL;
	nbPop = 0;
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

int Population::getNbPop() 
{
	return nbPop;
}

void Population::add(Agent a)
{
	ag[nbPop]= a;
	nbPop += 1;
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================