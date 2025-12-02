//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("theater masks");
    addAlias("stone masks");
    addAlias("carvings");
    addAlias("theatrical masks");
    addAlias("comedy and tragedy");

    addAdjectives(({ "carved", "stone", "weathered", "ancient", "theatrical" }));

    addDescriptionTemplate("##Adjective## masks of comedy and tragedy adorning the wall behind the stage");
    addItemTemplate("Despite centuries of weathering, their exaggerated expressions remain clearly visible - one with an exaggerated grin, the other with a dramatic frown");
    addItemTemplate("These iconic symbols of theater have watched over countless performances through the ages");

    addSomeLightDescriptionTemplate("carved stone faces with exaggerated expressions");
    addDimLightDescriptionTemplate("what appear to be theatrical masks carved into the wall");
    addLowLightDescriptionTemplate("carvings on the wall that resemble faces");
    addNearDarkDescriptionTemplate("shadowy shapes on the wall that might be decorative carvings");
}
