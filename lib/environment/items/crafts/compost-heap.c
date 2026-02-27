//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("compost heap");
    addAlias("compost");
    addAlias("midden");
    addAlias("compost pile");

    addAdjectives(({ "steaming", "dark", "rich", "earthy", "pungent",
        "large", "decomposing", "warm", "loamy", "well-tended" }));

    addDescriptionTemplate("a ##Adjective## compost heap behind the garden");

    addItemTemplate(
        "The compost heap is a mound of decomposing vegetable matter, "
        "kitchen scraps, and garden waste in various stages of breaking "
        "down into rich, dark soil. It steams faintly in cool air and "
        "smells of earth and decay — not entirely unpleasant. A pitchfork "
        "is stuck into its side."
    );

    addSomeLightDescriptionTemplate(
        "a compost heap steams gently, dark and rich with decomposing matter"
    );
    addDimLightDescriptionTemplate(
        "a dark mound steams faintly behind the garden"
    );
    addLowLightDescriptionTemplate(
        "a dark mound of something sits behind the garden"
    );
    addNearDarkDescriptionTemplate(
        "the earthy smell of decomposing plant matter fills the air"
    );
}
