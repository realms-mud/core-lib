//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("silted sluice");
    addAlias("sluice gate");
    addItemTemplate(
        "A narrow iron sluice gate is half-buried in silt and gravel. "
        "Water still finds a way beneath it, leaving a dark wet seam."
    );
    addDescriptionTemplate(
        "a rusted sluice gate clogged with silt and gravel"
    );
}
