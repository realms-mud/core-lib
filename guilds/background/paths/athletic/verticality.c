//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Verticality");
    addSpecification("source", "background");
    addSpecification("description",
        "You are skilled at moving up and down vertical surfaces and "
        "navigating obstacles.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus climb", 1);
    addSpecification("bonus acrobatics", 1);
    addSpecification("bonus dexterity", 1);
}
