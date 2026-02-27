//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("broom");
    addAlias("straw broom");
    addAlias("besom");
    addAlias("sweeping broom");

    addAdjectives(({ "straw", "worn", "leaning", "old", "sturdy",
        "well-used", "frayed", "simple", "rough", "serviceable" }));

    addDescriptionTemplate("a ##Adjective## broom leaning against the wall");

    addItemTemplate(
        "The broom is a simple affair of stiff straw bristles bound to a "
        "long wooden handle with wire. The bristles are worn uneven from "
        "use, and the handle is smooth where hands have gripped it "
        "countless times. It leans at a familiar angle against the wall, "
        "ready for the next sweeping."
    );

    addSomeLightDescriptionTemplate(
        "a straw broom leans against the wall, its bristles worn and frayed"
    );
    addDimLightDescriptionTemplate(
        "a broom leans against the wall, a thin shape with a broad base"
    );
    addLowLightDescriptionTemplate(
        "a thin shape leans against the wall"
    );
    addNearDarkDescriptionTemplate(
        "something long and thin leans against the wall nearby"
    );
}
