# createMultipleTextFile

createMultipleTextfile is a small C++ program used to split a huge text file into multiple subtext files.
This script is used for the files created with a pixel's response script.

## Philosophy

### INPUT

This script has been written for text file having the following structure
  * N lines corresponding to the number of thresholds used during the pixel's response study;
  * M column containing the threshold (first element) followed by the U\*V pixels'response of the sensor.
 
### OUTPUT

 The program creates U\*V files containing:
  * N lines for the different thresholds used;
  * 2 columns: the first one is the threshold and the second one the pixel's response at this threshold.

## Compatibility

The few lines of code were written and compiled on macOS Sierra.

## TODO

* Test the code on Linux and Windows
* Make code more flexible for the output files created and the input file used
