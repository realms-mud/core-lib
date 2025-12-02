//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rush strewn floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("rushes");
    addAlias("rush");
    addAlias("straw");

    addAdjectives(({ "covered with fresh green rushes",
        "strewn with dried reeds and grasses",
        "that rustles softly with each footstep",
        "with sweet herbs mixed among the rushes",
        "showing bare patches where the covering has worn thin",
        "that releases a pleasant grassy scent when disturbed",
        "with layers of old rushes beneath the fresh ones",
        "that feels springy and soft underfoot" }));

    addDescriptionTemplate("the floor is rush-strewn "
        "##Adjective##. The woven grasses provide cushioning "
        "and warmth over the hard surface beneath");
    addSomeLightDescriptionTemplate("the floor is rush-strewn "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be covered with "
        "dried grasses. They rustle softly underfoot");
    addLowLightDescriptionTemplate("the floor is strewn with rushes. "
        "The dried grasses create a soft, yielding surface");
    addDimLightDescriptionTemplate("the floor is covered with rush matting. "
        "The woven grasses show signs of regular replacement");

    addItemTemplate("The floor is strewn with rushes, long grasses and "
        "reeds that have been cut, dried, and spread to provide a soft "
        "covering over the hard surface beneath. The rushes are renewed "
        "regularly, with fresh layers added over old ones that gradually "
        "compress into a cushioning mat that absorbs moisture and provides "
        "both comfort and insulation.");
}
