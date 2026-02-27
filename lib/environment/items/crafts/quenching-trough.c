//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("quenching trough");
    addAlias("slack tub");
    addAlias("tempering trough");

    addAdjectives(({ "stone", "water-filled", "steaming", "soot-ringed",
        "deep", "dark", "cool", "brimming", "oil-sheened", "old" }));

    addDescriptionTemplate("a ##Adjective## quenching trough near the anvil");

    addItemTemplate(
        "The quenching trough is a deep stone basin filled with dark water "
        "that carries a faint sheen of oil on its surface. Wisps of steam "
        "rise from it occasionally when hot metal is plunged in, and the "
        "stone rim is blackened with soot and scale. The water smells of "
        "iron and quenching oil."
    );

    addSomeLightDescriptionTemplate(
        "a stone quenching trough sits near the anvil, its water dark and "
        "still"
    );
    addDimLightDescriptionTemplate(
        "a deep trough of dark water is visible near the forge"
    );
    addLowLightDescriptionTemplate(
        "a dark shape filled with water sits near the forge"
    );
    addNearDarkDescriptionTemplate(
        "the scent of hot iron and oil suggests a quenching trough nearby"
    );
}
