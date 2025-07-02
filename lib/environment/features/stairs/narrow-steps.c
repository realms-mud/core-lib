//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("narrow steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("narrow");

    addAdjectives(({ "that force single-file passage",
        "cramped between confining walls",
        "with treads barely wide enough for a single foot",
        "that wind steeply in the confined space",
        "worn smooth by countless hurried passages",
        "with walls that seem to press inward",
        "designed for servants and quick access",
        "that echo with hollow footsteps" }));

    addDescriptionTemplate("narrow steps ##Adjective## "
        "provide cramped access between levels");
    addSomeLightDescriptionTemplate("narrow steps ##Adjective## "
        "connect floors in the confined space");
    addNearDarkDescriptionTemplate("a cramped stairway can be felt "
        "in the narrow passage");
    addLowLightDescriptionTemplate("narrow steps "
        "force careful movement in the tight space");
    addDimLightDescriptionTemplate("narrow steps ##Adjective## "
        "wind through the confined passage");

    addItemTemplate("The narrow steps are built for utility rather than "
        "comfort, squeezed into spaces where larger stairs would not fit. "
        "Each step is barely wide enough for a single person, and the "
        "confining walls force travelers to move carefully. The construction "
        "is simple but functional, designed to provide access where space "
        "is at a premium, often used by servants or for emergency passage.");
}
