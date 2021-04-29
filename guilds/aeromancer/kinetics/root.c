//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aeromancer Kinetics");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of propulsion mechanisms for constructed Aeromancer spells.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus spellcraft", 1);
}
