//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("agility training course");
    addAlias("training course");
    addAlias("agility course");

    addItemTemplate(
        "The agility training course is a series of obstacles—low hurdles, "
        "weaving posts, and balance beams—arranged to test speed and "
        "coordination. The ground is packed hard by the passage of many "
        "trainees. "
    );

    addNearDarkDescriptionTemplate(
        "the outline of an agility training course is barely visible, its "
        "obstacles lost in the gloom"
    );
    addLowLightDescriptionTemplate(
        "an agility training course stretches into the shadows, its hurdles "
        "and posts just visible"
    );
    addDimLightDescriptionTemplate(
        "the agility training course is faintly illuminated, its obstacles "
        "apparent"
    );
    addSomeLightDescriptionTemplate(
        "the agility training course is clearly visible, its hurdles and "
        "beams standing out"
    );
    addAdjectives(({ "challenging", "outdoor", "obstacle", "military", "sprawling" }));
    addDescriptionTemplate("a ##Adjective## agility training course with hurdles and beams");
}
