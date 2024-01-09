//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "stoic");
    addSpecification("description", "You tend to not speak of or show "
        "your feelings when enduring hardships or pain.");
    addSpecification("root", "humble");
    addSpecification("opinion", 5);
}
