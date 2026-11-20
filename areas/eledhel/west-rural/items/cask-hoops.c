//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cask hoops");
    addAlias("barrel hoops");
    addAlias("wooden hoops");
    addDescriptionTemplate("a stack of iron cask hoops");
    addItemTemplate(
        "The hoops are sorted by diameter and tied in bundles of four. "
        "A chalk mark on each bundle records which household supplied "
        "the wood for its casks.");
    addNearDarkDescriptionTemplate("a stack of metal rings");
    addLowLightDescriptionTemplate("several iron cask hoops");
    addDimLightDescriptionTemplate("bundles of iron hoops sorted by size");
    addSomeLightDescriptionTemplate(
        "iron hoops stacked beside the cooper's work space");
}
