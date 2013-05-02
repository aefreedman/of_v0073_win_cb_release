#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Screen.h"
#include <vector>
#include <iostream>
#include "ofMain.h"
#include "GameObject.h"
#include "Gravitator.h"
#include "Comet.h"
#include "Planet.h"
#include "Sun.h"
#include "BlackHole.h"
#include "Astronaut.h"
#include "Player.h"
#include "StrandedAstronaut.h"
#include "Decor.h"
#include "Shell.h"
#include "Solid.h"
#include "Nonsolid.h"
#include "GUI.h"
#include "GUIFadeIn.h"
#include "Message.h"
#include "LevelEditor.h"
#include "GUIOverlay.h"
#define nl '\n'
#define fps 60

class GameScreen : public Screen {
public:
    GameScreen();
    virtual ~GameScreen();

        void setup();
		void update();
		void draw();
		void renderSprites();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

		void addGravitator(ofVec2f pos, int r, int gR, int m);
		void addStrandedAstronaut(ofVec2f _pos, string _name);
		void camera();
		void reset();
		void loadSound();
		void drawGUI();
		ofVec2f getLocalPosition(ofVec2f global_pos);
		ofVec2f getGlobalPosition(ofVec2f local_pos);

        void exportLevel();
        void importLevel();
        void importLevel(int levelID);

        std::vector<Gravitator *> gravitator;
        std::vector<StrandedAstronaut *> strandedAstronaut;
        std::vector<GUI *> gui;
        Player player;
        int totalCrew;

        ofImage background;

        //HUD ASSETS
            ofImage O2frame;
            ofImage O2bar;
            ofImage map;

        ofxSpriteSheetRenderer * planetRenderer;
        ofxSpriteSheetRenderer * nautRenderer;
        bool CONTINUOUS_CAMERA;

        //enum name {UNNAMED, TUTORIAL_ONE, TUTORIAL_TWO, TUTORIAL_THREE};

        /// Level Editor
        string clickState;
        string levelState;
        string new_gravitator_type;
        ofVec2f NEW_PLANET_POS;
        ofVec2f NEW_COMET_POS;
        int NEW_PLANET_R;
        int NEW_PLANET_GR;
        int NEW_PLANET_M;
        int NEW_COMET_R;
        string new_astronaut_name;
        int levelID;

        ofVec3f camera_pos;
        ofVec3f camera_target;
        ofVec3f camera_independent_target;
        ofVec3f camera_target_save;

        int justPressed[100];
        int wasPressed[];
        GUIFadeIn fadeIn;
        bool ENABLE_EDITOR;

protected:
private:
        void drawLevelEditorGUI();
        void setCameraTarget(ofVec2f target);
        void moveCameraTarget(ofVec2f direction);
        void getState();
        void exportSessionData();
        void exit();

        int planet_base_m;
        int planet_mass_multiplier;

        bool USING_LEVEL_EDITOR;
        bool MOVE_CAMERA;
        bool CAMERA_SCALING;
        bool MAP_VIEW;
        bool WON_LEVEL;
        bool LEVEL_HAS_ASTRONAUTS;
        bool MOVE_MESSAGES;
        bool PAUSE;
        bool PLACING_SOMETHING;
        bool CAN_MOVE_CAM;
        bool AN_ASTRONAUT_DIED;
        bool FREEZE_PLAYER;

        ofSoundPlayer jupiterSound;
        ofSoundPlayer backgroundSound;

        ofVec2f player_start_pos;

        int iddqd;

        float camera_lerp_speed;
        float view_scale;
        float view_scale_target;
        float default_view_scale;
        float view_lerp_speed;
        float map_view_scale_target;
        float level_over_timer_start;
        float level_over_timer;

        ofVec3f topRightCorner;
        ofVec3f bottomRightCorner;
        ofVec3f bottomLeftCorner;
        ofVec3f topLeftCorner;

        /// Metrics
        std::vector<ofVec4f> metric_playerDeaths;
        std::vector<string> metric_playerDeaths_cause;
        //std::vector<int> metric_playerJetpackUses;
};

#endif // GAMESCREEN_H