//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quick Learner");
    addSpecification("source", "background");
    addSpecification("description",
        "You pick up new skills and knowledge with remarkable speed.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus reading", 1);
    addSpecification("bonus writing", 1);
    addSpecification("bonus intelligence", 1);
}
