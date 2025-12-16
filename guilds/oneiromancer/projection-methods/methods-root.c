//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Projection Methods");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "foundational knowledge of projecting psionic attacks through various "
        "methods. These techniques modify how attacks are delivered and can "
        "be stacked in combination attacks for enhanced effects.");
    addSpecification("usage summary", "Foundational projection method knowledge");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus mind", 1);
    addSpecification("bonus senses", 1);
}
