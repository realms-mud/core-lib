//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/investigationRoom.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addFeature("/areas/tol-dhurath/features/copper-seam.c", "east");
    addFeature("/lib/environment/features/water/creek.c", "south");
    addItem("/lib/environment/items/crafts/ore-cart.c", "west");
    addInvestigationClue("spring water",
        "/areas/minlach/quests/safe-seam.c", "inspectSpringWater",
        "The spring runs clear and at a steady level. It is not connected "
        "to the flooded lower gallery, but the old record should confirm "
        "how it was maintained.");
    addInvestigationClue("copper seam",
        "/areas/minlach/quests/safe-seam.c", "inspectCopperSeam",
        "The copper is a thin, discontinuous seam. The rock beyond it is "
        "barren; any extraction would be small and slow.");
    addInvestigationClue("roof supports",
        "/areas/minlach/quests/safe-seam.c", "inspectRoofSupports",
        "Several old props have shifted, but the main roof has not fallen. "
        "The safe approach is narrow, and the unstable gallery must remain "
        "closed.");

    addExit("south", "/areas/tol-dhurath/forest-4/14x7.c");
}
