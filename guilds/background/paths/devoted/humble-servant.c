//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Humble Servant");
    addSpecification("source", "background");
    addSpecification("description", "Humility has taught you to listen and serve.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus charisma", 1);
    addSpecification("bonus diplomacy", 1);
}
