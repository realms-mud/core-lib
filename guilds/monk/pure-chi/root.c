//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addSpecification("name", "Pure Chi Foundations");
    addSpecification("description", "The principles of focusing internal "
        "energy through your existing spell-point reserves. Individual "
        "techniques require advanced instruction.");
    addSpecification("source", "monk");
    addSpecification("research type", "tree root");
}
