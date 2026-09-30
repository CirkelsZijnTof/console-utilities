# console utilities

A simple console utility (tested on VSCode windows 11, using ucrt64) to draw various things on a terminal.
The console utilities class contains all necessary functions and libraries to work as intended.

Features include:
* Colored text, ANSI codes or RGB
* Position cursor (row, column, clear line)
* Clear line (row)
* Progress bar (fully white)
* Progress bar (red to green as it approaches 100% filled)
* Pause

# Use recommendations

In the case of looped redrawings, there may be unsightly flickering in the terminal. To prevent this, use pause(0.05) inside your loop. Be aware, this slows down the execution of your loop. If you have a large loop that takes a long time to execute, you may not need the pause() function to prevent flickering anymore.

# Colored text: textColored()

Overloaded function will draw a string of text in your terminal based on the standard ANSI codes or offers improved readability through a set of accepted strings 
that denote the desired color.

# 



