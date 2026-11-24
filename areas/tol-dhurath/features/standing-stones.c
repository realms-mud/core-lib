//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("standing stones");
    addAlias("stone ring");
    addDescriptionTemplate("a ring of old standing stones among the trees");
    addNearDarkDescriptionTemplate("dark silhouettes in a clearing");
    addLowLightDescriptionTemplate("a ring of stones at the edge of the trees");
    addDimLightDescriptionTemplate(
        "an incomplete ring of standing stones in a forest clearing");
    addSomeLightDescriptionTemplate(
        "a weathered ring of standing stones, with two fallen inward");
    addItemTemplate("Six stones remain upright and two have fallen inward. "
        "On the tallest, a shallow carving shows a forked path and a spring. "
        "The mark is older and rougher than the trail blazes nearby.");
}
