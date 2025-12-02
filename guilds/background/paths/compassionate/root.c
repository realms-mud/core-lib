//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Background in Compassion");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from caring for others and developing "
        "deep empathy for those who suffer.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus charisma", 1);
    addSpecification("bonus anatomy and physiology", 2);
    addSpecification("bonus herbalism", 1);
    addSpecification("bonus diplomacy", 1);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus animal handling", 1);
    addSpecification("bonus cooking", 1);
}
