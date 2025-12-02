//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pantry");
    addAlias("larder");
    addAlias("food cupboard");
    addAlias("storage pantry");

    addAdjectives(({ "wooden", "tall", "narrow", "sturdy", "plain", "shelved",
        "old", "well-built", "broad", "heavy" }));

    addDescriptionTemplate("a ##Adjective## pantry with shelves and a sturdy door");

    addItemTemplate(
        "This pantry is a tall, narrow cupboard fitted with shelves for storing "
        "food and supplies. The door is secured with a simple latch, and the wood "
        "shows the marks of long use. Inside, the shelves are deep enough to hold "
        "jars, sacks, and preserved goods."
    );

    addSomeLightDescriptionTemplate(
        "a wooden pantry stands in the corner, its shelves hidden behind a closed "
        "door"
    );
    addDimLightDescriptionTemplate(
        "a pantry is visible in the gloom, its outline tall and narrow"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a pantry can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a pantry is present, but details are lost in the "
        "darkness"
    );
}
