//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __AGENT_H__
#define __AGENT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>



// ===========================================================================
//                                Project Files
// ===========================================================================



// ===========================================================================
//                              Class declarations
// ===========================================================================






class Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Agent(void);
    Agent(double W, double H, bool obstacle);
    Agent(double X, double Y, double Vx, double Vy,double W, double H, double dt, bool obstacle);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    double getx();  // get the position x of the Agent
    double gety();  // get the position y of the Agent
    double getVx(); // get the velocity on the x line of the Agent
    double getVy(); // get the velocity on the y line of the Agent
    double getNextX();
    double getNextY();
    double getNextvx(); // get the next velocity on the x line of the Agent
    double getNextvy(); // get the next velocity on the y line of the Agent
    double getDT();
    bool getisObstacle();
    bool getalive();
    
   

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    void setX(double px);  // pour test
    void setVx(double v);
    void setVy(double v);
    void setNextvx(double v);
    void setNextvy(double v);
    void setAlive(bool b);

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================

     /*Agent(const Agent &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/

    void newPosition();
    double* v1(Agent* ag, int nbPop);
    double* v2(Agent* ag, int nbPop);
    double* v3(Agent* ag, int nbPop); 
    double* v4(Agent* pop, int nbPop, double rp);
    bool isClosedTo(Agent ag, double distance);

    double norm(Agent ag);
    double* diffPos(Agent ag);
    double* diffSpeed(Agent ag);

    double random(int min, int vmax);

    void print(); //print informations about the Agent (attributes)
    
    
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Agent(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
   


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================

    static const double XMAX;  // max position on the x line (because of the size of the window)
    static const double YMAX;  //max position on the y line

    static const double R; // radius of perception
    static const double c; //contact distance

    bool isObstacle;
    bool alive;    // true if alive

    double x;  // position of the Agent on the x line
    double y;  // position of the Agent on the y line

    double vx;    // coordinate x of the velocity vector
    double vy;    // coordinate y of the velocity vector

    double nextX; // next position of the Agent on the x line
    double nextY; // next position of the Agent on the x line

    double nextVx; // coordinate x of the next velocity vector
    double nextVy; // coordinate y of the next velocity vector

    double DT;  // time interval
       

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



#endif // __AGENT_H__

