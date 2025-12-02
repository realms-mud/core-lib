//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unbreakable");
    addSpecification("source", "background");
    addSpecification("description",
        "You are nearly impossible to defeat, enduring even the harshest "
        "punishment.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 10);
    addSpecification("bonus resist paralysis", 2);
    addSpecification("bonus resist magical", 2);
}
