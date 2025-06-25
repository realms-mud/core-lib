//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Drill Discipline");
    addSpecification("source", "background");
    addSpecification("description",
        "You have learned the value of repetition, order, and discipline in "
        "military training.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus parry", 1);
    addSpecification("bonus resist paralysis", 1);
}
