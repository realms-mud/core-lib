//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pure Chi Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The principles of focusing internal energy through your existing "
        "spell-point reserves. Disciplined breathing opens the first "
        "projection lesson; further study develops circulation and "
        "resonance without a separate chi pool.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addSpecification("research type", "tree root");
}
