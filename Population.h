//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __POPULATION_H__
#define __POPULATION_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================

#include "Agent.h"
#include "bwindow.h"


// ===========================================================================
//                              Class declarations
// ===========================================================================






class Population
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Population(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Population(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    int getNbPop();
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================

    void add(Agent a);
    void run();
    void speed();    // calculate the new velocity and set vx, vy, nextVx, nextVy

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Population(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Population(const Population &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================

    static const size_t MAX_POP;
    Agent* ag;   // table wich contains the Agents
    int nbPop;

    double W;   // weight of the window
    double H;   // height of the window

    double DT;  // time interval

    double g1;  // gamma 1 
    double g2;  // gamma 2
    double g3;  // gamma 3

};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __NODE_H__

