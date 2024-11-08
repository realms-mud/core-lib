//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "hydra");
    addSpecification("description", "You are a hydra.");
    addSpecification("root", "large creature persona");
    addSpecification("bonus soak", 5);
    addSpecification("bonus heal hit points rate", 25);
}
