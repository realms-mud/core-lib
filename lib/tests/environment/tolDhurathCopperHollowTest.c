//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

/////////////////////////////////////////////////////////////////////////////
void CopperHollowIsLinkedFromForestFour()
{
    object forest = load_object("/areas/tol-dhurath/forest-4/14x7.c");
    object hollow = load_object("/areas/tol-dhurath/forest-4/copper-hollow.c");

    ExpectEq("/areas/tol-dhurath/forest-4/copper-hollow.c",
        forest->getExitDirections()["default"]["north"]);
    ExpectEq("/areas/tol-dhurath/forest-4/14x7.c",
        hollow->getExitDirections()["default"]["south"]);
}

/////////////////////////////////////////////////////////////////////////////
void ForestFourAndFiveTrailsAreReciprocal()
{
    object forestFour = load_object("/areas/tol-dhurath/forest-4/14x7.c");
    object forestFive = load_object("/areas/tol-dhurath/forest-5/14x8.c");

    ExpectEq("/areas/tol-dhurath/forest-5/14x8.c",
        forestFour->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/tol-dhurath/forest-4/14x7.c",
        forestFive->getExitDirections()["default"]["west"]);
}

/////////////////////////////////////////////////////////////////////////////
void SunkenChapelIsLinkedToTheForestFiveTrail()
{
    object trail = load_object("/areas/tol-dhurath/forest-5/14x7.c");
    object chapel = load_object(
        "/areas/tol-dhurath/forest-5/sunken-chapel.c");

    ExpectEq("/areas/tol-dhurath/forest-5/sunken-chapel.c",
        trail->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/tol-dhurath/forest-5/14x7.c",
        chapel->getExitDirections()["default"]["east"]);
}

/////////////////////////////////////////////////////////////////////////////
void ForestTwoLodgeAndForestThreeCampHaveAuthoredLocations()
{
    object lodgeApproach = load_object(
        "/areas/tol-dhurath/forest-2/15x7.c");
    object lodge = load_object(
        "/areas/tol-dhurath/forest-2/waykeeper-lodge.c");
    object camp = load_object("/areas/tol-dhurath/forest-3/20x5.c");

    ExpectEq("/areas/tol-dhurath/forest-2/waykeeper-lodge.c",
        lodgeApproach->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/tol-dhurath/forest-2/15x7.c",
        lodge->getExitDirections()["default"]["west"]);
    ExpectTrue(member(camp->getExitDirections()["default"], "north") >= 0);
    ExpectTrue(member(camp->getExitDirections()["default"], "west") >= 0);
}

/////////////////////////////////////////////////////////////////////////////
void ForestOneStandingStonesHaveAReciprocalApproach()
{
    object approach = load_object("/areas/tol-dhurath/forest-1/14x7.c");
    object stones = load_object("/areas/tol-dhurath/forest-1/14x6.c");

    ExpectEq("/areas/tol-dhurath/forest-1/14x6.c",
        approach->getExitDirections()["default"]["south"]);
    ExpectEq("/areas/tol-dhurath/forest-1/14x7.c",
        stones->getExitDirections()["default"]["north"]);
}

/////////////////////////////////////////////////////////////////////////////
void ForestTwoHuntingTowerHasAReciprocalApproach()
{
    object approach = load_object("/areas/tol-dhurath/forest-2/12x6.c");
    object tower = load_object(
        "/areas/tol-dhurath/forest-2/hunting-tower.c");

    ExpectEq("/areas/tol-dhurath/forest-2/hunting-tower.c",
        approach->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/tol-dhurath/forest-2/12x6.c",
        tower->getExitDirections()["default"]["east"]);
}
