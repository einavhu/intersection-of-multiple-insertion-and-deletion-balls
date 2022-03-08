//
// Created by User on 3/8/2022.
//

#ifndef INTERSECTION_RUNS_VS_ALTERNATE_H
#define INTERSECTION_RUNS_VS_ALTERNATE_H

#include "helper.h"
#include "CommonSequences.h"
#include <fstream>
#include <time.h>
#include <sstream>

void alternating_intersection(vector<string> supers, vector<string> subs, ofstream& doc);
void runs_intersection(vector<string> supers, vector<string> subs, ofstream& doc);
void compare(vector<string> supers, vector<string> subs, ofstream& doc);


#endif //INTERSECTION_RUNS_VS_ALTERNATE_H
