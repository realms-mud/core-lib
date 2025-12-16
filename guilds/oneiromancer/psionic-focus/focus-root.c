//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psionic Focus");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "foundational knowledge of focusing psychic energy into offensive "
        "forms. These mental constructs serve as the core of psionic attacks "
        "and can be combined with dream imagery and projection methods for "
        "devastating effect.");
    addSpecification("usage summary", "Foundational psionic attack knowledge");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus mind", 1);
    addSpecification("bonus senses", 1);
}
