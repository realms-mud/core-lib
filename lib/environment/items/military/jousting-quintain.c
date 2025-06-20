//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("jousting quintain");
    addAlias("quintain");
    addAlias("jousting target");

    addAdjectives(({ "wooden", "rotating", "training", "mounted", "medieval" }));
    addDescriptionTemplate("a ##Adjective## jousting quintain with a shield and sandbag");

    addItemTemplate(
        "The jousting quintain is a wooden post with a rotating arm. One end "
        "bears a shield, while the other holds a sandbag. Riders aim to strike "
        "the shield and avoid the swinging counterweight."
    );

    addNearDarkDescriptionTemplate(
        "the outline of a jousting quintain is barely visible, its arm lost in "
        "the gloom"
    );
    addLowLightDescriptionTemplate(
        "a jousting quintain stands in the shadows, its shield and sandbag "
        "just visible"
    );
    addDimLightDescriptionTemplate(
        "the jousting quintain is faintly illuminated, its rotating arm and "
        "targets apparent"
    );
    addSomeLightDescriptionTemplate(
        "the jousting quintain is clearly visible, its shield and sandbag "
        "ready for practice"
    );
}
