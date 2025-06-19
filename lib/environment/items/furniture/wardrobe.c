//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wardrobe");
    addAlias("clothes press");
    addAlias("wooden wardrobe");
    addAlias("armoire");

    addAdjectives(({ "tall", "wooden", "carved", "broad", "sturdy", "old",
        "panelled", "plain", "functional", "heavy" }));

    addDescriptionTemplate("a ##Adjective## wardrobe with double doors");

    addItemTemplate(
        "This wardrobe is a tall, broad cabinet with double doors and a "
        "spacious interior for hanging clothes. The wood is carved with simple "
        "designs, and the doors are fitted with iron handles."
    );

    addSomeLightDescriptionTemplate(
        "a wooden wardrobe stands against the wall, its doors closed"
    );
    addDimLightDescriptionTemplate(
        "a wardrobe is visible in the gloom, its outline tall and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a wardrobe can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a wardrobe is present, but details are lost in "
        "the darkness"
    );
}
