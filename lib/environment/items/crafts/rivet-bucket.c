//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rivet bucket");
    addAlias("rivets");
    addAlias("nail bucket");
    addAlias("fastener bucket");

    addAdjectives(({ "iron", "heavy", "clinking", "full", "well-stocked",
        "small", "battered", "old", "dented", "handy" }));

    addDescriptionTemplate("a ##Adjective## bucket of rivets near the workbench");

    addItemTemplate(
        "The bucket is a small iron pail filled with hundreds of iron "
        "rivets, nails, and fasteners of various sizes. They clink and "
        "shift when disturbed, and the bucket itself is battered from "
        "being kicked and moved around the workshop. A few rivets have "
        "spilled onto the floor."
    );

    addSomeLightDescriptionTemplate(
        "a bucket of iron rivets sits near the bench, bristling with "
        "fasteners"
    );
    addDimLightDescriptionTemplate(
        "a small bucket of metal objects sits near the workbench"
    );
    addLowLightDescriptionTemplate(
        "a small metal container sits near the bench"
    );
    addNearDarkDescriptionTemplate(
        "the clink of metal comes from a small container nearby"
    );
}
