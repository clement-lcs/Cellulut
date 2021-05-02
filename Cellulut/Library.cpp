#include "main.h"

Library* Library::singleton = new Library;

vector<Model*>* Library::getListModels(){return listModels;}
