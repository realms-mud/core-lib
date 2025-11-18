//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Calming Presence");
    addSpecification("source", "background");
    addSpecification("description",
        "There's something about you that puts others at ease. In your presence, "
        "fear subsides and hope kindles. Animals sense your gentle nature and "
        "the wounded find comfort in your care.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus charisma", 1);
    addSpecification("bonus animal handling", 2);
    addSpecification("bonus etiquette", 1);
}
