//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quick Lie");
    addSpecification("source", "background");
    addSpecification("description",
        "You can fabricate believable lies at a moment's notice.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus bluff", 3);
    addSpecification("bonus charisma", 1);
}
