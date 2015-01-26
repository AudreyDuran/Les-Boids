#include <stdio.h>
#include "bwindow.h"
#include "Agent.h"
#include "Population.h"
#include "Predator.h"

int main()
{
	srand(time(NULL));

    //Test for Agent's default constructor
    printf("\nAGENT : default constructor\n");
	  Agent test;
    printf("x=%lf y=%lf vx=%lf \n", test.getx(), test.gety(), test.getVx());

    //Test for Agent's constructor with 6 parameters
    printf("\n\nAGENT : constructor Agent(double X, double Y, double Vx, double Vy,double W, double H, double dt)\n");
    Agent test2 = Agent(0,1, 1,1,100,100,1, false);
    printf("x=%lf y=%lf vx=%lf \n", test2.getx(), test2.gety(), test2.getVx());

    Agent test3 = Agent(5,5,2,0,100,100,1, false);


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

   //Test for Agent::newPosition()
    printf("\n\nAGENT : newPosition\n\n");
    /*Agent test4 = Agent(639,20,1,1,640,480,1);
    test4.print();
    test4.newPosition();
    test4.print();*/
    //test4.newPosition();
    //test4.print();

    Population popu;

    Agent test5 = Agent(640,480, false);
    Agent test6 = Agent(640,480, false);
    Agent test7 = Agent(640,480, false);

    /*popu.add(test5);
    popu.add(test6);
    popu.add(test7);*/
    printf("add\n");
    popu.print();

    for(int i =0; i<popu.getNbPop();i++)
    {
     (popu.getAg(i))->newPosition();
      printf("la nouvelle nextX est%lf\n", (popu.getAg(i))->getNextX());
    }

    popu.print();
  

    //Test for Population: constructor with a given size
    printf("\n\nPOPULATION : constructor with a given size\n\n");

    //100, 5, 1, 50, 1, 640, 480, 
    //(nbPrey, nbObs, nbPredator, radiusP, re, w, h, g1, g2, g3, g4)
    Population hirondelles(100, 5, 1, 80, 5, 640, 480, 0.01, 1, 0.4, 20);
    hirondelles.print();
    for (int i = 0; i < hirondelles.getNbPop(); ++i)
    {
     double* vitesse = (hirondelles.getAg(i))->v3(hirondelles.getAg(), hirondelles.getNbPop());
     printf("i=%d v3x = %lf v3y=%lf\n",i, vitesse[0], vitesse[1]);
    }
    
    hirondelles.print();

  //Test Population::run
    printf("\n\nPOPULATION : run\n");
    //printf("DT =%lf\n", (hirondelles.getAg(0))->getDT());

    //popu.run();
    hirondelles.run();


    //Test for predator

   /* Predator mammouth(640,480,100,10);
    mammouth.print();

    mammouth.v4(popu.getAg(), popu.getNbPop());
    mammouth.print();

    mammouth.newPosition();
    printf("Apreès nouvelle position de mammouth\n");
    mammouth.print();

    mammouth.newPosition();
    printf("Après nouvelle position de mammouth 2\n");
    mammouth.print();
*/
    printf("\n\n AGENT :: is isClosedTo\n");
    Agent test11 = Agent(0,0,1,1,640,480, 1, false);
    Agent test12 = Agent(2,2,1,1,640,480,1,false);

    test11.print();
    test12.print();

    printf("isclosed to %d\n",test11.isClosedTo(test12,2));

    printf("norm %lf\n",test11.norm(test12));

    Predator* pred = new Predator[1];
    pred[0] = Predator(1,1,640,480,10,400);
    pred->print();

    test11.v4(pred, 1,0.5);


    return 0;
}
