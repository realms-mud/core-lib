//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Keen Memory");
    addSpecification("source", "background");
    addSpecification("description",
        "You have an excellent memory for facts and details.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 2);
    addSpecification("bonus intelligence", 1);
}
