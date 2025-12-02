//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("pet bed");
    addAlias("dog bed");
    addAlias("hound couch");
    addAlias("animal bed");

    addAdjectives(({ "straw-filled", "soft", "round", "worn", "old", "plain",
        "small", "padded", "low", "comfortable" }));

    addDescriptionTemplate("a ##Adjective## pet bed set near the hearth");

    addItemTemplate(
        "This pet bed is a round cushion or sack filled with straw or rags. "
        "The cover is worn and patched, but it offers a soft place for an "
        "animal to rest."
    );

    addSomeLightDescriptionTemplate(
        "a pet bed lies near the hearth, its surface soft and inviting"
    );
    addDimLightDescriptionTemplate(
        "a pet bed is visible in the gloom, its outline low and round"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a pet bed can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a pet bed is present, but details are lost in "
        "the darkness"
    );
}
