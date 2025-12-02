//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dirty Fighting");
    addSpecification("source", "background");
    addSpecification("description",
        "You fight with every trick in the book, using underhanded "
        "tactics to gain the upper hand.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus unarmed", 1);

    addPrerequisite("/guilds/background/paths/miscreant/urban-survivor.c", 
        (["type":"research"]));
}
