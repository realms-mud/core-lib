//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("beehive");
    addAlias("hive");
    addAlias("bee skep");
    addAlias("straw hive");

    addAdjectives(({ "straw", "buzzing", "domed", "woven", "old",
        "weathered", "active", "cone-shaped", "wicker", "warm" }));

    addDescriptionTemplate("a ##Adjective## beehive humming with activity");

    addItemTemplate(
        "The beehive is a domed skep woven from coiled straw rope, set "
        "on a low wooden stand. Bees stream in and out of the narrow "
        "entrance at the base in a purposeful, endless procession. The "
        "hive hums with a deep, warm vibration, and the air around it "
        "is sweet with the scent of honey and beeswax."
    );

    addSomeLightDescriptionTemplate(
        "a straw beehive hums with activity, bees streaming in and out"
    );
    addDimLightDescriptionTemplate(
        "a domed straw shape hums faintly, bees barely visible around it"
    );
    addLowLightDescriptionTemplate(
        "a domed shape on a low stand hums with a low vibration"
    );
    addNearDarkDescriptionTemplate(
        "a low buzzing hum and the scent of honey suggest a beehive nearby"
    );
}
