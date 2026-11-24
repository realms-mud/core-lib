//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("counterweight assembly");
    addAlias("counterweight machine");
    addAlias("gear assembly");
    addAlias("gears");

    addAdjectives(({ "massive", "iron", "oiled", "balanced" }));

    addDescriptionTemplate("a ##Adjective## counterweight assembly");
    addItemTemplate(
        "A stack of iron gears transfers the pull of a hidden chain to "
        "the stone door above. The teeth are dark with oil, but the "
        "counterweights move freely. A small retaining pin at the rear "
        "keeps the drive gear engaged."
    );

    addSomeLightDescriptionTemplate(
        "an iron gear train with a retaining pin at the back");
    addDimLightDescriptionTemplate(
        "a heavy assembly of gears and counterweights");
    addLowLightDescriptionTemplate(
        "the dark outline of a geared machine");
    addNearDarkDescriptionTemplate(
        "a mass of iron shapes against the wall");
}
