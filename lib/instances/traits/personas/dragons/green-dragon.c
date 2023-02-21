//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "green dragon");
    addSpecification("description", "You are a green dragon.");
    addSpecification("root", "large creature persona");
    addSpecification("bonus resist fire", 75);
    addSpecification("bonus resist poison", 75);
}
