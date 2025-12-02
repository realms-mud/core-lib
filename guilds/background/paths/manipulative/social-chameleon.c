//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Social Chameleon");
    addSpecification("source", "background");
    addSpecification("description",
        "You easily adapt to different social situations and blend in.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus disguise", 1);
    addSpecification("bonus etiquette", 1);
    addSpecification("bonus charisma", 1);
}
