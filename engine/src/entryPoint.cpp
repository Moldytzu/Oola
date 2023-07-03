#include <iostream>
#include <oola.h>

int main()
{
    Oola::EarlyStart(); // function defined in the game ran before everything
    
    // init engine
    std::cout << "Oola " << OOLA_VERSION << std::endl;
    
    // call game start function
    Oola::Start();

    while(true)
    {
        Oola::Tick();
    }
}