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

# Colored text: printRGBColored()

Overloaded function will draw a string or a character in your terminal based on the input RGB value.

# moveCursor()

Takes a row argument and optional column and clear_line arguments to place the cursor in the terminal. Default column=1, default clear_line=true.

# clearLine()

Clears the terminal line on which the cursor is currently positioned.

# printProgressBar()

* int bar_len         | determines the total bar length in your terminal. + 2 if you include the characters for the side.
* double progress     | part of determining how full the bar needs to be drawn
* double finish       | part of determining how full the bar needs to be drawn
* bool is_complete    | tells the function that the bar needs to be drawn as complete. Optional.
* bool do_color       | tells the function that the bar needs to be drawn in the red to green gradient. Optional.
* char sides = '<'    | formatting option. Character for either side of the bar. Optional.
* char fill = '#'     | formatting option. Character to print for the filled part of the bar. Optional.
* char empty = ' '    | formatting option. Character to print for the empty part of the bar. Optional.
* char half = ':'     | formatting option. Character to print for the half-filled part of the bar. Optional.


