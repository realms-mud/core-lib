//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "talkative");
    addSpecification("description", "You can easily catch and hold the "
        "attention of those around you. Unfortunately, you tend to "
        "ramble on long after your audience has lost interest in what "
        "you have to say.");
    addSpecification("root", "interesting");
    addSpecification("opinion", -5);
    addSpecification("bonus bluff", 1);
}
