//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addSpecification("name", "Initiate's Discipline");
    addSpecification("description", "An instructor teaches safe, deliberate "
        "unarmed movement. This first lesson begins a mentored curriculum "
        "without replacing the self-taught foundations.");
    addSpecification("source", "monk");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);
    addSpecification("bonus unarmed", 1);
}
