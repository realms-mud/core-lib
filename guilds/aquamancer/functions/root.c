//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aquamancer Kinetics");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of propulsion mechanisms for constructed Aquamancer spells.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus spellcraft", 1);
}
