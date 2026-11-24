//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sighting tube");
    addAlias("periscope tube");
    addAlias("viewing tube");
    addAlias("tube");

    addAdjectives(({ "brass", "narrow", "polished", "dusty" }));

    addDescriptionTemplate("a ##Adjective## tube set through the stone");
    addItemTemplate(
        "The brass tube angles up through a narrow shaft toward the Hall "
        "of Justice. A small angled mirror at its lower end catches the "
        "light from above, allowing someone here to check the mural room "
        "before opening the stair."
    );

    addSomeLightDescriptionTemplate(
        "a brass sighting tube aimed toward the Hall of Justice");
    addDimLightDescriptionTemplate(
        "a narrow metal tube set into the ceiling");
    addLowLightDescriptionTemplate(
        "a dull brass glint above the mechanism");
    addNearDarkDescriptionTemplate(
        "a small circular opening in the ceiling");
}
