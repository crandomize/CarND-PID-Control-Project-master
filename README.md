# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Introduction
The purpose of this project is to program a PID Controller and tune the parameters(gains) as described in the lessons.  A simulator is provided to see the effects of changing and tuning these parameters.

The PID controller must be able to control the steering of the car having as input the cross-track error (CTE) provided by the emulator.

## Effect of P,I,D components in implementation
The combination of these parameters are responsable of the behaviour of the car.  All three parameters interact and are dependent so is needed different iterations to find out the most optimal combination of the parameter values.  A good understanding of how each of these parameters affect car's behaviour indepedently is essential to find the final proper balance.

### P - Proportional parameter
The parameter 'P' (proportional) is probably the most important during the initial tuning as the final effect is highly visible.  It defines the steering wheel angle proportional to the distance to the center lane.  This distance is called the cross-track error and is the main input for the controller.  The bigger this 'P' parameter is the bigger the angle towards the center lane will be.  Big values will make the car to steer to much to the center creating big oscillations.

These oscillations can be corrected with the next parameter, the D or differential parameter.

### D - Derivative parameter

This parameter acts as the resistance for the car to change its steering orientation.  Big speeds towards the center line will make the derivative factor to counter steer trying to smooth the changes.  This may avoid some overshooting caused the P controller.
The different values tested were more or less having a relative little effect at least compared with the 'P' parameter.

### I - Integral parameter

As cars may tend to be biased, due to many enviromental and mechanical factors (i.e. wind, wheel misalignments, etc), we need to crrect this bias by introducing a term which will be proportional to the accumulated cross track error.  For this simulator case, the better results are with very small I values, presumably due to the lack of  external factors taking into account in the simulation.

# Final P,I,D parameters

The final values for the implementation were:

* P = 0.12
* D = 1.2
* I = 0.0008

With this values the car was able to complete a lap in the circuit without any issue.


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
