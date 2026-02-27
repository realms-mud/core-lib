//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mill wheel");
    addAlias("water wheel");
    addAlias("mill paddle wheel");

    addAdjectives(({ "massive", "wooden", "creaking", "moss-covered",
        "turning", "dripping", "ancient", "iron-banded", "slow", "heavy" }));

    addDescriptionTemplate("a ##Adjective## mill wheel turned by flowing water");

    addItemTemplate(
        "The mill wheel is a great wooden wheel with broad paddles, set "
        "in the mill race where flowing water pushes it in a slow, "
        "relentless rotation. The wood is darkened with water and furred "
        "with moss, and the iron bands that hold it together are red with "
        "rust. Its axle groans with each revolution."
    );

    addSomeLightDescriptionTemplate(
        "a great mill wheel turns slowly in the water, dripping and creaking"
    );
    addDimLightDescriptionTemplate(
        "a large wheel turns in the water, its paddles catching faint light"
    );
    addLowLightDescriptionTemplate(
        "a large turning shape is visible near the water"
    );
    addNearDarkDescriptionTemplate(
        "the creak of wood and splash of water suggest a mill wheel turning"
    );
}
