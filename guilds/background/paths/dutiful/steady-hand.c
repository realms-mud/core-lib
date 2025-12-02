//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Steady Hand");
    addSpecification("source", "background");
    addSpecification("description",
        "You are calm and precise, even under pressure.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus parry", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus defense class", 1);
}
