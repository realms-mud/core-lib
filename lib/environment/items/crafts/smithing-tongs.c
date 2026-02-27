//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("smithing tongs");
    addAlias("tongs");
    addAlias("forge tongs");
    addAlias("iron tongs");

    addAdjectives(({ "iron", "long-handled", "heavy", "blackened",
        "well-used", "scarred", "sturdy", "functional", "soot-caked",
        "various" }));

    addDescriptionTemplate("##Adjective## smithing tongs hanging from a hook");

    addItemTemplate(
        "Several pairs of smithing tongs hang from hooks near the forge, "
        "each with a different jaw shape for gripping various types of "
        "work. The iron is blackened from heat, and the handles are worn "
        "smooth. Some have flat jaws for bar stock, others are curved for "
        "round work or notched for holding nails."
    );

    addSomeLightDescriptionTemplate(
        "several pairs of smithing tongs hang from hooks, blackened by use"
    );
    addDimLightDescriptionTemplate(
        "long iron tools hang from hooks near the forge"
    );
    addLowLightDescriptionTemplate(
        "dark shapes hang from hooks on the wall"
    );
    addNearDarkDescriptionTemplate(
        "the faint clink of iron suggests tools hanging nearby"
    );
}
