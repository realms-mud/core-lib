//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mill cellar ring");
    addAlias("iron ring");
    addAlias("hatch ring");
    addAlias("ring");
    addAdjectives(({ "iron", "small", "dusty", "half-hidden" }));
    addDescriptionTemplate("a ##Adjective## ring set into the mill floor");
    addNearDarkDescriptionTemplate("a dull loop near the floor");
    addLowLightDescriptionTemplate("a small iron ring in the flagstones");
    addDimLightDescriptionTemplate(
        "a ring set into the floor beside the turning gear");
    addSomeLightDescriptionTemplate(
        "a half-hidden iron ring under a drift of mill dust");
    addItemTemplate("The iron is worn bright where fingers have "
        "pulled it recently. It is not fixed to the mill machinery; "
        "the ring sits in a seam around a square stone beneath the "
        "millstone. The stone is too heavy to shift without it.");
}
