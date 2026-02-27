//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mounting block");
    addAlias("horse block");
    addAlias("step block");

    addAdjectives(({ "stone", "worn", "sturdy", "old", "mossy",
        "well-used", "broad", "low", "weathered", "solid" }));

    addDescriptionTemplate("a ##Adjective## mounting block for riders");

    addItemTemplate(
        "The mounting block is a broad, flat-topped stone set beside the "
        "road, its surface worn into a shallow depression by generations "
        "of boots stepping up to mount horses. The sides are scuffed and "
        "chipped, and moss grows in the joints of the stonework."
    );

    addSomeLightDescriptionTemplate(
        "a stone mounting block stands by the road, worn smooth by use"
    );
    addDimLightDescriptionTemplate(
        "a low stone block is visible by the road"
    );
    addLowLightDescriptionTemplate(
        "a low flat shape beside the road might be a mounting block"
    );
    addNearDarkDescriptionTemplate(
        "a low stone shape sits beside the road"
    );
}
