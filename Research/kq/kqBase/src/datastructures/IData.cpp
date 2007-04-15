#include "IData.h"

using namespace kq::base::datastructures;

IData::~IData(){
	cleanup();
}

void IData::cleanup(){
}