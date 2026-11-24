//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Battle of the Morannon mural");
    addAlias("battle mural");
    addAlias("Morannon mural");
    addAlias("mural");

    addAdjectives(({ "vast", "painted", "dark", "historic" }));

    addDescriptionTemplate("a ##Adjective## mural of the Battle of the Morannon");
    addItemTemplate(
        "The mural fills the stone wall with riders, standards, and a "
        "black line of defenders before the gate. The painted blocks at "
        "the lower edge do not quite meet; a faint vertical seam runs "
        "behind the fallen standard."
    );

    addSomeLightDescriptionTemplate(
        "the Battle of the Morannon mural, with a seam behind its lower edge");
    addDimLightDescriptionTemplate(
        "a broad battle mural covering the stone wall");
    addLowLightDescriptionTemplate(
        "the dark shapes of riders painted across the wall");
    addNearDarkDescriptionTemplate(
        "a broad, flat shape against the stone");
}
