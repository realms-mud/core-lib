//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Poison Affinity");
    addSpecification("source", "background");
    addSpecification("description",
        "You have developed a resistance to toxins and a knack for using them.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist poison", 10);
    addSpecification("bonus herbalism", 1);
    addSpecification("bonus chemistry", 1);
}
