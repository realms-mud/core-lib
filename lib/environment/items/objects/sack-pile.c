//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sack pile");
    addAlias("sacks");
    addAlias("grain sacks");
    addAlias("burlap sacks");

    addAdjectives(({ "bulging", "heavy", "burlap", "dusty", "stacked",
        "sagging", "rough", "flour-dusted", "lumpy", "tied" }));

    addDescriptionTemplate("a ##Adjective## pile of sacks stacked against a wall");

    addItemTemplate(
        "A heap of burlap sacks is stacked against the wall, each one "
        "bulging with grain, flour, or some other bulk commodity. The "
        "rough fabric is dusted with a fine powder, and the twine ties "
        "are knotted tight. A few mice have gnawed small holes in the "
        "bottom sacks."
    );

    addSomeLightDescriptionTemplate(
        "a pile of burlap sacks leans against the wall, dusty and full"
    );
    addDimLightDescriptionTemplate(
        "a heap of sacks is piled against the wall, their shapes lumpy"
    );
    addLowLightDescriptionTemplate(
        "a lumpy pile of something soft leans against the wall"
    );
    addNearDarkDescriptionTemplate(
        "the dusty scent of grain suggests sacks are stored nearby"
    );
}
