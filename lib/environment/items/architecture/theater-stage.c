//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("theater stage");
    addAlias("stone stage");
    addAlias("platform");
    addAlias("performance area");

    addAdjectives(({ "elevated", "marble", "ancient", "stone", "central" }));

    addDescriptionTemplate("##Adjective## stone stage forming the focal point of the amphitheater");
    addItemTemplate("The stage floor is made of polished marble slabs, some "
        "cracked with age but still impressive. A decorative frieze runs "
        "along the front edge of the stage, depicting scenes from famous "
        "performances");

    addSomeLightDescriptionTemplate("a raised stone platform at the base of the semicircular seating");
    addDimLightDescriptionTemplate("the outline of a stage area at the center of the amphitheater");
    addLowLightDescriptionTemplate("what appears to be a performance platform");
    addNearDarkDescriptionTemplate("a slightly raised area, barely visible in the darkness");
}
