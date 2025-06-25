//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pillar of Community");
    addSpecification("source", "background");
    addSpecification("description",
        "You are a model of service and reliability in your community.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus resist psionic", 5);
    addSpecification("bonus defense class", 1);

    addPrerequisite("/guilds/background/paths/dutiful/iron-discipline.c",
        (["type":"research"]));
}
