# Spirit Intruders

Game clone that I am developing to practice my skills in C++ and the Simple and Fast Multimedia Library (SFML).
This is only a *possible* implementation, there are many different ways to implement the functionality seen here.


## Description
This game clone consists of 3 states: 
1. MainMenu state
   - The MainMenu state has only two options:
     - "Play": Causes the game to change to the Play state.
     - "Settings": Causes the game to change to the settings state.

2. Play state
   - Has the main functionality of the game. 
   - The only way to return to the MainMenu state is by losing all of your lives or closing the application.
   - The Settings state is inaccessible from this state.

3. Settings state.
   - You can increase/decrease the volume of the game or return to the MainMenu state.


## Controls
Arrow keys to move around, Enter to select an option, 'S' to shoot.


## Future Work
I've almost implemented everything I had in mind for this project. I will add a title to the MainMenu state so that it doesn't
look so empty, change the current images that are used for sprites, change the font, and possibly change the audio that is used. 
Once that is done, I will consider this a finished project. 


## Assets
All sprites were made using [Krita](https://krita.org/en/). 
Audio files were acquired from [OpenGameArt.org](https://opengameart.org/), [Freesound.org](https://freesound.org/), and [mixkit.co](https://mixkit.co/free-sound-effects/game/).
