//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("display case");
    addAlias("case");
    addAlias("glass case");
    addAlias("wooden display case");

    addAdjectives(({ "ornate", "wooden", "glass-topped", "broad",
        "carved", "polished", "sturdy", "old", "decorative" }));

    addDescriptionTemplate("a ##Adjective## display case with a glass top");

    addItemTemplate(
        "This display case is built from dark wood, its top set with "
        "a thick pane of glass. The interior is lined with velvet, perfect for "
        "showcasing jewelry, relics, or other valuables."
    );

    addSomeLightDescriptionTemplate(
        "a glass-topped display case stands in the room, its contents visible "
        "beneath the glass"
    );
    addDimLightDescriptionTemplate(
        "a display case is visible in the gloom, its glass top reflecting "
        "faint light"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a display case can be made out, little more than a "
        "shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a display case is present, but details are "
        "lost in the darkness"
    );
}
