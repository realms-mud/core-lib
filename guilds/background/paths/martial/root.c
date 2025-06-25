//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Background in Martial Learning");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from a classical military education.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus constitution", 1);
    addSpecification("bonus parry", 1);
    addSpecification("bonus dodge", 1);
    addSpecification("bonus shield", 1);
    addSpecification("bonus axe", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus short sword", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus hammer", 1);
    addSpecification("bonus listen", 1);
    addSpecification("bonus reading", 1);
    addSpecification("bonus writing", 1);
}
