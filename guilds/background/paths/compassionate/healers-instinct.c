//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Healer's Instinct");
    addSpecification("source", "background");
    addSpecification("description", "Years of tending wounds have given you "
        "an instinctive understanding of injuries.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus herbalism", 1);

    addPrerequisite("/guilds/background/paths/compassionate/gentle-touch.c",
        (["type":"research"]));
}
