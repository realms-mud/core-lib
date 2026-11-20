//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("farm tally board");
    addAlias("tally board");
    addAlias("grain tally");
    addDescriptionTemplate(
        "a split tally board marked with wagon counts");
    addItemTemplate(
        "Notches are grouped in fours beside rough cart marks. "
        "A newer set has been crossed out, and a three-pronged branch "
        "has been burned into one edge.");
    addNearDarkDescriptionTemplate("a flat shape against the stone");
    addLowLightDescriptionTemplate("a marked board beside a crate");
    addDimLightDescriptionTemplate("a tally board with crossed-out marks");
    addSomeLightDescriptionTemplate(
        "a split board marked with wagon tallies");
}
