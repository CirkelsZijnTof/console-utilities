# console utilities

A simple console utility (tested on VSCode windows 11, using ucrt64) to draw various things on a terminal.
The console utilities class contains all necessary functions and libraries to work as intended.

Features include:
* Colored text
* Position cursor (row, column, clear line)
* Clear line (row)
* Progress bar (fully white)
* Progress bar (red to green as it approaches 100% filled)
* Pause

# Use recommendations

In the case of looped redrawings, there may be unsightly flickering in the terminal. To prevent this, use pause(0.05).

It is recommended to add a 0.05 second pause between callings of this function to prevent flickering. 

# Colored text



# 



