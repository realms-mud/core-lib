//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "A Background in Athletics");
    addSpecification("source", "background");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge learned from athletic pursuits.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
    addSpecification("bonus strength", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus dodge", 1);
    addSpecification("bonus unarmed", 1);
    addSpecification("bonus anatomy and physiology", 1);
    addSpecification("bonus climb", 1);
    addSpecification("bonus hunting", 1);
    addSpecification("bonus swimming", 1);
}
