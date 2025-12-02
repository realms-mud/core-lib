//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quick Reaction");
    addSpecification("source", "background");
    addSpecification("description",
        "You respond swiftly to threats and changes in the flow of battle.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus defense class", 1);
}
