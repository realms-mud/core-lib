//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

/////////////////////////////////////////////////////////////////////////////
void NorthernTrailConnectsForestOneToHrondil()
{
    object forest = load_object("/areas/tol-dhurath/forest-1/15x9.c");
    object forestTrail = load_object(
        "/areas/tol-dhurath/northern-trail/20x0.c");
    object hrondil = load_object(
        "/areas/northern-road/hrondil-approaches/24x4.c");
    object northernTrail = load_object(
        "/areas/tol-dhurath/northern-trail/0x4.c");

    ExpectEq("/areas/tol-dhurath/northern-trail/20x0.c",
        forest->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/tol-dhurath/forest-1/15x9.c",
        forestTrail->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/tol-dhurath/northern-trail/0x4.c",
        hrondil->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/hrondil-approaches/24x4.c",
        northernTrail->getExitDirections()["default"]["west"]);
}

/////////////////////////////////////////////////////////////////////////////
void NorthernRouteContinuesFromHrondilToMinlach()
{
    int x;
    string currentPath;
    string nextPath;
    object currentRoom;
    object nextRoom;
    object hrondil = load_object(
        "/areas/northern-road/hrondil-approaches/24x8.c");
    object lowerWilds = load_object(
        "/areas/northern-road/lower-northern-wilds/0x0.c");
    object lowerWildsExit = load_object(
        "/areas/northern-road/lower-northern-wilds/24x8.c");
    object upperWilds = load_object(
        "/areas/northern-road/upper-northern-wilds/0x0.c");
    object upperWildsExit = load_object(
        "/areas/northern-road/upper-northern-wilds/24x0.c");
    object minlachApproach = load_object(
        "/areas/northern-road/minlach-approaches/0x4.c");
    object minlachApproachExit = load_object(
        "/areas/northern-road/minlach-approaches/24x4.c");
    object minlach = load_object("/areas/minlach/1x0.c");

    ExpectEq("/areas/northern-road/lower-northern-wilds/0x0.c",
        hrondil->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/hrondil-approaches/24x8.c",
        lowerWilds->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/0x0.c",
        lowerWildsExit->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/northern-road/lower-northern-wilds/24x8.c",
        upperWilds->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/northern-road/minlach-approaches/0x4.c",
        upperWildsExit->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/upper-northern-wilds/24x0.c",
        minlachApproach->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/minlach/1x0.c",
        minlachApproachExit->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/northern-road/minlach-approaches/24x4.c",
        minlach->getExitDirections()["default"]["west"]);

    for (x = 0; x < 24; x++)
    {
        currentPath = sprintf(
            "/areas/northern-road/upper-northern-wilds/%dx0.c", x);
        nextPath = sprintf(
            "/areas/northern-road/upper-northern-wilds/%dx0.c", x + 1);
        currentRoom = load_object(currentPath);
        nextRoom = load_object(nextPath);

        ExpectEq(nextPath,
            currentRoom->getExitDirections()["default"]["east"]);
        ExpectEq(currentPath,
            nextRoom->getExitDirections()["default"]["west"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void NorthernTrailIsAConnectedLShapedRoute()
{
    object region = load_object("/areas/tol-dhurath/northern-trail/region.c");
    object forestEdge = load_object(
        "/areas/tol-dhurath/northern-trail/20x0.c");
    object northernTurn = load_object(
        "/areas/tol-dhurath/northern-trail/20x4.c");
    object westernEnd = load_object(
        "/areas/tol-dhurath/northern-trail/0x4.c");

    ExpectEq(25, region->xDimension());
    ExpectEq(10, region->yDimension());
    ExpectEq(5, region->regionLevel());
    ExpectEq("/areas/tol-dhurath/northern-trail/20x1.c",
        forestEdge->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/tol-dhurath/northern-trail/19x4.c",
        northernTurn->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/northern-road/hrondil-approaches/24x4.c",
        westernEnd->getExitDirections()["default"]["west"]);
}

/////////////////////////////////////////////////////////////////////////////
void MainTrailRoomsHaveReciprocalLinks()
{
    int x;
    int y;
    string currentPath;
    string nextPath;
    object currentRoom;
    object nextRoom;

    for (x = 0; x < 20; x++)
    {
        currentPath = sprintf(
            "/areas/tol-dhurath/northern-trail/%dx4.c", x);
        nextPath = sprintf(
            "/areas/tol-dhurath/northern-trail/%dx4.c", x + 1);
        currentRoom = load_object(currentPath);
        nextRoom = load_object(nextPath);

        ExpectEq(nextPath,
            currentRoom->getExitDirections()["default"]["east"]);
        ExpectEq(currentPath,
            nextRoom->getExitDirections()["default"]["west"]);
    }

    for (y = 0; y < 4; y++)
    {
        currentPath = sprintf(
            "/areas/tol-dhurath/northern-trail/20x%d.c", y);
        nextPath = sprintf(
            "/areas/tol-dhurath/northern-trail/20x%d.c", y + 1);
        currentRoom = load_object(currentPath);
        nextRoom = load_object(nextPath);

        ExpectEq(nextPath,
            currentRoom->getExitDirections()["default"]["north"]);
        ExpectEq(currentPath,
            nextRoom->getExitDirections()["default"]["south"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
void WaystationHermitAndOverlookAreReachableSideStops()
{
    object trail = load_object(
        "/areas/tol-dhurath/northern-trail/14x4.c");
    object waystation = load_object(
        "/areas/tol-dhurath/northern-trail/14x5.c");
    object cliffTrail = load_object(
        "/areas/tol-dhurath/northern-trail/6x4.c");
    object hermitCell = load_object(
        "/areas/tol-dhurath/northern-trail/6x5.c");
    object overlookTrail = load_object(
        "/areas/tol-dhurath/northern-trail/3x4.c");
    object overlook = load_object(
        "/areas/tol-dhurath/northern-trail/3x5.c");

    ExpectEq("/areas/tol-dhurath/northern-trail/14x5.c",
        trail->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/tol-dhurath/northern-trail/14x4.c",
        waystation->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/tol-dhurath/northern-trail/6x5.c",
        cliffTrail->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/tol-dhurath/northern-trail/6x4.c",
        hermitCell->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/tol-dhurath/northern-trail/3x5.c",
        overlookTrail->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/tol-dhurath/northern-trail/3x4.c",
        overlook->getExitDirections()["default"]["south"]);
}
