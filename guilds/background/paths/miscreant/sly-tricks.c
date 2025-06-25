//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sly Tricks");
    addSpecification("source", "background");
    addSpecification("description",
        "You have a knack for subtle misdirection and clever ruses.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus deception", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus intelligence", 1);
}
