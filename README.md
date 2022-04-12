# Spirit Intruders

"You are a ghost hunter fending off waves of paranormal entities. Just another day on the job."

This is a shoot'em up game clone that I am developing to practice my skills in C++ and the Simple and Fast Multimedia Library (SFML).
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
Arrow keys to move player and menu option selector around, left arrow or right arrow to lower and raise volume (Settings state), Enter to select an option, and 'S' key to shoot.


## Developer Notes
I won't be adding or changing any functionality/assets to this project as I've implemented everything I had in mind. Overall, this was a fun and simple project.
I decided not to use smart pointers, but I recommend their use to any developer that sees this. I just chose not to use them because of reasons. The most tedious 
part of development was searching for audio that would fit with the overall theme of the game. Not sure if I will develop another game clone for now. 
If I do, you'll see it in my repositories. Hope you liked this little project and good luck developing. :) 


## Assets
All sprites were made using [Krita](https://krita.org/en/). 
Audio files were acquired from [OpenGameArt.org](https://opengameart.org/), [Freesound.org](https://freesound.org/), and [mixkit.co](https://mixkit.co/free-sound-effects/game/).
Red Hot Chili font acquired from [dafont.com](https://www.dafont.com/) and created by Linafis Studio.
