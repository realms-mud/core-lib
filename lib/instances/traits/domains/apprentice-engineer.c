//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "professional");
    addSpecification("name", "apprentice engineer");
    addSpecification("description", "You have just begun learning about engineering");
    addSpecification("root", "engineer");
    addSpecification("opinion", 1);
    addSpecification("bonus engineering", 2);
    addSpecification("bonus mathematics", 1);
    addSpecification("bonus physics", 1);
}
