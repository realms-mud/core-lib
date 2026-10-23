//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addSpecification("name", "Mana Shield Foundations");
    addSpecification("description", "The principles of shaping a ward from "
        "your existing spell-point reserves. Individual wards still "
        "require advanced instruction.");
    addSpecification("source", "monk");
    addSpecification("research type", "tree root");
}
