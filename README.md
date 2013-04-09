Crazy-Tanks-Game-OpenGL
=======================

HOW TO RUN THE GAME


This is a tanks game like pocket games written in OpenGL and C. To run this game install the latest version of codeblock and then the glut libraries and header files into the installed codeblocks. make a glut project and in the main file copy main.cpp and build it run the game. Enjoy :)...

INTRODUCTION


Crazy Tank is a artillery game developed in OpenGL platform. It is tank game in which you and your opponent are giving opportunity to shoot at each other and the one with the maximum hits wins. The basic theme of the game is to guess the correct power and angle which will lead you shot on opponent’s head. Tank is controlled with keyboard. The idea behind the project is to explore the various features of OpenGL.


OVERVIEW


The project includes a few features of a real tank. To explore OpenGL keyboard functions have been used. The arrow keys are used to move one player while the other one is moved using the alphabet keys. With this objective, we decided to apply physics to our tank shooting functionality. We also could just implement a straight line equation. We did not choose to do it with straight line equation because the ballistic equation represents reality better.
Borrowing from physics the equation of moving objects according to velocity and gravity, we implemented that along with other trigonometry needed to separate the one physics equation into 3 parts.


Ballistic Trajectory:
S = So + Vo * T – G * T * T / 2,
Where:
S = final position,
So = initial position,
Vo = initial velocity,
G = acceleration due to gravity, and
T = time.
Trigonometry used:
Y = sin(angle_v) * Vo,
r = cos(angle_v) * Vo,
X = r * cos(angle_h),
Z = r * sin(angle_h)


After we understand the equation, we have to implement it into our code. As the tank moves and changes the angle of the barrel, the variables of the equation also have to change. The effect of the variable change must represent an approximation to the real world shooting.
We only considered gravity as the variable most important in calculating a realistic ballistics trajectory. We could have implemented air resistance, friction, or magnetic fields to try to approximate real bullet motion but it would result in much more calculations. We feel that for this game, gravity would be enough approximate real ballistics trajectories.


CONTROLS


Arrow keys - forwards and reverse movement of left tank
A- Move left tank’s gun anti-clockwise
D- Move left tank’s gun clockwise
W- Increase Power of Left Tank
S - Decrease Power of Left Tank
B – Shoot by left Tank
J,L - forwards and reverse movement of Right tank
U-Move Right tank’s gun anti-clockwise
O- Move Right tank’s gun clockwise
I- Increase Power of Right Tank
K - Decrease Power of Right Tank
N – Shoot by Right Tank
