//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("firewood bin");
    addAlias("wood bin");
    addAlias("log box");
    addAlias("wooden firewood bin");

    addAdjectives(({ "wooden", "broad", "open", "old", "sturdy", "plain",
        "functional", "worn", "rectangular", "heavy" }));

    addDescriptionTemplate("a ##Adjective## firewood bin filled with logs");

    addItemTemplate(
        "This firewood bin is a broad, open box made from thick wooden planks. "
        "It is set near the hearth and filled with split logs for the fire."
    );

    addSomeLightDescriptionTemplate(
        "a wooden firewood bin sits near the hearth, filled with logs"
    );
    addDimLightDescriptionTemplate(
        "a firewood bin is visible in the gloom, its outline broad and low"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a firewood bin can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a firewood bin is present, but details are lost "
        "in the darkness"
    );
}
