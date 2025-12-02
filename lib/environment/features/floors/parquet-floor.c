//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("parquet floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("parquet");
    addAlias("wood");
    addAlias("wooden");

    addAdjectives(({ "with intricate geometric patterns in contrasting woods",
        "displaying masterful craftsmanship in miniature",
        "that gleams with layers of polish and care",
        "showing elaborate star and diamond motifs",
        "with alternating light and dark wood creating designs",
        "that reflects light from its mirror-like finish",
        "featuring borders of interlacing patterns",
        "with some sections showing slight warping or separation" }));

    addDescriptionTemplate("the floor is parquet "
        "##Adjective##. Small pieces of fine wood create "
        "elaborate patterns of remarkable beauty");
    addSomeLightDescriptionTemplate("the floor is parquet "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be made of "
        "fitted wood pieces. Patterns are suggested in the darkness");
    addLowLightDescriptionTemplate("the floor consists of wooden pieces "
        "arranged in patterns. The craftsmanship is evident even in dim light");
    addDimLightDescriptionTemplate("the floor is inlaid parquet. "
        "Elaborate wooden patterns show skilled artistry");

    addItemTemplate("The floor is an elaborate parquet of small wooden "
        "pieces cut with precision and fitted together to create intricate "
        "geometric patterns. Different wood types provide contrasting colors "
        "and grains, while the entire surface has been polished to a high "
        "gloss that reflects the sophisticated artistry of master craftsmen.");
}
