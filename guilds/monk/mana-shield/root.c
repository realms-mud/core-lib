//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mana Shield Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The principles of shaping a ward from your existing spell-point "
        "reserves. Disciplined breathing opens Mindful Ward, followed by "
        "guarded recovery and counterprojection without another energy "
        "pool.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addSpecification("research type", "tree root");
}
