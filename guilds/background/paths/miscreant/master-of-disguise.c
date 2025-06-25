//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Master of Disguise");
    addSpecification("source", "background");
    addSpecification("description",
        "You are skilled at concealing your identity and blending in.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus disguise", 1);
    addSpecification("bonus bluff", 1);
    addSpecification("bonus persuasion", 1);

    addPrerequisite("/guilds/background/paths/miscreant/underworld-contacts.c", 
        (["type":"research"]));
}
