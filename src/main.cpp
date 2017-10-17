//
//  main.cpp
//  createMultipleTextFile
//
//  Created by Benjamin BOITRELLE on 11/10/2017.
//  Copyright © 2017 Benjamin BOITRELLE. All rights reserved.
//


#include <stdio.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <map>
#include <utility>

void splitString(const std::string& inputString, char delimiterChar, std::vector<std::string>& outputVector)
{
  // To Split a string in function of a delimiter and save it in a vector.
  std::string::size_type i = 0;
  std::string::size_type j = inputString.find(delimiterChar);

  while (j != std::string::npos) {
    outputVector.push_back(inputString.substr(i, j-i));
    i = ++j;
    j = inputString.find(delimiterChar, j);
    if (j == std::string::npos) outputVector.push_back(inputString.substr(i, inputString.length()));
  }
}

static int COLUMN = 128;
static int THRESHOLD_POSITION = 0;

int main(int argc, const char * argv[]) {

  std::string myLine;
  std::vector<std::vector<double>> tmpLine;
  std::vector<std::map<double, double>> pixel;
  std::fstream myfile("scans.txt");
  std::vector<double> threshold;
  std::vector<double> response;

  // Opening text file to scan it and read it line by line
  while (std::getline(myfile, myLine)){
    std::vector<std::string> result;
    splitString(myLine, ' ', result);
    std::vector<double> resultDoubleFormat(result.size());
    std::transform(result.begin(), result.end(), resultDoubleFormat.begin(), [](const std::string& val)
        {
        return std::stod(val);
        });
    tmpLine.push_back(resultDoubleFormat);
  }

  int row(0), column(-1);
  for (auto iteratorPixel = 1; iteratorPixel < tmpLine.at(0).size(); iteratorPixel++){
    if ((iteratorPixel%COLUMN) != 0){
      column++;
    }
    else{
      column = 0;
      row++;
    }
    std::ofstream outputFile("output/pixel_scan_row" + std::to_string(row) + "_col" + std::to_string(column) + ".txt", std::ios::out);
    for (auto iteratorThreshold = 0; iteratorThreshold < tmpLine.size(); iteratorThreshold++){
      outputFile << tmpLine[iteratorThreshold][THRESHOLD_POSITION] << " " << tmpLine[iteratorThreshold][iteratorPixel] << std::endl;
    }
  }
  myfile.close();

  return 0;
}

