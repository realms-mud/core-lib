//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stone Spells");
    addSpecification("source", "geomancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of stone-based spells for Geomancers.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus elemental earth", 1);
    addSpecification("bonus magical essence", 1);
}
