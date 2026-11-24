//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("chapel register");
    addAlias("stone register");
    addDescriptionTemplate("a stone register carved with names and work dates");
    addItemTemplate("The register records that the cave path and spring were "
        "maintained by local foresters and miners in rotation. No house is "
        "listed as owner, and the final entries order the adit closed after "
        "a roof fall.");
}
