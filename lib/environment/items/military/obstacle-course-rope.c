//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("obstacle course rope");
    addAlias("rope");
    addAlias("training rope");

    addAdjectives(({ "thick", "hanging", "knotted", "training", "swaying" }));
    addDescriptionTemplate("a ##Adjective## rope suspended for climbing in the course");

    addItemTemplate(
        "A thick rope is suspended between two posts, its surface rough and "
        "frayed from use. It sways slightly in the breeze, challenging "
        "trainees to cross hand-over-hand."
    );

    addNearDarkDescriptionTemplate(
        "the outline of an obstacle course rope is barely visible, its length "
        "lost in the gloom"
    );
    addLowLightDescriptionTemplate(
        "an obstacle course rope hangs in the shadows, its frayed surface just "
        "visible"
    );
    addDimLightDescriptionTemplate(
        "the obstacle course rope is faintly illuminated, its length and "
        "texture apparent"
    );
    addSomeLightDescriptionTemplate(
        "the obstacle course rope is clearly visible, swaying gently in the "
        "breeze"
    );
    addDescriptionTemplate(
        "sunlight shines on the obstacle course rope, making every twist and "
        "fiber stand out"
    );
}
