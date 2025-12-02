//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "trusting");
    addSpecification("description", "You tend take peoples words and "
        "actions at face value. You see the best in people and generally "
        "trust their intentions.");
    addSpecification("root", "kind");
    addSpecification("opposing root", "cruel");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", 5);
    addSpecification("bonus persuasion", 1);
}
