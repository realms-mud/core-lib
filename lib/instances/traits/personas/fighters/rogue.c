//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "persona");
    addSpecification("name", "rogue");
    addSpecification("description", "You are a cunning rogue.");
    addSpecification("root", "fighter persona");
}
