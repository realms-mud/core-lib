//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Underworld Contacts");
    addSpecification("source", "background");
    addSpecification("description",
        "You have cultivated a network of shady contacts, making it "
        "easier to gather information and favors.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus bluff", 1);
    addSpecification("bonus barter", 1);

    addPrerequisite("/guilds/background/paths/miscreant/dirty-fighting.c", 
        (["type":"research"]));
}
