//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wine cask");
    addAlias("cask");
    addAlias("wine barrel");
    addAlias("tapped cask");

    addAdjectives(({ "oak", "large", "iron-banded", "tapped", "stained",
        "aged", "well-sealed", "heavy", "aromatic", "dark" }));

    addDescriptionTemplate("a ##Adjective## wine cask racked on a wooden cradle");

    addItemTemplate(
        "The wine cask is a large oak barrel resting on a wooden cradle, "
        "a brass spigot tapped into one end. The oak is dark with age "
        "and stained purple around the tap where countless cups have been "
        "filled. A chalk marking on the head indicates the vintage and "
        "variety within."
    );

    addSomeLightDescriptionTemplate(
        "a wine cask sits on its cradle, its brass spigot gleaming"
    );
    addDimLightDescriptionTemplate(
        "a large cask rests on a wooden cradle, a spigot visible at one end"
    );
    addLowLightDescriptionTemplate(
        "a large cylindrical shape rests on a cradle"
    );
    addNearDarkDescriptionTemplate(
        "the rich aroma of aged wine emanates from a large container"
    );
}
