//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("saw horse");
    addAlias("sawhorse");
    addAlias("trestle");
    addAlias("cutting horse");

    addAdjectives(({ "wooden", "sturdy", "saw-scarred", "battered",
        "rough", "functional", "simple", "well-used", "splayed", "old" }));

    addDescriptionTemplate("a ##Adjective## saw horse standing in the work area");

    addItemTemplate(
        "The saw horse is a simple X-frame of sturdy timber, its top beam "
        "deeply scarred by saw cuts. Sawdust fills the joints, and the "
        "splayed legs are solid despite years of heavy use. A few wood "
        "shavings curl around its base."
    );

    addSomeLightDescriptionTemplate(
        "a saw horse stands in the work area, its top deeply scarred"
    );
    addDimLightDescriptionTemplate(
        "an X-shaped wooden frame suggests a saw horse"
    );
    addLowLightDescriptionTemplate(
        "a low wooden frame is visible in the work area"
    );
    addNearDarkDescriptionTemplate(
        "a wooden frame of some kind stands in the darkness"
    );
}
