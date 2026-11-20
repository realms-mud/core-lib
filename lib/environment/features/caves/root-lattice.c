//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("root lattice");
    addAlias("exposed roots");
    addDescriptionTemplate("a lattice of oak roots threaded through the roof");
    addItemTemplate(
        "The roots have followed a seam in the rock, spreading into a "
        "natural roof of living wood. Small tufts of dry grass and down "
        "mark a sheltered hollow beyond the narrow passage.");
    addNearDarkDescriptionTemplate("a low lattice of roots overhead");
    addLowLightDescriptionTemplate("oak roots woven through the stone");
    addDimLightDescriptionTemplate("a natural roof of roots and dark soil");
    addSomeLightDescriptionTemplate(
        "a thick lattice of oak roots holding the den roof together");
}
