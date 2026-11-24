//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("soot-smudged wall");
    addAlias("soot marks");
    addAlias("blackened stone");
    addAlias("torch soot");

    addAdjectives(({ "blackened", "soot-marked", "smudged", "dark" }));

    addDescriptionTemplate("a ##Adjective## patch on the limestone");
    addItemTemplate(
        "A row of black thumbprints stops at the narrowest part of the "
        "passage. Two charred torch ends lie in the grit below them. "
        "The soot does not continue beyond the bend, where even a small "
        "flame would throw light toward the den mouth."
    );

    addSomeLightDescriptionTemplate(
        "black soot and two charred torch ends at the constriction");
    addDimLightDescriptionTemplate(
        "a dark smudge on the limestone beside two burnt sticks");
    addLowLightDescriptionTemplate(
        "a black patch on the wall");
    addNearDarkDescriptionTemplate(
        "the smell of old soot near the narrowing");
}
