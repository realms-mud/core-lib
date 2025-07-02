//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("packed earth floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("earth");
    addAlias("dirt");
    addAlias("ground");

    addAdjectives(({ "that has been trampled hard as stone",
        "with a dusty surface that stirs with movement",
        "showing deep ruts and impressions from heavy use",
        "mixed with straw and debris for reinforcement",
        "that feels cool and slightly damp underfoot",
        "with uneven patches where the soil has settled",
        "that releases a musty, earthy scent when disturbed",
        "worn smooth in some areas, rough in others" }));

    addDescriptionTemplate("the floor is packed earth "
        "##Adjective##. The compressed soil provides a basic "
        "but functional surface");
    addSomeLightDescriptionTemplate("the floor is packed earth "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be bare earth. "
        "It feels firm and compacted underfoot");
    addLowLightDescriptionTemplate("the floor consists of packed dirt. "
        "The surface appears well-trampled and hard");
    addDimLightDescriptionTemplate("the floor is compacted earth. "
        "The soil has been packed hard by years of use");

    addItemTemplate("The floor consists of earth that has been compressed "
        "through years of constant traffic into a surface nearly as hard "
        "as stone. Mixed with the soil are bits of straw, small stones, "
        "and organic debris that help bind the surface together, creating "
        "a functional if humble foundation that serves its purpose well.");
}
