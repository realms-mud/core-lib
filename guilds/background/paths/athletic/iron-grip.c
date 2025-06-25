//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Iron Grip");
    addSpecification("source", "background");
    addSpecification("description",
        "Your hands are strong and steady, allowing you to hold on even in "
        "the most challenging circumstances.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus climb", 1);
    addSpecification("bonus strength", 1);
    addSpecification("bonus unarmed", 1);
}
