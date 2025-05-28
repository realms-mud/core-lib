//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("theater seating");
    addAlias("benches");
    addAlias("stone seating");
    addAlias("tiers");
    addAlias("tiered seating");

    addAdjectives(({ "tiered", "stone", "semicircular", "ancient", "limestone" }));

    addDescriptionTemplate("##Adjective## rows of limestone benches arranged in a semicircular pattern");
    addItemTemplate("The lower rows, reserved for dignitaries, have carved backs and armrests, while the upper tiers are simpler in design");
    addItemTemplate("The stone has been worn smooth by centuries of use, showing subtle depressions where countless spectators once sat");

    addSomeLightDescriptionTemplate("tiers of stone benches rising in a semicircular pattern");
    addDimLightDescriptionTemplate("rows of seating, barely visible in the dim light");
    addLowLightDescriptionTemplate("the vague outline of tiered seating");
    addNearDarkDescriptionTemplate("the suggestion of tiered structures in the darkness");
}
