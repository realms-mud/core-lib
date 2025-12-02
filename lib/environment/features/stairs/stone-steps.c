//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("stone");

    addAdjectives(({ "that have been worn smooth by weather and use",
        "carved from blocks of gray granite",
        "with edges chipped and weathered",
        "that are stained with moss and lichen",
        "showing deep depressions from countless feet",
        "with mortar crumbling between the blocks",
        "that gleam wetly in damp conditions",
        "hewn from local limestone" }));

    addDescriptionTemplate("stone steps ##Adjective## "
        "provide access between levels");
    addSomeLightDescriptionTemplate("stone steps ##Adjective## "
        "connect the different floors");
    addNearDarkDescriptionTemplate("rough stone steps can be felt "
        "in the darkness");
    addLowLightDescriptionTemplate("weathered stone steps "
        "with worn smooth surfaces");
    addDimLightDescriptionTemplate("stone steps ##Adjective## "
        "link the levels");
    addSourceOfLight(1);

    addItemTemplate("The stone steps are hewn from solid blocks, each "
        "piece carefully shaped and fitted to its neighbors. Years of "
        "weather and foot traffic have worn the surfaces smooth, creating "
        "shallow depressions in the center of each step. Moss and lichen "
        "have found purchase in the cracks between stones, adding touches "
        "of green to the weathered gray surface.");
}
