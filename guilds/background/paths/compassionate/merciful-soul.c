//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Merciful Soul");
    addSpecification("source", "background");
    addSpecification("description",
        "You cannot turn away from suffering, even that of your enemies. "
        "Your compassion extends to all living things, and your presence "
        "offers comfort even in the darkest moments.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus charisma", 2);
    addSpecification("bonus persuasion", 1);
    addSpecification("bonus animal handling", 1);
}
