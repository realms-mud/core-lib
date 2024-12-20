//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("amethyst floor");
    suppressEntryMessage();

    addDescriptionTemplate("the floor is fashioned out of what "
        "appears to be solid amethyst");
    addSourceOfLight(10);

    addItemTemplate("The floor appears to be fashioned out of a single "
        "amethyst crystal of mammoth proportions. All along the course of "
        "the amethyst, it has been scored with intricate etchings, each "
        "giving off an ambient glow of a different color");
}
