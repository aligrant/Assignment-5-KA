/* Intro
Emily is tired of rabbits eating her lettuce plants in her backyard. She is thinking of designing a ballistic Nerf dart rabbit
deterrent system, to be placed in the centre of her back lawn, which can be considered as (0,0). As part of the design
phase, over a 24-hour period starting at midnight, she recorded the time a rabbit was spotted and the (x,y) coordinates in
meters of the rabbit, saving them to a file called wascally_wabbits.txt. She wants to know the distance and heading
(an angle from -180 to 180 degrees, where 0 degrees is along the positive x-axis) of each rabbit, and the shortest time in
minutes between rabbit sightings.
*/

/* File Format
wascally_wabbits.txt contains an unknown number of lines. Each line contains three values: a time, an x
coordinate, and a y coordinate.
? The time is an integer in an HHMM format on a 24 hour clock. For example, 1450 represents the time 2:50 pm.
? The x and y coordinates are relative to a point at the centre of the lawn (0,0).
? File data can be assumed to be valid coordinates, which will not include the point (0,0)
*/

/* The program:
Write a function that:
? Receives a time as an integer in HHMM format (eg. 0350)
? Returns the time in minutes from midnight (eg. 230)
Write a function that:
? Receives a location x and y in m
? Returns the distance to that location in m
Write a function that:
? Receives a location x and y in m
? Returns the heading in degrees, between -180 and 180
Write a program that:
? Opens the file wascally_wabbits.txt and checks if it has opened
? Opens an output file to store the results
? Reads the data on each rabbit, and outputs to the file the distance and heading to each rabbit
? Outputs to the file the shortest time, in minutes, between rabbits
? Closes the files
*/

