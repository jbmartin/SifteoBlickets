/**
    File: main.cpp
    Purpose: Blicket detector for Sifteo Cubes 

    @author Jay B. Martin
    @version 0.1 16 Mar 2013
*/


#include <sifteo.h>
#include "assets.gen.h"
using namespace Sifteo;

// Number of cubes to deploy (N blickets + 1 blicket detector)
static const unsigned gNumCubes = 5;
Random gRandom;

// METADATA
static Metadata M = Metadata()
    .title("Blicket Tutorial")
    .package("blickets", "0.1")
    .icon(Icon)
    .cubeRange(gNumCubes);


AssetSlot gMainSlot = AssetSlot::allocate()
    .bootstrap(BootstrapAssets);

// GLOBALS

static VideoBuffer vbuf[CUBE_ALLOCATION]; // one video-buffer per cube
static CubeSet newCubes; // new cubes as a result of paint()
static CubeSet lostCubes; // lost cubes as a result of paint()
static CubeSet reconnectedCubes; // reconnected (lost->new) cubes as a result of paint()
static CubeSet dirtyCubes; // dirty cubes as a result of paint()
static CubeSet activeCubes; // cubes showing the active scene

static AssetLoader loader; // global asset loader (each cube will have symmetric assets)
static AssetConfiguration<1> config; // global asset configuration (will just hold the bootstrap group)

// Experiment Globals
static CubeSet blicketCubes;
static CubeSet nonBlicketCubes;

static CubeID blicketDetector = 0;
static CubeID blicket1 = 1;
static CubeID blicket2 = 3;
static CubeID nonBlicket1 = 2;
static CubeID nonBlicket2 = 4;

// Set of 7 experimental conditions (see Gopnik & Sobel (2000))
AssetImage conditions[] = {Set1IdenticalObjects, Set2SameColorDifferentShape,
                           Set3SameShapeDifferentColors, Set4DifferentColorsAndShapes,
                           Set5SameShapeConflictsOnColor, Set6SameColorConflictsOnShape,
                           Set7ConflictsOnShapeAndColor};

class Conditions {
    int condition;
    public:
        void set_condition(int);
        AssetImage get_condition();
        int get_condition_number();
        void next_condition();
        Conditions();
};

void Conditions::set_condition(int condition_) { condition = condition_; };
AssetImage Conditions::get_condition() { return conditions[condition]; };
int Conditions::get_condition_number() { return condition; };
// TODO(Jay): Make condtions after 0 randomly selected.
void Conditions::next_condition() { condition = (condition + 1) % 7; };
Conditions::Conditions(){ condition = 0; }

// Initialize conditions
Conditions cond;

// FUNCTIONS

static void playSfx(const AssetAudio& sfx) {
    static int i=0;
    AudioChannel(i).play(sfx);
    i = 1 - i;
}

static void stopSfx() {
    for (int i=0; i < 8; i++) {
        AudioChannel(i).stop();
    }
}

static Int2 getRestPosition(Side s) {
    // Look up the top-left pixel of the bar for the given side.
    // We use a switch so that the compiler can optimize this
    // however if feels is best.
    switch(s) {
      case TOP: return vec(64 - Bars[0].pixelWidth()/2, 0);
      case LEFT: return vec(0, 64 - Bars[1].pixelHeight()/2);
      case BOTTOM: return vec(64 - Bars[2].pixelWidth()/2, 128 - Bars[2].pixelHeight());
      case RIGHT: return vec(128 - Bars[3].pixelWidth(), 64 - Bars[3].pixelHeight()/2);
      default: return vec(0,0);
    }
}

static int barSpriteCount(CubeID cid) {
    // How many bars are showing on this cube?
    ASSERT(activeCubes.test(cid));
    int result = 0;
    for(int i=0; i < 4; ++i) {
        if (!vbuf[cid].sprites[i].isHidden()) {
            result++;
        }
    }
    return result;
}

static bool showSideBar(CubeID cid, Side s) {
    // If cid is not showing a bar on side s, show it and check if the
    // blicket detector shold go off.
    ASSERT(activeCubes.test(cid));
    if (vbuf[cid].sprites[s].isHidden()) {
        vbuf[cid].sprites[s].setImage(Bars[s]);
        vbuf[cid].sprites[s].move(getRestPosition(s));
        if (barSpriteCount(cid) == 1 && cid == 0) {
            vbuf[cid].bg0.image(vec(0,0), Backgrounds, 1);
        }
        else {
            vbuf[cid].bg0.image(vec(0,0), cond.get_condition(), cid - 1);
        }
        return true;
    } else {
        return false;
    }
}

static bool hideSideBar(CubeID cid, Side s) {
    // If cid is showing a bar on side s, hide it and check if the
    // blicket detector should turn off.
    ASSERT(activeCubes.test(cid));
    if (!vbuf[cid].sprites[s].isHidden()) {
        vbuf[cid].sprites[s].hide();
        if (barSpriteCount(cid) == 0 && cid == 0) {
            vbuf[cid].bg0.image(vec(0,0), Backgrounds, 0);
        }
        else {
            vbuf[cid].bg0.image(vec(0,0), cond.get_condition(), cid - 1);
        }
        return true;
    } else {
        return false;
    }
}

static void activateCube(CubeID cid) {
    // Mark cube as active and render its canvas
    //
    activeCubes.mark(cid);
    vbuf[cid].initMode(BG0_SPR_BG1);
    if (cid == 0) {
        vbuf[cid].bg0.image(vec(0,0), Backgrounds, 0);
    } else {
        vbuf[cid].bg0.image(vec(0,0), cond.get_condition(), cid - 1);
    }
    auto neighbors = vbuf[cid].physicalNeighbors();
    for(int side=0; side<4; ++side) {
        if (neighbors.hasNeighborAt(Side(side))) {
            showSideBar(cid, Side(side));
        } else {
            hideSideBar(cid, Side(side));
        }
    }
}

static void paintWrapper() {
    // Clear the palette
    newCubes.clear();
    lostCubes.clear();
    reconnectedCubes.clear();
    dirtyCubes.clear();

    // Fire events
    System::paint();

    // Dynamically load assets just-in-time
    if (!(newCubes | reconnectedCubes).empty()) {
        AudioTracker::pause();
        playSfx(SfxSong);
        loader.start(config);
        while(!loader.isComplete()) {
            for(CubeID cid : (newCubes | reconnectedCubes)) {
                vbuf[cid].bg0rom.hBargraph(
                    vec(0, 4), loader.cubeProgress(cid, 128), BG0ROMDrawable::ORANGE, 8
                );
            }
            // Fire events while we wait
            System::paint();
        }
        loader.finish();
        AudioTracker::resume();
    }

    // Repaint cubes
    for(CubeID cid : dirtyCubes) {
        activateCube(cid);
    }

    // Also, handle lost cubes, if you so desire :)
}

static void onCubeConnect(void* ctxt, unsigned cid) {
    // This cube is either new or reconnected
    if (lostCubes.test(cid)) {
        // This is a reconnected cube since it was already lost this paint()
        lostCubes.clear(cid);
        reconnectedCubes.mark(cid);
    } else {
        // This is a brand-spanking new cube
        newCubes.mark(cid);
    }
    // Begin showing some loading art (have to use BG0ROM since we don't have assets)
    dirtyCubes.mark(cid);
    auto& g = vbuf[cid];
    g.attach(cid);
    g.initMode(BG0_ROM);
    g.bg0rom.fill(vec(0, 0), vec(16, 16), BG0ROMDrawable::SOLID_BG);
    g.bg0rom.text(vec(1, 1), "Hold on!", BG0ROMDrawable::BLUE);
    g.bg0rom.text(vec(1, 14), "Adding Cube...", BG0ROMDrawable::BLUE);
}

static void onCubeDisconnect(void* ctxt, unsigned cid) {
    // Mark as lost and clear from other cube sets
    lostCubes.mark(cid);
    newCubes.clear(cid);
    reconnectedCubes.clear(cid);
    dirtyCubes.clear(cid);
    activeCubes.clear(cid);
}

static void onCubeRefresh(void* ctxt, unsigned cid) {
    // Mark this cube for a future repaint
    dirtyCubes.mark(cid);
}

static bool isActive(NeighborID nid) {
    // Does this nid indicate an active cube?
    return nid.isCube() && activeCubes.test(nid);
}

static void onNeighborAdd(void* ctxt, unsigned cube0, unsigned side0, unsigned cube1, unsigned side1) {
    // Update art on active cubes (not loading cubes or base)
    bool sfx = false;
    if (isActive(cube0) && cube0 == blicketDetector && blicketCubes.test(cube1)) {
        sfx |= showSideBar(cube1, Side(side1));
        sfx |= showSideBar(cube0, Side(side0));
    }
    if (isActive(cube1) && cube1 == blicketDetector && blicketCubes.test(cube0)) {
        sfx |= showSideBar(cube0, Side(side0));
        sfx |= showSideBar(cube1, Side(side1));
    }
    if (sfx) { playSfx(SfxSong); }
}

static void onNeighborRemove(void* ctxt, unsigned cube0, unsigned side0, unsigned cube1, unsigned side1) {
    // Update art on active cubes (not loading cubes or base)
    bool sfx = false;
    if (isActive(cube0) && cube0 == blicketDetector && blicketCubes.test(cube1)) {
        sfx |= hideSideBar(cube1, Side(side1));
        sfx |= hideSideBar(cube0, Side(side0));
    }
    if (isActive(cube1) && cube1 == blicketDetector && blicketCubes.test(cube0)) {
       sfx |= hideSideBar(cube1, Side(side1));
       sfx |= hideSideBar(cube0, Side(side0));
    }
    if (sfx) { playSfx(SfxDetach); }
    if (sfx) { stopSfx(); }
}

// Candidate function for interventions
static void onCubeTouch(void* ctxt, unsigned cid) {
    cond.next_condition();
    LOG("Condition %i\n", cond.get_condition_number());
    for(CubeID cid : CubeSet::connected()) {
        vbuf[cid].attach(cid);
        activateCube(cid);
    }
}

// When pressed, move to the next condition
void onTouch(void* ctxt, unsigned id) {
    CubeID cube(id);
    // On touchout (similar to mouseout)
    if (cube.isTouching() == 0) {
        cond.next_condition();
            LOG("Condition %i\n", cond.get_condition_number());
        for(CubeID cid : CubeSet::connected()) {
            vbuf[cid].attach(cid);
            activateCube(cid);
        }
    }
}

void main() {
    blicketCubes.mark(blicket1);
    blicketCubes.mark(blicket2);
    nonBlicketCubes.mark(nonBlicket1);
    nonBlicketCubes.mark(nonBlicket2);

    // Initialize asset configuration and loader
    config.append(gMainSlot, BootstrapAssets);
    loader.init();

    // Subscribe to events (See pubsub design pattern)
    Events::cubeConnect.set(onCubeConnect);
    Events::cubeDisconnect.set(onCubeDisconnect);
    Events::cubeRefresh.set(onCubeRefresh);
    Events::neighborAdd.set(onNeighborAdd);
    Events::neighborRemove.set(onNeighborRemove);
    // Events::cubeTouch.set(onCubeTouch);
    Events::cubeTouch.set(onTouch);

    // Initialize cubes
    for(CubeID cid : CubeSet::connected()) {
        vbuf[cid].attach(cid);
        activateCube(cid);
    }

    // Run loop
    for(;;) {
        paintWrapper();
    }
}
