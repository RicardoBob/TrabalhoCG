#include "classes.h"
#include <string>

using namespace std;
Group :: Group(int a){ id = a; }
Group :: Group(){ id = 0; }
void Group :: setId(int a){ id = a; }
int Group :: getId(){ return id; }


Translate :: Translate(){ x = y = z = 0.0f;}
Translate :: Translate(float x, float y, float z){ setX(x); setY(y); setZ(z); }
void Translate :: setX(float a){ x = a; }
void Translate :: setY(float a){ y = a; }
void Translate :: setZ(float a){ z = a; }
float Translate :: getX(){ return x; }
float Translate :: getY(){ return y; }
float Translate :: getZ(){ return z; }


Scale ::Scale(){ x = y = z = 0.0f;}
Scale ::Scale(float x, float y, float z){ setX(x); setY(y); setZ(z); }
void Scale :: setX(float a){ x = a; }
void Scale :: setY(float a){ y = a; }
void Scale :: setZ(float a){ z = a; }
float Scale :: getX(){ return x; }
float Scale :: getY(){ return y; }
float Scale :: getZ(){ return z; }


Rotate :: Rotate(){ x = y = z = angle =0.0f;}
Rotate :: Rotate(float x, float y, float z, float angle){ setX(x); setY(y); setZ(z); setAngle(angle);}
void Rotate :: setX(float a){ x = a; }
void Rotate :: setY(float a){ y = a; }
void Rotate :: setZ(float a){ z = a; }
void Rotate :: setAngle(int a){ angle = a; }
float Rotate :: getX(){ return x; }
float Rotate :: getY(){ return y; }
float Rotate :: getZ(){ return z; }
float Rotate :: getAngle(){ return angle; }


Model :: Model(){file = "";}
Model :: Model(string file){ setFile(file); }
void Model :: setFile(string a){ file = a; }
string Model :: getFile(){ return file; }




