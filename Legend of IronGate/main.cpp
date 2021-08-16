#include "world.h"
int main() {
    //Creating game window
    World world;
    
    
    //variable that keeps game loop running
    bool play = true;
    //Game Loop
    while (play == true)
    {
        
        //Events
        
        world.Events();
            
            
        
        //LOGIC-----------------------------------------------------------------------------------------------------
        
        //std::cout << "SpriteVector is..." << eContainer.SpriteVector.size() << "\n";
        
        //Player Movements
        
        
        
        //Physics.AddObjects(lContainer, eContainer, enemyContainer, player, textures, sounds);
        //Physics.RemoveObjects(lContainer, eContainer, enemyContainer, player, textures);
        //Physics.Updates(lContainer, eContainer, enemyContainer, player, textures);
        
        //player.Animations();
        //player.Movements(leftPressed, rightPressed, lContainer, spacePressed);
        //RENDERING
        world.Rendering();
    }
    
    //Clean Up
    world.renderWindow.close();
    return 0;

}
