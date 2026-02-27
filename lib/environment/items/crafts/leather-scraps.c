//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("leather scraps");
    addAlias("scraps");
    addAlias("hide trimmings");
    addAlias("offcuts");

    addAdjectives(({ "scattered", "various", "curling", "colored",
        "assorted", "piled", "thin", "thick", "trimmed", "mixed" }));

    addDescriptionTemplate("##Adjective## leather scraps scattered on the floor");

    addItemTemplate(
        "Scraps and offcuts of leather in various colors and thicknesses "
        "litter the work area. Curling strips, irregular pieces, and "
        "punched-out circles cover the floor and overflow from a bin. "
        "The scraps range from supple doeskin to stiff sole leather, "
        "each a remnant of some finished project."
    );

    addSomeLightDescriptionTemplate(
        "leather scraps of various colors litter the floor and overflow "
        "from a bin"
    );
    addDimLightDescriptionTemplate(
        "scraps of leather are scattered about the work area"
    );
    addLowLightDescriptionTemplate(
        "the floor is littered with something soft and irregular"
    );
    addNearDarkDescriptionTemplate(
        "the rich smell of worked leather pervades the area"
    );
}
