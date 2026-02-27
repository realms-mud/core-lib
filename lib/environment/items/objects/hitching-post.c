//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hitching post");
    addAlias("post");
    addAlias("hitching rail");
    addAlias("tying post");

    addAdjectives(({ "wooden", "sturdy", "worn", "notched", "weathered",
        "old", "gnarled", "scarred", "crooked", "solid" }));

    addDescriptionTemplate("a ##Adjective## hitching post for tying horses");

    addItemTemplate(
        "The hitching post is a stout length of timber sunk deep into the "
        "ground, its surface scarred with countless rope marks and the "
        "tooth-marks of impatient horses. An iron ring is bolted near the "
        "top, and scraps of old rope cling to its base."
    );

    addSomeLightDescriptionTemplate(
        "a sturdy hitching post stands by the road, its wood scarred by use"
    );
    addDimLightDescriptionTemplate(
        "a hitching post is visible, its dark shape rising from the ground"
    );
    addLowLightDescriptionTemplate(
        "a vertical shape suggests a post of some kind"
    );
    addNearDarkDescriptionTemplate(
        "a vague upright shape might be a hitching post"
    );
}
