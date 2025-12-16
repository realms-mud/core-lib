//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Imagery");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "foundational knowledge of weaving nightmare imagery into psionic "
        "attacks. These terrifying visions enhance combination attacks with "
        "additional damage types and debilitating effects.");
    addSpecification("usage summary", "Foundational nightmare imagery knowledge");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus mind", 1);
    addSpecification("bonus evocation", 1);
}
