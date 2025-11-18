//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Empathic Sense");
    addSpecification("source", "background");
    addSpecification("description",
        "You can read the pain and emotions of others with uncanny accuracy. "
        "This deep empathy allows you to understand what people truly need, "
        "often before they say a word.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus persuasion", 2);
    addSpecification("bonus diplomacy", 1);
}
