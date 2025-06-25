//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quick Hands");
    addSpecification("source", "background");
    addSpecification("description",
        "Your nimble fingers make you adept at sleight of hand and picking pockets.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus sleight of hand", 1);
    addSpecification("bonus lock picking", 1);
    addSpecification("bonus dexterity", 1);
}
