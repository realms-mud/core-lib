//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tannery interior");

    addItemTemplate(
        "The tannery is a rough, workmanlike space with a sharp, acrid smell "
        "that pervades everything. Wooden frames hold stretched hides in "
        "various stages of curing, and stone vats of tanning solution line "
        "one wall. A heavy worktable is covered with cutting tools, awls, "
        "and coils of waxed thread. Finished goods - belts, satchels, and "
        "pieces of boiled leather armor - hang from pegs near the entrance. "
        "The floor is stained dark from years of spilled dye, and bundles of "
        "bark for tannin are stacked in a corner."
    );

    addNearDarkDescriptionTemplate(
        "the tannery is nearly pitch black, its sharp chemical smell the "
        "only sure sign of where you stand"
    );
    addLowLightDescriptionTemplate(
        "the tannery is barely visible, the stretched hides on their frames "
        "looking like pale, ghostly shapes in the dark"
    );
    addDimLightDescriptionTemplate(
        "enough light reaches into the tannery to reveal the frames of "
        "stretched hides and the worktable laden with tools"
    );
    addSomeLightDescriptionTemplate(
        "the tannery is well-lit enough to see the finished leather goods "
        "hanging near the entrance and the vats along the wall"
    );
    addDescriptionTemplate(
        "light illuminates the tannery, showing the stretched hides in "
        "their frames and the orderly arrangement of leatherworking tools"
    );
}
