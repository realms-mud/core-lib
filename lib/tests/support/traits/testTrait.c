//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "role");
    addSpecification("name", "Sword Boy");
    addSpecification("description", "blah blah blah");
    addSpecification("bonus strength", 2);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus fire attack", 15);
    addSpecification("bonus weapon attack", 1);
    addSpecification("bonus resist fire", 10);
    addSpecification("root", "jock");
    addSpecification("opposing root", "nerd");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    addSpecification("cost", 8);
}

/////////////////////////////////////////////////////////////////////////////
public int addSpecification(string type, mixed value)
{
    return baseTrait::addSpecification(type, value);
}
