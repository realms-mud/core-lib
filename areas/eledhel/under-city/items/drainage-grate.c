//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("drainage grate");
    addAlias("street grate");
    addAlias("iron grate");
    addItemTemplate(
        "A narrow iron grate is set high in the fitted vault. It drains "
        "street runoff into the cistern channel; by day, only a thin grey "
        "wash of light filters through its bars."
    );
    addNearDarkDescriptionTemplate(
        "a faint grey lattice high in the stone vault"
    );
    addLowLightDescriptionTemplate(
        "a narrow grate set high in the vault"
    );
    addDimLightDescriptionTemplate(
        "an iron drainage grate with a thin wash of daylight behind it"
    );
    addSomeLightDescriptionTemplate(
        "an iron street grate filtering daylight into the tunnel"
    );
    addDescriptionTemplate(
        "a street grate set into the stone vault"
    );
    addSourceOfLight(2, "default", "dawn");
    addSourceOfLight(2, "default", "morning");
    addSourceOfLight(2, "default", "noon");
    addSourceOfLight(2, "default", "afternoon");
}
