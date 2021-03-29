#include "classes.h"
#include <string>

using namespace std;
class Group {
    private:
        int id;
    public: // Access specifier
        Group(){
            id = 0;
        }
        Group(int a){
            id = a;
        }
        void setId(int a){
            id = a;
        }
        int getId(){
            return id;
        }
};

class Translate : public Group{
    private:
        float x,y,z;
    public:
        Translate(){ x = y = z = 0.0f;}
        Translate(float x, float y, float z){ setX(x); setY(y); setZ(z); }
        void setX(float a){ x = a; }
        void setY(float a){ y = a; }
        void setZ(float a){ z = a; }
        float getX(){ return x; }
        float getY(){ return y; }
        float getZ(){ return z; }
};

class Scale : public Group{
private:
    float x,y,z;
public:
    Scale(){ x = y = z = 0.0f;}
    Scale(float x, float y, float z){ setX(x); setY(y); setZ(z); }
    void setX(float a){ x = a; }
    void setY(float a){ y = a; }
    void setZ(float a){ z = a; }
    float getX(){ return x; }
    float getY(){ return y; }
    float getZ(){ return z; }
};

class Rotate : public Group{
private:
    float x,y,z,angle;
public:
    Rotate(){ x = y = z = angle =0.0f;}
    Rotate(float x, float y, float z, float angle){ setX(x); setY(y); setZ(z); setAngle(angle);}
    void setX(float a){ x = a; }
    void setY(float a){ y = a; }
    void setZ(float a){ z = a; }
    void setAngle(int a){ angle = a; }
    float getX(){ return x; }
    float getY(){ return y; }
    float getZ(){ return z; }
    float getAngle(){ return angle; }
};

class Model : public Group{
    private:
        string file;
    public:
        Model(){file = "";}
        Model(string file){ setFile(file); }
        void setFile(string a){ file = a; }
        string getFile(){ return file; }
};



