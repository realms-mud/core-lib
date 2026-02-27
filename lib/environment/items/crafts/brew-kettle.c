//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("brew kettle");
    addAlias("kettle");
    addAlias("copper kettle");
    addAlias("brewing kettle");

    addAdjectives(({ "copper", "massive", "dented", "steaming",
        "well-used", "bright", "heavy", "riveted", "old", "patinated" }));

    addDescriptionTemplate("a ##Adjective## brew kettle suspended over a fire pit");

    addItemTemplate(
        "The brew kettle is a massive copper vessel, its sides dented "
        "and patinated green from years of use. It hangs from an iron "
        "chain over a fire pit, and the interior is stained dark from "
        "countless batches of ale. The warm, yeasty smell of brewing "
        "permeates everything nearby."
    );

    addSomeLightDescriptionTemplate(
        "a massive copper brew kettle hangs over a fire pit, steaming gently"
    );
    addDimLightDescriptionTemplate(
        "a large copper vessel hangs over a pit, its surface dully gleaming"
    );
    addLowLightDescriptionTemplate(
        "a large vessel hangs from a chain, steam rising from within"
    );
    addNearDarkDescriptionTemplate(
        "the warm smell of yeast and brewing fills the air"
    );
}
