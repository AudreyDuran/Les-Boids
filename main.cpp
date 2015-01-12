#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Population.h"
#include "Obstacle.h"

int main()
{
	srand(time(NULL));

    //Test for Agent's default constructor
    printf("\nAGENT : default constructor\n");
	Agent test;
    printf("x=%lf y=%lf vx=%lf \n", test.getx(), test.gety(), test.getVx());

    //Test for Agent's constructor with 6 parameters
    printf("\n\nAGENT : constructor Agent(double X, double Y, double Vx, double Vy,double W, double H, double dt)\n");
    Agent test2 = Agent(0,1, 1,1,100,100,1);
    printf("x=%lf y=%lf vx=%lf \n", test2.getx(), test2.gety(), test2.getVx());

    Agent test3 = Agent(5,5,1,0,100,100,1);


    // Test for Population's default constructor
    printf("\n\nPOPULATION : default constructor\n");
    Population pop;
    printf("nb pop : %d\n", pop.getNbPop());

    //Test Population::add$
    printf("\n\nPOPULATION : add (add 3 Agent)\n");
    pop.add(test);
    pop.add(test2);
    pop.add(test3);
    printf("nb pop : %d\n", pop.getNbPop());
    
    //Test of Agent::isClosedTo
    printf("\n\nAGENT : isClosedTo\n");
   printf("test2.isClosedTo(test,5) = %d \n",test2.isClosedTo(test, 0.2));

    //Test Population::getAg
    printf("\n\nPOPULATION : getAg\n");
    Agent* lapop = pop.getAg();

    for(int i=0; i<pop.getNbPop(); i++)
    {
        lapop[i].print();
    }

    //Test Population::print
    printf("\n\nPOPULATION : print\n");
    pop.print();

    //Test Agent::v1()
   printf("\n\nAGENT : v1 (tested on the Agent (1) test)\n");
   test.v1(pop.getAg(),pop.getNbPop());

    //Test Agent::v2()
   printf("\n\nAGENT : v2 (tested on the Agent (1) test)\n");
   test.v2(pop.getAg(),pop.getNbPop());

    //Test Agent::v3()
   printf("\n\nAGENT : v3 (tested on the Agent (1) test)\n");
   test.v3(pop.getAg(),pop.getNbPop());

   //Test for Agent::setVx()
   printf("\n\nAGENT : setVx\n");
   test.setVx(10);
   printf("vx = %lf\n", test.getVx() );

   //Test for Population::speed()
   printf("\n\nPOPULATION : speed\n");
   pop.print();
   pop.speed();
   pop.print();

	//Test Population::run
    printf("\n\nPOPULATION : run\n");
    pop.run();


    

    return 0;
}
