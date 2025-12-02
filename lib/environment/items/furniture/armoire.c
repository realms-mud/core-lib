//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("armoire");
    addAlias("wardrobe");
    addAlias("wooden armoire");
    addAlias("clothes press");

    addAdjectives(({ "tall", "wooden", "carved", "ornate", "broad",
        "sturdy", "old", "polished", "heavy" }));

    addDescriptionTemplate("a ##Adjective## armoire with double doors");

    addItemTemplate(
        "This armoire is a tall, imposing piece of furniture with "
        "double doors and a spacious interior. The wood is carved with "
        "decorative motifs, and the doors are fitted with iron handles and "
        "hinges."
    );

    addSomeLightDescriptionTemplate(
        "a wooden armoire stands against the wall, its double doors closed"
    );
    addDimLightDescriptionTemplate(
        "an armoire is visible in the gloom, its outline tall and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of an armoire can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests an armoire is present, but details are lost in "
        "the darkness"
    );
}
