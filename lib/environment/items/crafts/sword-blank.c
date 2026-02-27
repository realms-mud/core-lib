//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sword blank");
    addAlias("blade blank");
    addAlias("unfinished blade");
    addAlias("rough blade");

    addAdjectives(({ "unfinished", "rough", "dark", "iron", "glowing",
        "half-forged", "crude", "heavy", "cooling", "hammer-marked" }));

    addDescriptionTemplate("a ##Adjective## sword blank cooling on the anvil");

    addItemTemplate(
        "The sword blank is a rough shape of hammered iron, recognizably "
        "blade-like but far from finished. The metal is dark with scale "
        "and marked with hammer blows, its edges thick and unground. "
        "Several such blanks in various stages of completion lean against "
        "the wall nearby, each awaiting its turn at the grinder."
    );

    addSomeLightDescriptionTemplate(
        "rough sword blanks lean against the wall, unfinished and "
        "hammer-marked"
    );
    addDimLightDescriptionTemplate(
        "dark elongated metal shapes lean against the wall"
    );
    addLowLightDescriptionTemplate(
        "dark shapes lean against the wall, vaguely blade-like"
    );
    addNearDarkDescriptionTemplate(
        "the smell of hot iron and scale fills the smithy"
    );
}
