//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fleet-Footed");
    addSpecification("source", "background");
    addSpecification("description",
        "You move with speed and agility, able to cover ground quickly and "
        "evade danger.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus stamina points", 2);
}
