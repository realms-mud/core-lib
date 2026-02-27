//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("merchant scales");
    addAlias("scales");
    addAlias("balance");
    addAlias("weighing scales");

    addAdjectives(({ "brass", "polished", "precise", "old", "well-used",
        "balanced", "ornate", "functional", "delicate", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## set of merchant scales on the counter");

    addItemTemplate(
        "The scales are a simple balance of polished brass, with two shallow "
        "pans suspended from a central beam by fine chains. A set of iron "
        "and brass weights sits in a velvet-lined box nearby, each stamped "
        "with an official mark. The pivot is well-oiled and responds to "
        "the lightest touch."
    );

    addSomeLightDescriptionTemplate(
        "a set of brass merchant scales gleams on the counter"
    );
    addDimLightDescriptionTemplate(
        "a pair of scales is visible on the counter, faintly glinting"
    );
    addLowLightDescriptionTemplate(
        "something metallic glints faintly on the counter"
    );
    addNearDarkDescriptionTemplate(
        "the faint clink of metal suggests scales or chains nearby"
    );
}
