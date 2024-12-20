//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Background in Manipulation");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from a lifetime of doing what you "
        "can to get what you want.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus charisma", 1);
    addSpecification("bonus perception", 1);
    addSpecification("bonus etiquette", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus intimidation", 1);
    addSpecification("bonus barter", 1);
    addSpecification("bonus diplomacy", 1);
    addSpecification("bonus linguistics", 1);
    addSpecification("bonus philosophy", 1);
    addSpecification("bonus bluff", 1);
    addSpecification("bonus reading", 1);
    addSpecification("bonus writing", 1);
}
