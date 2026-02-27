//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("iron cauldron");
    addAlias("cauldron");
    addAlias("cooking pot");
    addAlias("great pot");

    addAdjectives(({ "iron", "heavy", "blackened", "steaming", "massive",
        "three-legged", "soot-caked", "bubbling", "old", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## iron cauldron hanging over a fire");

    addItemTemplate(
        "The cauldron is a massive iron pot suspended from a swinging arm "
        "over a fire pit. Its three stubby legs allow it to stand freely "
        "when removed from the hook, and its sides are blackened by "
        "countless fires. The interior is stained from years of stews, "
        "soups, and broths, and a wooden ladle rests across the rim."
    );

    addSomeLightDescriptionTemplate(
        "a great iron cauldron hangs over a fire, its contents steaming"
    );
    addDimLightDescriptionTemplate(
        "a large iron pot hangs over a fire, steam rising from within"
    );
    addLowLightDescriptionTemplate(
        "a large dark shape hangs over a faint glow, steam rising"
    );
    addNearDarkDescriptionTemplate(
        "the smell of cooking and the sound of bubbling liquid fill the air"
    );
}
