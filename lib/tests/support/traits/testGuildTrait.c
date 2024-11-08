//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "guild");
    addSpecification("name", "Sword Dude");
    addSpecification("description", "blah blah blah");
    addSpecification("root", "swords");
    addSpecification("opposing root", "fists");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
    addSpecification("cost", 1);
}
