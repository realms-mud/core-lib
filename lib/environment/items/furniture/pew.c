//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pew");
    addAlias("bench");
    addAlias("wooden pew");
    addAlias("church bench");

    addAdjectives(({ "wooden", "long", "plain", "old", "sturdy", "broad",
        "carved", "high-backed", "worn", "simple" }));

    addDescriptionTemplate("a ##Adjective## pew set along the wall");

    addItemTemplate(
        "This pew is a long, high-backed bench made from sturdy wood. The seat "
        "is broad and the back is upright, designed for use in a chapel or hall."
    );

    addSomeLightDescriptionTemplate(
        "a wooden pew stands along the wall, its surface worn by use"
    );
    addDimLightDescriptionTemplate(
        "a pew is visible in the gloom, its outline long and upright"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a pew can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a pew is present, but details are lost in "
        "the darkness"
    );
}
