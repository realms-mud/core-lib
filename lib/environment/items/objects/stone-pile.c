//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone pile");
    addAlias("rubble");
    addAlias("pile of stones");
    addAlias("rock pile");

    addAdjectives(({ "rough", "mossy", "large", "scattered", "grey",
        "weathered", "tumbled", "lichen-covered", "old", "crumbling" }));

    addDescriptionTemplate("a ##Adjective## pile of stones heaped on the ground");

    addItemTemplate(
        "A heap of stones lies in a rough pile, some squared and dressed "
        "as if salvaged from a demolished wall, others raw and unworked. "
        "Moss and lichen cover the lower stones, and weeds push up between "
        "the gaps. It may be construction material, demolition debris, or "
        "simply a farmer's field clearings."
    );

    addSomeLightDescriptionTemplate(
        "a pile of stones sits in a rough heap, mossy and weathered"
    );
    addDimLightDescriptionTemplate(
        "a heap of stones is visible, grey and indistinct"
    );
    addLowLightDescriptionTemplate(
        "a rough mound of something hard sits on the ground"
    );
    addNearDarkDescriptionTemplate(
        "an uneven mound is barely perceptible in the darkness"
    );
}
