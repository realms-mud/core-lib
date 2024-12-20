//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "role");
    addSpecification("name", "Sword Master");
    addSpecification("description", "blah blah blah");
    addSpecification("bonus strength", 2);
    addSpecification("bonus long sword", 1);
    addSpecification("limited by", (["equipment":"long sword"]));
    addSpecification("bonus weapon attack", 1);
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
