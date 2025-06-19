//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pulpit");
    addAlias("preaching stand");
    addAlias("wooden pulpit");
    addAlias("lectern");

    addAdjectives(({ "wooden", "carved", "tall", "ornate", "old", "broad",
        "panelled", "plain", "sturdy", "upright" }));

    addDescriptionTemplate("a ##Adjective## pulpit raised above the floor");

    addItemTemplate(
        "This pulpit is a tall, enclosed stand made from carved wood. The "
        "front is panelled and the top is broad enough to hold a book or notes. "
        "Steps lead up to the platform."
    );

    addSomeLightDescriptionTemplate(
        "a wooden pulpit stands at the front of the room, its platform raised"
    );
    addDimLightDescriptionTemplate(
        "a pulpit is visible in the gloom, its outline tall and upright"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a pulpit can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a pulpit is present, but details are lost in "
        "the darkness"
    );
}
