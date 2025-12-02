//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "persuasive");
    addSpecification("description", "You are very good at convincing "
        "others of your deeply-held convictions.");
    addSpecification("root", "persuasive");
    addSpecification("opinion", 5);
    addSpecification("bonus persuasion", 3);
}
