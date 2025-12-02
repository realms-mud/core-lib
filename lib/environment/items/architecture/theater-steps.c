//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("theater steps");
    addAlias("stone steps");
    addAlias("stairways");
    addAlias("stairs");

    addAdjectives(({ "narrow", "worn", "stone", "ancient", "access" }));

    addDescriptionTemplate("##Adjective## stone stairways dividing the "
        "semicircular seating into wedge-shaped sections");
    addItemTemplate("The steps are worn smooth in the center from centuries "
        "of foot traffic, creating shallow depressions in the limestone. "
        "These access ways were designed to allow efficient movement of large "
        "audiences into and out of the performance space");

    addSomeLightDescriptionTemplate("narrow stone stairways between sections of seating");
    addDimLightDescriptionTemplate("what appear to be access stairs between seating sections");
    addLowLightDescriptionTemplate("vertical passages between blocks of seating");
    addNearDarkDescriptionTemplate("darker lines cutting through the seating areas");
}
