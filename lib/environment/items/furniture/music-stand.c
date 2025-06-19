//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("music stand");
    addAlias("stand");
    addAlias("sheet music stand");
    addAlias("wooden music stand");

    addAdjectives(({ "wooden", "upright", "carved", "plain", "old", "sturdy",
        "adjustable", "broad", "polished", "functional" }));

    addDescriptionTemplate("a ##Adjective## music stand for holding sheet music");

    addItemTemplate(
        "This music stand is made from wood, with a slanted top for holding "
        "sheet music or songbooks. The base is broad and stable, and the height "
        "can be adjusted."
    );

    addSomeLightDescriptionTemplate(
        "a wooden music stand stands near the wall, its top angled for reading"
    );
    addDimLightDescriptionTemplate(
        "a music stand is visible in the gloom, its outline upright and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a music stand can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a music stand is present, but details are lost "
        "in the darkness"
    );
}
