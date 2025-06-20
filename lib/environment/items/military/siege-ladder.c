//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("siege ladder");
    addAlias("ladder");
    addAlias("scaling ladder");

    addAdjectives(({ "tall", "wooden", "reinforced", "siege", "portable" }));
    addDescriptionTemplate("a ##Adjective## siege ladder with iron-bound rungs");

    addItemTemplate(
        "The siege ladder is a long, sturdy construction of wood, reinforced "
        "with iron bands. Its rungs are worn smooth by the passage of many "
        "boots, and the ends are notched to grip the top of a wall. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of a siege ladder is barely visible, its length lost in "
        "the darkness"
    );
    addLowLightDescriptionTemplate(
        "a siege ladder leans against the wall, its rungs just visible in the "
        "gloom"
    );
    addDimLightDescriptionTemplate(
        "the siege ladder is faintly illuminated, its wooden rungs and iron "
        "bands just visible"
    );
    addSomeLightDescriptionTemplate(
        "the siege ladder is clearly visible, its length and construction "
        "apparent"
    );
    addDescriptionTemplate(
        "sunlight shines on the siege ladder, making every notch and rung stand "
        "out"
    );
}
