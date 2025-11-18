//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Weapon Mastery");
    addSpecification("source", "background");
    addSpecification("description",
        "You have achieved mastery with your chosen weapons.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
    addSpecification("bonus weapon attack", 1);

    addPrerequisite("/guilds/background/paths/martial/armor-training.c",
        (["type":"research"]));
}
