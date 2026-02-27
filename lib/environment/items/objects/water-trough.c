//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("water trough");
    addAlias("trough");
    addAlias("horse trough");
    addAlias("stone trough");

    addAdjectives(({ "stone", "long", "mossy", "weathered", "brimming",
        "half-full", "algae-streaked", "cool", "old", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## water trough for livestock");

    addItemTemplate(
        "This long trough is hewn from a single block of stone, its interior "
        "darkened by years of standing water. A thin film of algae clings to "
        "the waterline, and the ground around its base is perpetually muddy "
        "from the splashing of thirsty animals."
    );

    addSomeLightDescriptionTemplate(
        "a stone water trough sits by the road, its surface rippling faintly"
    );
    addDimLightDescriptionTemplate(
        "a long stone trough is visible, the water within dark and still"
    );
    addLowLightDescriptionTemplate(
        "a low stone shape suggests a trough, water faintly gleaming"
    );
    addNearDarkDescriptionTemplate(
        "the faint sound of dripping water hints at a trough nearby"
    );
}
