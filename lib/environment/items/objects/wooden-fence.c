//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wooden fence");
    addAlias("fence");
    addAlias("rail fence");
    addAlias("split-rail fence");

    addAdjectives(({ "wooden", "weathered", "crooked", "mossy", "old",
        "sturdy", "split-rail", "sagging", "patched", "rough-hewn" }));

    addDescriptionTemplate("a ##Adjective## fence marking a boundary");

    addItemTemplate(
        "The fence is made of split rails set between rough-hewn posts, "
        "its wood silvered by years of sun and rain. In places the rails "
        "sag or have been replaced with fresher timber, and moss grows "
        "thick on the shaded side of the posts."
    );

    addSomeLightDescriptionTemplate(
        "a wooden fence runs along the boundary, its rails silvered with age"
    );
    addDimLightDescriptionTemplate(
        "a fence line is visible, its posts and rails casting thin shadows"
    );
    addLowLightDescriptionTemplate(
        "the horizontal lines of a fence can barely be made out"
    );
    addNearDarkDescriptionTemplate(
        "something low and horizontal suggests a fence nearby"
    );
}
