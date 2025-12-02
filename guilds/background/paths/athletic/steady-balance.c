//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Steady Balance");
    addSpecification("source", "background");
    addSpecification("description",
        "You have an exceptional sense of balance, making it difficult to "
        "knock you off your feet.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus acrobatics", 1);
    addSpecification("bonus defense class", 1);
    addSpecification("bonus constitution", 1);
}
