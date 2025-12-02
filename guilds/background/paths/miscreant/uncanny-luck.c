//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Uncanny Luck");
    addSpecification("source", "background");
    addSpecification("description",
        "You seem to avoid harm and misfortune more often than chance would allow.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense class", 2);
    addSpecification("bonus resist poison", 2);
    addSpecification("bonus resist paralysis", 2);
}
