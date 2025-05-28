//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("grand banquet hall");

    addAdjectives(({
        "grand hall with long wooden tables and ornate chandeliers hanging overhead",
        "spacious feasting chamber, the air rich with the aroma of food and spiced wine",
        "noble dining hall where polished silverware gleams in warm candlelight",
        "magnificent banquet space, its walls adorned with tapestries depicting hunts and feasts",
        "regal feasting hall, where minstrel galleries overlook tables arranged for celebrations",
        "impressive dining chamber with a massive hearth crackling at one end"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate("a shadowy hall where only the embers in the "
        "great hearth provide light, glinting occasionally off abandoned goblets "
        "and platters");

    addLowLightDescriptionTemplate("a dimly lit banquet hall, where candles "
        "flicker low in their holders, casting long shadows across tables that "
        "could seat hundreds");

    addDimLightDescriptionTemplate("a dimly-lit ##Adjective##, the light soft "
        "and golden from wall sconces and candelabras, reflecting off polished "
        "wood and metal");

    addSomeLightDescriptionTemplate("a well-illuminated ##Adjective##, where "
        "light dances off crystal goblets and the polished surfaces of serving "
        "platters");
}
