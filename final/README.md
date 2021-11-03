Source Code for v-group

controller.h - Controlling and scheduling of signal lights

signal.h - initialisationg of lights and initial priorities to lights

trafficinfo.h - vehicle traffic assumption taken to simulate traffic light system

For checking collisions, red-light violations and u-turns, disable the comments in main.cpp to get violation count in output.
To take different assumptions of vehicle traffic, change the the function "assume_traffic5" to desired traffic assumption, for example assume_traffic3 or assume_traffic8

Result from i-group simulation is stored in a file named in output_traffic.txt. This files is read and plotted to create a visual representation of traffic light system. After all time intervals are plotted, we used an online gif converter to show switching of lights as an animation/video.
