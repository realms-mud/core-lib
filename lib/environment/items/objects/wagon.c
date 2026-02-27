//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wagon");
    addAlias("farm wagon");
    addAlias("horse cart");
    addAlias("ox cart");

    addAdjectives(({ "wooden", "heavy", "iron-rimmed", "weathered",
        "creaking", "large", "sturdy", "mud-spattered", "battered",
        "well-worn" }));

    addDescriptionTemplate("a ##Adjective## wagon parked by the road");

    addItemTemplate(
        "The wagon is a heavy four-wheeled affair with iron-rimmed wheels "
        "and a bed of thick oak planks. Its sides are built up with "
        "removable slat boards, and the whole thing is scarred and "
        "mud-spattered from years of hard service on country roads. "
        "The tongue rests on the ground, unhitched."
    );

    addSomeLightDescriptionTemplate(
        "a heavy wagon is parked nearby, its bed empty and tongue resting "
        "on the ground"
    );
    addDimLightDescriptionTemplate(
        "a large wagon is visible, its bulk casting a broad shadow"
    );
    addLowLightDescriptionTemplate(
        "a large shape with wheels suggests a parked wagon"
    );
    addNearDarkDescriptionTemplate(
        "something large and wheeled looms in the darkness nearby"
    );
}
