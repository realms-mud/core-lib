//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("obstacle course ditch");
    addAlias("ditch");
    addAlias("training ditch");

    addAdjectives(({ "wide", "muddy", "deep", "training", "challenging" }));
    addDescriptionTemplate("a ##Adjective## obstacle course ditch filled with mud");

    addItemTemplate(
        "The obstacle course ditch is a wide, shallow trench dug into the "
        "ground. Its sides are muddy and uneven, and footprints mark the "
        "bottom where trainees have leapt across."
    );

    addNearDarkDescriptionTemplate(
        "the outline of an obstacle course ditch is barely visible, its depth "
        "lost in the darkness"
    );
    addLowLightDescriptionTemplate(
        "an obstacle course ditch lies in the gloom, its muddy sides just "
        "visible"
    );
    addDimLightDescriptionTemplate(
        "the obstacle course ditch is faintly illuminated, its uneven bottom "
        "apparent"
    );
    addSomeLightDescriptionTemplate(
        "the obstacle course ditch is clearly visible, its muddy sides and "
        "footprints standing out"
    );
    addDescriptionTemplate(
        "sunlight shines on the obstacle course ditch, making every footprint "
        "and clump of mud stand out"
    );
}
