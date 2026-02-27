//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("museum display case");
    addAlias("case");
    addAlias("glass case");
    addAlias("cabinet");

    addAdjectives(({ "wooden", "glass-topped", "carefully arranged",
        "protective", "antique" }));

    addDescriptionTemplate("##Adjective## display case containing historical "
        "artifacts and curiosities");

    addItemTemplate("The wooden cabinet features a glass top to protect the "
        "contents while allowing visitors to examine the carefully arranged "
        "items within");

    addSomeLightDescriptionTemplate("a wooden cabinet with a glass top, "
        "protecting treasured artifacts from dust and handling");

    addDimLightDescriptionTemplate("what appears to be a display case with "
        "items arranged inside");

    addLowLightDescriptionTemplate("the outline of what might be a cabinet or "
        "display case");

    addNearDarkDescriptionTemplate("a darker shape that could be furniture of "
        "some kind");
}

