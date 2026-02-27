//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mill hopper");
    addAlias("hopper");
    addAlias("grain hopper");
    addAlias("feed hopper");

    addAdjectives(({ "wooden", "funnel-shaped", "large", "grain-filled",
        "dusty", "vibrating", "suspended", "old", "sturdy", "heavy" }));

    addDescriptionTemplate("a ##Adjective## mill hopper suspended above the stones");

    addItemTemplate(
        "The hopper is a large wooden funnel suspended above the millstones "
        "by a timber frame. Grain is poured into the top and trickles down "
        "through a narrow gap onto the spinning stone below. A wooden shoe "
        "mechanism rattles against the stone, regulating the flow of grain "
        "with a steady tap-tap-tap."
    );

    addSomeLightDescriptionTemplate(
        "a wooden hopper is suspended above the millstones, grain trickling "
        "through"
    );
    addDimLightDescriptionTemplate(
        "a funnel-shaped wooden structure hangs above the grinding area"
    );
    addLowLightDescriptionTemplate(
        "a large wooden shape is suspended from the ceiling"
    );
    addNearDarkDescriptionTemplate(
        "a rhythmic tapping sound comes from overhead"
    );
}
