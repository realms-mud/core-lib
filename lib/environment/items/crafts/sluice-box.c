//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sluice box");
    addAlias("sluice");
    addAlias("wash box");
    addAlias("ore sluice");

    addAdjectives(({ "wooden", "long", "water-filled", "angled",
        "rough", "muddy", "well-used", "simple", "functional", "sturdy" }));

    addDescriptionTemplate("a ##Adjective## sluice box set in a running stream");

    addItemTemplate(
        "The sluice box is a long, narrow wooden trough set at an angle "
        "in the current of a diverted stream. Cross-ribs along its bottom "
        "trap heavy particles of ore and precious metal while water washes "
        "lighter debris away. The wood is perpetually wet and the ground "
        "around it is churned to mud."
    );

    addSomeLightDescriptionTemplate(
        "a sluice box channels water over its ribs, sediment collecting "
        "at the bottom"
    );
    addDimLightDescriptionTemplate(
        "a long wooden trough channels water, its surface rippling"
    );
    addLowLightDescriptionTemplate(
        "a long trough carries running water"
    );
    addNearDarkDescriptionTemplate(
        "the sound of running water through a wooden channel fills the air"
    );
}
