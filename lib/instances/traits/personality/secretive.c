//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "secretive");
    addSpecification("description", "You are inclined to conceal your "
        "motivations and feelings.");
    addSpecification("root", "secretive");
    addSpecification("opinion", -5);
}
