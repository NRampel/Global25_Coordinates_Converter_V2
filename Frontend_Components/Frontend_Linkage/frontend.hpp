#ifndef FRONTEND_H
#define FRONTEND_H 


#include "../../G25_Components/G25_Math/g25_math.h"
#include <iostream>
#include <vector> 

void convertToUnscaled(const std::string& sampleName, const std::vector<float>& coords); 
void convertToScaled(const std::string& sampleName, const std::vector<float>& coords); 



#endif 