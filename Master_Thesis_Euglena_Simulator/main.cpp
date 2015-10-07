#include "Simulation.h"
#include<SFML/Graphics.hpp>


int main(int argc, char* argv[])
{
    auto cellCountX = 50;
    auto cellCountY = 50;

    auto cellSizeX = 16.0f;
    auto cellSizeY = 16.0f;

   
    sf::RenderWindow window(sf::VideoMode(cellCountX*cellSizeX, cellCountY*cellSizeY), "Euglena pre Alpha 0.02a");
   
    Simulation sim(cellCountX, cellCountY, cellSizeX, cellSizeY);
    std::vector<glm::ivec2> stats = {{0,0},{ 2,2 },{ 49,49 } };
    EuglenaAgent test(glm::vec2(10,10),0,0,5);
    sim.setStaticLight(stats, 100);
    sim.setAgentTemplate(test);
    EuglenaEmitter emitter({ 30,30 }, test,1, 20.0f);

    sim.addEmitter(emitter);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);        
        sim.draw(window);
        
        //test.draw(window);
        sim.update(1.0);
        window.display();
        sf::sleep(sf::seconds(0.1));
      
    }
    return 0;

}
