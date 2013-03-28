#ifndef COMET_H
#define COMET_H
#include "ofMain.h"
#include "Gravitator.h"

class Comet : public Gravitator
{
    public:
        Comet();
        Comet(ofVec2f _pos,int _r);

        void update();
        void draw();

        //vector <ofVec2f> pathPoints;

        ofVec2f destination;
        int currentDest;
        //ofVec2f pos;
        ofVec2f dir;
        float vel;

        virtual ~Comet();
    protected:
    private:
};

#endif // COMET_H